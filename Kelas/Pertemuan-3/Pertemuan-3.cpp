#include <iostream>
using namespace std;

int hitungLuas(int panjang, int lebar) {
    int hasil = panjang * lebar;
    return hasil; // return mengembalikan nilai hasil
}

int main() {
    int p = 10;
    int l = 5;
// pemanggilan fungsi
    int luasTanah = hitungLuas(p, l);
    cout << "Panjang: " << p << "m, Lebar: " << l << "m" << endl;
// Sekarang variabel luasTanah sudah memiliki nilai yang dikembalikan
    cout << "Total Luas Tanah: " << luasTanah << " meter persegi." << endl;
    return 0;
}