class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int ansinc=1,ansdec=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
            inc++;
            ansinc=max(ansinc,inc);
            }
            else
            inc=1;
        }
            for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
            dec++;
            ansdec=max(ansdec,dec);
            }
            else
            dec=1;
        }
        return max(ansinc,ansdec);
    }
};