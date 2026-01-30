#include<iostream>
using namespace std;
int main(){
    int n , m ;
    cout<<"Enter size of array a: ";
    cin>>n;
    cout<<"Enter size of array b: ";
    cin>>m;
    int a[n], b[m];
    cout<<"Enter elements of array a: ";
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter elements of array b: ";
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }
    int i= 0, j = 0;
    cout<<"Intersection: ";
    while(i<n && j<m){
        if(a[i] == b[j] ){
           cout<<a[i]<<" ";
           i++;
           j++;
        } 
        else if(a[i]<b[j]){
            i++;
        }  
        else{
            j++;
        }
     }

    return 0; 
}