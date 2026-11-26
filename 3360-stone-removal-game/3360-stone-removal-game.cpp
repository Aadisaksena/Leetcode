class Solution {
public:
    bool canAliceWin(int n) {
        int i=10;
        while(n>=i){
            n=n-i;
            i=i-1;
        }
        if(i%2==0)
        return false;
        else return true;
    }
};