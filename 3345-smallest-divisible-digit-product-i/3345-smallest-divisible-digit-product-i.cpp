class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            if(product(n)%t==0)return n;
            n=n+1;
        }
    }
    int product(int n){
        int p=1;
        while(n>0){
            int dig=n%10;
            p=p*dig;
            n/=10;
        }
        return p;
    }
};