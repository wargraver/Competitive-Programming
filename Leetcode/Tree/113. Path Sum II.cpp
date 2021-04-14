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
vector<vector<int>> ans;
void ways(TreeNode* node,int sum,vector<int> temp,int curr_sum){
    if(node==NULL) return;
    else{
        temp.push_back(node->val);
        if(sum==curr_sum+node->val && node->left==NULL && node->right==NULL) ans.push_back(temp);
        ways(node->left,sum,temp,curr_sum+node->val);
        ways(node->right,sum,temp,curr_sum+node->val);
        temp.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        ans.clear();
        ways(root,targetSum,temp,0);
        return ans;
    }
};
