#ifndef matriks_H
#define matriks_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Bottom(P) (P)->bottom
#define First(L) (L).First

typedef char* infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next,bottom;
} ElmtList;

typedef struct {
	address First;
} List;

bool isEmpty(List L);
address Alokasi(List *L);
address createMatrix(int row,int column,int x, int y);
void insertRow(List *L,infotype X);
void insertColumn(List *L,infotype X);
void display(List Head);

#endif
