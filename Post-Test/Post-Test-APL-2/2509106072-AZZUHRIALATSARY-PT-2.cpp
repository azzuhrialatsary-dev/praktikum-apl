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

int main(){
    User user[10];
    Tiket tiket[100];

    int jumlahUser = 2;
    int jumlahTiket = 3;

    user[0].username = "admin";
    user[0].password = "admin123";
    user[0].role = "admin";

    user[1].username = "user";
    user[1].password = "user123";
    user[1].role = "user";

    tiket[0].kode = "TK01";
    tiket[0].jadwal.tujuan = "Jakarta";
    tiket[0].jadwal.tanggal = "10-06-2026";
    tiket[0].harga = 250000;
    tiket[0].jumlah = 18;
    tiket[0].status = "tersedia";

    tiket[1].kode = "TK02";
    tiket[1].jadwal.tujuan = "Surabaya";
    tiket[1].jadwal.tanggal = "12-06-2026";
    tiket[1].harga = 300000;
    tiket[1].jumlah = 22;
    tiket[1].status = "tersedia";

    tiket[2].kode = "TK03";
    tiket[2].jadwal.tujuan = "Bandung";
    tiket[2].jadwal.tanggal = "15-06-2026";
    tiket[2].harga = 200000;
    tiket[2].jumlah = 20;
    tiket[2].status = "tersedia";

    bool program = true;

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

        if(menuAwal == 1){
            system("cls");

            cout<<"=========== REGISTER USER ===========\n";
            cout<<"Username : ";
            cin>>user[jumlahUser].username;
            cout<<"Password : ";
            cin>>user[jumlahUser].password;
            user[jumlahUser].role = "user";

            jumlahUser++;
            cout<<"\nRegister berhasil\n";
            system("pause");
        }

        else if(menuAwal == 2){
            string username,password;
            bool login = false;
            string roleLogin;

            for(int i=1;i<=3;i++){
                system("cls");

                cout<<"============= LOGIN ==============\n";
                cout<<"Username : ";
                cin>>username;
                cout<<"Password : ";
                cin>>password;

                for(int j=0;j<jumlahUser;j++){
                    if(username == user[j].username && password == user[j].password){
                        login = true;
                        roleLogin = user[j].role;
                    }
                }
                if(login){
                    cout<<"\nLogin berhasil\n";
                    system("pause");
                    break;
                }
                else{
                    cout<<"\nLogin gagal\n";
                    system("pause");
                }
                if(i==3){
                    cout<<"3 kali gagal login, coba lagi nanti\n";
                    return 0;
                }
            }
            if(login){
                bool menu = true;

                if(roleLogin == "admin"){
                    while(menu){
                        system("cls");
                        int pilih;

                        cout<<"===================== MENU ADMIN ======================\n";
                        cout<<"1. Tambah Tiket\n";
                        cout<<"2. Lihat Tiket\n";
                        cout<<"3. Update Tiket\n";
                        cout<<"4. Hapus Tiket\n";
                        cout<<"5. Logout\n";
                        cout<<"========================================================\n";
                        cout<<"Pilih : ";
                        cin>>pilih;

                        if(pilih == 1){
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
                            cout<< endl <<"Tiket berhasil ditambahkan\n";
                            system("pause");
                        }

                        else if(pilih == 2){
                            system("cls");

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
                            system("pause");
                        }

                        else if(pilih == 3){
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

                        else if(pilih == 4){
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
                        else if(pilih == 5){
                            menu = false;
                        }
                    }
                }
                else{
                    while(menu){
                        system("cls");
                        int pilih;

                        cout<<"===================== MENU USER ======================\n";
                        cout<<"1. Lihat Tiket\n";
                        cout<<"2. Beli Tiket\n";
                        cout<<"3. Logout\n";
                        cout<<"======================================================\n";
                        cout<<"Pilih menu : ";
                        cin>>pilih;
                        system("cls");

                        if(pilih == 1){
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
                            system("pause");
                        }

                        else if(pilih == 2){
                            string kode;

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
                            cout<< endl << "Masukkan kode tiket : ";
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
                        else if(pilih == 3){
                            menu = false;
                        }
                    }
                }
            }
        }
        else if(menuAwal == 3){
            program = false;
            cout<<"\nTerima kasih telah menggunakan layanan kami\n";
        }
    }
}