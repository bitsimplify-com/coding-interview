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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
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
     cin>>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    TreeNode* root=constructTree(A,0);
     cout<<g.isValidBST(root);
    return 0;
}
