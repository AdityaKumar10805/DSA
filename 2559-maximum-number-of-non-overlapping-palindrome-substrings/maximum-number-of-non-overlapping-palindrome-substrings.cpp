class Solution {
public:
    bool checkPalindrome(int st, int end, string &s, vector<vector<int>>& rem){
        // Base cases
        if (st >= end) return true;
        
        if (rem[st][end] != -1) {
            return rem[st][end];
        }
        
        // Properly reuse the inner substring subproblem
        if (s[st] == s[end]) {
            return rem[st][end] = checkPalindrome(st + 1, end - 1, s, rem);
        }
        
        return rem[st][end] = false;
    }
    int solve(int st,int &k,string &s,vector<int>&dp,vector<vector<int>>&rem){
        if(st>=s.size()){
            return 0;
        }
        int ans=0;
        if(dp[st]!=-1){
            return dp[st];
        }
        for(int i=st;i<s.size();i++){
            if(checkPalindrome(st,i,s,rem)){
                int add=0;
                if(i-st+1>=k){
                    add++;
                }
                ans=max(ans,solve(i+1,k,s,dp,rem)+add);
            }
        }
        return dp[st]= ans;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<int>>rem(n,vector<int>(n,-1));
        vector<int>dp(s.size(),-1);
        return solve(0,k,s,dp,rem);
    }
};