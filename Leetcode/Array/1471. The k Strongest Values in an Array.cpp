class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> vect;
        int med=arr[((int)arr.size()-1)/2];
        int start=0,end=(int)arr.size()-1;
        while(vect.size()!=arr.size()){
            if(abs(med-arr[start])>abs(med-arr[end])){
                vect.push_back(arr[start]);
                start++;
             }
            else{
                vect.push_back(arr[end]);
                end--;
            }
        }
        vector<int> vect2;
        for(int i=0;i<k;i++) vect2.push_back(vect[i]);
        return vect2;
    }
};
