class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long res = LLONG_MAX;
        long long sum = 0;
        multiset<int> small, large;

        for (int i = 1; i <= dist + 1; i++){
            small.insert(nums[i]);
            sum += nums[i];

            if (small.size() > k-1){
                auto it = prev(small.end());
                sum -= *it;

                large.insert(*it);
                small.erase(it);
            }
        }

        res = min(sum, res);

        for (int i = dist + 2; i < n; i++){
            int in = nums[i];
            int out = nums[i-dist-1];

            //out
            if (small.find(out) != small.end()){
                auto it = small.find(out);
                sum -= *it;
                small.erase(it);
                
                if (!large.empty()){
                    auto it = large.begin();
                    sum += *it;
                    small.insert(*it);
                    large.erase(it);
                }

            } else {
                large.erase(large.find(out));
            }


            //in

            small.insert(in);
            sum += in;

            if (small.size() > k-1){
                auto it = prev(small.end());
                sum -= *it;

                large.insert(*it);
                small.erase(it);
            }

            res = min(res, sum);

        }

        return nums[0]+res;
    }
};