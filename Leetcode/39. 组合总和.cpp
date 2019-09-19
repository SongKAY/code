class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	unordered_map<int, set<vector<int>>>dict;
	for (int i = 1; i <= target; i++)
	    for (int it : candidates) 
		if (i == it) dict[i].insert(vector<int>{it});
		else if (i > it)
		     for (auto ivec : dict[i - it]) {
			ivec.push_back(it);
			sort(ivec.begin(), ivec.end());
			if(dict[i].count(ivec)==0)
		            dict[i].insert(ivec);
		    }
	vector<vector<int>>ans;
	for (auto it : dict[target]) ans.push_back(it);
	return ans;
    }
};
