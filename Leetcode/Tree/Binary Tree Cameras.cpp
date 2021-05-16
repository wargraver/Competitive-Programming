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
//flag=1,parent has camera
//flag=0,parent has no camera and parent is already covered
//flag=2,parent has no camera and parent is not covered,i.e install camera
int ways(TreeNode *node,int flag,int i){
    if(node->left==NULL && node->right==NULL){
        if(flag==1) return 0;
        else return 1;
    }
    else if(node->left==NULL){
        if(i==1) return min(1+ways(node->right,1,0),ways(node->right,2,0));
        if(flag==1) return min(1+ways(node->right,1,0),ways(node->right,0,0));
        else if(flag==2) return 1+ways(node->right,1,0);
        else return min(1+ways(node->right,1,0),ways(node->right,2,0));
    }
    else if(node->right==NULL){
        if(i==1) return min(1+ways(node->left,1,0),ways(node->left,2,0));
        else if(flag==1) return min(1+ways(node->left,1,0),ways(node->left,0,0));
        else if(flag==2) return 1+ways(node->left,1,0);
        else return min(1+ways(node->left,1,0),ways(node->left,2,0));
    }
    else{
        if(i==1){
             int ans = 1+ways(node->left,1,0)+ways(node->right,1,0);
             int ans2 = ways(node->left,2,0)+ways(node->right,0,0);
             int ans3 = ways(node->left,0,0)+ways(node->right,2,0);
            int ans4 = ways(node->left,2,0)+ways(node->right,2,0);
            return min(ans3,min(ans,min(ans4,ans2)));
        }
       else if(flag==0) {
            int ans = 1+ways(node->left,1,0)+ways(node->right,1,0);
            int ans1 = ways(node->left,2,0)+ways(node->right,0,0);
            int ans2 = ways(node->left,0,0)+ways(node->right,2,0);
            int ans3 = ways(node->left,2,0)+ways(node->right,2,0);
            return min(ans3,min(ans,min(ans1,ans2)));
        }
        else if(flag==1){
            int ans = ways(node->left,0,0)+ways(node->right,0,0);
            int ans3 = 1+ways(node->left,1,0)+ways(node->right,1,0);
            return min(ans,ans3);
        }
        else{
            int ans = 1+ways(node->left,1,0)+ways(node->right,1,0);
            return ans;
        }
    }
    return 0;
}
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        else if(root->left==NULL && root->right==NULL) return 1;
        return ways(root,1,1);
    }
};
