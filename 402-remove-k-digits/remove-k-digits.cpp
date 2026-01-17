class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        for (char c: num){
            while (!st.empty() && k > 0 && st.back() > c){
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        while (!st.empty() && k > 0) {
            st.pop_back();
            k--;
        }

        int start = 0;
        while (!st.empty() && st[start] =='0') start++;
        string res = st.substr(start);
        return (res == "")? "0": res;
    }
};