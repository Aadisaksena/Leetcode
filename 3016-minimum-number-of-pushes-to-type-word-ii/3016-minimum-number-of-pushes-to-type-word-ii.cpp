class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(int i=0;i<word.length();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int push=0;
        for(int i=0;i<26;i++){
            if(i<8){
                push=push+freq[i];
            }
            else if(i>=8 && i<16){
                push=push+freq[i]*2;
            }
            else if(i>=16 && i<24){
                push=push+freq[i]*3;
            }
            else push=push+freq[i]*4;
        }
        return push;
    }
    
};