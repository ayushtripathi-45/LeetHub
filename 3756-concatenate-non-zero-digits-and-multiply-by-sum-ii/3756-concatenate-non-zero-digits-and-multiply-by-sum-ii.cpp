class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long mod = 1000000007; // 1e9 + 7 ko simple number mei likha
        
        // 1. Powers of 10 nikalna (Modulo ke sath)
        long long pow[100001];
        pow[0] = 1;
        for (int i = 1; i < 100001; i++) {
            pow[i] = (pow[i - 1] * 10) % mod;
        }

        // 2. Prefix Arrays banana simple 0-initialization ke sath
        vector<long long> pref(n + 1, 0);  // Sum store karne ke liye
        vector<long long> numbs(n + 1, 0); // Number store karne ke liye
        vector<long long> len(n + 1, 0);   // Non-zero digits ka count rakhne ke liye

        // 3. String ko traverse karke prefix calculation karna (Simple if-else ke sath)
        for (int i = 0; i < n; i++) {
            int digi = s[i] - '0'; // Character ko integer digit mei badla
            
            // Sum hamesha normal add hota rahega
            pref[i + 1] = pref[i] + digi;

            // Agar digit 0 se bada hai (Non-zero)
            if (digi > 0) {
                numbs[i + 1] = (numbs[i] * 10 + digi) % mod; // Naya number banaya
                len[i + 1] = len[i] + 1;                     // Length ko 1 badhaya
            } 
            // Agar digit '0' hai toh pichli values hi aage copy ho jayengi
            else {
                numbs[i + 1] = numbs[i]; 
                len[i + 1] = len[i];
            }
        }

        // 4. Queries ko process karna
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1; // 1-indexed offset adjustment

            // Dono indices ke bich kitne non-zero characters hain
            int lensubstr = len[r] - len[l];

            // Substring se number alag karne ka math formula
            long long multi = (numbs[l] * pow[lensubstr]) % mod;
            long long num = (numbs[r] - multi + mod) % mod; // +mod kiya taaki negative value na aaye

            // Range ka sum
            long long currsum = pref[r] - pref[l];

            // Final answer dono ka product modulo mod ke sath
            long long prod = (num * currsum) % mod;

            ans.push_back(prod);
        }

        return ans;
    }
};