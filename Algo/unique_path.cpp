#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define INF (1<<30)

int bfs(vector< vector<int> > &G, vector< vector<int> > &parent, int s, int t, int n){
	vector<int> Vis(n, false);
	vector<int> d(n, INF);
	queue<int> q;

	q.push(s);
	Vis[s] = true;
	d[s] = 0;

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(int u : G[v]){
			if(!Vis[u]){
				Vis[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
			}
			if(d[v]+1==d[u]){
				parent[u].push_back(v);
			}
		}
	}

	return d[t];
}

void __build_graph(vector< vector<int> > &P, vector< vector<int> > &G, vector<bool> &in_graph, int t){
	in_graph[t] = true;
	for(int v:P[t]){
		G[t].push_back(v);
		G[v].push_back(t);
		if(!in_graph[v])
			__build_graph(P, G, in_graph, v);
	}
}
void build_graph(vector< vector<int> > &P, vector< vector<int> > &G, int t, int n){
	vector<bool> in_graph(n, false); 
	__build_graph(P, G, in_graph, t);
}

void dfs(int v, vector<bool> &Vis, vector<int> &dis, vector<int> &low, vector<int> &parent, vector< pair<int, int> > &bridges, int &time, vector< vector<int> > &G){
	Vis[v] = true;

	dis[v] = low[v] = time++;

	for(int u : G[v]){
		if(!Vis[u]){
			parent[u] = v;

			dfs(u, Vis, dis, low, parent, bridges, time, G);

			low[v] = min(low[v], low[u]);

			if(low[u] > dis[v])
				bridges.push_back({v, u});
		} else if(u != parent[v])
			low[v] = min(low[v], dis[u]);
	}
}

void find_bridges(vector< vector<int> > &G, vector< pair<int, int> > &bridges, int n, int s){
	vector<bool> Vis(n, false);
	vector<int> low(n), dis(n);
	vector<int> parent(n, -1);
	int time = 0;
	dfs(s, Vis, dis, low, parent, bridges, time, G);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n, m;

	cin>>n>>m;

	vector< vector<int> > G(n);

	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int s, t;
	cin>>s>>t;

	vector< vector<int> > parent(n);

	if(bfs(G, parent, s, t, n) == INF){
		cout<<"Nie spujny graf :) "<<endl;
		return 0;
	}

	vector< vector<int> > GP(n); // G prim
	build_graph(parent, GP, t, n);

	vector< pair<int, int> > bridges;

	find_bridges(GP, bridges, n, s);

	if(bridges.size() == 0){
		cout<<"Ni ma"<<endl;
	} else {
		cout<<bridges[0].first<<" "<<bridges[0].second<<endl;
	}
	return 0;
}