#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/* Algorithm:

In this problem we can use 0/1 knapsack dynamick https://en.wikipedia.org/wiki/Knapsack_problem
Main idea of algorithm is to decide wether to take next and curent tree, curent, or skip this tree

F(n) - maximum sum that we can make using first n elements of sequence

Base cases:

if we have 1 tree it's alwase optimal to take it
if we have 2 trees we can take them bouse

Prove:

assume we know how to solve F(n), F(n-1), F(n-2) .......
we want to know how to solve F(n+1)

- Observation:
	our decision wether to take the n-th element or not lead us to problem that we alredy can solve 

so F(n+1) = max{ F(n), // we skip this tree
				 F(n-1) + c(n+1), // we take this tree but skip tree from the left
				 F(n-2) + c(n+1) + c(n) } // we take this and left tree, and skip next from the left('couse we can't take 3 in a row)
*/

int calculate_cost(int n, vector<int> &c, vector<int> &DP){
	if(DP[n]!=-1)return DP[n];
	return DP[n] = max(calculate_cost(n-3, c, DP) + c[n] + c[n-1], max(calculate_cost(n-2, c, DP)+c[n], calculate_cost(n-1, c, DP)));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> c(n+1); // cost vector

	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}


	vector<int> DP(n+1, -1);
	DP[0] = 0;
	DP[1] = c[1];
	DP[2] = c[1] + c[2];

	int res = calculate_cost(n, c, DP);

	cout<<res<<endl;

	return 0;
}