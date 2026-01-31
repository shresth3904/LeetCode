class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = 'z'+1;

        for (char& c: letters){
            if (c > target){
                res = min(res, c);
            }
        }

        return (res == 'z'+1)? letters[0]: res;
    }
};