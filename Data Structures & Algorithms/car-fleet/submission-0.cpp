class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, double>> cars; 
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position descending (closest to target first)
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double currMaxTime = 0.0;
        for (auto &car : cars) {
            if (car.second > currMaxTime) {
                // New fleet
                fleets++;
                currMaxTime = car.second;
            }
            // else car merges with existing fleet
        }

        return fleets;
    }
};
