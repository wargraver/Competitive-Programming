class Solution {
public:
    bool isPossible(vector<int>& target) {
          long long int i,j,k,n,m,sum=0;
          n = target.size();
          priority_queue<pair<long long int ,long long int >,vector<pair<long long int ,long long int >>> pq;
          for(i=0;i<n;i++){
              pq.push(make_pair(target[i],i));
              sum+=target[i];
          }
         if(target.size()==1 && target[0]!=1) return false;
         else if(target.size()==1) return true;
          while(pq.top().first!=1){
              m = pq.top().first;i = pq.top().second;
              pq.pop();
              sum-=m;
              if(sum>=m && sum!=1) return false;
              int val = m%sum;
              if(val==0 && sum==1) return true;
              if(val<=0 || sum<=0) return false;
              sum+=val;
              pq.push(make_pair(val,i));
          }
        return true;
    }
};
