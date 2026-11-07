class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Free servers: {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > free;

        // Busy servers: {finishTime, index}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // Initially all servers are free
        for (int i = 0; i < servers.size(); i++) {
            free.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {

            // Task i arrives at time i
            time = max(time, (long long)i);

            // Move all finished servers from busy -> free
            while (!busy.empty() && busy.top().first <= time) {

                int index = busy.top().second;
                busy.pop();

                free.push({servers[index], index});
            }

            // If no server is free,
            // jump time to the earliest server finishing
            if (free.empty()) {

                time = busy.top().first;

                // Move all servers that finish at this time
                while (!busy.empty() && busy.top().first <= time) {

                    int index = busy.top().second;
                    busy.pop();

                    free.push({servers[index], index});
                }
            }

            // Pick server with:
            // 1. smallest weight
            // 2. smallest index
            int index = free.top().second;
            free.pop();

            ans.push_back(index);

            // Server becomes busy
            busy.push({
                time + tasks[i],
                index
            });
        }

        return ans;
    }
};