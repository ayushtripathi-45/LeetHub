class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();

        auto cs = [] (vector<int>& int1, vector<int>& int2){
            if(int1[0] == int2[0]){
                return int1[1] > int2[1];
            }

            return int1[0] < int2[0];
        };

        sort(begin(intervals), end(intervals), cs);

        res.push_back(intervals[0]);

        for(int i = 1; i<n; i++){
            if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1]){
                continue;
            }
            res.push_back(intervals[i]);
        }
        return res.size();
    }
};