#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

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

    string username,password;

    cout<<"=========== REGISTER USER ===========\n";
    cout<<"Username : ";
    cin>>username;

    if(cekUsername(user,jumlahUser,username)){
        cout<<"Username sudah digunakan!\n";
        system("pause");
        return;
    }

    cout<<"Password : ";
    cin>>password;

    user[jumlahUser].username = username;
    user[jumlahUser].password = password;
    user[jumlahUser].role = "user";

    jumlahUser++;

    cout<<"Register berhasil\n";
    system("pause");
}

void tampilTiket(Tiket *tiket, int jumlahTiket){
    system("cls");
    cout<<"================ DATA TIKET ================\n";

    for(int i=0;i<jumlahTiket;i++){
        Tiket *t = &tiket[i];

        cout<<"Kode    : "<<t->kode<<endl;
        cout<<"Tujuan  : "<<t->jadwal.tujuan<<endl;
        cout<<"Tanggal : "<<t->jadwal.tanggal<<endl;
        cout<<"Harga   : "<<t->harga<<endl;
        cout<<"Jumlah  : "<<t->jumlah<<endl;
        cout<<"Status  : "<<t->status<<endl;
        cout<<"---------------------------------------------\n";
    }
}

void tambahTiket(Tiket *tiket, int *jumlahTiket){
    system("cls");

    cout<<"Kode Tiket : ";
    cin>>tiket[*jumlahTiket].kode;
    cout<<"Tujuan : ";
    cin>>tiket[*jumlahTiket].jadwal.tujuan;
    cout<<"Tanggal : ";
    cin>>tiket[*jumlahTiket].jadwal.tanggal;
    cout<<"Harga : ";
    cin>>tiket[*jumlahTiket].harga;
    cout<<"Jumlah tiket : ";
    cin>>tiket[*jumlahTiket].jumlah;

    tiket[*jumlahTiket].status = "tersedia";

    (*jumlahTiket)++;

    cout<<"Tiket berhasil ditambahkan\n";
    system("pause");
}

void updateTiket(Tiket *tiket, int jumlahTiket){
    system("cls");

    string kode;
    cout<<"Masukkan kode tiket yang ingin diupdate : ";
    cin>>kode;

    for(int i=0;i<jumlahTiket;i++){
        if(tiket[i].kode == kode){

            Tiket *t = &tiket[i];

            cout<<"Harga baru : ";
            cin>>t->harga;

            cout<<"Tanggal baru : ";
            cin>>t->jadwal.tanggal;

            cout<<"Jumlah tiket : ";
            cin>>t->jumlah;

            if(t->jumlah == 0)
                t->status = "habis";
            else
                t->status = "tersedia";

            cout<<"Data berhasil diupdate\n";
        }
    }

    system("pause");
}

void hapusTiket(Tiket *tiket, int *jumlahTiket){
    system("cls");

    string kode;
    cout<<"Masukkan kode tiket : ";
    cin>>kode;

    for(int i=0;i<*jumlahTiket;i++){
        if(tiket[i].kode == kode){
            for(int j=i;j<*jumlahTiket-1;j++){
                tiket[j] = tiket[j+1];
            }
            (*jumlahTiket)--;

            cout<<"Data berhasil dihapus\n";
        }
    }
    system("pause");
}

void beliTiket(Tiket *tiket, int jumlahTiket){
    system("cls");

    string kode;

    tampilTiket(tiket,jumlahTiket);

    cout<<"Masukkan kode tiket : ";
    cin>>kode;

    for(int i=0;i<jumlahTiket;i++){
        if(tiket[i].kode == kode){

            if(tiket[i].jumlah > 0){
                tiket[i].jumlah--;

                if(tiket[i].jumlah == 0)
                    tiket[i].status = "habis";

                cout<<"Tiket berhasil dibeli\n";
            }
            else{
                cout<<"Tiket habis\n";
            }
        }
    }

    system("pause");
}

void menuAdmin(Tiket *tiket, int *jumlahTiket){
    system("cls");

    int pilih;
    do{
        system("cls");

        cout<<"========== MENU ADMIN ==========\n";
        cout<<"1. Tambah Tiket\n";
        cout<<"2. Lihat Tiket\n";
        cout<<"3. Update Tiket\n";
        cout<<"4. Hapus Tiket\n";
        cout<<"5. Logout\n";
        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1) tambahTiket(tiket, jumlahTiket);
        else if(pilih==2){
            system("cls");
            tampilTiket(tiket, *jumlahTiket);
            system("pause");
        }
        else if(pilih==3) updateTiket(tiket, *jumlahTiket);
        else if(pilih==4) hapusTiket(tiket, jumlahTiket);

    }while(pilih!=5);
}

void menuUser(Tiket *tiket, int jumlahTiket){
    system("cls");
    
    int pilih;
    do{
        system("cls");

        cout<<"========== MENU USER ==========\n";
        cout<<"1. Lihat Tiket\n";
        cout<<"2. Beli Tiket\n";
        cout<<"3. Logout\n";
        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1){
            tampilTiket(tiket,jumlahTiket);
            system("pause");
        }
        else if(pilih==2){
            beliTiket(tiket,jumlahTiket);
        }

    }while(pilih!=3);
}

int main(){
    User user[10];
    Tiket tiket[100];

    int jumlahUser = 2;
    int jumlahTiket = 2;

    user[0]={"admin","admin","admin"};
    user[1]={"user","user","user"};

    tiket[0]={"TK01",{"Jakarta","10-06-2026"},200000,10,"tersedia"};
    tiket[1]={"TK02",{"Bandung","12-06-2026"},150000,5,"tersedia"};

    int menu;
    do{
        system("cls");

        cout<<"========== MENU UTAMA ==========\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih : ";
        cin>>menu;

        if(menu==1){
            registerUser(user,jumlahUser);
        }
        else if(menu==2){
            string role;

            if(loginUser(user,jumlahUser,role)){
                if(role=="admin"){
                    menuAdmin(tiket, &jumlahTiket);
                }else{
                    menuUser(tiket, jumlahTiket);
                }
            }else{
                system("pause");
            }
        }

    }while(menu!=3);
}