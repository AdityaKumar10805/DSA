class Solution {
public:
    bool solve(int i,string s ,set<string>&st,vector<int>&dp){
        if(i>=s.size()){
            return true;
        }
        bool res=false;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int l=1;l<=20;l++){
            if(st.count(s.substr(i,l))){
                res=solve(i+l,s,st,dp);
                if(res){
                   return dp[i]= res;
                }
            }
        }
       return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        vector<int>dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};