class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        stack<char> st;
        vector<bool>has(26,false);
        for(int i=0;i<s.length();i++){
            //agar wo character nahi hai
            if(has[s[i]-'a']==false){
                while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
                    has[st.top()-'a']=false;
                    st.pop();
                }
                st.push(s[i]);
                has[s[i]-'a']=true;
            }
            freq[s[i]-'a']--;
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};