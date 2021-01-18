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
vector<TreeNode*> ways(int st,int en){
    vector<TreeNode*> vect;
    if(st>en){    
        vect.push_back(NULL);
        return vect;
    }
    else{
        for(int i=st;i<=en;i++){
            vector<TreeNode*> left=ways(st,i-1);
            vector<TreeNode*> right=ways(i+1,en);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
                    root->val=i;root->left=NULL;root->right=NULL;
                    root->left=l;
                    root->right=r;
                    vect.push_back(root);
                }
            }
        }
        return vect;
    }
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        int i,j,k,m,ct=0;
        vector<TreeNode*> vect;
        if(n==0) return vect;
        else vect=ways(1,n);
        return vect;
    }
};
