class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> r = {
            {'I', 1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int sum_val = 0;
        int i = 0;
        int size = s.size();

        while (i < size)
        {
            if(i < size-1 && r[s[i]] < r[s[i+1]])
            {
                sum_val += r[s[i+1]] - r[s[i]];
                i += 2;
            }
            else
            {
                sum_val += r[s[i]];
                i += 1;
            }
        }
        return sum_val;
    }
};
