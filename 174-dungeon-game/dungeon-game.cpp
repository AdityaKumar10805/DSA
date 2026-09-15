class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dungeon,vector<vector<int>>&dp){
        if(i>=dungeon.size()||j>=dungeon[0].size()){
            return 1e9;
        }
        if(i==dungeon.size()-1&&j==dungeon[i].size()-1){
            return max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(i,j+1,dungeon,dp);
        int down =solve(i+1,j,dungeon,dp);
        int mini=min(right,down);
        return dp[i][j]= max(1,mini-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,dungeon,dp);
    }
};