class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return {};
        unordered_map<int,int>mp;
        vector<int> nums=arr;
        int x=1;
        sort(nums.begin(),nums.end());
        mp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
             if(nums[i]!=nums[i-1])
             x=x+1;
            mp[nums[i]]=x;
           
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};