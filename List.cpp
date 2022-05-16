/* 
Nama : Panji Judha Fadhilla & Nurul Anisah
NIM : 211511053 & 211511052
Kelas : 1B
Tanggal : 8/03/2022
 */
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

bool ListEmpty (List L){
    if (Point(L) == Nil){
    	return true;
    } else {
          return false;
        }
}
        
void CreateList (List * L){
	if(ListEmpty){
     	Point(*L) = NULL;
	}
}

address Alokasi (infotype X,int jam,int menit){
	address P;
	
	P = (address)malloc(sizeof(ElmtList));
	if(P == Nil){
		cout << "Alokasi Gagal!";
		return NULL;
	}
	Info(P) = X;
	Jam(P) = jam;
	Menit(P) = menit;
	Next(P) = Nil;
	cout << "tes";
	return P;
}

void DeAlokasi (address *P){
	Next(*P) = Nil;
	free(*P);
}

address Search (List L, infotype X){
	address temp;
	
	temp = Point(L);
	while(1){
		if(Info(temp) == X){
			return temp;
		}
		if(temp == Nil){
			return Nil;
		}
		temp = Next(temp);
	}	
}

bool FSearch (List L, address P){
	address index;
	
	index = Point(L);
	if(P == index){
		return true;
	}
	do {
		index = Next(index);
		if(P == index){
			return true;
		}		
	}while(Next(index) != Nil);
	return false;
}

address SearchPrec (List L, infotype X){
	address P,index;
	
	P = Point(L);
	index = Point(L);
	if(Info(P) == X){
		return Nil;
	}
	do {
		P = Next(P);
		if(Info(P) == X){
		break;
		}	
	}while(Next(P) != Nil);
	if(Info(P) != X){
		return Nil;
	}
	while(Next(index) != P){
		index = Next(index);
	}
	return index;
}

void InsVFirst (List * L, infotype X,int jam,int menit){
	address temp;
	
	if (ListEmpty(*L)){
		Point(*L) = Alokasi(X,jam,menit);
	}else {
		InsertFirst(L,Alokasi(X,jam,menit));
	}
}

void InsVLast (List * L, infotype X,int jam,int menit){
	if(ListEmpty(*L)){
		InsertFirst(L,Alokasi(X,jam,menit));
	} else{
		InsertLast(L,Alokasi(X,jam,menit));	
	}
	
}


void DelVFirst (List * L, infotype * X){
	address temp;
	
	DelFirst(L,&temp);
	*X = Info(temp);
	DeAlokasi(&temp);	
}

void DelVLast (List * L, infotype * X){
	address temp;
	
	DelLast(L,&temp);
	*X = Info(temp);
	DeAlokasi(&temp);
	
}

void InsertFirst (List * L, address P){
	Next(P) = Point(*L);
	Point(*L) = P;
}

void InsertAfter (List * L, address P, address Prec){
//	if(Prec == Nil){
//		return;
//	}
	if(ListEmpty(*L)){
		printf("\nList Kosong!");
	}else if(Prec == Nil){
			printf("\nAddress tidak ditemukan!");
			return;
			} else if(Next(Prec) == Nil ){
					printf("\nAddress Merupakan Address Terakhir!");
				} else {
					Next(P) = Next(Prec);
					Next(Prec) = P;			
				}
}

void InsertLast (List * L, address P){
	address index;
	
	index = Point(*L);
	while(Next(index) != Nil){
		index = Next(index);
	}
	Next(index) = P;
	Next(P) = Nil;
}

void DelFirst (List * L, address * P){
	List temp;
	
	*P = Point(*L);
	if(ListEmpty(*L)){
		printf("\nList Kosong!");
	} else if(Next(Point(*L)) != Nil){
			
			Point(temp) = Point(*L);
			Point(*L) = Next(Point(*L));
			Next(Point(temp)) = Nil;
		}else{
			Point(*L) = Nil;
		}
}

void DelP (List * L, infotype X){
	address temp;
	
	if(ListEmpty(*L)){
		printf("\nList Kosong!");
	}
	DelAfter(L,&temp,SearchPrec(*L,X));
	DeAlokasi(&temp);
}

void DelLast (List * L, address * P){
	address temp1,temp2;
	
	temp1 = Point(*L);
	while(temp1 != Nil){
		temp1 = Next(temp1);
	}
	*P = temp1;
	temp2 = SearchPrec(*L,Info(temp1));
	Next(temp2) = Nil;
}

void DelAfter (List * L, address * Pdel, address Prec){
	if(ListEmpty(*L)){
		printf("\nList Empty!");
		return;
	} else if (Prec == Nil){
		printf("\nAddress Tidak Ada!");
		return;
	}
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	DeAlokasi(Pdel);
}

//void PrintInfo (List L){
////	address index;
////	
////	index = Point(L);
//	if(ListEmpty(L)){
//		printf("\nList Kosong!");
//	}else{
//		while(1){
//			if(Point(L) == Nil){
//				break;
//			}
//			printf("%d\t",Info(Point(L)));
//			Point(L) = Next(Point(L));
//		}
//	}
//}

void DelAll (List * L){
	infotype temp2;
	while(!ListEmpty(*L)){
		DelVFirst(L,&temp2);
	}
}

int CountList(List L){
	int count = 0;
	if(ListEmpty(L)){
		printf("\nList Empty!");
		return count;
	}
	while(Next(Point(L)) != Nil){
		count++;
		Point(L) = Next(Point(L));
	}
	return count + 1;
}


