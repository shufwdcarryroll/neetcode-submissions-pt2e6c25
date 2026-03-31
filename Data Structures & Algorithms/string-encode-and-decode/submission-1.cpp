class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            // Find the delimiter to get the length
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);
            result.push_back(word);

            i = j + 1 + len;
        }

        return result;
    }
};
