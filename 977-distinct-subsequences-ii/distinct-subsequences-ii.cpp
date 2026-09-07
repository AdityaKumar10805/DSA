class Solution {
public:
    int distinctSubseqII(string s) {
        int ans=0;
        vector<int>dp(26);
        int mod=1e9+ 7;
        for(char c:s){
            int add=(ans-dp[c-'a']+mod)%mod;
            dp[c-'a']=1+ans;
            ans=(add+dp[c-'a'])%mod;
        }
        return ans;
    }
};