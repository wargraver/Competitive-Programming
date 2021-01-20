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
int ways(TreeNode* root,int flag){
    if(root==NULL) return 0;
   // else if(root->left==NULL && root->right==NULL && flag==1) return 0;
    else{
        if(flag==1) return ways(root->left,0)+ways(root->right,0); 
        else{
            return max(root->val+ways(root->left,1)+ways(root->right,1),ways(root->left,0)+ways(root->right,0));
        }
    }
}
class Solution {
public:
    int rob(TreeNode* root) {
         return ways(root,0);
    }
};
