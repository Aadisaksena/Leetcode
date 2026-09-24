class Solution {
public:
    int smallestIndex(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
        if(sod(nums[i])==i)
        return i;
       } 
       return -1;
    }
    int sod(int n){
        int sum=0;
        while(n>0){
            int dig=n%10;
            sum+=dig;
            n/=10;
        }
        return sum;
    }
};