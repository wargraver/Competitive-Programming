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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp=head,*prev=head;
        int i,j,n,m,ct=0;
        ListNode *Node1=head,*Node2=head,*prev1=head,*prev2=head;
        while(temp!=NULL){
            temp=temp->next;
            ct++;
        }
        int n1=k,n2=ct-k+1;
        //cout<<n1<<" "<<n2<<endl;
        if(n1==n2) return head;
        temp=head;ct=0;
        while(temp!=NULL){
            ct++;
            if(ct==n1){
                Node1=temp;
                prev1=prev;
            }
            if(ct==n2){
                Node2=temp;
                prev2=prev;
            }
            prev=temp;
            temp=temp->next;
        }
       // cout<<Node1->val<<" "<<Node2->val<<endl;
        if(n1==1){
            j=Node1->val;
            Node1->val=Node2->val;
            Node2->val=j;
        }
        else{
        j=Node1->val;
            Node1->val=Node2->val;
            Node2->val=j;
        }
        return head;
    }
};
