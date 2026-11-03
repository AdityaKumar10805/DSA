class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(maxi-nums[i]);
        }
        return ans;
    }
};