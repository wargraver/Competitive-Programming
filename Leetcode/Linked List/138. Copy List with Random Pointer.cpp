/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *head2=(Node*)malloc(sizeof(Node));
        Node *temp2=head,*temp3=head2;
        if(head==NULL) return NULL;
        while(temp2!=NULL){
            temp3->val=temp2->val;
            temp3->next=temp2->next;
            temp2->next=temp3;
            temp3->random=temp2->random;
            temp2=temp3->next;
            temp3=(Node*)malloc(sizeof(Node));
        }
        temp2=head;
        temp3=head2;
        while(temp3!=NULL){
           // if(temp2->next!=NULL) temp2=temp2->next->next;
            if(temp3->random!=NULL) temp3->random=temp3->random->next;
            if(temp3->next==NULL) break;
            else temp3=temp3->next->next;
        }
        temp2=head;
        temp3=head2;
        while(temp2!=NULL){
        if(temp2->next!=NULL) temp2->next=temp2->next->next;
        if(temp3->next!=NULL) temp3->next=temp3->next->next;
        temp2=temp2->next;
        temp3=temp3->next;
        }
        return head2;
    }
};
