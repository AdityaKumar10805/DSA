class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=1e9;
        int curr=0;
        vector<int>minLen(n+1,1e9);
        int left=0;
        for(int right=0;right<arr.size();right++){
            curr+=arr[right];
            if(right>0){
                minLen[right]=minLen[right-1];
            }
            while(curr>target&&left<right){
                curr-=arr[left];
                left++;
            }
            if(curr==target){
                if(left>0){
                    ans=min(ans,right-left+1+minLen[left-1]);
                }
                minLen[right]=min(minLen[right],right-left+1);
                

            }
            
        }
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};