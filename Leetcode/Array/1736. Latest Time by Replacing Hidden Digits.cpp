class Solution {
public:
    string maximumTime(string s) {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?' && i==0)
            {
                if(s[1]=='?')  s[0]='2';
                else if(s[i+1]!='0' && s[i+1]!='1' &&s[i+1]!='3' && s[i+1]!='2'&&  s[i+1]!='?') s[i]='1';
                else s[i]='2';   
                
            }
                if(s[i]=='?' && i==1)
                {
                    if(s[0]=='1' || s[0]=='0')s[i]='9';
                    else s[i]='3';
                }
                        if(s[i]=='?' && i==3)s[i]='5';
                            if(s[i]=='?' && i==4)s[i]='9';
        }
        return s;
    }
};
