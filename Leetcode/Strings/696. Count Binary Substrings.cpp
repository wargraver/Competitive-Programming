class Solution {
public:
    int countBinarySubstrings(string str) {
        int ct=0,i,j,k,n=str.size();
       vector<int> vect;
        char last=str[i];
        for(i=0;i<str.size();i++){
            if(last==str[i]) ct++;
            else{
                vect.push_back(ct);
                ct=1;
                last=str[i];
            } 
        }
        int ans=0;
        if(ct!=0) vect.push_back(ct);
        for(i=0;i<vect.size()-1;i++){
            j=min(vect[i],vect[i+1]);
            ans+=j;
        }
        
        return ans;
    }
};
