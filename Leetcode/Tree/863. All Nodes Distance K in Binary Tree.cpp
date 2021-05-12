/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans;
TreeNode *parent[505];
TreeNode *new_root;
int vis[505];
class Solution {
public:
    void find_parent(TreeNode *node,TreeNode *parent_node,int target){
         if(node==NULL) return;
         if(node->val==target) new_root = node; 
         parent[node->val] = parent_node;
         find_parent(node->left,node,target);
         find_parent(node->right,node,target);
    }
    void dfs(TreeNode *node,int k,int dist){
        if(node==NULL) return;
        vis[node->val]=1;
        if(dist==k) {
            ans.push_back(node->val);
            return;
        }
        if(node->left!=NULL && vis[node->left->val]==0) dfs(node->left,k,dist+1);
        if(node->right!=NULL && vis[node->right->val]==0) dfs(node->right,k,dist+1);
        if(parent[node->val]!=NULL && vis[parent[node->val]->val]==0) dfs(parent[node->val],k,dist+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        //memset(parent,NULL,sizeof(parent)); 
        memset(vis,0,sizeof(vis));
        find_parent(root,NULL,target->val);
        dfs(new_root,k,0);
        return ans;
    }
};
