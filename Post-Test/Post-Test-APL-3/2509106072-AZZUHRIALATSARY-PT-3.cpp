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

        if(i==3){
            cout<<"3 kali gagal login\n";
        }
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

void tampilTiket(Tiket tiket[], int jumlahTiket){
    cout<<"============================= DATA TIKET ==============================\n";
    cout<<left
    <<setw(10)<<"Kode"
    <<setw(15)<<"Tujuan"
    <<setw(15)<<"Tanggal"
    <<setw(10)<<"Harga"
    <<setw(10)<<"Jumlah"
    <<setw(10)<<"Status"
    <<endl;

    cout<<"-----------------------------------------------------------------------\n";

    for(int i=0;i<jumlahTiket;i++){
        cout<<left
        <<setw(10)<<tiket[i].kode
        <<setw(15)<<tiket[i].jadwal.tujuan
        <<setw(15)<<tiket[i].jadwal.tanggal
        <<setw(10)<<tiket[i].harga
        <<setw(10)<<tiket[i].jumlah
        <<setw(10)<<tiket[i].status
        <<endl;
    }
}

void tambahTiket(Tiket tiket[], int &jumlahTiket){
    system("cls");

    cout<<"Kode Tiket : ";
    cin>>tiket[jumlahTiket].kode;
    cout<<"Tujuan : ";
    cin>>tiket[jumlahTiket].jadwal.tujuan;
    cout<<"Tanggal : ";
    cin>>tiket[jumlahTiket].jadwal.tanggal;
    cout<<"Harga : ";
    cin>>tiket[jumlahTiket].harga;
    cout<<"Jumlah tiket : ";
    cin>>tiket[jumlahTiket].jumlah;

    tiket[jumlahTiket].status = "tersedia";

    jumlahTiket++;

    cout<<"Tiket berhasil ditambahkan\n";
    system("pause");
}

void updateTiket(Tiket tiket[], int jumlahTiket){
    system("cls");

    string kode;

    cout<<"Masukkan kode tiket : ";
    cin>>kode;

    for(int i=0;i<jumlahTiket;i++){
        if(tiket[i].kode == kode){
            cout<<"Harga baru : ";
            cin>>tiket[i].harga;

            cout<<"Tanggal baru : ";
            cin>>tiket[i].jadwal.tanggal;

            cout<<"Jumlah tiket : ";
            cin>>tiket[i].jumlah;

            if(tiket[i].jumlah == 0)
                tiket[i].status = "habis";
            else
                tiket[i].status = "tersedia";

            cout<<"Data berhasil diupdate\n";
        }
    }

    system("pause");
}

void hapusTiket(Tiket tiket[], int &jumlahTiket){
    system("cls");

    string kode;

    cout<<"Masukkan kode tiket : ";
    cin>>kode;

    for(int i=0;i<jumlahTiket;i++){
        if(tiket[i].kode == kode){
            for(int j=i;j<jumlahTiket-1;j++){
                tiket[j] = tiket[j+1];
            }

            jumlahTiket--;

            cout<<"Data berhasil dihapus\n";
        }
    }

    system("pause");
}

void beliTiket(Tiket tiket[], int jumlahTiket){
    system("cls");

    string kode;

    tampilTiket(tiket,jumlahTiket);

    cout<<"\nMasukkan kode tiket : ";
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
                cout<<"Tiket sudah habis\n";
            }
        }
    }

    system("pause");
}

void menuAdmin(Tiket tiket[], int &jumlahTiket){
    bool menu=true;

    while(menu){
        system("cls");
        int pilih;

        cout<<"===================== MENU ADMIN ======================\n";
        cout<<"1. Tambah Tiket\n";
        cout<<"2. Lihat Tiket\n";
        cout<<"3. Update Tiket\n";
        cout<<"4. Hapus Tiket\n";
        cout<<"5. Logout\n";
        cout<<"=======================================================\n";
        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1) tambahTiket(tiket,jumlahTiket);
        else if(pilih==2){
            system("cls");
            tampilTiket(tiket,jumlahTiket);
            system("pause");
        }
        else if(pilih==3) updateTiket(tiket,jumlahTiket);
        else if(pilih==4) hapusTiket(tiket,jumlahTiket);
        else if(pilih==5) menu=false;
    }
}

void menuUser(Tiket tiket[], int jumlahTiket){
    bool menu=true;

    while(menu){
        system("cls");
        int pilih;

        cout<<"===================== MENU USER ======================\n";
        cout<<"1. Lihat Tiket\n";
        cout<<"2. Beli Tiket\n";
        cout<<"3. Logout\n";
        cout<<"======================================================\n";
        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1){
            system("cls");
            tampilTiket(tiket,jumlahTiket);
            system("pause");
        }
        else if(pilih==2){
            beliTiket(tiket,jumlahTiket);
        }
        else if(pilih==3){
            menu=false;
        }
    }
}

int main(){
    User user[10];
    Tiket tiket[100];

    int jumlahUser = 2;
    int jumlahTiket = 3;

    user[0]={"admin","admin123","admin"};
    user[1]={"user","user123","user"};

    tiket[0]={"TK01",{"Jakarta","10-06-2026"},250000,18,"tersedia"};
    tiket[1]={"TK02",{"Surabaya","12-06-2026"},300000,22,"tersedia"};
    tiket[2]={"TK03",{"Bandung","15-06-2026"},200000,20,"tersedia"};

    bool program=true;

    while(program){

        system("cls");

        int menuAwal;

        cout<<"================================\n";
        cout<<"     SISTEM TIKET KERETA API\n";
        cout<<"================================\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Keluar\n";
        cout<<"================================\n";
        cout<<"Pilih menu : ";
        cin>>menuAwal;

        if(menuAwal==1){
            registerUser(user,jumlahUser);
        }

        else if(menuAwal==2){

            string roleLogin;

            if(loginUser(user,jumlahUser,roleLogin)){

                if(roleLogin=="admin"){
                    menuAdmin(tiket,jumlahTiket);
                }
                else{
                    menuUser(tiket,jumlahTiket);
                }

            }
            else{
                system("pause");
            }
        }

        else if(menuAwal==3){
            program=false;
            cout<<"Terima kasih\n";
        }
    }
}