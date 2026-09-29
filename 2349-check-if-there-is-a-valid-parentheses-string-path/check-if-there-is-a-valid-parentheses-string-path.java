class Solution {
    boolean solve(int i,int j,int cnt,char[][] grid,Boolean[][][] dp){
        if(cnt<0){
            return false;
        }
        if(i>=grid.length||j>=grid[0].length){
            return false;
        }
        if(i==grid.length-1&&j==grid[0].length-1){
            return cnt==1;
        }
        if(dp[i][j][cnt]!=null){
            return dp[i][j][cnt];
        }
        if(grid[i][j]=='('){
            return dp[i][j][cnt]=solve(i+1,j,cnt+1,grid,dp)||solve(i,j+1,cnt+1,grid,dp);
        }
        return dp[i][j][cnt]=solve(i+1,j,cnt-1,grid,dp)||solve(i,j+1,cnt-1,grid,dp);
    }
    public boolean hasValidPath(char[][] grid) {
        
        int m=grid.length;
        int n=grid[0].length;
        if(grid[m-1][n-1]=='('){
            return false;
        }
        Boolean[][][] dp=new Boolean[m][n][m+n];
        
        return solve(0,0,0,grid,dp);
    }
}