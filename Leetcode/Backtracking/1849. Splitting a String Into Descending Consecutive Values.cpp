//1849. Splitting a String Into Descending Consecutive Values
bool compar(string curr,string prev){
    vector<char> vect1,vect2;
    int i=0,j=0;
    int flag=0;
    while(i!=curr.size()){
        if(curr[i]=='0' && flag==0) i++;
        else {vect1.push_back(curr[i]);i++;flag=1;}
    }
    if(vect1.size()==0 && curr.size()>=1) vect1.push_back('0');
    flag=0;i=0;
    while(i!=prev.size()){
            if(prev[i]=='0' && flag==0) i++;
            else{vect2.push_back(prev[i]);i++;flag=1;}
        }
    if(vect2.size()==0 && prev.size()>=1) vect2.push_back('0');
    if(vect2.size()-vect1.size()==1 || vect1.size()-vect2.size()==0){
         long long m=0,n=0;
         j=vect1.size()-1;i=0;
        while(j>=0){
            m+=(vect1[j]-'0')*pow(10,i);
            i++;j--;
        }
        j=vect2.size()-1;i=0;
        while(j>=0){
            n+=(vect2[j]-'0')*pow(10,i);
            i++;j--;
        }
        if(n-m==1) return true;
        else return false;
    }
     return false;
}
bool ways(string s,int ind,string prev){
    bool ans=false;
    for(int i=ind;i<s.size();i++){
         string curr;
        for(int j=ind;j<=i;j++) curr+=s[j];
        if(prev.size()!=0 && compar(curr,prev)==true){
            if(i+1==s.size()) return true;
            else ans = ans || ways(s,i+1,curr);
        }
        else if(prev.size()==0) ans = ans ||ways(s,i+1,curr);
        else continue;
    }
    return ans;
}
class Solution {
public:
    bool splitString(string s) {
        int i,j,k,n,m,ct=0;
        n=s.size();
        string str1,str2;
        return ways(s,0,"");
    }
};
