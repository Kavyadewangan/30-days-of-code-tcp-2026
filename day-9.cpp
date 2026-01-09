#include<iostream>
#include<string>
using namespace std;
int main(){
    string num;
    cout<<"Enter a number: ";
    cin>>num;
    int length = num.size() -1;
    int arr[length + 1] ;
    for(int i = length; i>=0; i--) {
        arr[i] = num[i]- 0;
    }

    int index = -1;
    for(int i = length; i>=0; i--){
        if(arr[i]%2 != 0){
             index = i;
             break;
        }
    }

    if (index != -1){
        for(int i = 0; i<= index; i++){
            cout<<num[i];
        }
    }

    return 0;

}