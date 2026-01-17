class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        deque<int> mainq;
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++){
            while (!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
            mainq.push_back(nums[i]);
            if (mainq.size() == k){
                res.push_back(q.front());
                int temp = mainq.front();
                mainq.pop_front();
                if (temp == q.front()) q.pop_front();
            }
        }

        return res;

    }
};