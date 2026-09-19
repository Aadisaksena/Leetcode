class Solution {
public:
    bool differByOne(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;

            if (diff > 1)
                return false;
        }

        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        // endWord must exist
        // bool found = false;
        // for (string word : wordList) {
        //     if (word == endWord) {
        //         found = true;
        //         break;
        //     }
        // }

        // if (!found)
        //     return 0;

        // Add beginWord to the list
        wordList.push_back(beginWord);

        int n = wordList.size();

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (differByOne(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Find indices
        int start = n - 1;
        int target = -1;

        for (int i = 0; i < n - 1; i++) {
            if (wordList[i] == endWord) {
                target = i;
                break;
            }
        }

        // BFS
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int node = q.front();
                q.pop();

                if (node == target)
                    return level;

                for (int next : adj[node]) {

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            level++;
        }

        return 0;
    }
};