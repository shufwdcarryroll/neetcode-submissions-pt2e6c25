class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool ok1 = false, ok2 = false, ok3 = false;

        for (auto &t : triplets) {
            // Skip if any element exceeds target
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            if (t[0] == target[0]) ok1 = true;
            if (t[1] == target[1]) ok2 = true;
            if (t[2] == target[2]) ok3 = true;
        }

        return ok1 && ok2 && ok3;
    }
};
