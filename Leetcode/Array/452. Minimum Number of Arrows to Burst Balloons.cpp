class Solution {
public:
    
    static bool comp(const vector<int>& vec1, const vector<int>& vec2)
    {
	    return vec1[1] < vec2[1];
    }
	
	int findMinArrowShots(vector<vector<int>>& points) 
    {
		if (points.size() <= 1) 
			return points.size();
			
		sort(points.begin(), points.end(), comp);

		int minNumArrow = 0;
		int tmp = points[0][1];

		for (int i = 1; i < points.size(); i++)
		{
			minNumArrow += points[i][0] > tmp;
			tmp = points[i][0] > tmp ? points[i][1] : tmp;
		}

		return minNumArrow + 1;
    }
};
