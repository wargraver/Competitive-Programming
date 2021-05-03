class Solution {
public:
    string removeDuplicates(string s, int k) {
          int i,j,n,m;
          n=s.size();
          stack<pair<char,int>> st;
          for(i=0;i<n;i++){
              if(st.empty()==true) st.push(make_pair(s[i],1));
              else{
                  auto it = st.top();
                  if(it.second==k-1 && it.first==s[i]){
                      while(it.first==s[i]){
                          st.pop();
                          if(st.empty()) break;
                          it=st.top();
                      }
                  }
                  else if(it.first==s[i]) st.push(make_pair(s[i],it.second+1));
                  else st.push(make_pair(s[i],1));
              }
          }
        string str;
        while(st.empty()==false){
            str+=st.top().first;
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
