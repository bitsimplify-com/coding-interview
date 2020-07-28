#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *dummy=new ListNode(0),*prev=dummy;
        dummy->next=head;
        while(head){
            if(head->next && head->next->val==head->val){
                ListNode *temp=head;
                while(temp->next && temp->next->val==temp->val)temp=temp->next;
                temp=temp->next;
                prev->next=temp;
                head=temp;
            }
            else{
                prev=head;
                head=head->next;
            }
        }
        return dummy->next;
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
  ListNode* x= deleteDuplicates(head);
  
      while(x!=NULL){
          cout<<x->val<<" ";
          x=x->next;
      }

  return 0;
}
