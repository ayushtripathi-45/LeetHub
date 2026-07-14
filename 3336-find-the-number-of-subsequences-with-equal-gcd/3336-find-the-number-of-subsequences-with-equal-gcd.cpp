class Solution {
private:
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int max_val = 200; 
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));

        dp[0][0] = 1;
        
        for (int num : nums) {

            vector<vector<int>> next_dp = dp;
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
 
                    int new_g1 = findGCD(g1, num);
                    next_dp[new_g1][g2] = (next_dp[new_g1][g2] + dp[g1][g2]) % MOD;

                    int new_g2 = findGCD(g2, num);
                    next_dp[g1][new_g2] = (next_dp[g1][new_g2] + dp[g1][g2]) % MOD;

                }
            }
            dp = next_dp;
        }
        long long total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }
        
        return total_pairs;
    }
};