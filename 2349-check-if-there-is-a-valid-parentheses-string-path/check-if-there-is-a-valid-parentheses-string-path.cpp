class Solution {
public:
    bool solve(int i,int j,int cnt,vector<vector<char>>&grid,vector<vector<vector<int>>>&dp){
        if(cnt<0){
            return false;
        }
        if(i>=grid.size()||j>=grid[0].size()){
            return false;
        }
        
        if(i==grid.size()-1&&j==grid[0].size()-1){
            cnt=cnt-1;
            return cnt==0;

        }
        if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
        }
        if(grid[i][j]=='('){
            
            return dp[i][j][cnt]=(solve(i+1,j,cnt+1,grid,dp)||solve(i,j+1,cnt+1,grid,dp));
        }
        
        return dp[i][j][cnt]=  (solve(i+1,j,cnt-1,grid,dp)||solve(i,j+1,cnt-1,grid,dp));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[m-1][n-1]=='('){
            return false;
        }
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(201,-1)));
        return solve(0,0,0,grid,dp);
    }
};