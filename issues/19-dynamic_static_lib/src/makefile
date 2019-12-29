c_m_file := $(abspath $(lastword $(MAKEFILE_LIST)))
c_m_path := $(patsubst %/, %, $(dir $(c_m_file)))
l_a_path := $(c_m_path)/../lib/a
l_s_path := $(c_m_path)/../lib/so
lib_path := $(c_m_path)/../lib
output_path := $(c_m_path)/../output
src_path := $(c_m_path)/../src
include_path := $(c_m_path)/../include

Dynamic Static : static.c libshare.a dynamic.c libshare.so
	gcc static.c -I $(include_path) -L $(l_a_path) -l share -o $(output_path)/Static
	gcc dynamic.c -I $(include_path) -L $(l_s_path)/ -l share -o $(output_path)/Dynamic -Wl,-rpath $(l_s_path)/

libshare.so :
	gcc -fPIC -shared share.c -o $(l_s_path)/libshare.so


libshare.a :
	gcc -c share.c -o $(lib_path)/share.o
	ar -crv $(l_a_path)/libshare.a $(lib_path)/share.o


.PHONY : clean
clean :
	rm -rf $(output_path)/* $(lib_path)/*
