bool sort1(const pair<int,int> &a,const pair<int,int> &b)
{   if(a.first==b.first) return (a.second > b.second);
    return (a.first<b.first);
}
bool sort2(const pair<int,int> &a,const pair<int,int> &b)
{   if(a.first==b.first) return (a.second > b.second);
    return (a.first<b.first);
}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        int i,j,k,n,m,ct=0;
        multiset<int>dict;
        vector<vector<int>> ans;
        vector<pair<int,int>> start,end;
        vector<vector<int>> buildings;
        for(i=0;i<b.size();i++){
            j=i;vector<int> ve;ve.push_back(b[i][0]);ve.push_back(b[i][1]);int max_1=0;
            while(j<b.size() && b[i][0]==b[j][0] && b[i][1]==b[j][1]){
               max_1 = max(max_1,b[j][2]);
                j++;
            }
            j--;ve.push_back(max_1);
            i=j;
            buildings.push_back(ve);
        }
        for(i=0;i<buildings.size();i++){
           start.push_back(make_pair(buildings[i][0],buildings[i][2]));
           end.push_back(make_pair(buildings[i][1],buildings[i][2]));
        }
        sort(start.begin(),start.end(),sort1);
        sort(end.begin(),end.end(),sort2);
        for(i=0;i<start.size();i++) cout<<start[i].first<<" "<<start[i].second<<endl;
         for(i=0;i<start.size();i++) cout<<end[i].first<<" "<<end[i].second<<endl;
       int st=0,en=0;
       i=0;j=0;
       while(i!=start.size() || j!=end.size()){
           if(i<start.size() && j<end.size()){
               if(start[i].first<=end[j].first){
                   if(dict.size()==0){
                       dict.insert(start[i].second);
                       vector<int> v;
                       v.push_back(start[i].first);v.push_back(start[i].second);
                       ans.push_back(v);
                   }
                   else{
                       auto it=dict.end();
                       it--;
                       if(*it<start[i].second){
                           vector<int> v;
                           v.push_back(start[i].first);v.push_back(start[i].second);
                           ans.push_back(v);
                       }
                       dict.insert(start[i].second);
                   }
                   i++;
               }
               else{
                   //cout<<j<<" ";
                   auto kt=dict.find(end[j].second);
                   int exp=end[j].second;
                   //cout<<end[j].first<<" "<<end[j].second<<endl;
                   dict.erase(kt);
                   if(dict.size()==0){
                    vector<int> v;
                     v.push_back(end[j].first);v.push_back(0);
                     ans.push_back(v);
                   }
                   else{
                    vector<int> v;
                    auto it=dict.end();
                    it--;int val = *it;
                    if(exp>val) {v.push_back(end[j].first);v.push_back(val);
                    ans.push_back(v);}
                   }
                   j++;
               }
           }
           else if(i<start.size()){
               if(dict.size()==0){
                       dict.insert(start[i].second);
                       vector<int> v;
                       v.push_back(start[i].first);v.push_back(start[i].second);
                       ans.push_back(v);
                   }
                   else{
                       auto it=dict.end();
                       it--;
                       if(*it<start[i].second){
                           vector<int> v;
                           v.push_back(start[i].first);v.push_back(start[i].second);
                           ans.push_back(v);
                       }
                       dict.insert(start[i].second);
                   }
                   i++;
           }
           else{
                 auto kt=dict.find(end[j].second);
                   int exp=end[j].second;
                   //cout<<end[j].first<<" "<<end[j].second<<endl;
                   dict.erase(kt);
                   if(dict.size()==0){
                    vector<int> v;
                     v.push_back(end[j].first);v.push_back(0);
                     ans.push_back(v);
                   }
                   else{
                    vector<int> v;
                    auto it=dict.end();
                    it--;int val = *it;
                    if(exp>val) {v.push_back(end[j].first);v.push_back(val);
                    ans.push_back(v);}
                   }
                   j++;
           }
       }
        
        return ans;
    }
};
