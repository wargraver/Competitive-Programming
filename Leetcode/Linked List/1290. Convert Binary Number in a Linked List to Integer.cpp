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
    int getDecimalValue(ListNode* head) {
        int ct=0;
        ListNode *temp =head;
        while(temp!=NULL){
            ct++;
            temp=temp->next;
        }
        int ans=0;
        temp=head;int kt=0;
        while(temp!=NULL){
            if(temp->val!=0){
                ans+=pow(2,ct-1);
            }
            temp=temp->next;
            ct--;
        }
        return ans;
    }
};
