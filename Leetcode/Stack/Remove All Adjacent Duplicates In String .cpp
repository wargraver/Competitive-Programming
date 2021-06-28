class Solution {
public:
    string removeDuplicates(string s) {
        int i,j,k,n = s.size(),m,ct=0;
        stack<char> st;
        for(i=0;i<n;i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(st.top()==s[i]) st.pop();
                else st.push(s[i]);
            }
        }
        string ans;
        while(st.empty()==false){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
