class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        int current_max = 0;
        
        // Step 1 & 2: Build the prefixGcd array in-place
        for (int i = 0; i < n; ++i) {
            current_max = std::max(current_max, nums[i]);
            nums[i] = std::gcd(nums[i], current_max);
        }
        
        // Step 3: Sort the prefixGcd array in non-decreasing order
        std::sort(nums.begin(), nums.end());
        
        // Step 4: Form pairs from both ends and calculate the total sum
        long long total_sum = 0;
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            total_sum += std::gcd(nums[i], nums[j]);
            i++; // Move to the next smallest element
            j--; // Move to the next largest element
        }
        
        return total_sum;
    }
};