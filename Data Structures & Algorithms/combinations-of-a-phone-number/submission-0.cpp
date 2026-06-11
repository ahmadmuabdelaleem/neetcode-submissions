class Solution {
public:
    map<int, string> mp;
    vector<string> ans;
    void fill()
    {

        for(int i = 2; i <= 7; i++)
        {
            char c = 'a' + (i-2)*3;
            for(int j = 0; j < 3; j++, c++)
            {
                mp[i].push_back(c);
            }
        }
        mp[7].push_back('s');
        for(int i = 8; i <= 9; i++)
        {
            char c = 't' + (i-8)*3;
            for(int j = 0; j < 3; j++, c++)
            {
                mp[i].push_back(c);
            }
        }
        mp[9].push_back('z');
    }    
    void solve(string origin, string forming, int idx)
    {
        if(forming.size() == origin.size() && forming.size())
        {
            ans.push_back(forming);
            return;
        }

        for(int j = 0; j < mp[origin[idx]-'0'].size(); j++)
        {
            solve(origin, forming+mp[origin[idx]-'0'][j], idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        fill();
        solve(digits, "", 0);
        return ans;
    }
};
