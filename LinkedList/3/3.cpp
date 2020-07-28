#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

vector<ListNode*> splitList(ListNode* root, int k) {
        vector<ListNode*> res(k,nullptr);
        ListNode* head=root;
        int l=0;
        while(root!=NULL){l++;root=root->next;};
        int Q=l/k,R=l%k;
        root=head;
        for(int i=0;i<k && root;i++){
            res[i]=root;
            for(int j=1;j<Q+(i<R);j++) root=root->next;
            ListNode* next=root->next;
            root->next=NULL;
            root=next;
        }
        return res;
    }

void push(ListNode **head_ref, int new_data) {
  ListNode *new_node = new ListNode;
  new_node->val = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  ListNode* head = NULL;
  int n,k;
  cin >>n>>k;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    push(&head, j);
  }
  ListNode* prev=NULL;
  while(head!=NULL){
      ListNode* temp=head->next;
      if(!prev){
          head->next=NULL;
      }
      else
      head->next=prev;
      prev=head;
      head=temp;
  }
  head=prev;
  vector<ListNode*> result= splitList(head,k);
  for(auto x:result){
      while(x!=NULL){
          cout<<x->val<<" ";
          x=x->next;
      }
      cout<<"\n";
  }

  return 0;
}
