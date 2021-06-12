int dp[2005][2005];
class Solution {
public:
    int ways(vector<int> s,unordered_map<int,int> dict,int i,int prev){
        //cout<<i<<" "<<prev<<endl;
        if(i>s.size()-1) return 0;
        if(i==s.size()-1) return 1;
        if(prev==0 && i!=0) return 0;
        if(prev>s.size()) return 0;
        else if(dp[i][prev]==-1){
            if(i==0){
                int m1 = s[i]+1;
                auto it = dict.find(m1);
                if(it==dict.end()) return false;
                else return dp[i][prev]=ways(s,dict,it->second,1);
            }
            else{
                bool val1=false,val2=false,val3=false;
                int m1 = s[i]+prev+1;
                int m2 =s[i]+prev;
                int m3 = s[i]+prev-1;
                auto it1 = dict.find(m1);auto it2 = dict.find(m2);auto it3 = dict.find(m3);
                if(it1!=dict.end()) val1 = ways(s,dict,it1->second,prev+1);
                //if(val1==true) return true;
                if(it2!=dict.end()) val2 = ways(s,dict,it2->second,prev);
                //if(val2==true) return true;
                if(it3!=dict.end()) val3 = ways(s,dict,it3->second,prev-1);
               // if(val3==true) return true;
                return dp[i][prev]=(val1 or val2 or val3);
            }
        }
        else return dp[i][prev];
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> dict;
        for(int i=0;i<stones.size()+3;i++){
            for(int j=0;j<stones.size()+3;j++) dp[i][j]=-1;
        }
        for(int i=0;i<stones.size();i++) dict.insert({stones[i],i});
        int k =  ways(stones,dict,0,0);
        return k==1 ? true:false;
    }
};
