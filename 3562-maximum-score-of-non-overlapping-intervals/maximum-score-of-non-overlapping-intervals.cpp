struct Node{
    long long score=0;
    vector<int>idx;
    bool flag=false;
};
class Solution {
public:
    Node  solve(int i,int k,vector<int>&next,vector<vector<int>>&intervals,vector<vector<Node>>&dp){
        if(k==0||i>=intervals.size()){
            return Node();
        }
        if(dp[i][k].flag){
            return dp[i][k];
        }
        Node notTake=solve(i+1,k,next,intervals,dp);
        Node temp=solve(next[i],k-1,next,intervals,dp);
       Node take;
       take.score=temp.score+intervals[i][2];
       take.idx=temp.idx;
       take.idx.push_back(intervals[i][3]);
       sort(take.idx.begin(),take.idx.end());
       Node res;
       if(take.score>notTake.score){
        res=take;
       }else if(take.score<notTake.score){
        res=notTake;
       }else{
        if(take.idx>notTake.idx){
            res=notTake;
        }else{
            res=take;
        }
       }
       res.flag=true;
       return dp[i][k]=res;

    }
    int find(int st,int end,int target,vector<vector<int>>& intervals){
        
        int ans=intervals.size();
        while(st<=end){
            int mid=st+(end-st)/2;
            if(intervals[mid][0]>target){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }

        }
        return ans;

    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        for(int i=0;i<intervals.size();i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<int>next(intervals.size());
        for(int i=0;i<intervals.size();i++){
                next[i]=find(i+1,n-1,intervals[i][1],intervals);
        }
        vector<vector<Node>>dp(intervals.size(),vector<Node>(5));
        return solve(0,4,next,intervals,dp).idx;
        

    }
};