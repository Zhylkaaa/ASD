#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
struct element{
    int key;
    int data = 0;
    element* next;
};
 
struct HashTable{
    int N;
    element** elements;
 
    int hash(int n){
        return n%N;
    }
};
 
HashTable* initHashTable(int n){
    HashTable* m = new HashTable;
    m->N = 2*n;
    m->elements = new element*[m->N];
    for(int i = 0;i<m->N;i++)m->elements[i]=NULL;
    return m;
}
 
void insert_element(HashTable* m, int key){
    int f = m->hash(key);
   
    if(m->elements[f] != NULL){
        element* e = m->elements[f];
        while(e != NULL && e->key != key)e = e->next;
        if(e == NULL){
            e = new element;
            e->key = key;
            e->data = 1;
            e->next = m->elements[f];
            m->elements[f] = e;
        } else {
            (e->data)++;
        }
    } else {
        element* e = new element;
        e->next = NULL;
        e->key = key;
        e->data = 1;
        m->elements[f] = e;
    }
}
 
void delete_element(HashTable* m, int key){
    int f = m->hash(key);
    element* e = m->elements[f];
    element* prev = NULL;
 
    while(e != NULL && e->key != key){
        prev = e;
        e = e->next;
    }
 
    if(e != NULL && prev == NULL){
        m->elements[f] = e->next;
        delete e;
    } else if(e!=NULL){
        prev->next = e->next;
        delete e;
    }
}
 
element* find(HashTable* m, int key){
    int f = m->hash(key);
    element* e = m->elements[f];
    while(e != NULL && e->key != key)e=e->next;
 
    return e != NULL ? e : NULL;
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
            element* it = find(m, t);
            if(it != NULL){
                cout<<it->data<<endl;
            } else {
                cout<<0<<endl;
            }
        }
    }
 
    return 0;
}