class Solution:
    def romanToInt(self, s: str) -> int:
        r = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}

        sum_val = 0
        size = len(s)
        i=0
        while i < size:
            if i < size-1 and r[s[i]] < r[s[i+1]]:
                sum_val += r[s[i+1]] - r[s[i]]
                i += 2
            else:
                sum_val += r[s[i]]
                i += 1
        return sum_val
