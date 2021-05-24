/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return NULL;
        ListNode *slow=head,*fast=head;
        int flag=0;
        while(flag==0){
            if(fast->next==NULL || fast->next->next==NULL) break;
            else{
                    fast = fast->next->next;
                    slow = slow->next;
                 if(fast==slow) {flag=1;break;}
            }
        }
       // cout<<slow->val<<" "<<fast->val<<endl;
        if(flag==0) return NULL;
        slow = head;
        cout<<slow->val<<endl;
        //return NULL;
        while(slow!=fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
