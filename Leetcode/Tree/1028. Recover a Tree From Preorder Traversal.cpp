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
int i=0;
class Solution {
public:
    //converting the given string to a number
    int convert(vector<int> vect){
        int j=vect.size()-1,k=0,m=0;
        while(j>=0){
            m+=vect[j]*pow(10,k);
            k++;j--;
        }
        return m;
    }
    //Recursively genrating the tree form string S
    TreeNode *construct(string S,int req_level){
           int j=i,curr_level=0;
           if(i==S.size()) return NULL;
           j--;
           while(j>=0 && S[j]=='-'){
               curr_level++;
               j--;
           }
           //if current level is not equal to required level return NULL
           if(curr_level!=req_level) return NULL;
           vector<int> vect;
           while(i!=S.size() && S[i]!='-'){
               vect.push_back(S[i]-'0');
               i++;
           }
           while(i!=S.size() && S[i]=='-') i++;
           int num = convert(vect);
           TreeNode *node = new TreeNode(num);
           node->left = construct(S,curr_level+1);
           node->right = construct(S,curr_level+1);
           return node;
    }
    TreeNode* recoverFromPreorder(string S) {
        i=0;
        TreeNode *root = construct(S,0);
        return root;
    }
};
