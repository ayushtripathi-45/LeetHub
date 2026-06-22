class Solution(object):
    def sortedSquares(self, nums):
        n = len(nums)
        res = [0] * n
        l = 0
        r = n - 1
        ind = 0
        
        while l <= r :
            lsq = nums[l] ** 2
            rsq = nums[r] ** 2

            if lsq > rsq:
                res[ind] = lsq
                l += 1

            else:
                res[ind] = rsq
                r -= 1

            ind += 1

        return res[::-1]

        