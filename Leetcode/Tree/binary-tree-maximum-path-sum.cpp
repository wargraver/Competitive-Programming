int max1=-500000;
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
int inorder(TreeNode* root){
    if(root==NULL) return 0;
    else{
       int l=0,r=0,m=root->val;
        if(root->left==NULL) {l=0;max1=max(root->val,max1);}
        if(root->right==NULL){r=0;max1=max(root->val,max1);}
        if(root->left!=NULL) {
            l=inorder(root->left);
            m=max(l+root->val,m);
            max1=max(max1,max(m,l));
        }
        if(root->right!=NULL) {
            r=inorder(root->right);
            m=max(r+root->val,m);
            max1=max(max1,max(m,r));
        }
       // cout<<l<<" "<<r<<endl;
        max1=max(max1,l+root->val+r);
        return m;
    }
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int i,j,k,n,m,ct=0;
        max1=-50000;
        k=inorder(root);
        return max1;
    }
};
