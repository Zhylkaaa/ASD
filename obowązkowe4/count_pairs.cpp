// ilość i,j: A[i] + A[j] = x
 
#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int C(int n, int k){
    int res = 1;
 
    if(n==0)return 0;
    if(n==1)return 0;
    if(n==2)return 1;
 
    if( k > n - k){
        k = n - k;
    }
 
    for(int i = 0;i<k;i++){
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    int* A = new int[n];
 
    unordered_map<int,int> m;
 
    for(int i = 0;i<n;i++){
        cin>>A[i];
        m[A[i]]++;
    }
 
    int res = 0;
 
    for(int i = 0;i<n;i++){
        if(A[i]!=x-A[i]){
            res += m[A[i]] * m[x - A[i]];
            m[A[i]] = 0;
            m[x - A[i]] = 0;
        } else {
            res += C(m[A[i]], 2);
            m[A[i]]=0;
        }
    }
 
    cout<<res<<endl;
    delete[] A;
    return 0;
}