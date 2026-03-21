class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());

        queue<string> q;
        int n = wordList.size();
        q.push(beginWord);
        int length = 1;
        vector<bool> visited(n, false);
        while (!q.empty()){
            int k = q.size();

            for (int z = 0; z < k; z++){
                string top = q.front();
                q.pop();
                if (top == endWord) return length;
                for (int i = 0; i < top.size(); i++){
                    char ori = top[i];

                    for (char c = 'a'; c <= 'z'; c++){
                        if (c == ori) continue;
                        top[i] = c;
                        if (s.find(top) != s.end()){
                            q.push(top);
                            s.erase(top);
                        }
                    }

                    top[i] = ori;
                }
            }

            length++;
        }

        return 0;
    }
};