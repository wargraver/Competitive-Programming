class Solution {
public:
    int search(vector<int> vect,int val){
        int low=0,high=vect.size()-1,i,ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(vect[mid]>=val){
                ans = vect[mid];
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    string removeDuplicateLetters(string s) {
        string str;
        int i,j,k,n,m,ct=0;
        n=s.size();
        vector<pair<vector<int>,int>> vect;
        for(i=0;i<26;i++){
            vector<int> temp;
            vect.push_back(make_pair(temp,0));
        }
        for(i=0;i<n;i++){
            vect[s[i]-'a'].first.push_back(i);
           // cout<<s[i]-'a'<<endl;
            
            //it.first.push_back(i);
        }
        for(i=0;i<26;i++) if(vect[i].first.size()!=0) ct++;
        int curr = 0,min_ind=-1;
    /*   for(i=0;i<26;i++){
            for(auto x:vect[i].first) cout<<x<<" ";
            cout<<endl;
        }*/
        while(str.size()!=ct){
            for(i=0;i<26;i++){
            if(vect[i].first.size()==0 || vect[i].second==1) continue;
            else{
                int flag=0;
                int new_min = search(vect[i].first,min_ind);
                //if(i==5 && str[ct-1]=='l'&& min_ind==0) cout<<new_min<<endl;
                if(new_min==-1) continue;
                 for(j=0;j<26;j++){
                     if(j==i || vect[j].first.size()==0 || vect[j].second==1) continue;
                     else{
                         if(j!=i && new_min<vect[j].first[vect[j].first.size()-1]) continue;
                         else flag=1;
                     }
                 }
                if(flag==0) {
                    str+= char(97+i);
                   // cout<<char(97+i)<<" "<<new_min<<endl;
                    curr++;
                    min_ind = new_min;
                    vect[i].second = 1;
                    break;
                }
                else continue;
            }
            }
        }
        return str;
    }
};
