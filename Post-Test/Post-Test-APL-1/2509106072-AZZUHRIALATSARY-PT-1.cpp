#include <iostream>
using namespace std;

int main() {
    string nama;
    string password;
    string passwordBenar = "072";
    int percobaan = 0;
    
    while (percobaan < 3) {
        cout << "\n================= LOGIN =================" << endl;
        cout << "Nama     : ";
        getline(cin, nama);
        cout << "Password : ";
        getline(cin, password);
        cout << "=========================================" << endl;

        if (password == passwordBenar) {
            cout << "Login berhasil...\n";
            break;
        } else {
            cout << "Password salah...\n";
            percobaan++;
        }
    }

    if (percobaan == 3) {
        cout << "salah 3 kali, program berhenti...";
        return 0;
    }

    int pilihan;
    float nilai;

    do {
        cout << "\n============= MENU KONVERSI =============" << endl;
        cout << "1. Meter --> Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer --> Meter dan Centimeter" << endl;
        cout << "3. Centimeter --> Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "=========================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;


        if (pilihan == 1) {
            cout << "Masukkan nilai Meter: ";
            cin >> nilai;
            cout << "Hasil: " << nilai/1000 << " km dan " << nilai*100 << " cm" << endl;

        } else if (pilihan == 2) {
            cout << "Masukkan nilai Kilometer: ";
            cin >> nilai;
            cout << "Hasil: " << nilai*1000 << " m dan " << nilai*100000 << " cm" << endl;

        } else if (pilihan == 3) {
            cout << "Masukkan nilai Centimeter: ";
            cin >> nilai;
            cout << "Hasil: " << nilai/100 << " m dan " << nilai/100000 << " km" << endl;

        } else if (pilihan == 4) {
            cout << "Program selesai...";

        } else {
            cout << "Pilihan tidak tersedia...";
        }

    } while (pilihan != 4);

    return 0;
}