#include "matriks.h"
#include <conio.h>

bool isEmpty(List L){
	if(First(L) == NULL){
		return true;
	} else {
		return false;
	}
}address Alokasi(infotype X){
	address temp;

	temp = (tElmtList*) malloc (sizeof(tElmtList));
	Info(temp) = (char*) malloc (sizeof(char)*strlen(X));
	Info(temp) = X;
	Next(temp) = NULL;
	Bottom(temp) = NULL;
	if(temp == NULL){
		return NULL;
	}	
	return temp;
}

address createMatrix(int row,int column,int x,int y){
	address temp;
	if(x >= row || y >= column){
		return NULL;
	}
	temp = Alokasi("Tes");
	Next(temp) = createMatrix(row,column,x+1,y);
	Bottom(temp) = createMatrix(row,column,x,y+1);
	
	return temp;
}

void insertRow(List *L,infotype X){
	address x,y;
	
	y = First(*L);
	x = Alokasi(X);
	First(*L) = x;
	while(Next(y) != NULL){
		Bottom(x) = y;
		y = Next(y);
		Next(x) = Alokasi(X);
		x = Next(x);	
	}
	
	
}

void insertColumn(List *L,infotype X){
	
	address index,x,temp,y;
	int row = 1;
	int count = 1;
	index = y = First(*L);
	if(isEmpty(*L)){
		printf("\nMatrix belum dibuat!");
		getche();
		return;
	} else {
		while(Bottom(index) != NULL){
			index = Bottom(index);
//			printf("\nberhasil");
			row++;
		}
//		printf("\n");
		while(Next(y)!=NULL){
			y = Next(y);
//			printf("\nberhasil");
		}
//		printf("\n");
		temp = Alokasi(X);
		x = temp;
//		printf("\nberhasil");
		while(count < row){
			Bottom(temp) = Alokasi(X);
			temp = Bottom(temp);
			count++;
		}
		while(x != NULL){
			Next(y) = x;
			y = Bottom(y);
			x = Bottom(x);
		}
	}
//	while(Next(x) != NULL){
//		x = Next(x);
//	}
//	y = Alokasi(X);
//	Next(x) = y;
//	while(x != NULL){
//		x = Bottom(x);
//		Bottom(y) = Alokasi(X);
//		y = Bottom(y);
//		Next(x) = y;
//	}
}

void display(List Head){
	address x,y;
	y = First(Head);
	
	while(y != NULL){
		x = y;
		while(x != NULL){
			printf("|%s|",Info(x));
			x = Next(x);
		}
		printf("\n");
		y = Bottom(y);
	}
}
