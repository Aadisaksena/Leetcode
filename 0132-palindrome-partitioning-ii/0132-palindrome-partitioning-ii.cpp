class Solution {
public:

    int minCut(string s) {
        if(isPalindrome(s,0,s.length()-1))return 0;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solve(s,0 ,s.length()-1,dp);
    }
    int solve(string& s, int start,int end,vector<vector<int>>&dp){
        int ans=INT_MAX;
        if(isPalindrome(s,start,end))
        return 0;
        if(dp[start][end]!=-1)
        return dp[start][end];
        for(int k=start;k<end;k++){
            
            if(isPalindrome(s,start,k)){
                //we can either choose to partition ot extend the substr
                int partition = 1+solve(s,k+1,end,dp);
                ans=min(ans,partition);
            }
        }
        dp[start][end]=ans;
        return dp[start][end];
    }
   bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
};