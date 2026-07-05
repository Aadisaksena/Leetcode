class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
    return a.length() < b.length();
});
        vector<int> dp(words.size(),1);

        for(int i=0;i<words.size();i++){
            int max=0;
            for(int j=0;j<i;j++){
                if(Criteria(words[i],words[j]) && dp[j]>max){
                    max=dp[j];
                }
            }
            dp[i]=max+1;
        }
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
    bool Criteria(string &word1, string &word2) {
    // word1 should be exactly one character longer
    if (word1.length() != word2.length() + 1)
        return false;

    int i = 0, j = 0;
    int skipCount = 1;

    while (i < word1.length() && j < word2.length()) {
        if (word1[i] == word2[j]) {
            i++;
            j++;
        } else {
            skipCount--;
            if (skipCount < 0)
                return false;
            i++;   // Skip one character in the longer word
        }
    }

    return true;
}
    
};