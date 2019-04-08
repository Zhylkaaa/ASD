#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
struct node
{
    node* next;
    double val;
};
 
node* concatenate(node* head, node* list){
    head->next = list;
    while(head->next != NULL){
        head = head->next;
    }
    return head;
}
 
void sort_list(node* list){
    if(list == NULL)return;
    node* i = list;
    node* j;
    while(i->next!=NULL){
        j = list->next;
        while(j!=NULL){
            if(i->val > j->val){
                swap(i->val, j->val);
            }
            j = j->next;
        }
        i = i->next;
    }
}
 
void bucket_sort(node* head, int k){
    if(head->next == NULL)return;
    int n = k*10;
 
    node* lists[n];
 
    for(int i = 0;i<n;i++){
        lists[i] = NULL;
    }
 
    node* item = head->next;
 
    while(item!=NULL){
        int num = item->val * n;
 
        node* tmp = item;
        item = item->next;
        tmp->next = lists[num];
        lists[num] = tmp;
    }
 
    head->next = NULL;
 
    for(int i = 0;i<n;i++){
        sort_list(lists[i]);
    }
 
    item = head;
    for(int i = 0;i<n;i++){
        item = concatenate(item, lists[i]);
    }
 
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    node* head = new node;
    head->next = NULL;
    int n;
    cin>>n;
 
    int k = 10;
 
    for(int i = 0;i<n;i++){
        node* tmp = new node;
        cin>>tmp->val;
        tmp->next = head->next;
        head->next = tmp;
    }
 
    bucket_sort(head, k);
 
    while(head!=NULL){
        node* tmp = head;
        head=head->next;
        cout<<tmp->val<<" ";
        delete tmp;
    }
 
    return 0;
}