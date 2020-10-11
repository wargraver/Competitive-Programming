/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
Node *global=NULL;
void dfs(Node *root,int i,int j){
    if(root==NULL) return;
    j++;
    if(j==i){
        root->next=global;
        global=root;
        return;
    }
    else{
        dfs(root->right,i,j);
        dfs(root->left,i,j);
    }
}
class Solution {
public:
    Node* connect(Node* root) {
        for(int i=0;i<=64;i++){
            dfs(root,i,-1);
            global=NULL;
        }
        return root;
    }
};
