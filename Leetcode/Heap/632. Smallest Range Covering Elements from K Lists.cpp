class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      int i,j,k,n=nums.size(),m,ans=INT_MAX;
      multimap<int,pair<int,int>> dict;
      for(i=0;i<n;i++) dict.insert({nums[i][0],make_pair(i,0)});
      int flag=0;
      while(flag==0){
          auto it=dict.begin();
          auto kt = it->second;
          int st = it->first;
          auto mt=dict.end();mt--;
          int en = mt->first;
          if(ans>en-st+1){
              ans=en-st+1;
              m=it->first;
          }
          dict.erase(it);
          if(nums[kt.first].size()==kt.second+1) {flag=1;break;}
          dict.insert({nums[kt.first][kt.second+1],make_pair(kt.first,kt.second+1)});
      }
    vector<int> temp;
    temp.push_back(m);
    temp.push_back(m+ans-1);
    return temp;
    }
};
