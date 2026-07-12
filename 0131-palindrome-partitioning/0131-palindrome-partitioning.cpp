class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, temp, ans);

        return ans;
    }

    void solve(string &s, int start, vector<string> &temp, vector<vector<string>> &ans) {

        // We have partitioned the entire string
        if (start == s.length()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start; end < s.length(); end++) {

            string curr = s.substr(start, end - start + 1);

            if (isPalindrome(curr)) {

                // Choose
                temp.push_back(curr);

                // Explore
                solve(s, end + 1, temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string str) {
        int i = 0;
        int j = str.length() - 1;

        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};