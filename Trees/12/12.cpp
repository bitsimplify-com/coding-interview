#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class sample {
public:
    TreeNode* flatten(TreeNode* root) {
        TreeNode* head=root;
       stack<TreeNode*> s;
       while(root && (root->left || root->right || !s.empty())){
           if(root->left){
               if(root->right)s.push(root->right);
               root->right=root->left;
               root->left=NULL;
               root=root->right;
           }
           else{
               if(root->right)root=root->right;
               else{
                   root->right=s.top();
                   s.pop();
                   root=root->right;
               }
           }
       } 
       return head;
    }
};
TreeNode* constructTree(vector<int> nums,int start){
    if(start>=nums.size() || nums[start]==-1)return NULL;
    TreeNode *root=new TreeNode(nums[start]);
    root->left=constructTree(nums,start*2+1);
    root->right=constructTree(nums,start*2 + 2);
    return root;
}
void inorder(TreeNode* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(TreeNode* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    TreeNode* root=constructTree(A,0);
   TreeNode* result=g.flatten(root);
    postorder(result);
    cout<<"\n";
    inorder(result);
    return 0;
}
