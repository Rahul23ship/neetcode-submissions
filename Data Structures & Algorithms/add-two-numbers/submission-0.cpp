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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode ans(0);
        ListNode* final=&ans;
        
        int temp=0;
        while(curr1!=NULL || curr2!=NULL || temp!=0){
            int sum=temp;
            if(curr1!=NULL){
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2!=NULL){
                sum+=curr2->val;
                curr2=curr2->next;   
            }
            temp=sum/10;
        
            final->next=new ListNode(sum%10);
            final=final->next;
        }
        return ans.next;
    }
};
