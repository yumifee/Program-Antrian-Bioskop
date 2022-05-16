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
Film *arrFilm;

void init(Studio * &arrStudio){
	arrStudio = new Studio[STUDIO];
	arrFilm = new Film[TFILM];
	CreateList(&listFilm);
	
//	inputFilm();
	for(int i = 0; i < STUDIO; i++){
		for(int y = 0; y < ROW; y++){
			for(int x = 0; x < COL; x++){
				arrStudio[i].kursi[x][y] = bangku[x][y];
			}
		}
		arrStudio[i].sisaBangku = (ROW - 1) * (COL - 1);
//		arrStudio[i].namaFilm = film[i];
	}
	
}

void inputFilm(){
//	film = new string[TFILM];
//	film[0] = "Doctor Strange : Multiverse Of Madness";
//	film[1] = "KKN";
//	film[2] = "From Deep Within";

	int jamFilm;
	int menitFilm;
	string namaFilm;
	address temp;
	
	do{
		cout << "Masukkan Judul Film :";
 		cin >> namaFilm;
			system("cls");
			break;
		
	}while(true);
	
	do{
		cout << "Masukkan Durasi Jam Film : ";
		cin >> jamFilm;
		if(jamFilm < 0 || jamFilm > 23){
			cout << "Format Jam Salah!";
			getch();
			system("cls");
		} else {
			break;
		}
	
	}while(true);
	
	do{
		cout << "Masukkan Durasi Menit Film :";
		cin >> menitFilm;
		if(menitFilm < 0 || menitFilm > 59){
			cout << "Format Menit Salah!";
			getch();
			system("cls");
		} else{
			break;
		}
	}while(true);
	InsVLast(&listFilm,namaFilm,jamFilm,menitFilm);
	
}
	
    
//void listFilm(){
//	cout << endl;
//	cout << endl;
//	cout << "ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» " << endl;
//	cout << "º                                                  SEDANG TAYANG                                                      º" << endl;
//	cout << "º                                    Berikut list film yang tayang pada hari ini                                      º" << endl;
//	cout << "ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ " << endl;
//	cout << endl;
//	cout << "ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» " << endl;
//	cout << "º No         Judul Film                                                 Studio                                        º" << endl;
//	cout << "º                                                                                                                     º" <<endl;
//	for(int i = 0; i < TFILM; i++){
//		cout << "º " << setw(11) << left << i+1 << setw(59) << left << film[i] << setw(46)<<left<< i << "º" << endl;
//	}
//	cout << "ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ " << endl;
//	cout << endl;
//}

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
	int film,pilih;
	string tipe,bangku,cek;
	do{
//		listFilm();
		cout << "Pilih Film :";
		cin >> film;
		if(film > TFILM || film < 1){
			cout << "Film Tidak Ada!";
			getch();
			system("cls");
		} else {
			break;
		}
	}while(true);
	
	do{
		layar(arrStudio[film - 1]);
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
			arrStudio[film-1].kursi[(int)bangku[1] - 48 + 1][(int)bangku[0] - 64] = "$";
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
void exit()
{
    cout << "\n\n Terima kasih!.";
    cout << endl
         << endl;
    exit(1);
}
