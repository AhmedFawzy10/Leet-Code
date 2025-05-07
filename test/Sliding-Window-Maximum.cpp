class Solution {
public:
    struct MonotonicQueue{
        queue<int> q;
        deque<int> pq;
        void push(int x)
        {
            while(!pq.empty() && x > pq.back())
            {
                pq.pop_back();
            }
            pq.push_back(x);
            q.push(x);
        }
        void pop()
        {
            if(pq.front() == q.front()) pq.pop_front();
            q.pop();
        }
        int max()
        {
            return pq.front();
        }
        bool empty()
        {
            return q.empty();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        MonotonicQueue mq;
        for(int i = 0; i < n; i++)
        {
            if(i < k)
                mq.push(nums[i]);
            else
            {
                ans.push_back(mq.max());
                mq.push(nums[i]);
                mq.pop();
            }
        }
        if(!mq.empty())ans.push_back(mq.max());
        return ans;
    }
};