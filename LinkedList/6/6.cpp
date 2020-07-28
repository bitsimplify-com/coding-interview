#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=new ListNode(0),*fast=head,*slowHead=slow;
        slow->next=head;
        while(n--){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return slowHead->next;
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
  ListNode* x= removeNthFromEnd(head,m);
  
      while(x!=NULL){
          cout<<x->val<<" ";
          x=x->next;
      }

  return 0;
}
