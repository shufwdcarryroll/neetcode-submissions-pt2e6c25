class Solution {
public:
    static bool comp(string a , string b)
    {
        return a + b > b +a;
    };
    string largestNumber(vector<int>& nums) {
        vector<string> numS;
        for(int n : nums)
        {
            numS.push_back(to_string(n));
        }

        sort(numS.begin(), numS.end(), comp);

        string s;
        if (numS[0] == "0") return "0";

        for(string t : numS)
        {
            s += t;
        }

        return s;

        
    }
};