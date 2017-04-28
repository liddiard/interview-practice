#include <iostream>
#include <string>
using namespace std;

int find(string arr[], int left, int right, string target) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    int lcur = mid - 1;
    int rcur = mid + 1;
    if (!arr[mid].size()) {
        while (true) {
            if (lcur < left && rcur > right)
                return -1;
            if (arr[lcur].size()) {
                mid = lcur;
                break;
            }
            else if (arr[rcur].size()) {
                mid = rcur;
                break;
            }
            else {
                --lcur;
                ++rcur;
            }
        }
    }
    if (arr[mid] > target) {
        return find(arr, left, mid-1, target);
    } 
    else if (arr[mid] < target) {
        return find(arr, mid+1, right, target);
    }
    else {
        return mid;
    }
}

int main() {
    string arr[] = {
        "adspicing",
        "amet",
        "",
        "",
        "consectectur",
        "",
        "dolor",
        "",
        "",
        "elit"
        "",
        "",
        "",
        "lorem",
        "",
        "sed",
        "",
        ""
    };
    cout << find(arr, 0, 17, "sed") << endl;
    return 0;
}