class Solution {
public:
    bool checkPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve( int st,string &s,vector<int>&dp){
        if(st>=s.size()){
            return 0;
        }
       
        if(checkPalindrome(s, st, s.size() - 1)){
            return 1;
        }
        int ans=1e9;
        if(dp[st]!=-1){
            return dp[st];
        }
        for(int i=st;i<s.size();i++){
            if(checkPalindrome(s, st, i)){
                ans=min(ans,1+solve(i+1,s,dp));
            }
        }
        return dp[st]=ans;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return solve(0,s,dp)-1;
    }
};