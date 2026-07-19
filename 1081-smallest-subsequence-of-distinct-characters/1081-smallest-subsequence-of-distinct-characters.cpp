class Solution {
public:
    string smallestSubsequence(string s) {
       
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        
        bool visited[26] = {false};
        
        string result = "";
       
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];
            
            count[currentChar - 'a']--;
            
            if (visited[currentChar - 'a']) {
                continue;
            }
           
            while (result.length() > 0 && result.back() > currentChar && count[result.back() - 'a'] > 0) {
                
                visited[result.back() - 'a'] = false;
               
                result.pop_back();
            }
            
            result.push_back(currentChar);
            visited[currentChar - 'a'] = true;
        }
        
        return result;
    }
};