class Solution(object):
    def findUnsortedSubarray(self, nums):
        n = len(nums)
        if n <= 1:
            return 0
        
        l = 0
        r = n - 1

        while l < n - 1:
            if nums[l] > nums[l+1]:
                break
            l += 1
            
        if l == n - 1:
            return 0

        while r > 0:
            if nums[r] < nums[r-1]:
                break
            r -= 1

        subarray = nums[l:r+1]
        sub_min = min(subarray)
        sub_max = max(subarray)

        while l > 0 and nums[l-1] > sub_min:
            l -= 1

        while r < n - 1 and nums[r+1] < sub_max:
            r += 1
            
        return r - l + 1