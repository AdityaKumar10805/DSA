class Solution {
public:
    int findPow(int a,int b){
        if(b==0){
            return 1;
        }
        int half=findPow(a,b/2);
        int ans=half*half;
        if(b%2){
            ans=ans*a;
        }
        return ans;
    }
    int solve(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==0){
            return 0;
        }
        if(i>=nums.size()){
            return 1e9;
        }
        if(sum<0){
            return 1e9;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int case1=solve(i+1,sum,nums,dp);
        int case2=1e9;
        for(int k=0;nums[i]*findPow(2,k)<=sum;k++){
            int curr=nums[i]*findPow(2,k);
            int temp;
           temp= solve(i+1,sum-curr,nums,dp)+k;
           case2=min(case2,temp);
        }
        int case3=1e9;
        for(int k=1;nums[i]/findPow(2,k)>=1;k++){
            int curr=nums[i]/findPow(2,k);
            int temp;
            temp=solve(i+1,sum-curr,nums,dp)+k;
            case3=min(case3,temp);
        }
        return dp[i][sum]=min({case1,case2,case3});
    }
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        int ans= solve(0,sum,nums,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};