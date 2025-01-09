class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int cnt = 0;
        if(words.size() == 0)
                return 0;
        for(const string word : words)
        {
            if(word.substr(0,n) == pref)
                cnt++;
            
        }
        return cnt;
    }
};
