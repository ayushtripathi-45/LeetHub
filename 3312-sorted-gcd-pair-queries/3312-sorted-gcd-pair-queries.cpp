class Solution {
public:
    int getGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int binarySearch(const std::vector<long long>& prefixSums, long long query_val) {
        int low = 1;
        int high = prefixSums.size() - 1;
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (prefixSums[mid] > query_val) {
                answer = mid;      
                high = mid - 1;    
            } else {
                low = mid + 1;     
            }
        }
        return answer;
    }

    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }

        std::vector<int> count(maxVal + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

        std::vector<long long> multiples(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; ++i) {
            long long totalMultiples = 0;
            for (int j = i; j <= maxVal; j += i) {
                totalMultiples += count[j];
            }
            multiples[i] = totalMultiples;
        }

        std::vector<long long> exactGcdPairs(maxVal + 1, 0);
        for (int i = maxVal; i >= 1; --i) {
            
            long long totalPairs = (multiples[i] * (multiples[i] - 1)) / 2;
            
           
            for (int j = 2 * i; j <= maxVal; j += i) {
                totalPairs -= exactGcdPairs[j];
            }
            exactGcdPairs[i] = totalPairs;
        }

       
        std::vector<long long> prefixSums(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; ++i) {
            prefixSums[i] = prefixSums[i - 1] + exactGcdPairs[i];
        }

        std::vector<int> answer(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            answer[i] = binarySearch(prefixSums, queries[i]);
        }

        return answer;
    }
};