class Solution {
public:
    int maxVowels(string s, int k) {
        int start=0;
        int end=start+k-1;
        int count=0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i]))
            count++;
        }
        int maxcount=count;
        while(end<s.length()-1){
            if(count>maxcount)
            maxcount=count;
            if(isvowel(s[start]))
            count--;
            start++;
            if(isvowel(s[end+1]))
            count++;
            end++;
        }
        if(count>maxcount)
        return count;
        return maxcount;
    }
    bool isvowel(char s){
         if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
         return true;
         return false;
    }
};