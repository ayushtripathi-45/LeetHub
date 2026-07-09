class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n);
        group[0] = 0;

        int currG = 0;

        for(int i = 1; i<n; i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                group[i] = currG;
            }else{
                currG++;
                group[i] = currG;
            }
        }
        vector<bool> ans;

        for(int i = 0; i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(group[u] == group[v]){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};