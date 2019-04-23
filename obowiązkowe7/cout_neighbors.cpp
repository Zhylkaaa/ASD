#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/* Test1
5
0 1 1 0 0
0 0 1 0 0
0 0 1 0 0
0 0 1 1 0
0 1 1 1 1
4 4
*/

/* Test2
3
0 1 0
1 1 1
0 1 0
1 1
*/

void check_and_add(vector< vector<int> > A, vector< vector<bool> > &Vis, int n, int x, int y, queue< pair<int,int> > &q, int &res){
	if(x<0 || x>=n || y<0 || y>=n || Vis[x][y] == true || A[x][y] != 1)return;

	Vis[x][y] = true;
	res++;
	q.push({x,y});
}

int count_neighbors1(int n, vector< vector<int> > A, int x, int y){
	int res = 0;
	queue< pair<int, int> > q;
	q.push({x, y});

	vector< vector<bool> > Vis(n, vector<bool>(n, false));
	Vis[x][y] = true;

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		check_and_add(A, Vis, n, x+1, y, q, res);
		check_and_add(A, Vis, n, x-1, y, q, res);
		check_and_add(A, Vis, n, x, y+1, q, res);
		check_and_add(A, Vis, n, x, y-1, q, res);
	}

	return res;
}

int get_parent(int a, int* parent){
	if(parent[a] == a)return a;
	else return parent[a] = get_parent(parent[a], parent);
}

void union_set(int a, int b, int* parent){
	int pa = get_parent(a, parent);
	int pb = get_parent(b, parent);
	if(pa==pb)return;
	parent[pb] = pa;
}

void check_and_union(int n, vector< vector<int> > A, int xp, int yp, int x, int y, int* parent){
	if(xp<0 || xp>=n || yp<0 || yp>=n || A[xp][yp] != 1)return;

	union_set(x*n+y, xp*n+yp, parent);
}

int count_neighbors2(int n, vector< vector<int> > A, int xs, int ys){
	int parent[n*n];

	for(int i=0;i<n*n;i++){
		parent[i] = i;
	}

	for(int i=0;i<n*n;i++){
		int x = i/n; // i = x*n + y, y<n
		int y = i - x*n;

		if(A[x][y]==1){
			check_and_union(n, A, x+1, y, x, y, parent);
			check_and_union(n, A, x-1, y, x, y, parent);
			check_and_union(n, A, x, y+1, x, y, parent);
			check_and_union(n, A, x, y-1, x, y, parent);
		}
	}

	int p = get_parent(xs*n+ys, parent);
	int res=0;

	for(int i=0;i<n*n;i++){
		int pp = get_parent(i, parent);
		if(pp == p)res++;
		//cout<<parent[i]<<" ";
	}
	//cout<<endl;

	return res-1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin>>n;

    vector< vector<int> > A(n, vector<int>(n));

    for(int i = 0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>A[i][j];
    	}
    }

    int x,y;

    cin>>x>>y;

    int res1 = count_neighbors1(n, A, x, y);

    int res2 = 0;

    res2 = count_neighbors2(n, A, x, y);
    cout<<res1<<" "<<res2<<endl;
	return 0;
}