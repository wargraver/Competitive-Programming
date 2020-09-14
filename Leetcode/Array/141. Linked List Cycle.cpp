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
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;int ct=0;int flag=0;
        while(flag==0){
            if(slow==fast && ct!=0) return true;
            if(slow==NULL) return false;
            else{
                slow=slow->next;
                if(slow==NULL) return false;
                else if(fast==NULL || fast->next==NULL) return false;
                fast=fast->next->next;
                ct++;
            }
        }
        return true;
    }
};
