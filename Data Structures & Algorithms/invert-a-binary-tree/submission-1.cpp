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
void reverse(TreeNode* curr){
    if(curr->left==NULL && curr->right==NULL){
        return;
    }
    if(curr->left!=NULL)reverse(curr->left);
    if(curr->right!=NULL)reverse(curr->right);
    TreeNode* temp=curr->left;
    curr->left=curr->right;
    curr->right=temp;
    return;
}
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root!=NULL)
        reverse(root);
        return root;
    }
};
