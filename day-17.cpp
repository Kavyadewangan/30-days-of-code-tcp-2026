#include <iostream>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result = (int)((1LL * result * base) % MOD);
        }
        return result;
    }

    int countGoodNumbers(int n) {
        int evenPositions = (n + 1) / 2;
        int oddPositions = n / 2;

        int ans = power(5, evenPositions);
        ans = (int)((1LL * ans * power(4, oddPositions)) % MOD);

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter length of digit string: ";
    cin >> n;

    Solution obj;
    cout << "Number of good digit strings: "
         << obj.countGoodNumbers(n) << endl;

    return 0;
}
