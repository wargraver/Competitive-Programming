bool inorder(TreeNode *root,long long  min1,long long max1){
    if(root==NULL) return false;
    else{
        bool val1=true,val2=true;int flag=0;
        if(min1<root->val && max1>root->val){
            flag=1;
        }
        else return false;
        if(root->left!=NULL){
           val1= inorder(root->left,min1,root->val);
        }
        if(root->right!=NULL){
            val2=inorder(root->right,root->val,max1);
        }
        if(val1==true && val2==true) return true;
        else return false;
    }
}
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
    bool isValidBST(TreeNode* root) {
         return inorder(root,-2e12,2e12);
    }
};
