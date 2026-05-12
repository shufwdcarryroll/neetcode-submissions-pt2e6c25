class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";

        for (string s : strs) {
            enc += to_string(s.size()) + "#" + s;
        }

        return enc;
    }

    vector<string> decode(string s) {
        vector<string> v;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // find '#'
            while (s[j] != '#') {
                j++;
            }

            // length of word
            int len = stoi(s.substr(i, j - i));

            // move after '#'
            j++;

            // extract word
            string word = s.substr(j, len);

            v.push_back(word);

            // move to next part
            i = j + len;
        }

        return v;
    }
};