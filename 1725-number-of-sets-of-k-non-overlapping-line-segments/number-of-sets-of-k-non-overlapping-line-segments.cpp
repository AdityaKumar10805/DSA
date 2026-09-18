class Solution {
public:
    const int MOD=1e9+7;
    int solve(int i,int curr,int &n,int &k,vector<vector<int>>&dp){
        if(curr==k){
            return 1;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        int  notTake=solve(i+1,curr,n,k,dp)%MOD;
        int take=0;
        for(int j=i+1;j<n;j++){
           take+= (solve(j,curr+1,n,k,dp)%MOD);
           take=take%MOD;
        }
        int ans=(1LL*take+notTake)%MOD;
        return dp[i][curr]= ans;
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        //bottom up approach
        for(int i=0;i<n;i++){
            dp[i][k]=1;
        }
        for(int i=0;i<=k;i++){
            dp[n][i]=0;
        }
        //
        for(int j=k-1;j>=0;j--){
            vector<int>suffix(n+1,0);
            suffix[n-1]=dp[n-1][j+1];
            for(int l=n-2;l>=0;l--){
                suffix[l]=(suffix[l+1]+dp[l][j+1])%MOD;
            }
            for(int i=n-1;i>=0;i--){
                int notTake=dp[i+1][j];
                int take=0;
                // for(int k=i+1;k<n;k++){
                //     take+=dp[k][j+1];
                //     take=take%MOD;
                // }
                take=suffix[i+1];

                int ans=(1LL*take+notTake)%MOD;
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
        
    }
};