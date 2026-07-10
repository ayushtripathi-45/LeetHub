class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        int maxL = log2(n) + 2;
        vector<vector<int>> up(maxL, vector<int>(n));

        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff) {
                r++;
            }
            up[0][l] = r; 
        }

        for (int j = 1; j < maxL; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        auto getDistance = [&](int u, int v) -> int {
            if (u == v) return 0;
            if (up[0][u] >= v) return 1;       
            if (up[maxL - 1][u] < v) return -1; 

            int steps = 0;
            for (int j = maxL - 1; j >= 0; j--) {
                if (up[j][u] < v) {
                    steps += (1 << j);
                    u = up[j][u];
                }
            }
            return steps + 1;
        };

        int qz = queries.size();
        vector<int> ans(qz);
        for (int i = 0; i < qz; i++) {
            int u = pos[queries[i][0]];
            int v = pos[queries[i][1]];
           
            if (u > v) swap(u, v);
            
            ans[i] = getDistance(u, v);
        }

        return ans;
    }
};