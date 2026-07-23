class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1)return 1;
        if(nums.size()==2)return 2;
        int maxn=*max_element(nums.begin(),nums.end());
        return 1 << bits(maxn);
    }
    int bits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n >>= 1;
    }
    return cnt;
}
};