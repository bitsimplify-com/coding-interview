#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int n=0;
        ListNode* tHead=head;
        while(head->next){head=head->next;n++;}
        n++;
        k=k%n;
        if(!k)return tHead;
        head->next=tHead;
        head=tHead;
        k=n-k;
        while(--k)head=head->next;
        tHead=head->next;
        head->next=NULL;
        return tHead;
    }

void push(ListNode **head_ref, int new_data) {
  ListNode *new_node = new ListNode;
  new_node->val = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  ListNode* head = NULL;
  int n,m;
  cin >>n>>m;
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
  ListNode* x= rotateRight(head,m);
  
      while(x!=NULL){
          cout<<x->val<<" ";
          x=x->next;
      }

  return 0;
}
