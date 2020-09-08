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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*temp1=l1,*temp2=l2,*temp3;int ct=0;
        if(l1!=NULL && l2!=NULL){
       if(temp1->val>=temp2->val){
           head=temp2;temp2=temp2->next;
           head->next=NULL;
       }
        else{
            head=temp1;temp1=temp1->next;
           head->next=NULL;
        }
        temp3=head;
        int flag=1;
        while(flag==1){
            if(temp1==NULL || temp2==NULL) break;
            else{
           if(temp1->val>=temp2->val){
           temp3->next=temp2;
           temp2=temp2->next;temp3->next->next=NULL;
             }
        else{
            temp3->next=temp1;
           temp1=temp1->next;temp3->next->next=NULL;
           }
                temp3=temp3->next;
            }
            }
        }
        else if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        if(temp1==NULL && temp2!=NULL) temp3->next=temp2;
        else if(temp2==NULL && temp1!=NULL) temp3->next=temp1;
        return head;
    }
};
