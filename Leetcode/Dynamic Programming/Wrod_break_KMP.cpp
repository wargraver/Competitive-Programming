int check(string str){
    int ct=0;
    for(int i=0;i<str.size();i++) if(str[i]=='1') ct++;
    if(ct==str.size()) return 1;
    else return 0;
 }
string ways(string str,string str2){
    string str3;int k=str2.size();
    for(int i=0;i<str2.size();i++) str3+=str2[i];
    for(int i=0;i<str.size();i++) str3+=str[i];
 /*   cout<<str3<<endl;*/int m=str3.size();
    int lps[25]={0};int len =0;int i=1;
     while(i<str3.size()){
        if(len<0){
            lps[i]=0;
            len=0;
        }
        else if(str3[i]==str3[len]) {
            lps[i]+=(len+1);
            i++;len++;
         }
        else if(str3[i]!=str3[len] && len==0) {lps[i]=0;i++;}
        else if(str3[i]!=str3[len] && len>0){
              len=lps[len-1];
         }
    }
    int flag=0;
    for(int i=k;i<str3.size();i++){
        if(lps[i]==k){
            flag=1;///cout<<"yoo";
            int m=k,j=i;
            while(m!=0){
                str[j-k]='1';
                j--;m--;
            }
        }
        else continue;
    }
    //cout<<str<<endl;
    return str;
}
int fun(string str, vector<string> vect,int i){
    if(i>=vect.size()) return 0;
    else{
        string sample=ways(str,vect[i]);
        if(check(sample)==1) return 1;
        else return fun(sample,vect,i+1)+ fun(str,vect,i+1);
    }
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    int k=fun(s,wordDict,0);
        if(k==0) return false;
        else return true;
    }
};int check(string str){
    int ct=0;
    for(int i=0;i<str.size();i++) if(str[i]=='1') ct++;
    if(ct==str.size()) return 1;
    else return 0;
 }
string ways(string str,string str2){
    string str3;int k=str2.size();
    for(int i=0;i<str2.size();i++) str3+=str2[i];
    for(int i=0;i<str.size();i++) str3+=str[i];
 /*   cout<<str3<<endl;*/int m=str3.size();
    int lps[25]={0};int len =0;int i=1;
     while(i<str3.size()){
        if(len<0){
            lps[i]=0;
            len=0;
        }
        else if(str3[i]==str3[len]) {
            lps[i]+=(len+1);
            i++;len++;
         }
        else if(str3[i]!=str3[len] && len==0) {lps[i]=0;i++;}
        else if(str3[i]!=str3[len] && len>0){
              len=lps[len-1];
         }
    }
    int flag=0;
    for(int i=k;i<str3.size();i++){
        if(lps[i]==k){
            flag=1;///cout<<"yoo";
            int m=k,j=i;
            while(m!=0){
                str[j-k]='1';
                j--;m--;
            }
        }
        else continue;
    }
    //cout<<str<<endl;
    return str;
}
int fun(string str, vector<string> vect,int i){
    if(i>=vect.size()) return 0;
    else{
        string sample=ways(str,vect[i]);
        if(check(sample)==1) return 1;
        else return fun(sample,vect,i+1)+ fun(str,vect,i+1);
    }
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    int k=fun(s,wordDict,0);
        if(k==0) return false;
        else return true;
    }
};
