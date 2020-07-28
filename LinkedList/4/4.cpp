#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reorderList(ListNode* head) {
        if(!head)return head;
        ListNode* h1=head,*h2=head->next;
        while(h2 && h2->next){
            h1=h1->next;
            h2=h2->next->next;
        }
        ListNode *t1=h1->next;
        h1->next=NULL;
        ListNode *prev=NULL;
        while(t1!=NULL){
            ListNode* temp=t1->next;
            t1->next=prev;
            prev=t1;
            t1=temp;
        }
        ListNode* T=prev;
        h1=head;
        while(head && T){
            ListNode* temp1=head->next;
            ListNode* temp2=T->next;
            head->next=T;
            T->next=temp1;
            head=temp1;
            T=temp2;
        }
        return h1;
    }

void push(ListNode **head_ref, int new_data) {
  ListNode *new_node = new ListNode;
  new_node->val = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  ListNode* head = NULL;
  int n;
  cin >>n;
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
  ListNode* x= reorderList(head);
  
      while(x!=NULL){
          cout<<x->val<<" ";
          x=x->next;
      }

  return 0;
}
