class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // cost[i] = minimum operations to make
        // nums[i ... i+x-1] equal
        vector<long long> cost(n - x + 1);

        multiset<long long> left, right;
        long long leftSum = 0, rightSum = 0;

        auto balance = [&]() {
            // left should contain the smaller half
            // right should contain the larger half

            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                long long val = *it;

                left.erase(it);
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }

            while (right.size() > left.size()) {
                auto it = right.begin();
                long long val = *it;

                right.erase(it);
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }
        };

        auto add = [&](long long val) {
            if (left.empty() || val <= *prev(left.end())) {
                left.insert(val);
                leftSum += val;
            } else {
                right.insert(val);
                rightSum += val;
            }

            balance();
        };

        auto remove = [&](long long val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                leftSum -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                rightSum -= val;
            }

            balance();
        };

        // Build the first window and slide
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                // Median is the largest element in left
                long long median = *prev(left.end());

                long long leftCost =
                    median * (long long)left.size() - leftSum;

                long long rightCost =
                    rightSum - median * (long long)right.size();

                cost[i - x + 1] = leftCost + rightCost;
            }
        }

        // DP
        //
        // dp[j] = minimum cost to choose j non-overlapping
        // windows among the part processed so far.
        //
        // We process windows from left to right.
        const long long INF = 4e18;

        vector<long long> dp(k + 1, INF);
        dp[0] = 0;

        for (int i = 0; i <= n - x; i++) {

            // Important: process backwards so that
            // this window isn't selected multiple times.
            for (int j = k; j >= 1; j--) {

                if (i == 0) {
                    if (j == 1)
                        dp[j] = min(dp[j], cost[i]);
                }
                else {
                    // Previous selected window must end
                    // before this window starts.
                    //
                    // Window i starts at i.
                    // Previous window can start at <= i-x.
                    //
                    // We therefore need a DP over positions.
                }
            }
        }

        // Easier and cleaner position-based DP
        vector<vector<long long>> f(
            n + 1,
            vector<long long>(k + 1, INF)
        );

        f[0][0] = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= k; j++) {

                // Don't start a window here
                f[i + 1][j] =
                    min(f[i + 1][j], f[i][j]);

                // Start a window at i
                if (j < k && i + x <= n &&
                    f[i][j] != INF) {

                    f[i + x][j + 1] =
                        min(
                            f[i + x][j + 1],
                            f[i][j] + cost[i]
                        );
                }
            }
        }

        return f[n][k];
    }
};