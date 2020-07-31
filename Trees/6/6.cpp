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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)return result;
        TreeNode* current=root;
        while(current){
            if(!current->left){
                result.push_back(current->val);
                current=current->right;
            }
            else{
                TreeNode* p=current->left;
                while(p->right && p->right!=current)p=p->right;
                if(!p->right){
                    p->right=current;
                    current=current->left;
                }
                else {
                    p->right=NULL;
                    result.push_back(current->val);
                    current=current->right;
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
     TreeNode* root=constructTree(nums,0);
    vector<int> result=g.inorderTraversal(root);
    for(auto x:result)cout<<x<<" ";
    return 0;
}
