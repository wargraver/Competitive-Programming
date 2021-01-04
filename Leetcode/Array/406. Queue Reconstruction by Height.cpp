bool myCompare(vector<int> x, vector<int> y) {
    if(x[0] != y[0]) return x[0] < y[0];
    else return x[1] > y[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int s = people.size();
        
        //1. Sort the people array by height in asc. if height is same, desc order of k value.
        sort(people.begin(), people.end(), myCompare);
        
        vector<vector<int>> ans(s);
        
        // Used to mark which all positions are set in the output array
        vector<bool> isTaken(s, false);
        
        // 2. Set the shortest height position
        ans[people[0][1]] = people[0];
        isTaken[people[0][1]] = true;
       
        // 3. Now we set the position of every pair in the order of sorted array
        for(int i = 1; i<s; i++) {
            int j = 0;
            int k = 0;
            
            // 4. Move until k reaches the current pair's person count attribute.
            while(k<people[i][1]) {
                if(!isTaken[j]) ++k;
                ++j;
            }
            
            //5. Find the next available index in the ans array.
            while(isTaken[j]) ++j;
            
            //6. Set the pair in ans and mark this index as taken
            ans[j] = people[i];
            isTaken[j] = true;
        }
        
        return ans;
    }
};
