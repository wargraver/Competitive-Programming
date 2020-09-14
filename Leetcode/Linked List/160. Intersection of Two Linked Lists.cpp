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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ct1=0,ct2=0,i,j,k,n,m;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1!=NULL){
            temp1=temp1->next;
            ct1++;
        }
        while(temp2!=NULL){
           temp2=temp2->next;
           ct2++;
        }
        temp1=headA;temp2=headB;
        if(ct1>ct2){
            int ct=ct1-ct2;temp1=headA;
            while(ct!=0){
                temp1=temp1->next;
                ct--;
            }
        }
        else if(ct2>ct1){
             int ct=ct2-ct1;temp2=headB;
            while(ct!=0){
                temp2=temp2->next;
                ct--;
            }
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
};
