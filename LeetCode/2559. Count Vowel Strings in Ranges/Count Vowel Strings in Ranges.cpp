class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result;
        int n = words.size();
        vector<int> validWords(n, 0);
        
        
        for (int i = 0; i < n; i++) {
            char first = words[i].front();
            char last = words[i].back();
            if (isVowel(first) && isVowel(last)) {
                validWords[i] = 1;
            }
        }
        
       
        vector<int> prefix(n + 1, 0);  
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + validWords[i - 1];
        }

        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            result.push_back(prefix[ri + 1] - prefix[li]);
        }

        return result;
    }

private:
  
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
