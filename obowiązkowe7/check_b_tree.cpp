#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define N 3

struct Node{
	int n; // liczba kluczy zawarta w węźle
	int key[N]; // tablica kluczy w węźle
	Node* child[N+1] // wskaźniki do synów węzła
	bool leaf; // czy węzeł jest liściem
};

bool valid_key(int key, int a, int b, bool corner){
	if(corner){
		if(a==-1){
			return key < b;
		} else {
			return key > a;
		}
		return true;
	} else {
		return key > a && key < b;
	}
}

bool is_b_tree(Node* tree, int h, int &lh, int a, int b, bool corner){
	if(tree == NULL)return false;

	if(h==0){
		for(int i = 1;i<n;i++){
			if(key[i-1]>key[i])return false;
		}
	}

	if(tree->leaf){
		if(hl == -1){
			hl = h;
		}
		return hl == h;
	}

	bool valid;

	if(h != 0 && n < N/2)return false; // n+1 child, (N+1) max child, ceil(N+1) = (N+2)/2 = floor(N/2) + 1

	for(int i=0;i<n+1;i++){
		if(i==0){
			if(h!=0 && !valid_key(tree->key[i], a, b, corner))return false;
			valid = is_b_tree(tree->child[i], h+1, lh, -1, tree->key[i], true);
		}
		if(i==n){
			if(h!=0 &&!valid_key(tree->key[i], a, b, corner))return false;
			valid = is_b_tree(tree->child[i], h+1, lh, tree->key[i-1], -1, true);
		}

		if(i!=0 && i!=n-1){
			if(h!=0 &&!valid_key(tree->key[i], a, b, corner))return false;
			if(tree->key[i-1] > tree->key[i])return false;
			valid = is_b_tree(tree->child[i], h+1, lh, tree->key[i-1], tree->key[i], false);
		}
		if(!valid)return false;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Node* root; // mamy drzewo :) // TODO: B-tree insertion

    cout<<is_b_tree(root, 0, -1, -1, -1, true)<<endl;	
	return 0;
}