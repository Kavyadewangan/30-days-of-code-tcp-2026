#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 int main(){
    int a, b;
    cout<<"Enter size of nums1: ";
    cin>>a;
    vector<int> nums1(a);
    cout<<"Enter elements of nums1: "<<endl;
    for(int i =0; i<a; i++){
        cin>>nums1[i];
    }
    cout<<"Enter size of nums2: "<<endl;
    cin>>b;

    vector<int> nums2(b);
    for(int i = 0; i<b; i++){
        cin>>nums2[i];
    }

    vector<int> ans;
    for(int i = 0; i<nums1.size(); i++){
        int index = -1;

        for(int j = 0; j<nums2.size(); j++){
            if(nums1[j] == nums1[i]){
                index = j;
                break;
            }
        }
        int nextGreater = -1;
        for(int k = index + 1; k<nums2.size(); k++ ){
            if(nums2[k]>nums1[i]){
                nextGreater = nums2[k];
                break;
            }
        }

        ans.push_back(nextGreater);
    }

    cout<<"Next Greater Element: "<<endl;
    for(int x: ans){
        cout<< x<< " ";
    }
    return 0;
 }