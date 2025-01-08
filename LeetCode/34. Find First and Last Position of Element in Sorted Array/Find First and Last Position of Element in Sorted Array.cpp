class Solution {
public:
    vector<int> searchRange(vector<int>& num, int target) {
        int n = num.size();
        int cnt = 0;
        vector<int> temp;
        vector<int> ans;
        for(int i = 0;i < n ; i++)
        {
            if(num[i] == target)
            {
                temp.push_back(i);
                cnt++;
            }
        }
        if(temp.empty())
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(temp[0]);
        ans.push_back(temp[cnt-1]);
        return ans;
    }
};
