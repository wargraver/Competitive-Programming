typedef pair<int, int> pd;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int n;n=lists.size();
        priority_queue<pd, vector<pd>,greater<pd>> q;
        ListNode *head=NULL,*temp;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL) q.push(make_pair(lists[i]->val,i));
        }
        if(q.size()==0) return NULL;
        pair<int,int> it=q.top();
        head=lists[it.second];
        lists[it.second]=lists[it.second]->next;
        q.pop();
        if(lists[it.second]!=NULL) q.push(make_pair(lists[it.second]->val,it.second));
        temp=head;
        while(q.empty()==false){
        pair<int,int> it=q.top();
        temp->next=lists[it.second];
      //  cout<<it.second<<" "<<lists[it.second]->val<<" "<<lists[it.second]->next->val<<endl;
        lists[it.second]=lists[it.second]->next;
        q.pop();
        temp=temp->next;
        temp->next=NULL;
        if(lists[it.second]!=NULL) q.push(make_pair(lists[it.second]->val,it.second));           
        }
        return head;
    }
};
