class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int i,j,k,n=a.size()-1,m,ct=0;
        sort(a.begin(),a.end());
        set<vector<int>> vect;
        vector<vector<int>> vect2;
        for(i=0;i<=n-3;i++){
            for(j=i+1;j<=n-2;j++){
                int start=j+1,end=n;
                while(start<end){
                    int sum=a[start]+a[end];
                    if(sum>target-a[i]-a[j]) end--;
                    else if(sum<target-a[i]-a[j]) start++;
                    else{
                        vector<int> temp;
                        temp.push_back(a[i]);temp.push_back(a[j]);
                        temp.push_back(a[start]);temp.push_back(a[end]);
                        vect.insert(temp);
                        start++;end--;
                    }
                }
            }
        }
        for(auto it=vect.begin();it!=vect.end();it++){
                 vect2.push_back(*it);
        }
        return vect2;
    }
};
