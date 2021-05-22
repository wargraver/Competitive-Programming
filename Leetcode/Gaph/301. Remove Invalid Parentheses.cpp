class Solution {
public:
    bool check(string str){
        stack<char> st;
        int flag=0,i=0;
        while(flag==0 && i<str.size()){
            if(str[i]=='(') st.push('(');
            else if(st.empty() && str[i]==')') return false;
            else if(str[i]==')') st.pop();
            i++;
        }
        if(st.empty()) return true;
        else return false;
    }
    vector<string> removeInvalidParentheses(string s) {
        string str1=s;
        int min1=1e9;
        queue<pair<string,int>> q;
        vector<string> vect;
        set<string> dict;
        q.push({str1,0});
        while(q.empty()==false){
            auto it = q.front();
           if(min1<it.second) break;
         //  cout<<it.first<<" "<<dict.size()<<endl;
            q.pop();
           /* if(it.first.size()==0){
                vect.push_back(it.first);
                return vect;
            }*/
            if(dict.find(it.first)!=dict.end()) continue;
            dict.insert(it.first);
            if(check(it.first)==true){
                if(min1>=it.second){
                 min1=min(min1,it.second);
                vect.push_back(it.first);
                }
               // cout<<it.first<<endl;
                continue;
            }
            for(int i=0;i<it.first.size();i++){
                string str2;
                if(it.first[i]=='(' or it.first[i]==')'){
                for(int j=0;j<i;j++) str2+=it.first[j];
                for(int j=i+1;j<it.first.size();j++) str2+=it.first[j];
                //cout<<str2<<endl;
                q.push({str2,it.second+1});
                }
            }
        }
        return vect;
    }
};
