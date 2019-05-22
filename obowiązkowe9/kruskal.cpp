#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define f first
#define s second

bool comp(pair< pair<int, int>, pair<int, int> > &a, pair< pair<int, int>, pair<int, int> > &b){
	return (a.f.f - a.s.f)*(a.f.f - a.s.f) + (a.f.s - a.s.s)*(a.f.s - a.s.s) < (b.f.f - b.s.f)*(b.f.f - b.s.f) + (b.f.s - b.s.s)*(b.f.s - b.s.s);
}

size_t pair_hash(const pair<int,int> &a){
	return hash<int>()(a.f) ^ hash<int>()(a.s);
}

int find(int a, int parent[]){
	if(parent[a]==a)return a;
	else return parent[a] = find(parent[a], parent);
}

void union_set(int a, int b, int parent[]){
	a = find(a, parent);
	b = find(b, parent);
	parent[a] = b;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector< pair<int,int> > X(n);

    for(int i = 0;i<n;i++){
    	cin>>X[i].f>>X[i].s;
    }

    vector< pair< pair<int, int>, pair<int, int> > > A;

    for(int i = 0;i<n;i++){
    	for(int j = i+1;j<n;j++){
    		A.push_back({X[i], X[j]});
    	}
    }

    sort(A.begin(), A.end(), comp);

    int parent[n];

    unordered_map<pair<int,int>, int, decltype(&pair_hash)> m(n, pair_hash);

    for(int i = 0;i<n;i++){
    	parent[i]=i;
    	m[X[i]] = i;
    }

    ld cost = 0;

    for(int i = 0;i<A.size();i++){
    	if(find(m[A[i].f], parent) != find(m[A[i].s], parent)){
    		cost += sqrt((A[i].f.f - A[i].s.f)*(A[i].f.f - A[i].s.f) + (A[i].f.s - A[i].s.s)*(A[i].f.s - A[i].s.s));
    		union_set(m[A[i].f], m[A[i].s], parent);
    	}
    }

    cout<<cost<<endl;

	return 0;
}