#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// TODO: free memory :)

//#define DEBUG

// Test 1
/*
20
26
17
41
14
21
30
47
10
16
19
23
28
38
7
12
15
20
35
39
3
*/

// Test 2
/*
9
12
7
14
6
9
13
15
8
10
*/

// Test 3
/*
5
6
10
8
7
11
*/

struct Node {
	int w;
	char color;
	int black_quota;
	int min_h;
	int h;
	Node* left;
	Node* right;
};

Node* create_node(int w){
	Node* node = new Node;
	node->w = w;
	node->left = NULL;
	node->right = NULL;
	node->min_h = 0;
	node->h = 0;
	node->color = 'h'; // h bo chuj wie jaki kolor
	return node;
}

void insert(Node* &tree, int w){
	if(tree == NULL){
		tree = create_node(w);
		return;
	}

	if(w > tree->w){
		if(tree->right == NULL){
			tree->right = create_node(w);
		} else {
			insert(tree->right, w);
		}
	} else {
		if(tree->left == NULL){
			tree->left = create_node(w);
		} else {
			insert(tree->left, w);
		}
	}
}

void height_count(Node* tree){
	if(tree == NULL)return;
	if(tree->left == NULL && tree->right == NULL)return;
	height_count(tree->left);
	height_count(tree->right);

	if(tree->left != NULL){
		tree->h = tree->left->h + 1;
	}

	if(tree->right != NULL){
		if(tree->h < tree->right->h + 1){
			tree->h = tree->right->h + 1;
		}
	}

	if(tree->right != NULL && tree->left != NULL){
		tree->min_h = min(tree->right->min_h, tree->left->min_h) + 1;
	} else tree->min_h = 0;

	#ifdef DEBUG
	cout<<tree->w<<" "<<tree->h<<" "<<tree->min_h<<endl;
	#endif
}

bool color_tree(Node* tree, int black_quota, char parent_color){
	if(tree==NULL){
		if(parent_color == 'r'){
			return black_quota == -1;
		} else {
			return black_quota == 0;
		}
	}
	if(tree->color != 'h'){
		return color_tree(tree->left, black_quota, tree->color) 
			&& color_tree(tree->right, black_quota, tree->color);
	}

	if(parent_color == 'r'){
		tree->color = 'b';
		return color_tree(tree->left, black_quota, tree->color) 
			&& color_tree(tree->right, black_quota, tree->color);
	} else {
		int new_quota = black_quota - 1;
		if(tree->min_h < new_quota)return false;
		if(tree->h - 1 <= 2*new_quota)tree->color = 'b';
		else tree->color = 'r';

		return color_tree(tree->left, new_quota, tree->color) 
			&& color_tree(tree->right, new_quota, tree->color);
	}
}

void print_tree(Node* tree){
	if(tree==NULL)return;

	print_tree(tree->left);
	print_tree(tree->right);
	cout<<tree->w<<" "<<tree->color<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    Node* root = NULL;

    for(int i=0;i<n;i++){
    	int k;
    	cin>>k;
    	insert(root, k);
    }

    height_count(root);
    root->color = 'b';

    bool done = color_tree(root, (root->h) / 2, 'h');
    if(!done){
    	cout<<"NO";
    } else {
    	print_tree(root);
    }

	return 0;
}