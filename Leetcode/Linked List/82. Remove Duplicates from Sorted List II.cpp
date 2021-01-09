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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> dict;
        ListNode *temp=head,*prev=head;int ct=0;
        while(temp!=NULL){
            dict[temp->val]++;
            temp=temp->next;
            ct++;
        }
        temp=head;
        if(head==NULL) return NULL;
        if(ct==dict[head->val] && ct!=1) return NULL;
        int flag=0;
        while(temp!=NULL){
            if(dict[temp->val]==1) {flag=1;head=temp;break;}
            temp=temp->next;
        }
        if(flag==0) return NULL;
        temp=head;prev=head;
        while(temp!=NULL){
            if(dict[temp->val]==1) {prev=temp;temp=temp->next;}
            else{
                prev->next=temp->next;
                temp=temp->next;
            }
        }
        return head;
    }
};
