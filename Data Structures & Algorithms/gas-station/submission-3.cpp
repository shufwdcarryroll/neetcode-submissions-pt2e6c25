class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIndex = 0;
        int totalGas = 0 ;
        int currentGas = 0;

        for(int i = 0 ; i < gas.size(); i++)
        {
            int def = gas[i] - cost[i];

            totalGas = totalGas + def;
            currentGas = currentGas + def;

            if(currentGas < 0)
            {
                startIndex = i+1;
                currentGas = 0;
            }

        }

        if(totalGas >= 0)
          return startIndex;

        return -1;

        
    }
};
