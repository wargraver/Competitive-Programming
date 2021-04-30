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
    TreeNode *ways(TreeNode *node,int min_val,int max_val,int val){
        if(node==NULL){
            TreeNode *new_node = new TreeNode(val);
            return new_node;
        }
       if(val>=min_val && val<=node->val) node->left = ways(node->left,min_val,node->val,val);
       else if(val>=node->val && val<=max_val)  node->right = ways(node->right,node->val,max_val,val);
       return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        int i,j,k,n,m,ct=0;
        TreeNode* temporay = ways(root,-1e9,1e9,val);
        return temporay;
    }
};
