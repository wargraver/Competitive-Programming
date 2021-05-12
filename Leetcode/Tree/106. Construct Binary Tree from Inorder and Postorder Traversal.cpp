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
    TreeNode* tree(int st1,int en1,int st2,int en2,vector<int> in,vector<int> post){
        //cout<<st1<<" "<<en1<<" "<<st2<<" "<<en2<<endl;
          if(st2==en2){
              TreeNode *node = new TreeNode(post[st2]);
              return node;
          }
          else if(st1>en1) return NULL;
          else{
              TreeNode *node = new TreeNode(post[en2]);
              int right_element=0,left_element=0,k=0;
              for(int i=st1;i<=en1;i++){
                  if(in[i]==post[en2]) {k=i;break;}
              }
              right_element =en1-k;left_element = k-st1;
              if(k!=st1) node->left = tree(st1,k-1,st2,en2-right_element-1,in,post);
              if(k!=en1) node->right = tree(k+1,en1,en2-right_element,en2-1,in,post);
              return node;
          }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          int i,j,k,n,m,ct=0;
          n = inorder.size()-1;
          int st=0,en=n;
          return tree(0,en,0,en,inorder,postorder);
    }
};
