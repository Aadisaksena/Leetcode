class Solution {
public:
    int numTrees(int n) {
        return uniqtre(n);
    }
    int uniqtre(int n){
        if(n==0)return 1;
        if(n==1)return 1;
        int ans=0;
        for(int i=1;i<=n;i++){
            //for a given index
            ans+=uniqtre(i-1)*uniqtre(n-i);
        }

        return ans;
    }
};