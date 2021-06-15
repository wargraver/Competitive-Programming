typedef long long ll;
class Solution {
public:
    bool ways(vector<int> match,ll i,ll s1,ll s2,ll s3,ll s4){
        if(s1==0 && s2==0 && s3==0 && s4==0 && i==match.size()) return true;
        else if(i>=match.size()) return false;
        else if(s1<0 || s2<0 || s3<0 || s4<0) return false;
        else{
return (ways(match,i+1,s1-match[i],s2,s3,s4) or ways(match,i+1,s1,s2-match[i],s3,s4) or ways(match,i+1,s1,s2,s3-match[i],s4) or ways(match,i+1,s1,s2,s3,s4-match[i]));
        }
    }
    bool makesquare(vector<int>& match) {
      ll i,j,k,n,m,ct=0,sum=0;
        n= match.size();
        for(i=0;i<n;i++) sum += match[i];
        if(sum%4==0){
            ll sidelength = sum/4;
            return ways(match,0,sidelength,sidelength,sidelength,sidelength);
        }
        else return false;
    }
};
