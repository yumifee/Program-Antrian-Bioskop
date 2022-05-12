#ifndef Logic_H
#define Logic_H
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>

using namespace std;

#define ROW 11
#define COL 11
#define STUDIO 3
#define TFILM 3

typedef struct {
	int sisaBangku;
	int terjual;
	string namaFilm;
	string kursi[ROW][COL];
}Studio;

void init(Studio * &arrStudio);
void inputFilm();
void listFilm();
void layar(Studio studio);
void input(Studio *arrStudio);
void exit();
string check(string x);

#endif
