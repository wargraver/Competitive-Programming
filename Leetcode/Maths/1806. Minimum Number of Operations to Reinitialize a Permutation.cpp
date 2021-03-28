int condition(vector<int> vect){
    int i,n=vect.size();
    for(i=0;i<n;i++){
        if(vect[i]==i) continue;
        else return 0;
    }
    return 1;
}
class Solution {
public:
    int reinitializePermutation(int n) {
        int i,j,k,ct=0;
        vector<int> vect1,vect2;
        for(i=0;i<n;i++) vect2.push_back(i);
        for(i=0;i<n;i++) vect1.push_back(-1);
        while(condition(vect1)!=1){
            for(i=0;i<n;i++){
                if(i%2==0) vect1[i] = vect2[i/2];
                else vect1[i] = vect2[n/2 +(i-1)/2];
            }
            for(i=0;i<n;i++) vect2[i]=vect1[i];
            ct++;
        }
        return ct;
    }
};
