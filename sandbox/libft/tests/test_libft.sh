#!/bin/sh

# Launch libft-unit-test and make clean 

cd ..;
cd libft-unit-test-master/
make re && make f;
cd ..;
cd libft;
make clean;