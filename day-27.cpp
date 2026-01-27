#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    vector<double>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
     double sum = 0;
     double result = 0;
     for(int i = 0; i<k; i++){
        sum = sum + a[i];
    }
    result =( result + sum)/k;
    for(int i = k; i<n; i++){
        sum = sum + a[i];
        sum = sum - a[i-k];
        result = result + sum/k;
    }

    cout<<fixed << setprecision(10)<<result;
    return 0;
}