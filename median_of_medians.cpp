// median of medians algorithm or megiczne piątki
// https://stackoverflow.com/questions/9489061/understanding-median-of-medians-algorithm
 
#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
void sort5(int* T, int l, int r){
    int i = l+1;
    while(i<=r){
        int j = i;
        while(j>l && T[j-1] > T[j]){
            swap(T[j-1], T[j]);
            j--;
        }
        i++;
    }
}
 
int select(int* T, int l, int r, int k){
    if( (r-l+1) <= 5 ){
        sort5(T, l, r);
        return T[k+l];
    }
 
    int* X = new int[ ( (r-l+1)+4 )/5 ];
    int c=0;
 
    for(int i = l;i<=r;i+=5){
        int j = i+4;
        if(j>r)j=r;
        X[c]=select(T, i, j, (j-i+1)/2);
        c++;
    }
 
    int M = select(X, 0, c-1, c/2);
 
    delete[] X;
 
    int* L1 = new int[(r-l+1)];
    int* L2 = new int[(r-l+1)];
    int* L3 = new int[(r-l+1)];
 
    int i1=-1,i2=-1,i3=-1;
 
    for(int i = l;i<=r;i++){
        if(T[i]<M){
            i1++;
            L1[i1] = T[i];
        } else if(T[i]>M){
            i3++;
            L3[i3]=T[i];
        } else {
            i2++;
            L2[i2]=T[i];
        }
    }
 
 
    if(k <= i1){
        int res = select(L1, 0, i1, k);
        delete[] L1;
        delete[] L2;
        delete[] L3;
        return res;
 
    } else if(k > (i1+i2+1)) {
        int res = select(L3, 0, i3, k-i1-i2-2);
        delete[] L1;
        delete[] L2;
        delete[] L3;
        return res;
    } else {
        delete[] L1;
        delete[] L2;
        delete[] L3;
        return M;
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n;
    cin>>n;
 
    vector<int> L(n);
 
    int* T = new int[n];
 
    for(int i = 0;i<n;i++){
        L[i] = rand()%61;
        T[i] = L[i];
        cout<<L[i]<<" ";
    }
    cout<<endl;
 
    int m = select(T, 0, n-1, (n)/2);
 
    cout<<m<<endl;
 
    sort(L.begin(), L.end());
    for(int i = 0;i<n;i++){
        cout<<L[i]<<" ";
    }
    cout<<endl;
 
    delete[] T;
 
    return 0;
}