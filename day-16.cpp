#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    int ratting[n], candies[n];
    cout<<"Enter the rating of the students: ";
    for(int i=0; i<n; i++){
        cin>>ratting[i];
        candies[i]=1;
    }
    for(int i = 1 ; i<n; i++){
        if(ratting[i]>ratting[i-1]){
            candies[i]=candies[i-1]+1;
        }
  }
    for(int i = n-2; i>=0; i--){
        if(ratting[i]>ratting[i+1] && candies[i]<=candies[i+1]){
            candies[i]=candies[i+1]+1;
        }
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + candies[i];
    }
    cout<<"Minimum number of candies required: "<<sum<<endl;
    return 0;
}