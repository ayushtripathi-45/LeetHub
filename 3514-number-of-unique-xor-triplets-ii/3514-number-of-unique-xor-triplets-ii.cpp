class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            if (x > maxVal) {
                maxVal = x;
            }
        }

        int maxPossibleXor = 1;
        while (maxPossibleXor <= maxVal) {
            maxPossibleXor <<= 1;
        }
        maxPossibleXor = (maxPossibleXor << 1);

        vector<bool> seenPairs(maxPossibleXor, false);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                seenPairs[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> seenTriplets(maxPossibleXor, false);
        for (int x : nums) {
            for (int val = 0; val < maxPossibleXor; ++val) {
                if (seenPairs[val]) {
                    seenTriplets[val ^ x] = true;
                }
            }
        }

        int count = 0;
        for (int val = 0; val < maxPossibleXor; ++val) {
            if (seenTriplets[val]) {
                count++;
            }
        }

        return count;
    }
};