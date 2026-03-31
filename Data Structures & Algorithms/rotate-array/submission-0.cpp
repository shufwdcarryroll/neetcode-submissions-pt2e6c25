class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len; // In case k > len
        vector<int> rot(len);

        for(int i = 0; i < len; i++) {
            rot[i] = nums[(i - k + len) % len];
        }

        nums = rot;
    }
};
