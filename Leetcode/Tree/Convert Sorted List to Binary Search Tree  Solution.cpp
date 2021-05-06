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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* ways(int st,int en,int dict[]){
        if(st==en) return new TreeNode(dict[st]);
        else if(st>en) return NULL;
        int mid = (st+en)/2;
        TreeNode *node = new TreeNode(dict[mid]);
        node->left = ways(st,mid-1,dict);
        node->right  = ways(mid+1,en,dict);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        int dict[20004];
        int ct=0;
        while(temp!=NULL){
            int val = temp->val;
            temp=temp->next;
            dict[ct]=val;
            ct++;
        }
        if(ct==0) return NULL;
        return ways(0,ct-1,dict);
    }
};
