#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* partition(ListNode* head, int x) {
        ListNode* head1=new ListNode(0);
        ListNode* head2=new ListNode(0);
        ListNode* res=head1,*temp=head2;
        while(head!=NULL){
            if(head->val<x){
                head1->next=new ListNode(head->val);
                head1=head1->next;
            }
            else{
                head2->next=new ListNode(head->val);
                head2=head2->next;
            }
            head=head->next;
        }
        head2->next=NULL;
        head1->next=temp->next;
        return res->next;
    }

void push(ListNode **head_ref, int new_data) {
  ListNode *new_node = new ListNode;
  new_node->val = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  ListNode* head = NULL;
  int n,x;
  cin >> n>>x;
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
  ListNode* result= partition(head,x);
  while(result!=NULL){
      cout<<result->val<<" ";
      result=result->next;
  }

  return 0;
}
