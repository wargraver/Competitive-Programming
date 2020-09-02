class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int diff,i,j,ct=0;
        vector<int> vect;
        int start=1,end=1+k;
        do{  if(end==start) {vect.push_back(start);break;}
            if(ct%2==0) {vect.push_back(start);start++;ct++;}
           else {vect.push_back(end);end--;ct++;}
           
        }while(abs(end-start)>=0);
        while(vect.size()!=n){
            vect.push_back(k+2);
            k++;
        }
        return vect;
    }
};
