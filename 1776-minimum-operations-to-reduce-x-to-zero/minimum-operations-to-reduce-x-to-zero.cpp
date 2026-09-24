class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0;
        int sum=0;
        int ans=-1;
        int target=0;
        for(auto num:nums){
            target+=num;
        }
        target-=x;
        if(target<0){
            return -1;
        }
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum==target){
                ans=max(ans,right-left+1);
            }
        }
        if(ans==-1){
            return ans;
        }
        return nums.size()-ans;
    }
};