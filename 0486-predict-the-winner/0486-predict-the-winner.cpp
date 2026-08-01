class Solution {
public:

    bool helper(vector<int>& nums, int p1, int p2, int i, int j, int turn){
        if (i>j){
            return p1>=p2;
        }

        if (turn == 1){
            return helper(nums, p1+nums[i], p2, i+1, j, turn*-1)||helper(nums, p1+nums[j], p2, i, j-1, turn*-1);
        }
        else{
            return helper(nums, p1, p2+nums[i], i+1, j, turn*-1)&&helper(nums, p1, p2+nums[j], i, j-1, turn*-1);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return helper(nums, 0, 0, 0, nums.size()-1, 1);
    }
};