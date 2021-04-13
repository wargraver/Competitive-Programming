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
TreeNode* ways(vector<int> p,int min1,int max1,int i){
          if(i==p.size()) return NULL;
          else{
               if(p[i]<=max1 && p[i]>=min1){
                 ct++;
                 TreeNode *node = new TreeNode(p[i]);
                   node->left=ways(p,min1,p[i],i+1);
                   node->right = ways(p,p[i],max1,ct);
                   return node;
               }
              else return NULL;
          }
}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i,j,k,n,m;
        n=preorder.size();
        ct=0;
        return ways(preorder,-1e9,1e9,0);
    }
    
    
    
    
};
