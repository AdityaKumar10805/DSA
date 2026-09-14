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
    int solve(TreeNode *root,unordered_map<TreeNode *,int>&mp){
        if(root==NULL){
            return 0;
        }
        if(mp.count(root)){
            return mp[root];
        }
        int case1=root->val;
        if(root->left!=NULL){
             case1+=solve(root->left->left,mp)+solve(root->left->right,mp);
        }
        if(root->right!=NULL){
            case1+=solve(root->right->left,mp)+solve(root->right->right,mp);
        }
        int case2;
        case2=solve(root->left,mp)+solve(root->right,mp);
        return mp[root]=max(case1,case2);
        
        
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *,int>mp;
        return solve(root,mp);
    }
};