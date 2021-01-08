int max1=-5000000;
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
int preorder(TreeNode* root){
    if(root==NULL) return 0;
    else{
       int l=0,r=0,lans=0,rans=0;
       l=preorder(root->left);
       r=preorder(root->right);
       if(root->left!=NULL && root->val==root->left->val) lans=l+1;
       if(root->right!=NULL && root->val==root->right->val) rans=r+1;
       max1=max(lans+rans,max1);
       return max(lans,rans);
    }
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int i,j,k,n,m,ct=0;
        max1=-5000000;
        k=preorder(root);
        if(max1==-5000000) return 0;
        else return max1;
    }
};
