class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> left(nums.begin(), nums.begin()+n);
        vector<int> right(nums.begin() + n, nums.end());

        auto getSum = [&](vector<int>& arr){
            vector<vector<int>> sums(n+1);
            int size = arr.size();
            for (int i = 0; i < (1 << size); i++){
                int sum = 0;
                int count = 0;
                for (int j = 0; j < n; j++){
                    if ((i >> j) & 1){
                        sum += arr[j];
                        count++;
                    }
                }

                sums[count].push_back(sum);
            }

            return sums;
        };

        vector<vector<int>> leftPart = getSum(left);
        vector<vector<int>> rightPart = getSum(right);

        for (auto& i: rightPart) sort(i.begin(), i.end());
        
        int min_ans = INT_MAX;

        for (int k = 0; k <= n; k++){
            int rightCount = n-k;
            for (int i: leftPart[k]){
                int target = totalSum/2 - i;
                auto& rightarr = rightPart[rightCount];
                int start = 0;
                int end = rightarr.size() - 1;

                while (start <= end){
                    int mid = start + (end -start)/2;
                    if (rightarr[mid] <= target) start = mid+1;
                    else end = mid-1;
                }

                if (end >= 0) min_ans = min(min_ans, abs(totalSum - 2*(i + rightarr[end])));
                if (end+1 < rightarr.size()) min_ans = min(min_ans, abs(totalSum - 2*(i + rightarr[end+1])));
                
            }
        }

        return min_ans;
        
    }
};