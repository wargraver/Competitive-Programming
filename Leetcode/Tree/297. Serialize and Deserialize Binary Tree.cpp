class Codec {
public:
    void tostring(TreeNode* root,string &res)
    {
        if(root==NULL)
        {
            res.push_back('#');
            res.push_back(' ');
            return ;
        }
        res.append(to_string(root->val));
        res.push_back(' ');
        tostring(root->left,res);
        tostring(root->right,res);
        return ;
    }
    
    string serialize(TreeNode* root) {
        string res;
        tostring(root,res);
        return res;
    }
    
    TreeNode* totree(queue<string> &q)
    {
        if(q.front()=="#")
        {
            q.pop();
            return NULL;
        }
        int val=stoi(q.front());
        q.pop();
        TreeNode *root=new TreeNode(val);
        root->left=totree(q);
        root->right=totree(q);
        return root;
    }

    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
        queue<string> q;
        string s;
        for(int i=0;i<data.length();i++)
        {
            if(data[i]==' ')
            {
                q.push(s);
                s.clear();
            }
            else
                s.push_back(data[i]);
        }
        return totree(q);
    }
};
