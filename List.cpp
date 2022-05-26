/*
Nama : Panji Judha Fadhilla & Yumi Febriana
NIM : 211511053 & 211511063
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
    Point(*L) = Nil;
}

address Alokasi (infotype X){
	address P = new ElmtList;

	if(P == Nil){
		system("cls");
		cout << "Error : Alokasi Gagal!";
		return P;
	}
	Info(P) = X;
//	P->info.namaFilm = X.namaFilm;
//	P->info.jamFilm = X.jamFilm;
//	P->info.menitFilm = X.menitFilm;

	Next(P) = Nil;
	return P;
}

void DeAlokasi (address *P){
	Next(*P) = Nil;
	delete P;
}

address Search (List L, infotype X){
	address temp;

	temp = Point(L);
	while(1){
		if(temp->info.namaFilm == X.namaFilm){
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
	if(P->info.namaFilm == X.namaFilm){
		return Nil;
	}
	do {
		P = Next(P);
		if(P->info.namaFilm == X.namaFilm){
		break;
		}
	}while(Next(P) != Nil);
	if(P->info.namaFilm == X.namaFilm){
		return Nil;
	}
	while(Next(index) != P){
		index = Next(index);
	}
	return index;
}

void InsVFirst (List * L, infotype X){
	address temp;

	if (ListEmpty(*L)){
		Point(*L) = Alokasi(X);
	}else {
		InsertFirst(L,Alokasi(X));
	}
}

void InsVLast (List * L, infotype X){
	address temp = Alokasi(X);
	if(ListEmpty(*L)){
		InsertFirst(&(*L),temp);
	} else{
		InsertLast(&(*L),temp);
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

void PrintInfo (List L){
	address index;

	index = Point(L);       //index diisi dengan yg ditunjuk oleh point L
	if(ListEmpty(L)){
		cout << "Film Kosong!";
	}else{
			cout <<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
			cout <<"บ                        Judul Film                       บ" << endl;
			cout <<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
			cout <<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
		while(1){
			if(index == Nil){
				break;
			}
			cout <<"บ " << setw(30) << left << index->info.namaFilm << setw(4) << right << "-> "<< setw(3) << left << index->info.jamFilm  << " jam " << setw(3) << left << index->info.menitFilm << setw(11) << left << " menit" << "บ" << endl;
			index = Next(index);
		}cout <<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
	}
}

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


