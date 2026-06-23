class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        int total_sum = 0;
        int n = nums.size();

        int l = 0;
        while (l < n) {
            int r = l + 1; 

            total_sum += min(nums[l], nums[r]);

            l = r + 1; 
        }
        
        return total_sum;
    }
};
    