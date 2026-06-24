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
    void countgood(TreeNode* root,int * count,int max){
        if(max<=root->val){
            (*count)++;
            max=root->val;
        }
        if(root->left)countgood(root->left,count,max);
        if(root->right)countgood(root->right,count,max);
    }
public:
    int goodNodes(TreeNode* root) {
        int max=root->val;
        int count=0;
        countgood(root,&count,max);
        return count;
    }
};
