#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include "validasi.h"
using namespace std;

#define MAX_USER 10
#define MAX_TIKET 100

struct Jadwal{
    string tujuan;
    string tanggal;
};

struct Tiket{
    string kode;
    Jadwal jadwal;
    int harga;
    int jumlah;
    string status;
};

struct User{
    string username;
    string password;
    string role;
};

int linearSearchKode(Tiket *tiket, int n, string kode){
    for(int i=0;i<n;i++){
        if(tiket[i].kode == kode){
            return i;
        }
    }
    return -1;
}

void sortTujuanAsc(Tiket *tiket, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(tiket[j].jadwal.tujuan > tiket[j+1].jadwal.tujuan){
                swap(tiket[j], tiket[j+1]);
            }
        }
    }
}

int binarySearchTujuan(Tiket *tiket, int n, string tujuan){
    int left = 0, right = n - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(tiket[mid].jadwal.tujuan == tujuan){
            return mid;
        }
        else if(tiket[mid].jadwal.tujuan < tujuan){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

bool cekUsername(User user[], int jumlahUser, string username){
    for(int i=0;i<jumlahUser;i++){
        if(user[i].username == username){
            return true;
        }
    }
    return false;
}

bool loginUser(User user[], int jumlahUser, string &roleLogin){
    string username,password;

    for(int i=1;i<=3;i++){
        system("cls");

        cout<<"============= LOGIN ==============\n";
        cout<<"Username : ";
        cin>>username;
        cout<<"Password : ";
        cin>>password;

        for(int j=0;j<jumlahUser;j++){
            if(username == user[j].username && password == user[j].password){
                roleLogin = user[j].role;
                return true;
            }
        }

        cout<<"Login gagal\n";
        system("pause");
    }
    return false;
}

void registerUser(User user[], int &jumlahUser){
    system("cls");

    try{
        if(jumlahUser >= MAX_USER){
            throw length_error("Kapasitas user penuh!");
        }

        string username,password;
        cin.ignore();

        cout<<"=========== REGISTER USER ===========\n";
        cout<<"Username : ";
        getline(cin, username);
        cekKosong(username);

        if(cekUsername(user,jumlahUser,username)){
            throw runtime_error("Username sudah digunakan!");
        }

        cout<<"Password : ";
        getline(cin, password);
        cekKosong(password);

        user[jumlahUser].username = username;
        user[jumlahUser].password = password;
        user[jumlahUser].role = "user";

        jumlahUser++;

        cout<<"Register berhasil\n";
    }
    catch(const exception &e){
        cout<<"Error: "<<e.what()<<endl;
    }

    system("pause");
}

void tampilTiket(Tiket *tiket, int jumlahTiket){
    system("cls");
    cout<<"================ DATA TIKET ================\n";

    for(int i=0;i<jumlahTiket;i++){
        cout<<"Kode    : "<<tiket[i].kode<<endl;
        cout<<"Tujuan  : "<<tiket[i].jadwal.tujuan<<endl;
        cout<<"Tanggal : "<<tiket[i].jadwal.tanggal<<endl;
        cout<<"Harga   : "<<tiket[i].harga<<endl;
        cout<<"Jumlah  : "<<tiket[i].jumlah<<endl;
        cout<<"Status  : "<<tiket[i].status<<endl;
        cout<<"---------------------------------------------\n";
    }
}

void tambahTiket(Tiket *tiket, int *jumlahTiket){
    system("cls");

    try{
        if(*jumlahTiket >= MAX_TIKET){
            throw length_error("Kapasitas tiket penuh!");
        }

        cin.ignore();

        cout<<"Kode Tiket : ";
        getline(cin, tiket[*jumlahTiket].kode);
        cekKosong(tiket[*jumlahTiket].kode);

        cout<<"Tujuan : ";
        getline(cin, tiket[*jumlahTiket].jadwal.tujuan);

        cout<<"Tanggal : ";
        getline(cin, tiket[*jumlahTiket].jadwal.tanggal);

        cout<<"Harga : ";
        cin>>tiket[*jumlahTiket].harga;
        if(cin.fail()) throw invalid_argument("Harga harus angka!");
        cekAngka(tiket[*jumlahTiket].harga);

        cout<<"Jumlah tiket : ";
        cin>>tiket[*jumlahTiket].jumlah;
        cekAngka(tiket[*jumlahTiket].jumlah);

        tiket[*jumlahTiket].status = "tersedia";
        (*jumlahTiket)++;

        cout<<"Tiket berhasil ditambahkan\n";
    }
    catch(const exception &e){
        cout<<"Error: "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }

    system("pause");
}

void updateTiket(Tiket *tiket, int jumlahTiket){
    system("cls");

    try{
        string kode;
        cout<<"Masukkan kode tiket : ";
        cin>>kode;

        int i = linearSearchKode(tiket, jumlahTiket, kode);

        if(i == -1){
            throw out_of_range("Kode tiket tidak ditemukan!");
        }

        cout<<"Harga baru : ";
        cin>>tiket[i].harga;
        cekAngka(tiket[i].harga);

        cout<<"Tanggal baru : ";
        cin>>tiket[i].jadwal.tanggal;

        cout<<"Jumlah tiket : ";
        cin>>tiket[i].jumlah;
        cekAngka(tiket[i].jumlah);

        tiket[i].status = (tiket[i].jumlah == 0) ? "habis" : "tersedia";

        cout<<"Data berhasil diupdate\n";
    }
    catch(const exception &e){
        cout<<"Error: "<<e.what()<<endl;
    }

    system("pause");
}

void hapusTiket(Tiket *tiket, int *jumlahTiket){
    system("cls");

    try{
        string kode;
        cout<<"Masukkan kode tiket : ";
        cin>>kode;

        int i = linearSearchKode(tiket, *jumlahTiket, kode);

        if(i == -1){
            throw out_of_range("Kode tidak ditemukan!");
        }

        for(int j=i;j<*jumlahTiket-1;j++){
            tiket[j] = tiket[j+1];
        }
        (*jumlahTiket)--;

        cout<<"Data berhasil dihapus\n";
    }
    catch(const exception &e){
        cout<<"Error: "<<e.what()<<endl;
    }

    system("pause");
}

void beliTiket(Tiket *tiket, int jumlahTiket){
    system("cls");

    try{
        tampilTiket(tiket,jumlahTiket);

        string kode;
        cout<<"Masukkan kode tiket : ";
        cin>>kode;

        int i = linearSearchKode(tiket, jumlahTiket, kode);

        if(i == -1){
            throw out_of_range("Kode tidak ditemukan!");
        }

        if(tiket[i].jumlah <= 0){
            throw runtime_error("Tiket habis!");
        }

        tiket[i].jumlah--;
        tiket[i].status = (tiket[i].jumlah == 0) ? "habis" : "tersedia";

        cout<<"Tiket berhasil dibeli\n";
    }
    catch(const exception &e){
        cout<<"Error: "<<e.what()<<endl;
    }

    system("pause");
}

void sortTujuanDesc(Tiket *tiket, int n){
    for(int i=0;i<n-1;i++){
        int maxIdx = i;
        for(int j=i+1;j<n;j++){
            if(tiket[j].jadwal.tujuan > tiket[maxIdx].jadwal.tujuan){
                maxIdx = j;
            }
        }
        swap(tiket[i], tiket[maxIdx]);
    }
    cout<<"Sorting tujuan (Z-A) selesai\n";
    system("pause");
}

void sortHargaAsc(Tiket *tiket, int n){
    for(int i=1;i<n;i++){
        Tiket key = tiket[i];
        int j = i-1;

        while(j>=0 && tiket[j].harga > key.harga){
            tiket[j+1] = tiket[j];
            j--;
        }
        tiket[j+1] = key;
    }
    cout<<"Sorting harga selesai\n";
    system("pause");
}

void sortJumlahDesc(Tiket *tiket, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(tiket[j].jumlah < tiket[j+1].jumlah){
                swap(tiket[j], tiket[j+1]);
            }
        }
    }
    cout<<"Sorting jumlah selesai\n";
    system("pause");
}

void menuAdmin(Tiket *tiket, int *jumlahTiket){
    int pilih;
    do{
        system("cls");

        cout<<"========== MENU ADMIN ==========\n";
        cout<<"1. Tambah Tiket\n";
        cout<<"2. Lihat Tiket\n";
        cout<<"3. Update Tiket\n";
        cout<<"4. Hapus Tiket\n";
        cout<<"5. Sort Tujuan (Z-A)\n";
        cout<<"6. Sort Harga (Asc)\n";
        cout<<"7. Sort Jumlah (Desc)\n";
        cout<<"8. Search Kode\n";
        cout<<"9. Search Tujuan\n";
        cout<<"10. Logout\n";
        cout<<"Pilih : ";
        cin>>pilih;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Input harus angka!\n";
            system("pause");
            continue;
        }

        if(pilih==1) tambahTiket(tiket, jumlahTiket);
        else if(pilih==2){ tampilTiket(tiket,*jumlahTiket); system("pause"); }
        else if(pilih==3) updateTiket(tiket,*jumlahTiket);
        else if(pilih==4) hapusTiket(tiket,jumlahTiket);
        else if(pilih==5) sortTujuanDesc(tiket,*jumlahTiket);
        else if(pilih==6) sortHargaAsc(tiket,*jumlahTiket);
        else if(pilih==7) sortJumlahDesc(tiket,*jumlahTiket);

        else if(pilih==8){
            try{
                string kode;
                cout<<"Masukkan kode tiket : ";
                cin>>kode;

                int i = linearSearchKode(tiket,*jumlahTiket,kode);

                if(i == -1) throw out_of_range("Data tidak ditemukan!");

                cout<<"Data ditemukan:\n";
                cout<<"Kode    : "<<tiket[i].kode<<endl;
                cout<<"Tujuan  : "<<tiket[i].jadwal.tujuan<<endl;
                cout<<"Tanggal : "<<tiket[i].jadwal.tanggal<<endl;
                cout<<"Harga   : "<<tiket[i].harga<<endl;
                cout<<"Jumlah  : "<<tiket[i].jumlah<<endl;
                cout<<"Status  : "<<tiket[i].status<<endl;
            }
            catch(const exception &e){
                cout<<"Error: "<<e.what()<<endl;
            }
            system("pause");
        }

        else if(pilih==9){
            try{
                string tujuan;
                cout<<"Masukkan tujuan : ";
                cin>>tujuan;

                sortTujuanAsc(tiket,*jumlahTiket);
                int i = binarySearchTujuan(tiket,*jumlahTiket,tujuan);

                if(i == -1) throw out_of_range("Data tidak ditemukan!");

                cout<<"Data ditemukan:\n";
                cout<<"Kode    : "<<tiket[i].kode<<endl;
                cout<<"Tujuan  : "<<tiket[i].jadwal.tujuan<<endl;
                cout<<"Tanggal : "<<tiket[i].jadwal.tanggal<<endl;
                cout<<"Harga   : "<<tiket[i].harga<<endl;
                cout<<"Jumlah  : "<<tiket[i].jumlah<<endl;
                cout<<"Status  : "<<tiket[i].status<<endl;
            }
            catch(const exception &e){
                cout<<"Error: "<<e.what()<<endl;
            }
            system("pause");
        }

    }while(pilih!=10);
}

void menuUser(Tiket *tiket, int jumlahTiket){
    int pilih;
    do{
        system("cls");

        cout<<"========== MENU USER ==========\n";
        cout<<"1. Lihat Tiket\n";
        cout<<"2. Beli Tiket\n";
        cout<<"3. Logout\n";
        cout<<"Pilih : ";
        cin>>pilih;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Input harus angka!\n";
            system("pause");
            continue;
        }

        if(pilih==1){ tampilTiket(tiket,jumlahTiket); system("pause"); }
        else if(pilih==2) beliTiket(tiket,jumlahTiket);

    }while(pilih!=3);
}

int main(){
    User user[MAX_USER];
    Tiket tiket[MAX_TIKET];

    int jumlahUser = 2;
    int jumlahTiket = 3;

    user[0]={"admin","admin","admin"};
    user[1]={"user","user","user"};

    tiket[0]={"TK01",{"Jakarta","10-06-2026"},200000,10,"tersedia"};
    tiket[1]={"TK02",{"Bandung","12-06-2026"},150000,5,"tersedia"};
    tiket[2]={"TK03",{"Surabaya","15-06-2026"},180000,8,"tersedia"};

    int menu;
    do{
        system("cls");

        cout<<"========== MENU UTAMA ==========\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih : ";
        cin>>menu;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Input harus angka!\n";
            system("pause");
            continue;
        }

        if(menu==1){
            registerUser(user,jumlahUser);
        }
        else if(menu==2){
            string role;

            if(loginUser(user,jumlahUser,role)){
                if(role=="admin"){
                    menuAdmin(tiket,&jumlahTiket);
                }else{
                    menuUser(tiket,jumlahTiket);
                }
            }else{
                system("pause");
            }
        }

    }while(menu!=3);
}