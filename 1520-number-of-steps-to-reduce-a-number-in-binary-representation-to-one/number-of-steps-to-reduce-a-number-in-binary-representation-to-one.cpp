class Solution {
public:
    string addOne(string s){
        int n = s.size();
        for (int i = n-1; i >= 0; i--){
            if (s[i] == '0'){
                s[i] = '1';
                return s;
            }

            else {
                s[i] = '0';
            }
        }

        return '1' + s;
    }
    int numSteps(string s) {
        int n = s.size();
        int count = 0;

        while (s != "1"){
            count++;
            if (s.back() == '1'){
                s = addOne(s);
            }

            else {
                s.pop_back();
            }
        }

        return count;
    }
};