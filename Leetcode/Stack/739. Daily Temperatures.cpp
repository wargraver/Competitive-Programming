class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> st;
    int n=T.size();
    vector<int> vect(n,0);
    vect[n-1]=0;
    st.push(n-1);
    int j=n-2;
    for(j=n-2;j>=0;j--){
           while(st.empty()==false && T[st.top()]<=T[j]) st.pop();
            if(st.empty()==false) vect[j]=st.top()-j;
            st.push(j);
        }
        return vect;
        
    }
};
