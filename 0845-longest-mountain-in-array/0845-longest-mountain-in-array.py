class Solution(object):
    def longestMountain(self, arr):
        n = len(arr)
        maxlength = 0

        for i in range(1, n - 1):

            if arr[i - 1] < arr[i] > arr[i + 1]:

                left = i
                while left > 0 and arr[left - 1] < arr[left]:
                    left -= 1

                right = i
                while right < n - 1 and arr[right] > arr[right + 1]:
                    right += 1

                currentmountainlen = right - left + 1
                maxlength = max(maxlength, currentmountainlen)
                
        return maxlength