#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n;
	cin>>n;

	vector< vector<int> > G (n, vector<int>(n, 0));

	int m;
	cin>>m;

	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;

		G[a][b] = 1;
	}

	int v = 0;

	for(int i = 1;i<n;i++){
		if(G[v][i] == 1)v = i;
	}

	bool f = true;

	for(int i = 0;i<n && f;i++){
		if(G[v][i] == 1)f = false;
		if(i!=v && G[i][v] != 1)f = false;
	}

	f ? cout<<v<<" jest ujsciem"<<endl : cout<<"nie ma ujscia"<<endl;

	return 0;
}