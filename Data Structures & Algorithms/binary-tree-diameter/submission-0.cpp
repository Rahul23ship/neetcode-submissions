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
int findl(TreeNode* curr, int* d){
    if(!curr) return 0;
    int hieght=0,l=0,r=0;
    if(curr->left)l=findl(curr->left,d)+1;
    if(curr->right)r=findl(curr->right,d)+1;
    hieght=max(l,r); 
    *d=max(*d,l+r);
    return hieght;
    
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int d=0;
        findl(root,&d);
        return d;
        
    }
};
