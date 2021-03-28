class Solution {
public:
    int numDifferentIntegers(string word) {
        int i,j,k,n,m,ct=0;
        n=word.size();
        set<string> dict;
        int flag=0;
        int st=0,en=0;
        for(i=0;i<n;i++){
            if(word[i]-'a'<=25 && word[i]-'a'>=0 && flag==1){
                en=i;int flag2=0;string temp;
                for(j=st;j<en;j++){
                    if(flag2==0 && word[j]=='0') continue;
                    else {
                        temp+=word[j];
                        flag2=1;
                    }
                }
                if(temp.size()>=1) dict.insert(temp);
                else {temp="0";dict.insert(temp);}
                flag=0;
            }
            else if(word[i]-'0'<=9 && word[i]-'0'>=0 && flag==0){
                st=i;
                flag=1;
            }
        }
        if(word[n-1]-'0'<=9 && word[n-1]-'0'>=0){
            string temp;en=n-1;int flag2=0;
                for(j=st;j<=en;j++){
                    if(flag2==0 && word[j]=='0') continue;
                    else {
                        temp+=word[j];
                        flag2=1;
                    }
                }
                if(temp.size()>=1) dict.insert(temp);
                else {temp="0";dict.insert(temp);}
        }
        return dict.size();
    }
};
