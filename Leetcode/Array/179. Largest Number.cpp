bool great(int i,int j,vector<vector<int>> vect){
    int i1=i,i2=j;int k=0,ct=0;
    string str1,str2;
    for(i=0;i<vect[i1].size();i++) str1+=to_string(vect[i1][i]);
    for(i=0;i<vect[i2].size();i++) str1+=to_string(vect[i2][i]);
    for(i=0;i<vect[i2].size();i++) str2+=to_string(vect[i2][i]);
    for(i=0;i<vect[i1].size();i++) str2+=to_string(vect[i1][i]);
   // cout<<str1<<" "<<str2<<endl;
    for(i=0;i<str1.size();i++){
        if(str1[i]-str2[i]<0) return true;
        if(str1[i]-str2[i]>0) return false;
    }
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int i,j,k,n,m,ct=0;
        n=nums.size();
        vector<vector<int>> vect(n);
        for(i=0;i<nums.size();i++){
            k=nums[i];
            while(k!=0){
                m=k%10;
                vect[i].push_back(m);
                k=k/10;
            }
            if(nums[i]==0) vect[i].push_back(0);
            reverse(vect[i].begin(),vect[i].end());
        }
        for(i=0;i<n;i++){
            int max_index=0;
            for(j=1;j<n-i;j++){
                //cout<<max_index<<" "<<j<<" ";
                if(great(max_index,j,vect)==true){
                     max_index=j;
                    
                }
               // cout<<max_index<<endl;
            }
            int i1=n-1-i;
           // cout<<max_index<<endl;
            vector<int> temp1,temp2;
            temp1.clear();temp2.clear();
            if(i1==max_index) continue;
            for(j=0;j<vect[i1].size();j++) temp1.push_back(vect[i1][j]);
          //  for(j=0;j<temp1.size();j++) cout<<temp1[j];
            for(j=0;j<vect[max_index].size();j++) temp2.push_back(vect[max_index][j]);
            vect[i1].clear();vect[max_index].clear();
            //for(j=0;j<vect[i1].size();j++) cout<<vect[i1][j]<<" ";
            for(j=0;j<temp1.size();j++) {vect[max_index].push_back(temp1[j]);}
            for(j=0;j<temp2.size();j++) {vect[i1].push_back(temp2[j]);}
            }
        string str;
        for(i=vect.size()-1;i>=0;i--){
            for(j=0;j<vect[i].size();j++) str+=to_string(vect[i][j]);
        }
        string str2;int flag=0;
        for(i=0;i<str.size();i++){
            if(str[i]=='0' && flag==0) continue;
            else{flag=1;str2+=str[i];}
        }
        if(str2.size()==0) return "0";
        else return str2;
    }
};
