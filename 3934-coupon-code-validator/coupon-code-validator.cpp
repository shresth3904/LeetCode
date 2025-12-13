class Solution {
public:
    bool validate(string s){
        if (s == "") return false;
        for (char c: s){
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_'))){
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics;
        vector<string> grocery;
        vector<string> pharmacy;
        vector<string> restaurant;
        
        int n = code.size();

        for (int i = 0; i < n; i++){
            if (validate(code[i]) && isActive[i]){
                string st = businessLine[i];
                if (st == "electronics") electronics.push_back(code[i]);
                else if (st == "grocery") grocery.push_back(code[i]);
                else if (st == "pharmacy") pharmacy.push_back(code[i]);
                else if (st == "restaurant") restaurant.push_back(code[i]);
            }
        }

        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        vector<string> res;

        for (string s: electronics) res.push_back(s);
        for (string s: grocery) res.push_back(s);
        for (string s: pharmacy) res.push_back(s);
        for (string s: restaurant) res.push_back(s);
        
        return res;
    }
};