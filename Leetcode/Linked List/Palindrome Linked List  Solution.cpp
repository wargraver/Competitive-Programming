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
ListNode *reversed_head;
ListNode* reverse_list(ListNode *temp){
        if(temp->next==NULL) return reversed_head = temp;
        ListNode *parent = reverse_list(temp->next);
        parent->next = temp;
        return temp;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int i,j,k,n,m,ct=0;
        if(head==NULL) return true;
        ListNode *head2 = new ListNode(head->val,NULL);
        ListNode *prev=head2;
        ListNode *temp=head->next;
        while(temp!=NULL){
            ListNode *temp2 = new ListNode(temp->val,NULL);
            prev->next = temp2;
            prev = temp2;
            temp=temp->next;
        }
        ListNode *head3 = reverse_list(head2);
        head2->next=NULL;
        temp = reversed_head;prev = head;
        while(temp!=NULL){
            if(prev->val!=temp->val) return false;
            prev=prev->next;
            temp = temp->next;
        }
        return true;
    }
};
