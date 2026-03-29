class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++){
            while (!q.empty() && nums[i] > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);

            while (!q.empty() && i - q.front() >= k) q.pop_front();

            if (i >= k-1) res.push_back(nums[q.front()]);
        }

        return res;
    }
};