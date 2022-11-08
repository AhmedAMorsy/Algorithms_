#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
void merge(int* A, int szA, int* B, int szB) { //O(n)
    int idxA = 0, idxB = 0, idxC = 0;
    //int C[szA+szB];
    int* C= new int[szA+szB];
    while (idxA < szA && idxB < szB) { //O(n)
        if (A[idxA] < B[idxB]) {
            C[idxC] = A[idxA];
            idxC++; idxA++;
        } else
            C[idxC++] = B[idxB++];
    }
    while (idxB < szB) { //O(n)
        C[idxC++] = B[idxB++];
    }
    while (idxA < szA) {//O(n)
        C[idxC++] = A[idxA++];
    }
    for (int i = 0; i < idxC; i++) {//O(n)
        A[i] = C[i];
    }
}

void mergeSort(int* begin, int* end) { //O(nlog(n))
    int sz = end - begin;
    if (sz <= 1) {
        return;
    }
    int mid = sz/2; //O(log (n))
    mergeSort(begin, begin+mid);
    mergeSort(begin+mid, end);
    merge(begin, mid, begin+mid, sz-mid);//O(n)
}
int n ,A[N];
int main() {
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>A[i];
    mergeSort(A, A+n);
    for (int i = 0; i < n; i++) {
      cout<<A[i]<<" ";
    }
    return 0; }
// 4,6,7,8,9,