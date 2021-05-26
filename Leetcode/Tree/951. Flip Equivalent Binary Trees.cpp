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
    bool ways(TreeNode* node1,TreeNode* node2){
    if(node1==NULL && node2==NULL) return true;
    else if(node1==NULL || node2==NULL) return false;
    else if(node1->val!=node2->val) return false;
    else{
        bool k = ((ways(node1->left,node2->left) && ways(node1->right,node2->right)));
        bool j =((ways(node1->left,node2->right) && ways(node1->right,node2->left)));
        return (k or j);
    }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        int i,j,k,n,m,ct=0;
        return ways(root1,root2);
    }
};
