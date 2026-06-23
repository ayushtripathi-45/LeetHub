class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int total_sum = 0;
 
        for (int i = 0; i < nums.size(); i += 2) {
            total_sum += nums[i];
        }
        
        return total_sum;
    }
};