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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>v;
        stringstream ss(data);
        string token;
        while(getline(ss,token,','))v.push_back(token);
        int i=0;
        return build(v,i);
    }
    TreeNode* build(vector<string>v,int &i){
        if(v[i]=="#"){
            i++;
            return nullptr;
        }
        int val=stoi(v[i]);
        TreeNode* root=new TreeNode(val);
        i++;
        root->left=build(v,i);
        root->right=build(v,i);
        return root;
    }
};
