vector<int> comp;
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {  if(a.first!=b.first) return a.first>b.first;
       else return a.second>b.second;
    }
};
struct myComp2 {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {  if(a.first!=b.first) return a.first>b.first;
       else return comp[a.second] > comp[b.second];
    }
};
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int i,j,k,n,m,ct=0,time=0,curr_time=0;
        n = servers.size();
        comp.clear();
        for(i=0;i<n;i++) comp.push_back(servers[i]);
        m = tasks.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> aval;
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp2> busy;
        for(i=0;i<n;i++) aval.push({servers[i],i});
        vector<int> ans;
        i=0;
        while(i!=m){
            if(aval.empty()==true && busy.empty()==false){
                auto [min_time,ind] = busy.top();
                busy.pop();
                if(i<=min_time) time = min_time;
                else time = i;
                //ind server is now free
                ans.push_back(ind);
                busy.push({time+tasks[i],ind});
            }
            else if(busy.empty()==false && time>=busy.top().first){
                 ans.push_back(busy.top().second);
                 busy.push({time+tasks[i],busy.top().second});
                 busy.pop();
                 time++;
                 //time++;
            }
            else{
                int t = aval.top().second;
                aval.pop();
                //cout<<servers[t]<<" "<<time+tasks[i]<<" "<<t<<endl;
                ans.push_back(t);
                busy.push({time+tasks[i],t});
                time++;
            }
           // cout<<time<<endl;
            i++;
        }
        return ans;
    }
};
