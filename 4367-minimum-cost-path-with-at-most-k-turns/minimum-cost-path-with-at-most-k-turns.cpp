class Solution {
public:
    int solve(int x,int y,int dir,int turn,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp){
        if(turn<0){
            return 1e9;
        }
        if(x==grid.size()-1&&y==grid[0].size()-1){
            return 0;
        }
        if(dp[x][y][dir][turn]!=-1){
            return dp[x][y][dir][turn];
        }
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int ans=1e9;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=grid.size()||ny<0||ny>=grid[0].size()){
                continue;
            }
            if(i==0&&dir==2||i==1&&dir==1||i==2&&dir==4||i==3&&dir==3){
                continue;
            }
            int nTurn;
            if(dir==0||i==0 &&dir==1||i==1&&dir==2||i==2&&dir==3||i==3&&dir==4){
                nTurn =turn;
            }else{
                 nTurn=turn-1;
            }
            int nDir;
            if(i==0){
                nDir=1;
            }else if(i==1){
                nDir=2;
            }else if(i==2){
                nDir=3;
            }else{
                nDir=4;
            }
            ans=min(ans,solve(nx,ny,nDir,nTurn,grid,dp)+grid[nx][ny]);
           
            



        }
        return dp[x][y][dir][turn]= ans;
    }
    int minCost(vector<vector<int>>& grid, int k) {
       vector<vector<vector<vector<int>>>>dp(grid.size(),vector<vector<vector<int>>>(grid[0].size(),vector<vector<int>>(5,vector<int>(k+1,-1))));
        int ans= solve(0,0,0,k,grid,dp)+grid[0][0];
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};