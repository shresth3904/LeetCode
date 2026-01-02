class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (int i = bookings.size()-1; i >= 0; i--){

            res[bookings[i][0]-1] += bookings[i][2];
            if (bookings[i][1] < n) res[bookings[i][1]] -= bookings[i][2];
        }

        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += res[i];
            res[i] = sum;
        }

        return res;
    }
};