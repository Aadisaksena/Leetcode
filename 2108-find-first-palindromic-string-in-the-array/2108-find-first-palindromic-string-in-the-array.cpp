class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(isPal(words[i]))
            return words[i];
        }
        return "";
    }
    bool isPal(string word){
        int start=0;
        int end=word.length()-1;
        while(start<=end){
            if(word[start]!=word[end])
            return false;
            start++;
            end--;
        }
        return true;
    }
};