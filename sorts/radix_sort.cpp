#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
void counting_sort(int* T, int n, int exp){
    int B[n];
    int C[10];
 
    for(int i = 0;i<10;i++)C[i]=0;
    for(int i = 0;i<n;i++)C[ (T[i]/exp)%10 ]++;
    for(int i = 1;i<10;i++)C[i] += C[i-1];
    for(int i = n-1;i>=0;i--){
        C[(T[i]/exp)%10]--;
        B[C[(T[i]/exp)%10]] = T[i];
    }
    for(int i = 0;i<n;i++){
        T[i] = B[i];
    }
}
 
void radix_sort(int* T, int n, int m){
    int exp=1;
    for(int i = 0;i<m;i++){
        counting_sort(T, n, exp);
        exp*=10;
    }
}
 
int count_digits(int n){
    int c = 0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n;
    cin>>n;
 
    int* T = new int[n];
 
    int m = -1;
 
    for(int i =0;i<n;i++){
        cin>>T[i];
        m = max(m, T[i]);
    }
 
    int nm = count_digits(m);
 
    radix_sort(T, n, nm);
 
    for(int i = 0;i<n;i++){
        cout<<T[i]<<" ";
    }
    cout<<endl;
 
    delete[] T;
    return 0;
}