#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define INF (1<<30)
#define f first
#define s second

/* 
In:
6 6
0 1 10
1 2 20
2 5 50
4 5 3
0 4 100
4 3 15

Out:
dijkstra:
parent: 1 2 5 4 5 -1 
weight: 80 70 50 18 3 0 
dijkstra_set:
parent: 1 2 5 4 5 -1 
weight: 80 70 50 18 3 0 
dijkstra_M:
parent: 1 2 5 4 5 -1 
weight: 80 70 50 18 3 0 
*/


void dijkstra(int n, vector< vector< pair<int, int> > > &G, vector<int> &parent, vector<int> &path_weight){

	int start = n-1; // start from vertex of your choice :) 

	for(int i = 0;i<n;i++){
		path_weight[i] = INF;
		parent[i] = -1;
	}

	path_weight[start] = 0;

	priority_queue< pair<int, int> > q;

	q.push({-path_weight[start], start}); // -path_weight[start] 'cause priority queue is sorted in decreasing order
                                 // pairs are sorted by first element. if first elements are equal then by second.
	while(!q.empty()){
		int v = q.top().s;
		int w = -q.top().f;

		q.pop();

		if(w > path_weight[v])continue; // skipping not up-to-date values

		for(pair<int, int> i : G[v]){ // iterating over adjacent vertices
			if(path_weight[i.f] > path_weight[v] + i.s){
				parent[i.f] = v;
				path_weight[i.f] = path_weight[v] + i.s;
				q.push({-path_weight[i.f], i.f}); 
			}
		}
	}
}

void dijkstra_set(int n, vector< vector< pair<int, int> > > &G, vector<int> &parent, vector<int> &path_weight){
	int start = n-1;

	for(int i = 0;i<n;i++){
		path_weight[i] = INF;
		parent[i] = -1;
	}

	path_weight[start] = 0;

	set< pair<int, int> > s; // set is red-black tree under the hood 

	s.insert({path_weight[start], start}); // and it is sorted in increasing order 
	while(!s.empty()){
		int v = s.begin()->s;

		s.erase(s.begin());

		for(pair<int, int> i : G[v]){ // iterating over adjacent vertices
			if(path_weight[i.f] > path_weight[v] + i.s){
				s.erase({path_weight[i.f], i.f});
				parent[i.f] = v;
				path_weight[i.f] = path_weight[v] + i.s;
				s.insert({path_weight[i.f], i.f}); 
			}
		}
	}
}

void dijkstra_M(int n, vector< vector< int > > &M, vector<int> &parent, vector<int> &path_weight){
	int start  = n-1;

	for(int i = 0;i<n;i++){
		path_weight[i] = INF;
		parent[i] = -1;
	}

	path_weight[start] = 0;
	vector<bool> vis(n, false);

	for(int i = 0;i<n;i++){
		int v = -1;
		int w = INF;

		for(int j=0;j<n;j++){
			if(!vis[j] && path_weight[j] < w){
				w = path_weight[j];
				v = j;
			}
		}

		if(v==-1)break;

		vis[v] = true;

		for(int i = 0;i<n;i++){
			if(i==v)continue;

			if(M[v][i] != INF && path_weight[i] > w + M[v][i]){
				path_weight[i] = w + M[v][i];
				parent[i] = v;
			}
		}
	}
}

void print_p_w(vector<int> &p, vector<int> &w){
	cout<<"parent: ";
	for(int i : p)cout<<i<<" ";
	cout<<endl;
	cout<<"weight: ";
	for(int i : w)cout<<i<<" ";
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n, m;

	cin>>n>>m;

	vector< vector< pair<int, int> > > G(n);

	vector< vector<int> > M(n, vector<int>(n, INF)); // recurrent constructor

	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;

		M[a][b] = w;
		M[b][a] = w;

		G[a].push_back({b, w});
		G[b].push_back({a, w});
	}

	vector<int> parent(n);
	vector<int> path_weight(n);

	cout<<"dijkstra:"<<endl;
	dijkstra(n, G, parent, path_weight);
	print_p_w(parent, path_weight);
	cout<<"dijkstra_set:"<<endl;
	dijkstra_set(n, G, parent, path_weight);
	print_p_w(parent, path_weight);
	cout<<"dijkstra_M:"<<endl;
	dijkstra_M(n, M, parent, path_weight);
	print_p_w(parent, path_weight);

	return 0;
}