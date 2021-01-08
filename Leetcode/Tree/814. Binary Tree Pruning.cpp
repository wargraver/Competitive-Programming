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
bool order(TreeNode* root){
    if(root==NULL) return false;
    //if(root->val==1) return true;
    else{
        bool l=order(root->left);
        bool r=order(root->right);
        if(l==false) root->left=NULL;
        if(r==false) root->right=NULL;
        if(root->val==1) return true;
        else if(l==false && r==false) {root=NULL;return false;}
        else{
            return true;
        }
    }
}
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        int i,j,k,n,m,ct=0;
        bool flag=order(root);
        if(flag==false) return NULL;
        return root;
    }
};
