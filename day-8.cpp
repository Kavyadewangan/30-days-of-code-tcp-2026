#include <vector>
#include<iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int count = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};
int main(){
    int arr[12] = {100,4,200,1,3,2,5,9,10,6,7,8};
    vector<int> nums (arr,arr+12);
    Solution sol;
    int result = sol.longestConsecutive(nums);
    cout << result << endl;
    return 0;
}
