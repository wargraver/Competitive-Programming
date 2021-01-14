class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int i,j,k,n,m,ct=0,ans=0;
        n=h.size();
        stack<int> st1,st2;
        int next[n+1],prev[n+1];
        st1.push(n-1);
        next[n-1]=-1;
        for(i=n-2;i>=0;i--){
            if(st1.empty()){
                st1.push(i);
                next[i]=-1;
            }
            else{
                while(st1.empty()==false && h[st1.top()]>=h[i]){
                    st1.pop();
                }
                if(st1.empty()){
                    st1.push(i);
                    next[i]=-1;
                }
                else{
                    next[i]=st1.top();
                    st1.push(i);
                }
            }
        }
        prev[0]=-1;
        st2.push(0);
        prev[0]=-1;
        for(i=1;i<n;i++){
            if(st2.empty()){
                prev[i]=-1;
                st2.push(i);
            }
            else{
                while(st2.empty()==false && h[st2.top()]>=h[i]){
                    st2.pop();
                }
                if(st2.empty()){
                    st2.push(i);
                    prev[i]=-1;
                }
                else{
                    prev[i]=st2.top();
                    st2.push(i);
                }
            }
        }
        //for(i=0;i<n;i++) cout<<next[i]<<" "<<prev[i]<<endl;
        for(i=0;i<n;i++){
            int val1=next[i],val2=prev[i];
            if(val1==val2 && val1==-1) ans=max(ans,h[i]*n);
            else if(val1==-1) ans=max(ans,h[i]*(i-val2+n-1-i));
            else if(val2==-1) ans=max(ans,h[i]*(i+val1-i));
            else ans=max(ans,h[i]*(i-val2-1+val1-i));
        }
        return ans;
    }
};
