#include<iostream>
#include<vector>
using namespace std;
void encrypted(int arr[], int size){
    int a = 0;
    int sum = 0;
    int digit2 = 0;
    int digit3 = 0;
    int encrypted = 0;
   for(int i = 0; i<size; i++){
    int num = arr[i]%10;
    int rem = (arr[i]/10)%10;
    int last = arr[i]/100;
    if (num>rem && num > last){
        a = num;
    } 
    else if(rem>num && rem>last){
        a = rem;
    }
    else{
        a = last;
    }
    digit2 = a*10;
    digit3 = a*100;
    encrypted = digit3 + digit2 + a;
    sum = sum + encrypted;
    cout<<"Encrypted number is: "<< encrypted<<endl;
   } 
   cout<<"sum of the encrpted number is : "<<sum<<endl;
}
int main(){
    int nums[5] = {123,456,789,145,297};
    encrypted(nums, 5);
    return 0;
}