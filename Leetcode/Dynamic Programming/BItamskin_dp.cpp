int n = req_skills.size();
		unordered_map<int,vector<int>> res;  // using unordered_map, we improve on time
        res.reserve(1 << n);    // using reserved space, we avoid rehash
        //map<int,vector<int>> res;
        res[0]={};
        unordered_map<string,int> skill_map;
        for(int i=0;i< req_skills.size();i++)
            skill_map[req_skills[i]]=i;
        
        for(int i=0;i<people.size();i++)
        {
            int curr_skill = 0;
            for(int j=0;j<people[i].size();j++)
                curr_skill |= 1<<skill_map[people[i][j]];
            
            for(auto it = res.begin();it!=res.end();it++)
            {
                int comb = it->first | curr_skill;
                if(res.find(comb)==res.end() || res[comb].size()>1+res[it->first].size())
                {
                    res[comb]=it->second;
                    res[comb].push_back(i);
                }       
            }
        }
        return res[(1<<n) -1];

//https://leetcode.com/problems/smallest-sufficient-team/
