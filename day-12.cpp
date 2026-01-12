#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            result = mid;
            right = mid - 1;   // move left to find first
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int lastSearch(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            result = mid;
            left = mid + 1;    // move right to find last
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;

    vector<int> nums(a);

    cout << "Enter the elements of the array in non-decreasing order: ";
    for (int i = 0; i < a; i++) {
        cin >> nums[i];
        while (i > 0 && nums[i] < nums[i - 1]) {
            cout << "Error: Enter a number >= " << nums[i - 1] << ": ";
            cin >> nums[i];
        }
    }

    int target;
    cout << "Enter the number to be searched: ";
    cin >> target;

    int first = binarySearch(nums, target);
    int last = lastSearch(nums, target);

    if(first == -1){
        cout << "[-1, -1]";
    } else {
        cout << "[" << first << ", " << last << "]";
    }

    return 0;
}
