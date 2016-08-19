// 不是最优的代码...
class Twitter {
    int time;
    unordered_map<int, set<int> > followers;
    unordered_map<int, vector<pair<int, int> > > homeTimeLine;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    // time complexity: O(1)
    void postTweet(int userId, int tweetId) {
        homeTimeLine[userId].push_back({time++, tweetId});
    }

    struct compare {
        bool operator() (const pair<int, int>& l, const pair<int, int>& r) {
            return l.first > r.first;
        }
    };

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    // time complexity: ( O(homeTimeLine[userId) + sum of O(homeTimeLine[followee]) ) * O(log10)
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, compare> Q;
        for (auto tweet: homeTimeLine[userId]) {
            Q.push(tweet);
            if (Q.size() > 10) Q.pop();
        }

        for (auto followee: followers[userId]) {
            for (auto tweet: homeTimeLine[followee]) {
                Q.push(tweet);
                if (Q.size() > 10) Q.pop();
            }
        }

        vector<int> newsFeed(Q.size());
        int count = Q.size();
        while (!Q.empty()) {
            newsFeed[--count] = Q.top().second; Q.pop();
        }
        return newsFeed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    // pay attention to the test case when one follower follow itself, it's illegal
    // time complexity: O(1)
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId && followers[followerId].find(followeeId) == followers[followerId].end())
            followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    // time complexity: O(1)
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && followers[followerId].find(followeeId) != followers[followerId].end())
            followers[followerId].erase(followeeId);
    }
};