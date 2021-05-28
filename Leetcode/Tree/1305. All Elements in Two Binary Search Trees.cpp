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
    void ways(TreeNode* node,vector<int>& vect){
        if(node==NULL) return;
        else{
            ways(node->left,vect);
            vect.push_back(node->val);
            ways(node->right,vect);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> vect1,vect2,vect3;
       ways(root1,vect1);
       ways(root2,vect2);
       int pt1=0,pt2=0,i=0;
        while(pt1<vect1.size() && pt2<vect2.size()){
            if(vect1[pt1]<vect2[pt2]){
                vect3.push_back(vect1[pt1]);
                pt1++;
            }
            else vect3.push_back(vect2[pt2]),pt2++;
        }
        while(pt1<vect1.size()){
            vect3.push_back(vect1[pt1]);
            pt1++;
        }
        while(pt2<vect2.size()){
            vect3.push_back(vect2[pt2]);
            pt2++;
        }
       return vect3;
    }
};
