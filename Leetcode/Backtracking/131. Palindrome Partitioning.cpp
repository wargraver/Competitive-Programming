vector<vector<string>> vect;
int n;
bool check(string s,int st,int en){
     string temp;
     int i,j,k;
     for(i=st;i<=en;i++) temp+=s[i];
     string temp2=temp;
     reverse(temp.begin(),temp.end());
     if(temp2==temp) return true;
     else return false;
}
void ways(string s,int st,int curr,int end,vector<string> vect2){
    if(curr>n || end>n) return;
    else if(curr==end){
         if(check(s,st,end)==true){
             string temp;
             for(int i=st;i<=end;i++) temp+=s[i];
             vect2.push_back(temp);
             vect.push_back(vect2);
         }
     }
    else{
        if(check(s,st,curr)==true){
             string temp;
             for(int i=st;i<=curr;i++) temp+=s[i];
             ways(s,st,curr+1,end,vect2);
             vect2.push_back(temp);
             ways(s,curr+1,curr+1,end,vect2);
        }
        else{
             ways(s,st,curr+1,end,vect2);
        }
    }
}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vect.clear();
        s+='a';
        int i,j,k,m,ct;
        n=s.size()-1;
        vector<string> vect2;
        ways(s,0,0,n-1,vect2);
        return vect;
    }
};
