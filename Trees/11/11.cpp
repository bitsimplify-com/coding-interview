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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)return result;
        TreeNode* current=root;
        while(current){
            if(!current->right){
                result.push_back(current->val);
                current=current->left;
            }
            else{
                TreeNode* temp=current->right;
                while(temp->left && temp->left!=current)temp=temp->left;
                if(!temp->left){
                    result.push_back(current->val);
                    temp->left=current;
                    current=current->right;
                }
                else{
                    temp->left=NULL;
                    current=current->left;
                }
            }
        }
        reverse(result.begin(),result.end());
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
    vector<int> result=g.postorderTraversal(root);
    for(auto x:result) cout<<x<<" ";
    return 0;
}
