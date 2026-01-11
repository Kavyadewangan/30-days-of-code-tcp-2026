#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int first, int mid, int last) {
    vector<int> temp;
    int i = first;
    int j = mid + 1;

    while (i <= mid && j <= last) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= last) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[first + idx] = temp[idx];
    }
} 

void mergeSort(vector<int> &arr, int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main() {
    int a;
    cout << "Enter size of array: ";
    cin >> a;

    vector<int> arr(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, a - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
