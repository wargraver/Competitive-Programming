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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vect;
        queue<TreeNode*> q;
        if(root==NULL) return vect;
        else{
            q.push(root);
            q.push(NULL);
            while(q.empty()==false){
                TreeNode* temp=q.front();
                if(q.front()==NULL) q.pop();
                else{
                    q.pop();
                    if(temp->left!=NULL) q.push(temp->left);
                    if(temp->right!=NULL) q.push(temp->right);
                    if(q.front()==NULL) {
                        vect.push_back(temp->val);
                        q.push(NULL);
                    }
                }
            }
        }
        return vect;
    }
};
