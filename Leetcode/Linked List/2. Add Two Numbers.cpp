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
        int i,j,k,n,m,ct1=0,ct2=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;int flag=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            ct1++;
        }
        while(temp2!=NULL){
            temp2=temp2->next;
            ct2++;
        }
        //cout<<ct1<<" "<<ct2<<endl;
        if(ct2>=ct1){
            temp1=l2;
            temp2=l1;
            flag=1;
        }
        else{
            temp1=l1;
            temp2=l2;
        }
        int carry=0;ListNode *prev,*head=temp1;
        while(temp1!=NULL){
            if(temp2==NULL){
                int val=temp1->val+carry;
                if(val>=10) carry=1;
                else carry=0;
                temp1->val=val%10;
            }
            else{
                int val=temp1->val+carry+temp2->val;
                if(val>=10) carry=1;
                else carry=0;
                temp1->val=val%10;
                temp2=temp2->next;
            }
            prev=temp1;
            temp1=temp1->next;
        }
        if(carry==1){
            if(flag==1) temp1=l1;
            else temp1=l2;
            temp1->val=1;
            temp1->next=NULL;
           prev->next=temp1;
        }
        return head;
    }
};
