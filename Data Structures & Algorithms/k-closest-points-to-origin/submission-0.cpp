class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0 ; i < points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            pq.push({x*x + y*y,i});
            
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while(pq.size() > 0)
        {
            result.push_back(points[pq.top().second]);
            pq.pop();

        }

       return result;



    }
};