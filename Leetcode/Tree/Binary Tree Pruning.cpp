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
    bool ways(TreeNode *node){
        if(node==NULL) return true;
        else{
            bool val1 = ways(node->left);
            bool val2 = ways(node->right);
            //Pruning left subtree
            if(val1==true) node->left = NULL;
            //Pruning Right subtree
            if(val2==true) node->right = NULL;
            //Pricessing current node
            if(node->val==0 && val1==true && val2==true) return true;
            else return false;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool val1 = ways(root);
        if(val1==false) return root;
        else return NULL;
    }
};
