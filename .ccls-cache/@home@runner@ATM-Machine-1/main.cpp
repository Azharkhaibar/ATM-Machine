#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class ATM {
private:
    string pin;
    double saldo;
    const double biayaAdmin = 5000.0;

public:
    ATM(string pin, double saldo) : pin(pin), saldo(saldo) {}

    void masukkanPIN() {
        system("cls");
        cout << "\tplease wait " << endl;
        cout <<"---------------------------------------" << endl;
        cout << "\tmohon tunggu.. " << endl;
        sleep(2);
        system("cls");
        cout << "\t\t || AZHARS ATM MACHINE ||" << endl;
        cout << "=============˜=========================================" << endl;
        cout << "=======================================================" << endl;
        cout << "mohon untuk memasukan pincode sesuai dengan pincode kartu!" << endl;
        cout << endl;
        cout << "masukan pincode \t: >";
        cin >> pin;

        if (pin != "0000") {
            cout << "pincode anda salah!, ulangi lagi." << endl;
            sleep(1);
            masukkanPIN();
        }
    }

    void pilihBahasa() {
        string bahasa;
        cout << "\t\t || AZHARS ATM MACHINE ||" << endl;
        cout << "=============˜=========================================" << endl;
        cout << "============== PILIH BAHASA ===========================" << endl;
        cout << "========== (ENTER YOUR LANGUAGE) ======================" << endl;
        cout << "=======================================================" << endl;

        cout << "(indo) :";
        cin >> bahasa;

        if (bahasa == "english") {
            cout << "language : english " << endl;
        } else if (bahasa == "indo") {
            cout << "bahasa : indonesia" << endl;
        } else {
            cout << "Anda tidak memiliki Opsi pilihan " << endl;
        }
    }

    void checkSaldo() {
        system("cls");
        cout << "\tplease wait " << endl;
        cout <<"---------------------------------------" << endl;
        cout << "\tmohon tunggu.. " << endl;
        sleep(2);
        system("cls");
        system("cls");
        cout << "==================== CHECK SALDO ==================================" << endl;
        cout << endl;
        cout << "Saldo anda : Rp " << fixed << setprecision(2) << saldo << endl;
    }

    void setorUang() {
        double setoran;
        system("cls");
        cout << "\tplease wait " << endl;
        cout <<"---------------------------------------" << endl;
        cout << "\tmohon tunggu.. " << endl;
        sleep(2);
        system("cls");
        cout << " masukan jumlah uang yang akan disetor : Rp ";
        cin >> setoran;
        saldo += setoran;
        cout << "setoran berhasil, saldo anda sekarang: Rp " << fixed << setprecision(2) << saldo << endl;
    }

    void transferAntarBank() {
        double jumlahTrf;
         system("cls");
        cout << "\tplease wait " << endl;
        cout <<"---------------------------------------" << endl;
        cout << "\tmohon tunggu.. " << endl;
        sleep(2);
        system("cls");
        cout << "masukan jumlah Transfer: Rp ";
        cin >> jumlahTrf;
        cin.clear();
        if (jumlahTrf > saldo) {
            cout << "Saldo anda tidak mencukupi" << endl;
        } else {
            saldo -= jumlahTrf;
            saldo -= biayaAdmin;
            cout << "Transfer berhasil, saldo anda sekarang: Rp " << fixed << setprecision(2) << saldo << endl;
        }
    }

    void tarikTunai() {
        int pilTunai;
        system("cls");
        cout << "\tplease wait " << endl;
        cout <<"---------------------------------------" << endl;
        cout << "\tmohon tunggu.. " << endl;
        sleep(2);
        system("cls");
        cout << "============== ( PECAHAN RP 50.000 ) ==================="<< endl;
        cout << "opsi penarikan :\n==================================================== \n[99]. jumlah lain \n=========================================== \n[1]. Rp 50,000 \n[2]. Rp 100,000 \n[3]. Rp 150,000 \n[4]. Rp 200,000 \n[5]. Rp 300,000 \n[0] Kembali menu" << endl;
        cout << "pilih kode \t:  " << endl;
        cin >> pilTunai;
        double jumlahTarik;
        switch (pilTunai) {
            case 1:
                jumlahTarik = 50000;
                break;
            case 2:
                jumlahTarik = 100000;
                break;
            case 3:
                jumlahTarik = 150000;
                break;
            case 4:
                jumlahTarik = 200000;
                break;
            case 5:
                jumlahTarik = 300000;
                break;
            case 99:
                cout << "masukan jumlah penarikan \t: Rp ";
                cin >> jumlahTarik;
                if (jumlahTarik > saldo) {
                    cout << "saldo lu ga Cukup!" << endl;
                } else {
                    saldo -= jumlahTarik;
                    cout << "Penarikan Berhasil! " << endl;
                    cout << " saldo anda sisa : Rp " << fixed << setprecision(2) << saldo << endl;
                }
                if (saldo == 0.0) {
                    cout << " =================================================" << endl;
                    cout << "saldo anda habis!" << endl;
                }
                break;
            case 0:
                return;
            default:
                cout << "pilihan tidak Valid, coba lagi " << endl;
                tarikTunai();
                return;
        }
        saldo -= jumlahTarik;
        cout << "Penarikan berhasil, saldo anda sekarang: Rp " << fixed << setprecision(2) << saldo << endl;
    }

    void biayaDonasi() {
        double Donasi;
        cout << "masukan jumlah Donasi Palestine : Rp ";
        cin >> Donasi;
        saldo -= Donasi;
        cout << "Donasi Berhasil!, Saldo anda sekarang : Rp " << fixed << setprecision(2) << saldo << endl;
    }
    
    void menuLain(){
    	int pilMenuLain;
        
        system("cls");
        cout << "\t pilih tranksaksi yang anda inginkan " << endl;
        cout << "------------------------------------------------" << endl;
        
        cout <<"[1] Transfer " << endl;
        cout <<"[2] ubah pincode " << endl;
        cout <<"[0] menu sebelumnya " << endl;
        
        cout <<" pilih kode \t: "; cin>>pilMenuLain;
        cin.clear();
        
        switch(pilMenuLain) {
        	case 1:
        		transferAntarBank();
        		
                     break;
        	case 2: 
        	       masukkanPIN();
        	      
        	      
        
        	case 3:
        		void menuAtm();
        	
        	
        	default: 
        	       cout << "anda tidak memilih opsi " << endl;
        	       sleep(1);
        	       menuLain();
	 }
    }
};

void menuAtm() {
    ATM azhar("0000", 0);

    azhar.pilihBahasa();
    azhar.masukkanPIN();

    int pilMenu;
    do {
        sleep(2);
        system("cls");
        cout << endl;
        cout << "\t\t || AZHARS ATM MACHINE ||" << endl;
        cout << "=============˜=========================================" << endl;
        cout << "=======================================================" << endl;
        cout << "[1] Informasi Saldo       ";
        cout << "[2] Setor Uang\n";
        cout << "[3] Transfer Antar Bank   ";
        cout << "[4] Tarik Tunai\n";
        cout << "[5] Donasi Palestine      ";
        cout << "[6] Menu Lainnya \n";
        cout << "[0] Keluar \n";
        cout << endl;
        cout << "Pilih menu: ";
        cin >> pilMenu;

        switch (pilMenu) {
            case 1:
                azhar.checkSaldo();
                break;
            case 2:
                azhar.setorUang();
                break;
            case 3:
                azhar.transferAntarBank();
                break;
            case 4:
                azhar.tarikTunai();
                break;
            case 5:
                azhar.biayaDonasi();
                break;
            case 6:
            	  azhar.menuLain();
            case 0:
                exit(0);
            default:
                cout << "Pilihan tidak Valid. silahkan pilih kembali. " << endl;
        }
    } while (pilMenu != 0);
}

int main() {
    system("color 1E");
    menuAtm();
    return 0;
}
