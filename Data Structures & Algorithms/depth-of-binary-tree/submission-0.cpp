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
int findl(TreeNode* curr,int length){
    if(!curr)return 0;

    int len=length+max(findl(curr->left,length),findl(curr->right,length));
    return len;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int length=1;
        length=findl(root,length);
        return length;
    }
};
