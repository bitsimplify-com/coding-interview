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
    vector<int> preorderIterative(TreeNode* A) {
        TreeNode* current=A;
    vector<int> result;
    while(current){
        if(!current->left){
            result.push_back(current->val);
            current=current->right;
        }
        else{
            TreeNode* p=current->left;
            while(p->right && p->right!=current)p=p->right;
            if(p->right){
                current=current->right;
                p->right=NULL;
            }
            else{
                result.push_back(current->val);
                p->right=current;
                current=current->left;
            }
        }
    }
    return result;
    }
};
TreeNode* constructTree(vector<int> nums,int start){
    if(start>=nums.size() || nums[start]==-1)return NULL;
    TreeNode *root=new TreeNode(nums[start]);
    root->left=constructTree(nums,start*2+1);
    root->right=constructTree(nums,start*2 + 2);
    return root;
}
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
     TreeNode* root=constructTree(A,0);
    vector<int> result=g.preorderIterative(root);
    for(auto x:result)cout<<x<<" ";
    return 0;
}
