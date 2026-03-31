class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {1};

        vector<int> result(n, 1);

        // Prefix pass: product of elements before i
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Suffix pass: product of elements after i
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};
