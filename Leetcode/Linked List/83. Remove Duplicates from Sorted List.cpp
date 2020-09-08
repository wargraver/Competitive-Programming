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
        ListNode *temp1=head,*temp2=head,*temp3=head;int flag=0;
        while(temp1!=NULL){
            if(temp2->val!=temp1->val){
                cout<<temp2->val<<" "<<temp1->val<<endl;
                temp2->next=temp1;
                temp2=temp1;
                //temp1=temp1->next;
            }
            else {
                temp1=temp1->next;
                temp2->next=NULL;
            }
        }
        return head;
    }
};
