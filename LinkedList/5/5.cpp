#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre=head,*curr,*currTemp,*prev=NULL;
        for(int i=1;i<m-1;i++){
            pre=pre->next;
        }
        if(m!=1)curr=pre->next;
        else curr=pre;
        currTemp=curr;
        for(int i=m;i<=n;i++){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        currTemp->next=curr;
        if(m!=1)pre->next=prev;
        else head=prev;
        return head;
    }

void push(ListNode **head_ref, int new_data) {
  ListNode *new_node = new ListNode;
  new_node->val = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  ListNode* head = NULL;
  int N,m,n;
  cin >>N>>m>>n;
  for (int i = 0; i < N; i++) {
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
  ListNode* x= reverseBetween(head,m,n);
  
      while(x!=NULL){
          cout<<x->val<<" ";
          x=x->next;
      }

  return 0;
}
