class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> result;
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0 ;

        while (i >= 0 || j >= 0 || carry > 0) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;
            int bitB = (j >= 0) ? b[j--] - '0' : 0;

            int sum = bitA + bitB + carry;
            carry = sum / 2;
            result.push_back('0' + sum % 2);  // ← fix here

        }

        reverse(result.begin(),result.end());
        std::string str(result.begin(), result.end());

        return str;
    }
};


