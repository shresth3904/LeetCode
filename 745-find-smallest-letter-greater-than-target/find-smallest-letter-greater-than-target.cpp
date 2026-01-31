class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = 'z'+1;

        int left = 0; 
        int right = letters.size() -1;

        while (left <= right){
            int mid = left + (right-left)/2;
            if (letters[mid] > target){
                res = letters[mid];
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        return (res == 'z'+1)? letters[0]: res;
    }
};