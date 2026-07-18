class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int start=0;
        int end=k-1;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int total=0;
        while(end<arr.size()-1){
            if(sum/k>=threshold)
            total++;

            sum=sum-arr[start];
            start++;
            end++;
            sum=sum+arr[end];
        }
        if(sum/k>=threshold)
        return total+1;
        return total;
    }
};