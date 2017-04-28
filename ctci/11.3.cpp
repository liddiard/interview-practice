#include <iostream>
using namespace std;


// 5 6 7 8 9 1 2 3 4
int binarySearchRotated(int arr[], int left, int right, int target) {
    int mid = (left + right) / 2;
    if (a[mid] == target) {
        return mid;
    }
    if (left > right) {
        return -1;
    }
    if (arr[left] < arr[mid]) {
        if (target >= arr[left] && target <= arr[mid]) {
            return binarySearchRotated(arr, left, mid-1, target);
        }
        else {
            return binarySearchRotated(arr, mid+1, right, target);
        }
    }
    else if (arr[left] > arr[mid]) {
        if (x >= a[mid] && x <= a[right]) {
            return binarySearchRotated(arr, mid+1, right, target);
        }
        else {
            return binarySearchRotated(arr, left, mid-1, target);
        }
    }
    else if (arr[left] == arr[mid]) {
        // left side is all the same number
        if (arr[mid] != arr[right]) {
            return binarySearchRotated(arr, mid+1, right, target);
        }
        else {
            int result = binarySearchRotated(arr, left, mid-1, target);
            if (result == -1) {
                return binarySearchRotated(arr, mid+1, right, target);
            }
            else {
                return result;
            }
        }
    }
    return -1;
}

int main() {
    return 0;
}