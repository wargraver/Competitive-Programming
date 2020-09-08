class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int ans=1;
        unordered_set<int> dict2;
        for(int i=0;i<A.size();i++) dict2.insert(A[i]);
        for(int i=0;i<A.size()-1;i++){
            for(int j=i+1;j<A.size();j++){
                int ct=2;
                int sum=A[i]+A[j],last=A[j];
                int flag=0;
                while(flag==0){
                    if(dict2.find(sum)==dict2.end()) flag=1;
                    else {
                        //dict.insert(sum);
                        ct++;
                     // cout<<last<<" ";
                        int k=sum;
                        sum+=last;
                        last=k;
                    }
                }
               // cout<<endl;
                ans = max(ct,ans);
                if(ans==2) ans=0;
            }
                }
        return ans;
    }
};
