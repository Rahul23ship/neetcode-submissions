/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode *a=head;
        int len=0;
        while(a!=NULL){
            st.push(a);
            a=a->next;
            len++;
        }
        len=len/2;
        a=head;
        while(len--){
            ListNode* temp=st.top();
            temp->next=a->next;
            a->next=temp;
            st.pop();
            a=temp->next;
        }
        a->next=NULL;
    }
};
