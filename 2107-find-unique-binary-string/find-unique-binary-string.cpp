class Solution {
public:
    int strTObin(string s){
        int res = 0;
        int n = s.size();
        int val = 1;
        while (n--){
            res += (s[n]-'0')*val;
            val *= 2;
        }

        return res;
    }

    string toBin(int n, int size){
        string res = "";
        if (n == 0) res = "0";
        
        else {
            while (n > 0){
                res = char('0' + n%2) + res;
                n /= 2;
            }
        }
        
        int rem = size - res.size();
        while (rem--) res = '0' + res;
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();

        vector<bool> hash(1<<n, false);
        for (string s: nums) hash[strTObin(s)] = true;

        for (int i = 0; i < 1<<n; i++){
            if (!hash[i]){
                return toBin(i, n);
            }
        }

        return "";
    }
};


// 31 = 11111