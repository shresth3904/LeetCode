class Solution {
public:
    int shortestSubarray(vector<int>& num1, int k) {
        int n = num1.size();
        deque<int> q;
        int sum = 0;
        vector<long long> nums(n+1, 0);
        for (int i = 0; i < n; i++) {
            nums[i+1] = nums[i] + num1[i];
        }

        int len = INT_MAX;
        q.push_back(0);
        for (int i = 0; i <= n; i++){
            while (!q.empty() && nums[i] - nums[q.front()] >= k){
                len = min(len, i - q.front());
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] >= nums[i]){
                q.pop_back();
            }

            q.push_back(i);

        }

        return (len==INT_MAX)? -1: len;
    }
};