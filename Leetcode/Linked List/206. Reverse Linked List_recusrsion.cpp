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
ListNode* rev(ListNode* prev,ListNode* curr){
     if(curr==NULL) return prev;
     else{
          ListNode *temp2=curr->next;
         curr->next=prev;
         ListNode *temp=rev(curr,temp2);
         return temp;
     }
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return rev(NULL,head);
    }
};
