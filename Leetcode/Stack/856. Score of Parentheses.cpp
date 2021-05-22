class Solution {
public:
    int scoreOfParentheses(string s) {
        int i,j,k,n,m,ct=0,ans=0;
        n=s.size();
        stack<int> st;
        i=0;
        while(i<n){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                k = st.top();
                st.pop();
                if(k==0){
                    if(st.empty()) ans+=1;
                    else st.top()+=1;
                }
                else{
                    if(st.empty()) ans+=2*k;
                    else st.top()+=2*k;
                }
            }
            i++;
        }
       return ans;
    }
};

/*
()()() = 1+1+1 = 3
(()()()) = 2*(1+1+1) = 6
((()())()) = 2*(2(1+1)+1) = 10
(()(())) = 2*(1+2*(1)) = 6
((())) = 2*(2*(1)) = 4

*/
