class Solution {
public:
    int currsum=0,count=0;
    unordered_map<int,int>prefix;
    
    void helper(TreeNode* root, int sum)
    {
    if(root==NULL)
        return;
        
    currsum+=root->val;
    if(currsum==sum)
        count++;
    if(prefix.find(currsum-sum)!=prefix.end())
        count+=prefix[currsum-sum];
        
    prefix[currsum]++;
        
    helper(root->left,sum);
    helper(root->right,sum);
        
    prefix[currsum]--;
    currsum-=root->val;
        
    }
    
     int pathSum(TreeNode* root, int sum) {
        helper(root,sum);
        return count; 
    }
        
};
