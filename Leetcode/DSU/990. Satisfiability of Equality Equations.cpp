class Solution {
public:
    int parent[26];
    int findparent(int parent[],int i){
        while(parent[i]!=i){
            i=parent[i];
        }
        return parent[i];
    }
    void join(int parent[],int i,int j){
        int x=i,y=j;
        i = findparent(parent,i);
        j = findparent(parent,j);
        if(i==j) return;
        else parent[j]=i;
        return;
    }
    bool equationsPossible(vector<string>& equations) {
        //storing all equal and unequal equations
        vector<string> equals,unequals;
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='=') equals.push_back(equations[i]);
            else unequals.push_back(equations[i]);
        }
        for(int i=0;i<26;i++) parent[i]=i;
        for(int i=0;i<equals.size();i++){
             string str = equals[i];
             join(parent,str[0]-'a',str[3]-'a');
        }
        for(int i=0;i<unequals.size();i++){
            string str = unequals[i];
            if(findparent(parent,str[0]-'a')==findparent(parent,str[3]-'a')) return false;
        }
        return true;
    }
    
};
