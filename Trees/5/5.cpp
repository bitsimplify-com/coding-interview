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
    int moves;
    int traverse(TreeNode* root){
        if(!root)return 0;
        int left=traverse(root->left);
        int right=traverse(root->right);
        moves+=abs(left)+abs(right);
        return root->val - 1 + left + right; 
    }
    int distributeCoins(TreeNode* root) {
        moves=0;
        int x=traverse(root);
        return moves;
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
    int n,x;
    cin >>n>>x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    TreeNode* root=constructTree(nums,0);
    cout<<g.distributeCoins(root);
    return 0;
}
