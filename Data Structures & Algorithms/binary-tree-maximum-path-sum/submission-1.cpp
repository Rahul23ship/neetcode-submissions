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
    int maxim=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        return max(maxim,maxi(root));
    }
    int maxi(TreeNode*root){
        if(!root)return 0;
        int left=max(0,maxi(root->left));
        int right=max(0,maxi(root->right));
        int val=left+right+root->val;
        maxim=max(maxim,val);
        return root->val+max(left,right);
    }
};
