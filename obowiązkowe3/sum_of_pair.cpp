#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
pair<int,int> find(int* A, int n, int x){
    int i = 0;
    int j = n-1;
 
    while(i<j){
        if(A[i]+A[j] == x)return make_pair(i, j);
 
        if(A[i]+A[j] > x)j--;
        else i++;
    }
 
    return make_pair(-1,-1);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,x;
    cin>>n>>x;
    int* A = new int[n];
 
    for(int i = 0;i<n;i++)cin>>A[i];
 
    pair<int,int> res = find(A, n, x);
 
    res.first == -1 ? cout<<-1<<endl : cout<<res.first<<" "<<res.second<<endl;
 
    delete[] A;
 
    return 0;
}