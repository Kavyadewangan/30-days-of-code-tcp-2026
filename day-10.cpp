#include<iostream>
using namespace std;

void sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int a;
    cout << "Enter number of elements: ";
    cin >> a;

    int num[a];

    cout << "Enter elements of array (0/1/2): ";
    for(int i = 0; i < a; i++){
        cin >> num[i];

        while(num[i] != 0 && num[i] != 1 && num[i] != 2){
            cout << "Invalid input! Enter only 0, 1, or 2: "<<endl;
            cin >> num[i];
        }
    }

    sort(num, a);

    cout << "Sorted array:\n[ ";
    for(int i = 0; i < a; i++){
        cout << num[i] << " ";
    }
    cout << "]";

    return 0;
}
