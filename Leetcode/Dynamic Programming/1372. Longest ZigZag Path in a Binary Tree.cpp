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
stack<TreeNode*> st;
int max2=0;
void traverse(TreeNode* root){
    if(root==NULL) return;
    else{
        st.push(root);
        traverse(root->left);
        traverse(root->right);
}
}
int ways(TreeNode* root,int i){
    if(root==NULL) return 0;
    else{
        int left,right;
         if(i==1){ 
             left=  ways(root->left,0);
             max2=max(max2,left+1);
             return left+1;
         }
        else{
            right=ways(root->right,1);
            max2=max(max2,right+1);
            return right+1;
        }
     }
}
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        max2=0;
        traverse(root);
        while(!st.empty()){
        TreeNode* root2=st.top();
        int k=ways(root2,0);
        int j=ways(root2,1);
        max2=max(max2,max(k,j));
        st.pop();
        }
        
        return max2-1;
    }
};
