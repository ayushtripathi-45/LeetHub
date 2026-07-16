class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        int current_max = 0;
        for (int i = 0; i < n; ++i) {
            current_max = std::max(current_max, nums[i]);
            nums[i] = std::gcd(nums[i], current_max);
        }
        std::sort(nums.begin(), nums.end());
        long long total_sum = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            total_sum += std::gcd(nums[i], nums[j]);
            i++;
            j--; 
        }
        return total_sum;
    }
};