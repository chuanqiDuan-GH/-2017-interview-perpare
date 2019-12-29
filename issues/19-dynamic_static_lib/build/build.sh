#!/bin/bash


CUR_PATH=`dirname $0`

if [ -d $CUR_PATH/../output ];then
    rm -rf $CUR_PATH/../output
fi
mkdir -p $CUR_PATH/../output

if [ -d $CUR_PATH/../lib ];then
    rm -rf $CUR_PATH/../lib
fi
mkdir -p $CUR_PATH/../lib/so
mkdir -p $CUR_PATH/../lib/a


cd $CUR_PATH/../src/

#make clean
make
