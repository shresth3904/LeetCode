class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for (auto book: bookings){
            res[book[0]-1] += book[2];
            if (book[1] < n) res[book[1]] -= book[2];
        }

        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += res[i];
            res[i] = sum;
        }

        return res;
    }
};