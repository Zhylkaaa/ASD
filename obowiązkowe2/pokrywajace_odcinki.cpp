#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
struct point {
    int poz;
    int index;
};
 
bool comp(point &a, point &b){
    return a.poz < b.poz;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n;
    cin>>n;
 
    point start[n];
    point end[n];
 
    int index_to_position[n];
 
    for(int i = 0;i<n;i++){
        cin>>start[i].poz>>end[i].poz;
        start[i].index = end[i].index = i;
    }
 
    sort(start, start+n, comp);
    sort(end, end+n, comp);
 
    for(int i = 0;i<n;i++){
        index_to_position[start[i].index] = i;
    }
 
    int max_val = -1;
    int j;
    for(int i = 0;i<n;i++){
        if(max_val < i - index_to_position[end[i].index]){
            max_val = i - index_to_position[end[i].index];
            j=i;
        }
    }
 
    cout<<start[index_to_position[end[j].index]].poz<<" "<<end[j].poz;
 
    return 0;
}