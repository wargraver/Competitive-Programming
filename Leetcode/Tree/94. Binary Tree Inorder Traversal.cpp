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
vector<int> vect;
void ways(TreeNode* root){
    if(root==NULL) return;
    else{
        ways(root->left);
        vect.push_back(root->val);
        ways(root->right);
    }
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        int i,j,k,n,m,ct=0;
        vect.clear();
        ways(root);
        return vect;
    }
};
