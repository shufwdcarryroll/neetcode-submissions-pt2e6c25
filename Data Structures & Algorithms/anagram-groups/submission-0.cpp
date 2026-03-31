class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            // Create a key by sorting the characters
            string key = str;
            sort(key.begin(), key.end());
            
            // Group words with the same key
            groups[key].push_back(str);
        }
        
        // Extract all groups into result vector
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
