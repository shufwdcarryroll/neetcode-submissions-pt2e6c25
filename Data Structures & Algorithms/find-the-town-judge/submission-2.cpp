class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    if (trust.empty()) return n == 1 ? 1 : -1;

    set<int> s;
    set<int> trusted;
    set<int> trusts;


    for (int i = 1; i <= n; i++) {
        s.insert(i);
    };

    unordered_map<int,int> mp;

        for(int i = 0 ; i < trust.size(); i++)
        {
            trusted.insert(trust[i][1]);
            trusts.insert(trust[i][0]);

            mp[trust[i][1]]++;
            // need to make a set which has trusted person list
            // need to make a set which has 
        }

        for (auto& [key, val] : mp) {
            if (val == n - 1 && trusts.find(key) == trusts.end()) {
                return key;
            }
      }

      return -1;
    }
};