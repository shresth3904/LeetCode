class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for (int i = 0, n = operations.size(); i < n; i++){
            int len = record.size();
            if (operations[i] == "+") {
                record.push_back(record[len-1] + record[len-2]);
            }
            else if (operations[i] == "D") {
                record.push_back(record[len-1]*2);
            }
            else if (operations[i] == "C") {
                record.pop_back();
            }
            else record.push_back(stoi(operations[i]));
        }

        int res = 0;
        for (int i: record){
            res += i;
        }

        return res;
    }
};