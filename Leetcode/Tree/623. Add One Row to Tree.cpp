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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int level=0,i,j,k,n,m,ct=0;
        queue<pair<TreeNode*,int>> q;
        TreeNode *temp=root;
        q.push({temp,1});
        if(d-1==0){
            TreeNode *root1=new TreeNode;
            root1->val=v;root1->left=root;root1->right=NULL;
            return root1;
        }else{
        while(q.empty()==false){
            auto it=q.front();
            TreeNode *temp2=it.first;
            //cout<<temp2->val<<endl;
           // cout<<it.second<<endl;
            q.pop();
            if(it.second==d-1){
                TreeNode *left=temp2->left;TreeNode *right=temp2->right;
                TreeNode *var1=new TreeNode;TreeNode *var2=new TreeNode;
                var1->val=v;var2->val=v;
                var1->left=left;var2->right=right;
                var1->right=NULL;var2->left=NULL;
                temp2->left=var1;temp2->right=var2;
            }
            if(temp2->left!=NULL) q.push({temp2->left,it.second+1});
            if(temp2->right!=NULL) q.push({temp2->right,it.second+1});
        }
        return root;
        }
    }
};
