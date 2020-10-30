int inf=1e9,n;
vector<vector<int>> vect;
void ways(set<int> ans,vector<int> vect1){
    //if(ans.size()==0) return;
    if(vect1.size()==n) {
       //for(int i=0;i<vect1.size();i++) cout<<vect1[i]<<" ";
        vect.push_back(vect1);//cout<<endl;
    }
    
    else{
        auto it=ans.begin();
        while(it!=ans.end()){
            int k=*it;
            it++;
            ans.erase(k);
            vect1.push_back(k);
            ways(ans,vect1);
            vect1.pop_back();
            ans.insert(k);
        }
    }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vect.clear();
    set<int> ans;vector<int> vect1;n=nums.size();
    for(int i=0;i<nums.size();i++) ans.insert(nums[i]);
    ways(ans,vect1);
    return vect;
    }
};
