#ifndef Logic_H
#define Logic_H
#include <iostream>
#include "List.h"
#include <iomanip>
#include <string>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

#define ROW 11
#define COL 11
#define STUDIO 3
#define TFILM 3
typedef struct tm* Jadwal;
typedef struct {
	int sisaBangku;
	int terjual;
	int jamFilm,menitFilm;
	Jadwal tayang;
	string namaFilm;
	string kursi[ROW][COL];
}Studio;


void setJadwal(Studio *arrStudio);
void init(Studio * &arrStudio);
void inputFilm();
void displayFilm();
void layar(Studio studio);
void input(Studio *arrStudio);
void beforeExit();
string check(string x);
bool is_empty(std::ifstream& pFile);
void saveToFile();
#endif
