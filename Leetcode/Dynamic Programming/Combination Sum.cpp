set<vector<int>> dict;
void ways(int i,vector<int> a,int sum,vector<int> vect){
   if(i>=a.size()) return;
    else{
        if(sum-a[i]>=0){
              ways(i+1,a,sum,vect);
              vect.push_back(a[i]);
            if(sum-a[i]==0){
                sort(vect.begin(),vect.end());
                dict.insert(vect);
            }
             else {ways(i,a,sum-a[i],vect);}
        }
        else ways(i+1,a,sum,vect);
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dict.clear();
        int i,j,k,n,m,ct=0;
        set<int> dict2;
        vector<int> vect;
        ways(0,candidates,target,vect);
        vector<vector<int>> ans;
        for(auto it=dict.begin();it!=dict.end();it++){
           // ans.push_back(*it);
            ans.push_back(*it);
           // cout<<endl;
        }
        return ans;
    }
};
