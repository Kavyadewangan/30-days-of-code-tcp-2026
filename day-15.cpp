#include <iostream>
using namespace std;

int main() {
    int a , b , c, n; 
    cout<<"enter the value of a: "; 
    cin>>a; 
    cout<<endl; 
    cout<<"enter the value of b: "; 
    cin>>b;
    cout<<endl; 
    cout<<"enter the value of c: ";
    cin>>c; cout<<endl; 
    cout<<"Enter the value of n: ";
    cin>>n;

    int l = 0;
    int j = 1;

    while (true) {
        if (j % a == 0 || j % b == 0 || j % c == 0) {
            l++;
            if (l == n) {
                cout << j;
                break;
            }
        }
        j++;
    }

    return 0;
}
