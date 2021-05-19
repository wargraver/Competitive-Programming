int dp[50005];
class Solution {
public:
    int search(int val,vector<pair<int,int>> vect,int i){
        int low=i,high = vect.size()-1,j=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(vect[mid].first>=val){
                j=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return j;
    }
    int ways(int i,vector<pair<int,int>> vect,vector<int> e,vector<int> p){
        /*if(i==vect.size()) return 0;
        else if(dp[i]==-1){
            int m1 = ways(i+1,vect,e,p);
            int j = search(e[vect[i].second],vect,i);
            if(j==-1) j=vect.size();
            int m2 = p[vect[i].second]+ways(j,vect,e,p);
            return dp[i]=max(m1,m2);
        }
        else return dp[i];
        */
        dp[vect.size()]=0;
        for(int j=vect.size()-1;j>=0;j--){
            int m1 = dp[j+1];
            int k=search(e[vect[j].second],vect,j);
            if(k==-1) k=vect.size();
            int m2 = dp[k]+p[vect[j].second];
            dp[j] = max(m1,m2);
        }
        return dp[0];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,int>> vect;
        for(int i=0;i<startTime.size();i++) {
            vect.push_back(make_pair(startTime[i],i));
            dp[i]=-1;
        }
        sort(vect.begin(),vect.end());
        return ways(0,vect,endTime,profit);
    }
};
