#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeZero(ListNode *head) {
  unordered_map<int,ListNode*> umap;
        ListNode* root=new ListNode(0);
        root->next=head;
        umap[0]=root;
        int sum=0;
        while(head!=NULL){
            sum+=head->val;
            if(umap.find(sum)!=umap.end()){ 
                ListNode* prev=umap[sum];
                ListNode* start=prev;
                int delVal=sum;
                while(prev!=head){
                    prev=prev->next;
                    delVal+=prev->val;
                    if(prev!=head)
                    umap.erase(delVal);
                }
                start->next=head->next;
            }
            else{
                umap[sum]=head;
            }
            head=head->next;
        }
        return root->next;
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
  cin >> n;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    push(&head, j);
  }

  ListNode* result= removeZero(head);
  while(result!=NULL){
      cout<<result->val<<" ";
      result=result->next;
  }

  return 0;
}
