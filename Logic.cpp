#include "Logic.h"


// membuat varibel bertipe data int (Integer )

//membuat output list tempat duduk yang masih tersedia dan tidak menggunakan array
string bangku[ROW][COL]{
    {"\b", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
    {"0", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"1", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"2", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"3", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"4", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"5", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"6", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"7", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"8", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"9", "**", "**", "**", "**", "**", "**", "**", "**", "**", "**"},
};
string *film;
List listFilm;

void init(Studio * &arrStudio){
	arrStudio = new Studio[STUDIO];
//	CreateList(&listFilm);
    string strDurasiJam,strDurasiMenit,tempJam,tempMenit;
//    stringstream jam,menit;
	fstream fileFilm("listFilm.txt",fstream::out|fstream::in);
	fstream fileStudio("arrStudio.txt",fstream::out|fstream::in);
	infotype temp;

	if(fileFilm.fail())
	{
		cout << "listFilm.txt tidak ditemukan! Membuat file baru...";
		fileFilm.open("listFilm.txt",fstream::out|fstream::in|fstream::trunc);
		fileFilm.close();

	}else if(fileStudio.fail()){
	    cout << "arrStudio.txt tidak ditemukan! Membuat file baru...";
        fileStudio.open("arrStudio.txt",fstream::out|fstream::in|fstream::trunc);
        fileStudio.close();
	} else{
			if(fileFilm.peek() != EOF) {
				do{
					getline(fileFilm, temp.namaFilm);
					getline(fileFilm, temp.jamFilm);
					getline(fileFilm, temp.menitFilm);
					InsVLast(&listFilm,temp);
				}while(!fileFilm.eof());

			}
			if(fileStudio.peek() != EOF){
                for(int i = 0; i < STUDIO; i++){
                    getline(fileStudio,arrStudio[i].namaFilm);
                    getline(fileStudio,strDurasiJam);
                    getline(fileStudio,strDurasiMenit);
                    getline(fileStudio,tempJam);
                    getline(fileStudio,tempMenit);
                    arrStudio[i].jamFilm = stoi(strDurasiJam);
                    arrStudio[i].menitFilm = stoi(strDurasiMenit);
                    arrStudio[i].tayang.tm_hour = stoi(tempJam);
                    arrStudio[i].tayang.tm_min = stoi(tempMenit);
                }
			}
		}

	for(int i = 0; i < STUDIO; i++){
		for(int y = 0; y < ROW; y++){
			for(int x = 0; x < COL; x++){
				arrStudio[i].kursi[x][y] = bangku[x][y];
			}
		}
		arrStudio[i].sisaBangku = (ROW - 1) * (COL - 1);
	}
	fileFilm.close();
	fileStudio.close();
}

void setJadwal(Studio *arrStudio){
	time_t t;
	int film,jam,menit,jumlahF,pilihStudio,durasiJam,durasiMenit;
	address index = Point(listFilm);
	Jadwal temp;

    jumlahF = CountList(listFilm);
	displayFilm();
	do{
		cout << "Pilih Film(1-" << jumlahF << "):";
 		cin >> film;
		if(film < 1 || film > jumlahF){
			cout << "Film Tidak Ada !";
			getch();
			system("cls");
		} else {
            for(int i = 1; i < film;i++){
                index = Next(index);
                durasiJam = stoi(index->info.jamFilm);
                durasiMenit = stoi(index->info.menitFilm);
		    }
			break;
		}
	}while(true);
    do{
        system("cls");
        cout << "Pilih Studio(1-" << STUDIO <<"):";
        cin >> pilihStudio;
        if(pilihStudio < 1 || pilihStudio >STUDIO){
            cout << "Studio yang dipilih tidak ada!";
            getch();
        }else{
            break;
        }
    }while(1);

	do{
		cout << "Jam tayang (0 - 23) : ";
		cin >> jam;
		if(jam < 0 || jam > 23){
			cout << "Format Jam Salah!";
			getch();
			system("cls");
		} else {
			break;
		}

	}while(true);

	do{
        system("cls");
		cout << "Menit Tayang (0 - 59) :";
		cin >> menit;
		if(menit < 0 || menit > 59){
			cout << "Format Menit Salah!";
			getch();
		} else{
			break;
		}
	}while(true);
	arrStudio[pilihStudio - 1].tayang.tm_hour = jam;
	arrStudio[pilihStudio - 1].tayang.tm_min = menit;
	arrStudio[pilihStudio - 1].jamFilm = durasiJam;
	arrStudio[pilihStudio - 1].menitFilm = durasiMenit;
	arrStudio[pilihStudio - 1].namaFilm = index->info.namaFilm;
}


void inputFilm(){

	infotype tempF;
	int tempJ,tempM;
	ofstream fileFilm("listFilm.txt");
	address temp;

	cout << "Masukkan Judul Film :";
    getline(cin >> ws, tempF.namaFilm);

	do{
		cout << "Masukkan Durasi Jam Film : ";
		cin >> tempF.jamFilm;
		tempJ = stoi(tempF.jamFilm);
		if(tempJ > 0 && tempJ < 24){
			break;
		} else {
			cout << "Format Jam Salah!";
			getch();
			system("cls");
		}

	}while(true);

	do{
		cout << "Masukkan Durasi Menit Film :";
		cin >> tempF.menitFilm;
		tempM = stoi(tempF.menitFilm);
		if(tempM > 0 && tempM < 60){
			break;
		} else{
			cout << "Format Menit Salah!";
			getch();
			system("cls");
		}
	}while(true);

	InsVLast(&listFilm,tempF);
	fileFilm.close();
}
void saveToFileStudio(Studio *arrStudio){
    string strDurasiJam,strDurasiMenit,tempJam,tempMenit;
    stringstream jam,menit;
    ofstream fileStudio("arrStudio.txt");
    for(int i = 0; i < STUDIO; i++){
        strDurasiJam = to_string(arrStudio[i].jamFilm);
        strDurasiMenit = to_string(arrStudio[i].menitFilm);
        jam << arrStudio[i].tayang.tm_hour;
        menit << arrStudio[i].tayang.tm_min;
        tempJam = jam.str();
        tempMenit = menit.str();
        cout << strDurasiJam << endl;
        if(i == STUDIO - 1){
            fileStudio << arrStudio[i].namaFilm << endl << strDurasiJam << endl << strDurasiMenit << endl << tempJam << endl << tempMenit;
        } else {
            fileStudio << arrStudio[i].namaFilm << endl << strDurasiJam << endl << strDurasiMenit << endl << tempJam << endl << tempMenit << endl;
        }
    }
    fileStudio.close();
}
void saveToFile(){
	ofstream fileFilm("listFilm.txt");
	address index = Point(listFilm);
	while(index != NULL)
	{
	    if(Next(index) != NULL){
            fileFilm << index->info.namaFilm << endl << index->info.jamFilm << endl << index->info.menitFilm << endl;
	    } else {
            fileFilm << index->info.namaFilm << endl << index->info.jamFilm << endl << index->info.menitFilm;
	    }
		index = Next(index);
	}
	fileFilm.close();
}

void displayFilm(){
	PrintInfo(listFilm);

}
void displayJadwal(Studio *arrStudio){
    for(int i = 0; i < STUDIO; i++){
        cout << arrStudio[i].namaFilm
    }
}
// Memberikan logic pada function layar()
void layar(Studio studio)
{
    cout << "\n\n";
    for (int i = 0; i < 11; i++)
    {
        //jika i sudah masuk ke bilangan 0 / 1 ( dalanm array ) program akan menampilkan " (======================== Layar Disini ========================) "
        if (i == 0)
        {
            cout << endl;
            cout << "\t    (======================== Layar Disini ========================) " << endl;
            cout << endl;
        }
        //jika i sudah masuk ke bilangan 10 / 9 ( dalanm array ) program akan menampilkan " Sweetbox "
        if (i == 10)
        {
            cout << endl;
            cout << "\t\t\t\t\tVIP\n";
            cout << endl;
        }
        for (int j = 0; j < 11; j++)
        {
            cout << setw(3) << left << studio.kursi[i][j];
        }
        cout << endl;
    }
    cout << endl << "\t\t* = Kosong, $ = Terisi" << endl;
}
// Memberikan logic pada function input()
void input(Studio *arrStudio)
{
	int film,pilih,jumlahF,pilihStudio;
	int iStudio[STUDIO];
	address index = Point(listFilm);
	string tipe,bangku,cek;

	jumlahF = CountList(listFilm);
	do{
		displayFilm();
		cout << "Pilih Film(1-" << jumlahF << "):";
		cin >> film;
		if(film > jumlahF || film < 1){
			cout << "Film Tidak Ada!";
			getch();
			system("cls");
		} else {
		    for(int i = 1; i < film;i++){
                index = Next(index);
		    }
			break;
		}
	}while(true);
	int i = 0;
	int x = 0;
	cout << "Studio yang menampilkan :" << endl;
    for(int i = 0;i < STUDIO;i++){
        if(arrStudio[i].namaFilm == index->info.namaFilm){
            cout << "Studio" << i+1 << endl;
            iStudio[x] = i;
        }
    }
    cout << "Pilih(1-"<<STUDIO<<"):";
    cin >> pilihStudio;
	do{
		layar(arrStudio[pilihStudio]);
		cout << "Pilih Tipe(BIASA/VIP) :";
		cin >> tipe;
		transform(tipe.begin(), tipe.end(),tipe.begin(), ::toupper);//toupper string
		if(tipe == "VIP" || tipe == "BIASA"){
			break;
		} else {
			cout << "Input Tidak Sesuai!";
			getch();
		}
		system("cls");
	}while(true);

	do{
		layar(arrStudio[film - 1]);
		cout << "Pilih Kursi :";
		cin >> bangku;
		cek = check(bangku);
		if(cek != "OK"){
			cout << cek;
			getch();
			system("cls");
		} else {
			arrStudio[film-1].kursi[(int)bangku[1] - 49][(int)bangku[0] - 64] = "$";
			arrStudio[film-1].sisaBangku--;
			arrStudio[film-1].terjual++;
			system("cls");
			break;
		}
	}while(true);

}

string check(string x)
{
    //Logic untuk memberikan panjang input 2 karakter
    if (x.length() == 2)
    {
        // Logic untuk melakukan pengecekan format yang dimasukan benar atau salah
        int sementara = toupper(x[0]);
        int simpan = x[1];
        if ((sementara >= 65 && sementara <= 90) && (simpan >= 48 && simpan <= 57))
        {
            if (toupper(x[0]) >= 'A' && toupper(x[0]) <= 'J')
            {
                //Logic untuk melakukan pengecekan inputan masih dalam tempat duduk yang tersedia
                if (bangku[(int)(x[1]) - 48 + 1][(int)(toupper(x[0])) - 64] == "*")
                {
                    return "OK";
                }
                else
                {
                    return "Tempat duduk sudah dibooking! silahkan pilih yang lain";
                }
            }
            else
            {
                return "Pastikan memilih tempat duduk dibarisan A sampai J";
            }
        }
        else
        {
            return "Masukan format yang benar";
        }
    }
    else
    {
        return "Nama Bangku Hanya Bisa 2 Karakter! contoh : B2 ";
    }
}
//menambahkan pesan "Terima Kasih" Jika function exit dieksekusi dan menyelesaikan program
void beforeExit(Studio *arrStudio)
{
	saveToFile();
	saveToFileStudio(arrStudio);
	DelAll(&listFilm);
    cout << "\n\n Terima kasih!.";
    cout << endl
         << endl;
    delete film;
    exit(1);
}
