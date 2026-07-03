class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (true) {
                if(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i] - 1]);
                else
                break;
            }
        }
    int i=0;
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1){
                break;
            }
        }

       
     return i+1;


    }
};