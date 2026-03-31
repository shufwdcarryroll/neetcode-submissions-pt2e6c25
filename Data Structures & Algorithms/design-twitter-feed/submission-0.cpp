class Twitter {
    int timestamp;
    struct Tweet {
        int id;
        int time;
        Tweet(int _id, int _time) : id(_id), time(_time) {}
    };
    
    unordered_map<int, vector<Tweet>> userTweets; // userId -> list of tweets
    unordered_map<int, unordered_set<int>> followers; // userId -> set of followees
    
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(tweetId, timestamp++);
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](Tweet &a, Tweet &b){ return a.time < b.time; };
        priority_queue<Tweet, vector<Tweet>, decltype(cmp)> pq(cmp);
        
        // Add user's own tweets
        for (auto &t : userTweets[userId]) pq.push(t);
        
        // Add followees' tweets
        for (int followeeId : followers[userId]) {
            for (auto &t : userTweets[followeeId]) pq.push(t);
        }
        
        vector<int> res;
        int count = 0;
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().id);
            pq.pop();
            count++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
