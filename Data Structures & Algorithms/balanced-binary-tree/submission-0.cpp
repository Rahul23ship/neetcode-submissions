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
int findl(TreeNode* curr,bool* ans){
    if(!curr) return 0;
    int l=findl(curr->left,ans);
    int r=findl(curr->right,ans);
    if(abs(l-r)>1)*ans=false;
    if(!ans)return 0;
    return max(r,l)+1;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool ans=true;
        findl(root,&ans);
        return ans;
    }
};
