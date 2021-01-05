class Solution {
public:
    int lengthOfSeq(unordered_set<int>& s, int key)
    {
        int count=1;
        if(s.find(key+1)!=s.end())
        {
            s.erase(key);
            count+=lengthOfSeq(s,key+1);
        }
        return count;
    }
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return nums.size();
        unordered_set<int> s;
        int seqLen=1;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end() && s.find(nums[i]+1)!=s.end())
            {
                seqLen=max(seqLen,lengthOfSeq(s,nums[i]));
            }
        }
        return seqLen;
    }
};
