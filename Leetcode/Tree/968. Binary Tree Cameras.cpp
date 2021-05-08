class Solution {
public:
    int ways(TreeNode *root,int ct,int flag,int isroot){
        if(root==NULL) return 0;
        else if(root->left==NULL && root->right==NULL){
                if(flag==0|| flag==2) return 1;
                else return 0;
            }
        if(isroot==1){
            int m1 = ways(root->left,0,1,0);
            int n1 = ways(root->right,0,1,0);
            int ans = ct+1+m1+n1;
            int l1 = ways(root->left,0,0,0);
            int r1 = ways(root->right,0,0,0);
            ans = min(ans,ct+l1+r1);
            if(root->left!=NULL && root->right!=NULL){
                ans = min(ans,ct+l1+m1);
                ans = min(ans,ct+n1+r1);
            }
            return ans;
        }
        else{
            if(flag==0){
            int l1 = ways(root->left,0,1,0);
            int r1 = ways(root->right,0,1,0);
            int ans = ct+1+l1+r1;
            return ans;
            }
            else if(flag==2){
            int m1 = ways(root->left,0,1,0);
            int n1 = ways(root->right,0,1,0);
            int ans = ct+1+m1+n1;
            int l1 = ways(root->left,0,0,0);
            int r1 = ways(root->right,0,0,0);
            ans = min(ans,ct+l1+r1);
            if(root->left!=NULL && root->right!=NULL){
                ans = min(ans,ct+l1+m1);
                ans = min(ans,ct+n1+r1);
            }
            return ans;
            }
            else{
            int l1 = ways(root->left,0,1,0);
            int r1 = ways(root->right,0,1,0);
            int ans = ct+1+l1+r1;
            l1 = ways(root->left,0,2,0);
            r1 = ways(root->right,0,2,0);
            ans = min(ans,ct+l1+r1);
            return ans;
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        int i,j,k,n,m,ct=0;
        k = ways(root,0,0,1);
        return k;
    }
};
