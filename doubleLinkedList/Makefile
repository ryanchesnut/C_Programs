double_list.o: double_list.c
	gcc -g -Wall -std=c99 -c double_list.c

test_double_list.o: test_double_list.c
	gcc -g -Wall -std=c99 -c test_double_list.c

test_double_list: double_list.o test_double_list.o
	gcc -o test_double_list test_double_list.o double_list.o 

