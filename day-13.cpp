#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool finishEating(vector<int> &piles, int k, int h){
    int hours = 0;
    for(int pile :piles){
        hours = hours + (pile + k -1)/k;
    }
    return hours <= h;
}
int minSpeed(vector<int> &piles, int h){
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int result = right;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(finishEating(piles, mid, h)){
            result = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
}
int main(){
    int n,h;
    cout<<"Enter number of piles: ";
    cin>>n;

    vector<int> piles(n);
    cout<<"Enter pile heights: ";
    for(int i=0;i<n;i++){
        cin>>piles[i];
    }
    cout<<"Gaurd will return in hours: ";
    cin>>h;

    int result = minSpeed(piles,h);
    cout<<"Minimus eating speed: "<<result<<endl;

    return 0;
}