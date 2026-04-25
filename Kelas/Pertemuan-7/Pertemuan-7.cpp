#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kembalianKoin(vector<int> coins, int target) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
        for (int coin : coins) {
            while (target >= coin) {
            target -= coin;
            count ++;
            }
        }
    return count;
}
int main() {
    vector<int> coins = {1, 5, 10, 25};
    int target = 30;
    cout << "Hasil: " << kembalianKoin(coins, target) << " koin" << endl;
    return 0;
}