// O(NlogN)

#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
struct poj {
    int x1,x2,y1,y2;
};
 
void swap_poj(poj &a, poj &b){
    poj t = a;
    a = b;
    b = t;
}
 
int partition(poj* T, int l, int r){
    int pivotIndex = (r+l)/2;
    poj pivot = T[pivotIndex];
   
    swap_poj(T[r],T[pivotIndex]);
   
    pivotIndex = l;
   
    for(int i = l;i<r;i++){
        if(T[i].y1 > pivot.y1){
            swap_poj(T[pivotIndex], T[i]);
            pivotIndex++;
        }
    }
   
    swap_poj(T[r], T[pivotIndex]);
   
    return pivotIndex;
}
 
void QuickSort(poj* T, int l, int r){
    if(l<r){
        int mid = partition(T, l, r);
       
        QuickSort(T, l, mid-1);
        QuickSort(T, mid+1, r);
    }
}
 
int res;
 
bool solve(poj* T,int A, int n, int p){
    int V = 0;
    res = 0;
 
    for(int i = 0;i<n;i++){
        if(T[i].y1 >= p){V+=(T[i].x2 - T[i].x1) * (T[i].y2-T[i].y1);res++;}
        if(T[i].y1 < p && T[i].y2 > p)V+=(T[i].x2 - T[i].x1)*(T[i].y2 - p);
    }
 
    return V<A;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n;
    int A;
   
    cin>>n>>A;
   
    poj* T = new poj[n];
   
    for(int i = 0;i<n;i++){
        cin>>T[i].x1>>T[i].y1>>T[i].x2>>T[i].y2;
    }
   
    QuickSort(T, 0, n-1);
   
    for(int i = 0;i<n;i++){
        cout<<T[i].x1<<" "<<T[i].y1<<" "<<T[i].x2<<" "<<T[i].y2<<endl;
    }
   
   
    int l=0, r = n-1;
 
    while(l<r){
        int m = (l+r+1)/2;
 
        if(solve(T, A, n, T[m].y1))l = m;
        else r = m-1;
    }
 
    if(!solve(T, A, n, T[l].y1)){
        cout<<0<<endl;
    } else {
        cout<<l<<" "<<res<<endl;
    }
   
    return 0;
}