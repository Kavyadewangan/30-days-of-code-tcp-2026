#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "Enter N and D:\n";

    int n;
    long long s;
    cin >> n >> s;

    cout << "Enter player powers:\n";

    vector<long long> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    sort(k.begin(), k.end());

    int l = 0;
    int r = n- 1;
    int win = 0;

    while (l <= r) {
        long long Power = k[r];
        long long teamMember = (s / Power) + 1;

        if (l + teamMember - 1 <= r) {
            win++;
            l = l + teamMember - 1;
            r--;
        } else {
            r--;
        }
    }

    cout << "Wins = " << win << endl;
    return 0;
}
