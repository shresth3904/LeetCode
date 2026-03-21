class Solution {
public:
    bool match(string a, string b){
        int n = a.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            if (a[i] != b[i]) count++;
            if (count > 1) return false;
        }

        return (count == 1)? true: false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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

                for (int i = 0; i < n; i++){
                    if (visited[i]) continue;
                    if (match(wordList[i], top)){
                        if (wordList[i] == endWord) return length+1;
                        q.push(wordList[i]);
                        visited[i] = true;
                    }
                }
            }

            length++;
        }

        return 0;
    }
};