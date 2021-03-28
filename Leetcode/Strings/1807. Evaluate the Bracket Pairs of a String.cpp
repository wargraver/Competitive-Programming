class Solution {
public:
    string evaluate(string str, vector<vector<string>>& s2) {
        int i,j,k,n,m,ct=0;
        string temp;
        n=str.size();
        m=s2.size();
        map<string,string> dict;
        for(i=0;i<m;i++) {
            string str1,str2;
            str1 = s2[i][0];str2 = s2[i][1];
            dict.insert({str1,str2});}
        for(i=0;i<n;i++){
            if(str[i]=='('){
                j=i+1;string key;
                while(str[j]!=')'){
                    key += str[j];
                    j++;
                }
                i=j;
                auto it=dict.find(key);
                if(it!=dict.end()) {for(j=0;j<it->second.size();j++) temp+=it->second[j];}
                else temp+='?';
            }
            else temp+=str[i];
        }
        return temp;
    }
};
