class Solution {
public:
    int ans;
    int distributeCoins(TreeNode* root) 
    {
        ans = 0;    
        solve(root);
        return ans;
    }
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        ans += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};
