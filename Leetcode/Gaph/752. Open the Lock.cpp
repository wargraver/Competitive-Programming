class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int i,j,k,n,m,ct=0;
        unordered_set<string> dict;
        for(i=0;i<deadends.size();i++) dict.insert(deadends[i]);
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        string str ="0000";
        if(dict.find(str)!=dict.end()) return -1;
        vis.insert(str);
        q.push({str,0});
        while(q.empty()==false){
            auto it = q.front();
            q.pop();
            //cout<<it.first<<endl;
            if(it.first==target) return it.second;
            for(i=0;i<4;i++){
                string temp = it.first;
                k = it.first[i]-'0';
                //increasing the index
                if(k==9) temp[i]='0';
                else{
                char curr = it.first[i];
                curr++;
                temp[i]=curr;
                }
                if(vis.find(temp)==vis.end() && dict.find(temp)==dict.end()){
                    q.push({temp,it.second+1});
                     vis.insert(temp);
                }
                //decreasing the index
                temp = it.first;
                if(k==0) temp[i]='9';
                else{
                    char curr = it.first[i];
                    curr--;
                    temp[i]=curr;
                }
                if(vis.find(temp)==vis.end() && dict.find(temp)==dict.end()){
                    q.push({temp,it.second+1});
                     vis.insert(temp);
                }
            }
        }
        return -1;
    }
};
