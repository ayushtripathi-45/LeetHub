class Solution(object):
    def maximumProduct(self, nums):
        nums.sort()
        n = len(nums)

        multi_start = nums[0] * nums[1] * nums[n-1]

        multi_end = nums[n-1] * nums[n-2] * nums[n-3]

        return max(multi_start, multi_end)