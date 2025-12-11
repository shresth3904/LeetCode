class Solution {
public:
    bool isPall(string s, int start, int end){
        while (start <= end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        bool one = false;
        while (left <= right){
            if (s[left] != s[right]){
               return (isPall(s, left+1, right) || isPall(s, left, right-1));
            }
            left++;
            right--;
        }

        return true;
    }
};