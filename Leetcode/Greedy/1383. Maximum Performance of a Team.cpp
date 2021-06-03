typedef long long ll;
bool sortby(pair<ll,ll> A,pair<ll,ll> B){
        if(A.first!=B.first) return A.first<B.first;
        else return A.second>B.second;
    }
class Solution {
public:
   
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int i,j,m,ct=0,mod = 1e9+7;
        vector<pair<ll,ll>> vect;
        for(i=0;i<speed.size();i++) vect.push_back({efficiency[i],speed[i]});
        sort(vect.begin(),vect.end(),sortby);
        //int ans=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        ll ans = (ll)(vect[n-1].second*vect[n-1].first);
        pq.push({vect[n-1].second,vect[n-1].first});
        ll val=0,sum_k=pq.top().first;
        i=n-2;
        while(i>=0){
            if(pq.size()==k){
                ll min2 = pq.top().first;
                ll temp_sum = sum_k+vect[i].second-min2;
                if(min2<vect[i].second){
                    pq.pop();
                    pq.push({vect[i].second,vect[i].first});
                    sum_k = temp_sum;
                }
                 ans = max(ans,temp_sum*vect[i].first);
            }
            else{
                sum_k+=vect[i].second;
                pq.push({vect[i].second,vect[i].first});
                ans = max(ans,sum_k*vect[i].first);
            }
            i--;
        }
        return ans%mod;
    }
};
