#include "Logic.h"

using namespace std;

int main (){
	int menu;
	Studio *arrStudio = NULL;
	init(arrStudio);
	do{

		system("cls");
		cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
		cout << "บ                    Cinema XXIX                   บ" << endl;
		cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
        cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
		cout << "บ                       MENU                       บ" << endl;
		cout << "บ                   ------------                   บ" << endl;
		cout << "บ1. Pesan Tiket                                    บ"  << endl;
		cout << "บ2. List Film                                      บ" << endl;
		cout << "บ3. Input Jadwal                                   บ" <<  endl;
		cout << "บ4. List Jam tayang                                บ"<< endl;
		cout << "บ5. Input Film                                     บ"<< endl;
		cout << "บ6. Keluar                                         บ"<<endl;
		cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl;
		cout << " " << endl;
		cout << "|======================================================================================================================|" << endl;
		cout << " " << endl;
		cout << " Pilih : ";
		cin >> menu;
		system("cls");

		switch(menu)
		{
		    case 1:
		    	input(arrStudio);
			    break;
            case 2:
			   	system("cls");
				displayFilm();
				getch();
				break;
            case 3:
			   	setJadwal(arrStudio);
                break;
            case 4:
                displayJadwal(arrStudio);
                getch();
                break;
            case 5:
				inputFilm();
                break;
			case 6:
			  	beforeExit(arrStudio);
			   	break;
			default:
                cout << "Menu tidak ditemukan";
			    break;
		}
	}while(true);
	return 0;
}


