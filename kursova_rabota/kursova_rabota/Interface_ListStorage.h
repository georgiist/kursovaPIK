#pragma once
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#ifndef INTERFACE_LISTSTORAGE_H
#define INTERFACE_LISTSTORAGE_H

typedef struct Ship {
	int xDown, yDown;
	int xUp, yUp;
	struct Ship* next;
}Ship;

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define file "result.txt"
#pragma warning(disable : 4996)

Ship* createList(int size);
int shooting(Ship* head, int n);
void writeInFile(int result);

void MainThread();

#endif /* INTERFACE_LISTSTORAGE_H */