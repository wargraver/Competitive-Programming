//1434. Number of Ways to Wear Different Hats to Each Other
int mod = 1e9 + 7;
map<pair<int,long long int>,int> ans;
class Solution {
public:
    int ways(long long int val,int i,vector<vector<int>> hats){
        if(i==hats.size()) return 1;
        else if(ans.find(make_pair(i,val))==ans.end()){
            int ans2 = 0;
            for(int j=0;j<hats[i].size();j++){
                int set_bit = 1<<hats[i][j];
               // cout<<i<<" "<<set_bit<<endl;
                //int k = val & set_bit;
               // cout<<k<<endl;
                if((val & set_bit)!=0) ans2 = (ans2%mod+ways(val ^ set_bit,i+1,hats)%mod)%mod;
            }
            ans.insert({make_pair(i,val),ans2});
            return ans2;
        }
        else{
            auto it = ans.find(make_pair(i,val));
            return (it->second)%mod;
        }
    }
    int numberWays(vector<vector<int>>& hats) {
        int i,j,k,n=hats.size();
        long long int val=0;
        ans.clear();
        //Creating a numbers with all set bits for easch hats[i][j]
        for(i=0;i<hats.size();i++){
            for(j=0;j<hats[i].size();j++){
                long long int set_bit = hats[i][j];
                if((1<<set_bit & val) ==1) continue;
                else{
                    long long int temp = 1<<set_bit;
                    val = val | temp;
                }
            }
        }
        cout<<val<<endl;
       return ways(val,0,hats);
        return 0;
    }
};
