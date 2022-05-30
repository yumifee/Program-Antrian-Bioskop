#include "Logic.h"

string bangku[ROW][COL]
{
    {"-", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
    {"0", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"1", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"2", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"3", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"4", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"5", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"6", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"7", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"8", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"9", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
};

int totTerjual;
List listFilm;

void init(Studio * &arrStudio)
{
    arrStudio = new Studio[STUDIO];
    totTerjual = 0;
//	CreateList(&listFilm);
    string strDurasiJam,strDurasiMenit,tempJam,tempMenit,strIndex;
    int i;
//  stringstream jam,menit;
    fstream fileFilm("listFilm.txt",fstream::out|fstream::in);
    fstream fileStudio("arrStudio.txt",fstream::out|fstream::in);
    infotype temp;

    if(fileFilm.fail())
    {
        cout << "listFilm.txt tidak ditemukan! Membuat file baru...";
        fileFilm.open("listFilm.txt",fstream::out|fstream::in|fstream::trunc);
        fileFilm.close();

    }
    else if(fileStudio.fail())
    {
        cout << "arrStudio.txt tidak ditemukan! Membuat file baru...";
        fileStudio.open("arrStudio.txt",fstream::out|fstream::in|fstream::trunc);
        fileStudio.close();
    }
    else
    {
        if(fileFilm.peek() != EOF)
        {
            do
            {
                getline(fileFilm, temp.namaFilm);
                getline(fileFilm, temp.jamFilm);
                getline(fileFilm, temp.menitFilm);
                InsVLast(&listFilm,temp);
            }
            while(!fileFilm.eof());

        }
        if(fileStudio.peek() != EOF)
        {
            while(!fileStudio.eof())
            {
                getline(fileStudio,strIndex);
                i = stoi(strIndex);
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

    for(int i = 0; i < STUDIO; i++)
    {
        for(int y = 0; y < ROW; y++)
        {
            for(int x = 0; x < COL; x++)
            {
                arrStudio[i].kursi[x][y] = bangku[x][y];
            }
        }
        arrStudio[i].sisaBangku = (ROW - 1) * (COL - 1);
    }
    fileFilm.close();
    fileStudio.close();
}

void setJadwal(Studio *arrStudio)
{
    time_t t;
    int film,jam,menit,jumlahF,pilihStudio,durasiJam,durasiMenit;
    address index = Point(listFilm);
    Jadwal temp;

    jumlahF = CountList(listFilm);
    displayFilm();
    do
    {
        cout << "Pilih Film(1-" << jumlahF << "):";
        cin >> film;
        if(film < 1 || film > jumlahF)
        {
            cout << "Film Tidak Ada !";
            getch();
            system("cls");
        }
        else
        {
            for(int i = 1; i < film; i++)
            {
                index = Next(index);
                durasiJam = stoi(index->info.jamFilm);
                durasiMenit = stoi(index->info.menitFilm);
            }
            break;
        }
    }
    while(true);
    do
    {
        system("cls");
        cout << "Pilih Studio(1-" << STUDIO <<"):";
        cin >> pilihStudio;
        if(pilihStudio < 1 || pilihStudio >STUDIO)
        {
            cout << "Studio yang dipilih tidak ada!";
            getch();
        }
        else
        {
            break;
        }
    }
    while(1);

    do
    {
        cout << "Jam tayang (0 - 23) : ";
        cin >> jam;
        if(jam < 0 || jam > 23)
        {
            cout << "Format Jam Salah!";
            getch();
            system("cls");
        }
        else
        {
            break;
        }

    }
    while(true);

    do
    {
        system("cls");
        cout << "Menit Tayang (0 - 59) :";
        cin >> menit;
        if(menit < 0 || menit > 59)
        {
            cout << "Format Menit Salah!";
            getch();
        }
        else
        {
            break;
        }
    }
    while(true);
    arrStudio[pilihStudio - 1].tayang.tm_hour = jam;
    arrStudio[pilihStudio - 1].tayang.tm_min = menit;
    arrStudio[pilihStudio - 1].jamFilm = durasiJam;
    arrStudio[pilihStudio - 1].menitFilm = durasiMenit;
    arrStudio[pilihStudio - 1].namaFilm = index->info.namaFilm;
}

void inputFilm()
{

    infotype tempF;     //struct Film (detail ada pada list..h)
    int tempJ,tempM;    //temporarty jam dan menit bertipe integer
    address temp;       //temporary address sebelum dimasukan ke queue

    cout << "Masukkan Judul Film :";
    getline(cin >> ws, tempF.namaFilm); //getline dan ws = agar cin dapat assign spasi ke variabel

    do      //looping untuk var jam jika penginputan 0-24
    {
        cout << "Masukkan Durasi Jam Film : ";
        cin >> tempF.jamFilm;
        tempJ = stoi(tempF.jamFilm);        // subvar jamFilm diubah ke dalam integer dan di assign ke variabel tempJ menggunakan stoi
        if(tempJ > 0 && tempJ < 24)
        {
            break;
        }
        else            //jika penginputan tidak sesuai dengan 0-24
        {
            cout << "Format Jam Salah!";
            getch();
            system("cls");
        }

    }
    while(true);

    do      //looping untuk penginputan var menit
    {
        cout << "Masukkan Durasi Menit Film :";
        cin >> tempF.menitFilm;
        tempM = stoi(tempF.menitFilm);      //subvar menitFilm diubah ke dalam integer dan di assign ke variabel tempM menggunakan stoi
        if(tempM > 0 && tempM < 60)
        {
            break;
        }
        else
        {
            cout << "Format Menit Salah!";
            getch();
            system("cls");
        }
    }
    while(true);

    InsVLast(&listFilm,tempF);      //memasukan hasil inputan ke dalam linkedlist
}

void saveToFileStudio(Studio *arrStudio)
{
    string strDurasiJam,strDurasiMenit,tempJam,tempMenit;
    stringstream jam,menit;
    int i;
    ofstream fileStudio("arrStudio.txt");

    i = 0;
    while(i < STUDIO)
    {
        if(!arrStudio[i].namaFilm.empty())
        {
            strDurasiJam = to_string(arrStudio[i].jamFilm);
            strDurasiMenit = to_string(arrStudio[i].menitFilm);
            tempJam = to_string(arrStudio[i].tayang.tm_hour);
            tempMenit = to_string(arrStudio[i].tayang.tm_min);
            cout << strDurasiJam << endl;
            if(i == STUDIO - 1)
            {
                fileStudio << i << endl << arrStudio[i].namaFilm << endl << strDurasiJam << endl << strDurasiMenit << endl << tempJam << endl << tempMenit;
            }
            else
            {
                fileStudio << i << endl << arrStudio[i].namaFilm << endl << strDurasiJam << endl << strDurasiMenit << endl << tempJam << endl << tempMenit << endl;
            }
        }
        i++;
    }
    fileStudio.close();
}
void saveToFile()
{
    ofstream fileFilm("listFilm.txt");
    address index = Point(listFilm);
    while(index != NULL)
    {
        if(Next(index) != NULL)
        {
            fileFilm << index->info.namaFilm << endl << index->info.jamFilm << endl << index->info.menitFilm << endl;
        }
        else
        {
            fileFilm << index->info.namaFilm << endl << index->info.jamFilm << endl << index->info.menitFilm;
        }
        index = Next(index);
    }
    fileFilm.close();
}

void displayFilm()
{
    PrintInfo(listFilm);
}
void displayJadwal(Studio *arrStudio)
{
    cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
    cout << "                     Jadwal Film                    " << endl;
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
    cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
    for(int i = 0; i < STUDIO; i++)
    {

        cout << setw(6) << right << "   Studio" << i+1 <<":" << endl << "\t " << setw(30) << left << arrStudio[i].namaFilm << arrStudio[i].tayang.tm_hour << ":" << arrStudio[i].tayang.tm_min <<setw(10)<< right << endl;
    }
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
}

void layar(Studio studio)
{
    cout << "\n\n";
    for (int i = 0; i < 11; i++)
    {
        //jika i sudah masuk ke bilangan 0 / 1 ( dalanm array ) program akan menampilkan " (======================== Layar Disini ========================) "
        if (i == 0)
        {
            cout << endl;
            cout << "\t\t (======================== Layar Disini ========================) " << endl;
            cout << endl;
        }

        if (i == 10)
        {
            cout << endl;
            cout << "\t\t\t\t\tVIP\n";
            cout << endl;
        }
        for (int j = 0; j < 11; j++)
        {
            cout << "\t" << studio.kursi[i][j];
        }
        cout << endl;
    }
    cout << endl << "\t\t\t\t\t* = Kosong, $ = Terisi" << endl;
}

void input(Studio *arrStudio)
{
    int film,pilih,jumlahF,pilihStudio,jml_tiket,total,kursiPesan;
    int iStudio[STUDIO];
    address index = Point(listFilm);
    string tipe,bangku,cek,pemesan;

    jumlahF = CountList(listFilm);
    do
    {
        displayJadwal(arrStudio);
        cout << "Pilih (1-" << STUDIO << "):";
        cin >> pilihStudio;
        if(pilihStudio > STUDIO || pilihStudio < 1)
        {
            cout << "Studio Tidak Ada!";
            getch();
            system("cls");
        }
        else if(arrStudio[pilihStudio - 1].namaFilm.empty())
        {
            cout << "Studio Belum Menampilkan Film!";
            getch();
            system("cls");
        }
        else
        {
            break;
        }
    }
    while(true);

    do
    {
        cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
        cout << "บ                    Harga Tiket                   บ" << endl;
        cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
        cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
        cout << "บ\t\t  BIASA : "<< hargaBiasa << "\t\t\t   บ" << endl;
        cout << "บ\t\t  VIP   : " << hargaVIP << " \t\t   บ" << endl;
        cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
        cout << "Pilih Tipe(BIASA/VIP) :";
        cin >> tipe;
        transform(tipe.begin(), tipe.end(),tipe.begin(), ::toupper);//toupper string
        if(tipe == "VIP" || tipe == "BIASA")
        {
            break;
        }
        else
        {
            cout << "Input Tidak Sesuai!";
            getch();
        }
        system("cls");
    }
    while(true);
    system("cls");
    do
    {
        layar(arrStudio[pilihStudio - 1]);
        if(tipe == "BIASA")
        {
            cout << "ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ" << endl;
            cout << " " << endl;
            cout << "Jumlah tiket : ";
            cin>> jml_tiket;
            total += hargaBiasa * jml_tiket;
            cout << jml_tiket<<" "<< tipe;
            cout<< " Rp. " << hargaBiasa * jml_tiket <<endl;
            getch();
            break;
        }
        else
        {
            cout << "Jumlah Tiket : ";
            cin>> jml_tiket;
            total += hargaVIP * jml_tiket;
            cout << jml_tiket<<" "<< tipe;
            cout<< " Rp. " << hargaVIP * jml_tiket <<endl;
            getch();
            break;
        }

    }
    while(true);
    kursiPesan = 0;
    do
    {
        system("cls");
        layar(arrStudio[pilihStudio - 1]);
        cout << "Pilih Kursi :";
        cin >> bangku;
        if(tipe == "BIASA")
        {
            cek = check(bangku,arrStudio[pilihStudio - 1],tipe);
            if(cek != "OK")
            {
                cout << cek;
                getch();
                system("cls");
            }
            else
            {

                arrStudio[pilihStudio-1].kursi[(int)bangku[1] - 47][(int)bangku[0] - 64] = '$';
                arrStudio[pilihStudio-1].sisaBangku--;
                arrStudio[pilihStudio-1].terjual++;
                if (kursiPesan == jml_tiket-1)
                {
                    getch();
                    break;
                }
            }
        }
        else if(tipe == "VIP")
        {
            cek = check(bangku,arrStudio[pilihStudio - 1],tipe);
            if(cek != "OK")
            {
                cout << cek;
                getch();
                system("cls");
            }
            else
            {

                arrStudio[pilihStudio-1].kursi[(int)bangku[1] - 47][(int)bangku[0] - 64] = '$';
                arrStudio[pilihStudio-1].sisaBangku--;
                arrStudio[pilihStudio-1].terjual++;
                if (kursiPesan == jml_tiket-1)
                {
                    getch();
                    break;
                }
            }
        }
        kursiPesan++;
    }
    while(true);
    cout << "Total Harga Tiket yang Harus Dibayar : Rp. " << total <<endl;

}


string check(string x,Studio arrStudio,string tipe)
{
    //Logic untuk memberikan panjang input 2 karakter
    if (x.length() == 2)
    {
        // Logic untuk melakukan pengecekan format yang dimasukan benar atau salah
        int sementara = toupper(x[0]);
        int simpan = x[1];
        if(tipe == "BIASA")
        {
            if(simpan == 57)
            {
                return "Khusus VIP";
            }

            if ((sementara >= 65 && sementara <= 90) && (simpan >= 48 && simpan <= 57))
            {
                if (toupper(x[0]) >= 'A' && toupper(x[0]) <= 'J')
                {
                    //Logic untuk melakukan pengecekan inputan masih dalam tempat duduk yang tersedia
                    if (arrStudio.kursi[(int)(x[1]) - 47][(int)(toupper(x[0])) - 64] == "*")
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
        else if (tipe == "VIP")
        {
            if(simpan != 57)
            {
                return "Tempat duduk Biasa";
            }
            if ((sementara >= 65 && sementara <= 90) && (simpan >= 48 && simpan <= 57))
            {
                if (toupper(x[0]) >= 'A' && toupper(x[0]) <= 'J')
                {
                    //Logic untuk melakukan pengecekan inputan masih dalam tempat duduk yang tersedia
                    if (arrStudio.kursi[(int)(x[1]) - 47][(int)(toupper(x[0])) - 64] == "*")
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
}

void beforeExit(Studio *arrStudio)
{
    saveToFile();
    saveToFileStudio(arrStudio);
    DelAll(&listFilm);
    cout << "\n\n Terima kasih!.";
    cout << endl << endl;
    exit(1);
}





