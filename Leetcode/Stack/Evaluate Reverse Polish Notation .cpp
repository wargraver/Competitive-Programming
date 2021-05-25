class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i,j,k,n,m,ct=0;
        n=tokens.size();
        stack<int> st;
        st.push(stoi(tokens[0]));
       // cout<<stoi(tokens[0]);
        int ans=0;i=1;
        while(i<tokens.size() && st.empty()==false){
            if(tokens[i].size()==1){
                if(tokens[i][0]-'0'>=0 && tokens[i][0]-'0'<=9){
                     st.push(stoi(tokens[i]));
                }
                else{
                    int m1 = st.top();st.pop();
                    int m2 = st.top();st.pop();
                    if(tokens[i][0]=='/') st.push(m2/m1);
                    else if(tokens[i][0]=='*') st.push(m2*m1);
                    else if(tokens[i][0]=='-') st.push(m2-m1);
                    else st.push(m2+m1);
                }
            }
            else st.push(stoi(tokens[i]));
            i++;
           
        }
        return st.top();
    }
};
