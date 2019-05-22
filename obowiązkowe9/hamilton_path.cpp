#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void dfs(int v, vector< set<int> > &A, stack<int> &s, vector<bool> &Vis){
	if(Vis[v])return;

	Vis[v] = true;

	for(int i : A[v]){
		dfs(i, A, s, Vis);
	}

	s.push(v);
}

bool is_hamiltonian(vector< set<int> > &A, int n){
	stack<int> s;
	vector<bool> Vis(n, false);

	for(int i = 0;i<n;i++){
		if(!Vis[i])dfs(i, A, s, Vis);
	}

	int v = s.top();
	s.pop();

	while(!s.empty()){
		if(A[v].find(s.top()) == A[v].end())return false;
		v = s.top();
		s.pop();
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n, m;
	cin>>n>>m;

	vector< set<int> > A(n);

	for(int i = 0;i<m;i++){
		int a, b;
		cin>>a>>b;
		A[a].insert(b);
	}

	cout<<(is_hamiltonian(A, n)?"Yes":"No")<<endl;
	return 0;
}