vector<string> vect;
int m;
void ways(int ct,int n,string str){
    if(ct==2*n){
        stack<char> st;int flag=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(') st.push('(');
            else if(str[i]==')'){
                if(st.empty()) {flag=1;break;}
                else st.pop();
            }
        }
        if(flag==0 && st.empty()) vect.push_back(str);
    }
    else{
        string str2=str;
        str2+='(';str+=')';
        ways(ct+1,n,str);
        ways(ct+1,n,str2);
    }
   }
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i,j,k,ct=0;m=n;
        vect.clear();string str="";
        ways(0,n,str);
        return vect;
    }
};
