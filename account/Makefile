account.o: account.c
	gcc -g -Wall -c account.c

test_account.o: test_account.c
	gcc -g -Wall -c test_account.c

test_account: account.o test_account.o
	gcc -o test_account test_account.o account.o
