CC = gcc

CFLAGS = -Wall -g

output: CruzHash

CruzHash: CruzHash.o inputHelper.o hashTable.o
	$(CC) $(CFLAGS) -o CruzHash CruzHash.o inputHelper.o hashTable.o

CruzHash.o: CruzHash.c inputHelper.h hashTable.h
	$(CC) $(CFLAGS) -c CruzHash.c

hashTable.o: hashTable.c hashTable.h
	$(CC) $(CFLAGS) -c hashTable.c

inputHelper.o: inputHelper.c inputHelper.h
	$(CC) $(CFLAGS) -c inputHelper.c
