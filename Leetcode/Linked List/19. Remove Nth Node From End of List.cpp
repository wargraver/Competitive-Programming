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
        ListNode *first=head,*nthnode=head,*prev=head;
        int ct=1;
        while(ct!=n){
            nthnode=nthnode->next;
            ct++;
        }
        while(nthnode->next!=NULL){
            nthnode=nthnode->next;
            prev=first;
            first=first->next;
        }
        if(first==head) return head->next;
        prev->next = first->next;
        return head;
    }
};
