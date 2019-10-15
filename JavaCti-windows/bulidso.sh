#!/bin/sh
#swig -java  shcti.i
gcc -shared shcti_wrap.c -o libshcti.so -lshpa3 
rm -rf /usr/lib/libshcti.so
ln  -s  `pwd`/libshcti.so   /usr/lib/libshcti.so
javac  *.java
