class Solution {
public:
    void gen(string num, int index, long long sum, long long prev,
             vector<string>& output, string curr_str, int target) {
        if (index == num.size()) {
            if (sum == target) {
                output.push_back(curr_str);
            }
            return;
        }
        string operand = "";
        int jump = 0;
        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                break;
            operand += num[i];
            long long focus = stoll(operand);
            jump++;
            if (index == 0)
                gen(num, i + 1, focus, focus, output, operand, target);
            else {

                gen(num, i + 1, sum + focus, focus, output,
                    curr_str + '+' + operand, target);
                gen(num, i + 1, sum - focus, -focus, output,
                    curr_str + '-' + operand, target);
                long long res = (sum - prev) + (focus * prev);
                gen(num, i + 1, res, prev * focus, output,
                    curr_str + '*' + operand, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> output;
        string s = "";
        gen(num, 0, 0, 0, output, s, target);
        return output;
    }
};