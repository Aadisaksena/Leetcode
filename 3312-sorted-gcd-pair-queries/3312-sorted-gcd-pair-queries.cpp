class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        // ---------------------- STEP 1 ----------------------
        // Find the maximum value in nums.
        // We only need to process gcd values up to this maximum.
        int mx = *max_element(nums.begin(), nums.end());

        // ---------------------- STEP 2 ----------------------
        // freq[x] = number of times x appears in nums.
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // ---------------------- STEP 3 ----------------------
        // gcdCnt[g] = number of pairs whose GCD is exactly g.
        vector<long long> gcdCnt(mx + 1, 0);

        // Process gcd values from largest to smallest.
        for (int g = mx; g >= 1; g--) {

            // Count how many numbers are divisible by g.
            long long divisible = 0;

            for (int multiple = g; multiple <= mx; multiple += g)
                divisible += freq[multiple];

            // Total pairs divisible by g.
            gcdCnt[g] = divisible * (divisible - 1) / 2;

            // Remove pairs whose gcd is actually a larger multiple of g.
            // This leaves only pairs with gcd exactly equal to g.
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                gcdCnt[g] -= gcdCnt[multiple];
        }

        // ---------------------- STEP 4 ----------------------
        // Build prefix array.
        // prefix[g] = number of pairs having gcd <= g.
        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + gcdCnt[g];

        // ---------------------- STEP 5 ----------------------
        // Answer each query using Binary Search.
        vector<int> ans;

        for (long long q : queries) {

            // Queries are 0-indexed.
            // We need the first gcd whose cumulative count > q.
            int gcdValue = lower_bound(prefix.begin() + 1,
                                       prefix.end(),
                                       q + 1) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};