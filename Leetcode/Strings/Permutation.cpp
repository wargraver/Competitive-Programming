class Solution {
public:
    bool check(int freq[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.size();i++) freq[s1[i]-'a']++;
        int i,j,k,n,m,ct=0;
        n=s1.size();m=s2.size();
        if(n>m) return false;
        ct=0;int freq2[26]={0};
        for(i=0;i<n;i++) freq2[s2[i]-'a']++;
        for(i=0;i<=m-n;i++){
            if(check(freq,freq2)) return true;
            freq2[s2[i]-'a']--;
            j = i+n;
            if(j<m) freq2[s2[j]-'a']++;
        }
        return false;
    }
};
