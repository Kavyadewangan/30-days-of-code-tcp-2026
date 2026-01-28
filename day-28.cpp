#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int numberOfSubarrays(vector<int>& nums, int k){
    unordered_map<int , int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;
    for(int num: nums){
        if(num%2 != 0){
            sum++;
        }; 
        if (mp.find(sum -k) != mp.end()){
            count = count + mp[sum - k];
        };

        mp[sum]++;
    }
    return count;
}
int main(){
    int n, k;
    cout<<"Enter size of array: ";
    cin>>n;
    cout << "Number of odd elements required in subarray: ";
    cin>>k;
    cout<<"Enter elements of array: ";
    vector<int>nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    cout<<numberOfSubarrays(nums, k);
    return 0;
}