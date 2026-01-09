class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> st;
        int top = -1;
        for (int i: arr){
            if (top == -1){
                st.push_back(i);
                top++;
            }
            else if (st[top]*i > 0){
                st.push_back(i);
                top++;
            }
            
            else {
                while (top > -1 && st[top] > 0 && i < 0 && abs(st[top]) < abs(i)){
                    st.pop_back();
                    top--;
                }
                if (top > -1 && st[top] > 0 && i < 0 && abs(st[top]) == abs(i)){
                    st.pop_back();
                    top--;
                }
                else if (top == -1 || !(st[top] > 0 && i < 0)) {
                    st.push_back(i);
                    top++;
                }
            }
        }

        return st;
    }
};