class Solution {
public:
    TreeNode* flat(TreeNode* &root, TreeNode* next){
        if(!root)   return NULL;
        
        if(!root->left && !root->right){
            root->right = next;
            return root;
        } 
        
        TreeNode *cur = root, *left = root->left, *right = root->right;
        
        cur->left = NULL;
        if(left){
            cur->right = flat(left,right);
        }
        flat(cur->right,next);
        
        return root;
    }
    
    void flatten(TreeNode* &root) {
        if(!root)   return;
        
        root = flat(root,NULL);
    }
};
