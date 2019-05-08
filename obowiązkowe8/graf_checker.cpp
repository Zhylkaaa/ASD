#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void dfs(int v, vector< vector<int> > &G, vector<bool> &Vis){
	if(Vis[v])return;
	Vis[v] = true;

	for(int i = 0;i<G[v].size();i++){
		dfs(G[v][i], G, Vis);
	}
}

int count_components(vector< vector<int> > &G){
	int n = G.size();
	vector<bool> Vis(n, false);
	int c = 0;

	for(int i = 0;i<n;i++){
		if(!Vis[i]){
			c++;
			dfs(i, G, Vis);
		}
	}

	return c;
}

bool is_bipartite_bfs(vector< vector<int> > &G){
	int n = G.size();

	vector<int> ns(n, 0);
	queue<int> q;
	q.push(0);
	ns[0] = 1;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		int u;
		for(int i = 0;i<G[v].size();i++){
			u=G[v][i];

			if(ns[u]==0){q.push(u); ns[u] = 3-ns[v];}
			else if(ns[u] != 3-ns[v])return false;
		}
	}

	return true;
}

bool _is_bipartite(int v, vector< vector<int> > &G, vector<int> &Vis, int c){
	if(Vis[v] != 0)return Vis[v] == 3-c;

	Vis[v] = 3-c;

	for(int i=0;i<G[v].size();i++){
		if(!_is_bipartite(G[v][i], G, Vis, Vis[v]))return false;
	}
	return true;
}

bool is_bipartite_dfs(vector< vector<int> > &G){
	int n = G.size();
	vector<int> Vis(n, 0);
	return _is_bipartite(0, G, Vis, 2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n;
	cin>>n;

	vector< vector<int> > G(n);

	int m;
	cin>>m;

	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	cout<<count_components(G)<<endl;
	cout<<(is_bipartite_bfs(G) ? "Yes" : "No")<<endl;
	cout<<(is_bipartite_dfs(G) ? "Yes" : "No")<<endl;
	return 0;
}