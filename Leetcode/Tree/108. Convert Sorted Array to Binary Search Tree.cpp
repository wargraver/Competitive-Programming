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
    TreeNode* ways(int st,int en,vector<int> vect){
        if(st>en) return NULL;
        if(st==en){
            TreeNode *node = new TreeNode(vect[st]);
            return node;
        }
        else{
            int mid = (st+en)/2;
            TreeNode *node = new TreeNode(vect[mid]);
            node->left = ways(st,mid-1,vect);
            node->right = ways(mid+1,en,vect);
            return node;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ways(0,nums.size()-1,nums);
    }
};
