class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<int> left;
    vector<int> right;
    
    int l=0; 
    int r = nums.size()-1;
    
    int mid = l+(r-l)/2;        

    for(int i = 0; i<=mid; i++){
        left.push_back(nums[i]);
    }
    for(int k = mid+1; k<nums.size(); k++){
        right.push_back(nums[k]);
    }
    
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    
    
    int even_fill=0;
    for(int i=0; i<left.size(); i++){
        nums[even_fill]=left[i];
        even_fill+=2; //jump by 2
    }
    int odd_fill =1;
    for(int i=0; i<right.size(); i++){
        nums[odd_fill]=right[i];
        odd_fill+=2;  //jump by 2
    }
    }
};
