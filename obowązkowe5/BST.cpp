#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct Node {
	int key;
	int left_size;
	int right_size;
	Node* left;
	Node* right;
	Node* parent;
};

Node* init_Node(int key){
	Node* tree = new Node;

	tree->key = key;
	tree->left_size = 0;
	tree->right_size = 0;
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;

	return tree;
}

void delete_BST(Node* tree){
	if(tree == NULL)return;
	if(tree->left != NULL){
		delete_BST(tree->left);
	}

	if(tree->right != NULL){
		delete_BST(tree->right);
	}

	delete tree;
	tree = NULL;
}

Node* find_kth(Node* tree, int k){
	if(tree == NULL)return NULL;
	if(k == tree->left_size + 1)return tree;

	if(k > tree->left_size){
		return find_kth(tree->right, k - tree->left_size - 1);
	} else {
		return find_kth(tree->left, k);
	}
}

Node* insert_Node(Node* tree, int key){
	if(tree == NULL){
		tree = init_Node(key);
		return tree;
	}

	if(tree->key > key){
		tree->left = insert_Node(tree->left, key);
		(tree->left_size)++;
	} else {
		tree->right = insert_Node(tree->right, key);
		(tree->right_size)++;
	}

	return tree;
}

int find_index(Node* tree, int key){
	if(tree == NULL)return -1;

	if(tree->key == key)return tree->left_size+1;

	if(tree->key > key){
		return find_index(tree->left, key);
	} else {
		// (tree->right_size != 0) returns 1 or 0 depending on condition is true or false respectively
		return find_index(tree->right, key) + ((tree->left_size + 1)*(tree->right_size > 0));
	}
}

void print_tree(Node* tree){
	if(tree == NULL)return;

	print_tree(tree->left);
	cout<<tree->key<<" ";
	print_tree(tree->right);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Node* tree = NULL;

    int n;
    cin>>n;

    for(int i = 0;i<n;i++){
    	int k;
    	cin>>k;
    	tree = insert_Node(tree, k);
    }

    print_tree(tree);
    cout<<endl;

    int q;
    cin>>q;

    for(int i = 0;i<q;i++){
    	int t, k;
    	cin>>t>>k;

    	// t == 0 find k-th smallest, t == 1 find @key position in sorted array
    	if(t==0){
    		Node* res = find_kth(tree, k);
    		if(res != NULL){
    			cout<<res->key<<endl;
    		} else {
    			cout<<"Index "<<k<<" is to high"<<endl;
    		}
    	} else {
    		int index = find_index(tree, k);
    		if(index != -1){
    			cout<<index<<endl;
    		} else {
    			cout<<"No such Node with key = "<<k<<endl;
    		}
    	}
    }

    delete_BST(tree);

	return 0;
}