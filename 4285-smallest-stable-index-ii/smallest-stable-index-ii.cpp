class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        prefix[0]=nums[0];
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            prefix[i]=max(nums[i],prefix[i-1]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(prefix[i]-suffix[i]<=k){
                return i;
            }
        }
        return -1;
    }
};