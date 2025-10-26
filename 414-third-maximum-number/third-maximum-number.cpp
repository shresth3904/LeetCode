class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN;
        long long b = LLONG_MIN;
        long long c = LLONG_MIN;

        for (int i: nums){
            if (i > a){
                c = b;
                b = a;
                a = i;
            }

            else if (i > b && i != a){
                c = b;
                b = i;
            }

            else if (i > c && i != b && i != a){
                c = i;
            }
        }


        return (c == LLONG_MIN) ? (int)a : (int)c;
    }
};