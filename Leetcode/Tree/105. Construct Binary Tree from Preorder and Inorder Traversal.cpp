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
int ct=0;
TreeNode* ways(vector<int>pre,vector<int> in,int st,int en,int i,unordered_map<int,int> dict){
         if(st>en) return NULL;
         else if(st==en){
             ct++;
              TreeNode *node=new TreeNode(pre[i]);
              return node;
          }
         else{
             TreeNode *node = new TreeNode(pre[i]);
             int j =dict[pre[i]];
             ct++;
            // cout<<j<<" "<<pre[i]<<endl;
             node->left = ways(pre,in,st,j-1,i+1,dict);  
             node->right = ways(pre,in,j+1,en,ct,dict);
             return node;
        }
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i,j,k,n;ct=0;
        unordered_map<int,int> dict;
        for(i=0;i<inorder.size();i++) dict.insert({inorder[i],i});
        return ways(preorder,inorder,0,preorder.size()-1,0,dict);
    }
};
