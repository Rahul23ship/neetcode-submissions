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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        if(len==n){
            return head->next;
        }
        len=len-n-1;
        curr=head;
        while(len--){
            curr=curr->next;
        }
        ListNode* temp=curr->next;
        curr->next=temp->next;
        
        return head;
    }
};
