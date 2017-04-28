#include <iostream>
using namespace std;

void merge(int a[], int b[], int aLen, int bLen) {
    int curA = aLen - 1;
    int curB = bLen - 1;
    int curMerged = aLen + bLen - 1;
    while (curA >= 0 && curB >= 0) {
        if (b[curB] > a[curA])
            a[curMerged] = b[curB--];
        else
            a[curMerged] = a[curA--];
        --curMerged;
    }
    while (curB >= 0)
        a[curMerged--] = b[curB--];
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 0, 0, 0, 0};
    int b[] = {2, 4, 6, 8};
    merge(a, b, 5, 4);
    for (int i = 0; i < 9; i++) {
        cout << a[i] << endl;
    }
    return 0;
}