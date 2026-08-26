/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int left=max(0,solve(root->left,ans));
        int right=max(0,solve(root->right,ans));
        int curr=max(left,right)+root->val;
        int temp=left+right+root->val;
        ans=max(ans,temp);
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        int ans=-1001;
        solve(root,ans);
        return ans;
    }
};