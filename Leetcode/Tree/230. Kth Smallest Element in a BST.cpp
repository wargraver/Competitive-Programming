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
int ct=0,val;
void fun(TreeNode* root,int k){
    if(root==NULL) return;
    else{
         fun(root->left,k);
         ct++;
        if(k==ct) val=root->val;
        fun(root->right,k);
    }
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        ct=0;
        fun(root,k);
        return val;
    }
};
