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
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);         
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pleft,int pright,int left,int right){
        if(left>right|| pleft>pright)return nullptr;
        int rootval=preorder[pleft];
        TreeNode* root=new TreeNode(rootval);
        int rootind=mp[rootval];
        int leftsize=rootind-left;
        root->left=build(preorder,inorder,pleft+1,pleft+leftsize,left,rootind-1);
        root->right=build(preorder,inorder,pleft+leftsize+1,pright,rootind+1,right);
        return root;
    }

};
