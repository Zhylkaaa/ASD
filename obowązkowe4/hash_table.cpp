// TODO: implement reorganization 

#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct element{
	int key;
	int data = 0;
	bool used = false;
};

struct HashTable{
	int N;
	element* elements;

	int hash(int n){
		return n%N;
	}
};

HashTable* initHashTable(int n){
	HashTable* m = new HashTable;
	m->N = 2*n;
	m->elements = new element[m->N];
	return m;
}

void insert_element(HashTable* m, int key){
	int f = m->hash(key);
	//cout<<f<<endl;
	while(m->elements[f].used && m->elements[f].key != key)f = m->hash(f+1);
	if(!m->elements[f].used){
		m->elements[f].data = 1;
		m->elements[f].used = true;
		m->elements[f].key = key;
	} else {
		m->elements[f].data += 1;
	}
}

void delete_element(HashTable* m, int key){
	int f = m->hash(key);
	while(m->elements[f].used && m->elements[f].key != key)f = m->hash(f+1);

	if(m->elements[f].used){
		m->elements[f].used = false;
	}
}

element find(HashTable* m, int key){
	int f = m->hash(key);
	while(m->elements[f].used && m->elements[f].key!=key)f = m->hash(f+1);
	if(!m->elements[f].used){
		m->elements[f].data = 0;
	} 
	return m->elements[f];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n;

	cin>>n;

	HashTable* m = initHashTable(n);

	for(int i = 0;i<n;i++){
		int k, t;
		cin>>k>>t;
		// k == 0 wstawianie, k == 1 usówanie, k == 2 ilość dannych elementów

		if(k == 0){
			insert_element(m, t);
		} else if(k == 1){
			delete_element(m, t);
		} else {
			element it = find(m, t);
			cout<<it.data<<endl;
		}
	}

	return 0;
}