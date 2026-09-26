class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        // a good question 
       // hamein test case ko dekhte hi hint milna chahiye ki yahan par O(n^2) work kar jayega 
       int ans=0;
       for(int i=0;i<nums.size();i++){
        int sum=0;
        unordered_set<int>s;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            s.insert((((2*nums[j])%k)+k)%k);
            if(((sum%k)+k)%k==0|| s.count(((sum%k)+k)%k)){
                ans=max(ans,j-i+1);
            }

        }
       }
       return ans;
    }
};