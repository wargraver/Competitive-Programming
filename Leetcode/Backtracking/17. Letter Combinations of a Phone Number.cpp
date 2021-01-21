vector<string> vect;
vector<string> vect2;
set<string> dict2;
int m;
void ways(map<int,int> dict,string str){
    if(str.size()==m) {dict2.insert(str);return;}
    else if(dict.size()==0) return;
    else{
        for(auto it=dict.begin();it!=dict.end();it++){
            int val=it->second;
            dict.erase(it);
            for(int i=0;i<vect[val].size();i++) {
                string str2=str;
                str2+=vect[val][i];
                ways(dict,str2);
            }
            //dict.insert(val);
        }
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int i,j,k,n,ct=0;m=digits.size();
        //cout<<m<<endl;
        dict2.clear();vect.clear();vect2.clear();
        if(m==0) return vect;
        vect.push_back("00");vect.push_back("11");
       vect.push_back("abc");vect.push_back("def");vect.push_back("ghi");
    vect.push_back("jkl");vect.push_back("mno");vect.push_back("pqrs");vect.push_back("tuv");
        vect.push_back("wxyz");
        map<int,int> dict;
        for(i=0;i<digits.size();i++) dict.insert({i,digits[i]-'0'});
        string str="";
        ways(dict,str);
        for(auto it=dict2.begin();it!=dict2.end();it++) vect2.push_back(*it);
        return vect2;
    }
};
