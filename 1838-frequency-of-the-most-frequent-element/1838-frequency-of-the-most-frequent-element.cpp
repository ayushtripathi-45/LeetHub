class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> uniqueNums(counts.begin(), counts.end());

        int left = 0;
        int maxFreq = 0;
        long long currentSum = 0;
        long long countInWindow = 0;

        for (int right = 0; right < uniqueNums.size(); right++) {
            long long val = uniqueNums[right].first;
            long long count = uniqueNums[right].second;

            currentSum += val * count;
            countInWindow += count;

            // Shrink ONE instance at a time from the left frequency group
            while (countInWindow * val - currentSum > k) {
                currentSum -= uniqueNums[left].first;
                countInWindow--;
                uniqueNums[left].second--;

                // Move left pointer only when the frequency group is completely exhausted
                if (uniqueNums[left].second == 0) {
                    left++;
                }
            }

            maxFreq = max(maxFreq, (int)countInWindow);
        }

        return maxFreq;
    }
};