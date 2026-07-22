/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*,Node*>mp;
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        mp.clear();
        Node* clone=new Node(node->val);
        mp[node]=clone;
        make(clone,node);
        return clone;
    }
    void make(Node* clone,Node* node){
        for(Node* n:node->neighbors){
            if(mp.find(n)==mp.end()){
                Node* temp=new Node(n->val);
                mp[n]=temp;
                clone->neighbors.push_back(temp);
                make(temp,n);
            }
            else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
};
