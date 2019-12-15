#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>

#define QUEUE_ASSERT(q) \
    do {\
        if (q == NULL)\
        {\
            return E_ERR;\
        }\
    } while (0)
#define SIZE 10

static int keyNum = 0;
enum _ret
{
    E_OK,
    E_ERR
};

char *keyPool[32] =
    {
        "UP",
        "DOWN",
        "LEFT",
        "RIGHT",
        "HOME",
        "BACK",
        "VOLUME_UP",
        "VOLUME_DOWN"};

typedef struct _queue //队列结构体
{
    char *key[SIZE];
    int front; // 指向队头的下标
    int rear;  // 指向队尾的下标
    int capacity; //队列容量
} Queue;

struct data //信号量结构体
{
    sem_t empty;
    sem_t full;
    Queue q;
};

pthread_mutex_t mutex;
int num = 0;
struct data sem;

int InitQueue(Queue *q) // 队列初始化
{
    QUEUE_ASSERT(q);

    q->front = 0;
    q->rear = 0;
    q->capacity = 0;

    return E_OK;
}

int QueueEmpty(Queue *q) //判断空对情况
{
    QUEUE_ASSERT(q);

    if (q->capacity == 0)
    {
        return E_OK; 
    }
    return E_ERR;
}

int QueueFull(Queue *q) //判断队满的情况
{
    QUEUE_ASSERT(q);

    if (q->capacity == SIZE)
    {
        return E_OK; 
    }
    return E_ERR;
}

int DeQueue(Queue *q, char **key) //出队函数
{
    QUEUE_ASSERT(q);

    if (QueueEmpty(q))
    {
        printf("queue is empty\n");
        return E_ERR;
    }

    q->front = q->front % SIZE;
    *key = q->key[q->front];
    (q->front)++;
    (q->capacity)--;

    return E_OK;
}

int EnQueue(Queue *q, char *key) //进队函数
{
    QUEUE_ASSERT(q);

    if (QueueFull(q))
    {
        printf("queue is full\n");
        return E_ERR;
    }

    q->rear = q->rear % SIZE;
    q->key[q->rear] = key;
    (q->rear)++;
    (q->capacity)++;

    return E_OK;
}

void *Producer()
{
    while (10 != keyNum)
    {
        int time = rand() % 10 + 1; //随机使程序睡眠0点几秒
        usleep(time * 100000);
        num = rand() % 8;

        sem_wait(&sem.empty);       //信号量的P操作
        pthread_mutex_lock(&mutex); //互斥锁上锁

        //消息进队
        if (EnQueue(&(sem.q), keyPool[num]))
        {
            printf("EnQueue err\n");  
            pthread_mutex_unlock(&mutex); //互斥锁解锁
            sem_post(&sem.full);          //信号量的V操作
            break;
        }
        printf("生产了一条消息：%s\n", keyPool[num]);

        pthread_mutex_unlock(&mutex); //互斥锁解锁
        sem_post(&sem.full);          //信号量的V操作

        keyNum++;
    }
}

void *Consumer()
{
    char *conKey = NULL;

    while (1)
    {
        int time = rand() % 10 + 1; //随机使程序睡眠0点几秒
        usleep(time * 100000);

        sem_wait(&sem.full);        //信号量的P操作
        pthread_mutex_lock(&mutex); //互斥锁上锁

        DeQueue(&sem.q, &conKey); //消息出队
        printf("消费了一条消息:%s\n", conKey);

        pthread_mutex_unlock(&mutex); //互斥锁解锁
        sem_post(&sem.empty);         //信号量的V操作

        if (1 == QueueEmpty(&sem.q))
        {
            break;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    sem_init(&sem.empty, 0, 10); //信号量初始化（做多容纳10条消息，容纳了10条生产者将不会生产消息）
    sem_init(&sem.full, 0, 0);

    pthread_mutex_init(&mutex, NULL); //互斥锁初始化

    InitQueue(&(sem.q)); //队列初始化

    pthread_t producid;
    pthread_t consumid;

    pthread_create(&producid, NULL, Producer, NULL); //创建生产者线程
    pthread_create(&consumid, NULL, Consumer, NULL); //创建消费者线程

    pthread_join(consumid, NULL); //线程等待，如果没有这一步，主程序会直接结束，导致线程也直接退出。

    sem_destroy(&sem.empty); //信号量的销毁
    sem_destroy(&sem.full);

    pthread_mutex_destroy(&mutex); //互斥锁的销毁
    printf("finished\n");
    return 0;
}
