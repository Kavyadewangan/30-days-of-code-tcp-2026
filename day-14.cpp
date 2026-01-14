#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string binary(int n){
    string result = " ";
    while(n>0){
        result = result + (n%2 == 1 ? '1' : '0');
        n = n/2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int setBits(int n){
    int count = 0 ;
      while(n!=0){
        if(n%2 == 1){
            count++;
        } 
         n = n/2;
      }
        return count;
} 


int main(){
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    cout<<"Binary representation: "<<binary(n)<<endl;
    cout<<"Number of set bits: "<<setBits(n)<<endl;
    return 0;
}