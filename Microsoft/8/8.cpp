#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
};
int findSecondLastNode(struct Node *head) {
  struct Node *temp = head;
  if (temp == NULL || temp->next == NULL)
    return -1;
  while (temp != NULL) {
    if (temp->next->next == NULL)
      return temp->data;
    temp = temp->next;
  }
}

void push(struct Node **head_ref, int new_data) {
  Node *new_node = new Node;
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  struct Node *head = NULL;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    push(&head, j);
  }

  cout << findSecondLastNode(head);

  return 0;
}
