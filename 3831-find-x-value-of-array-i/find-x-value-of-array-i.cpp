class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>prev(k);
        vector<long long >res(k);
        for(int i=0;i<nums.size();i++){
            
            vector<long long>curr(k);
            int rem=nums[i]%k;
            curr[rem]++;
            for(int j=0;j<k;j++){
                int nRem=((1LL*j*nums[i])%k)%k;
                curr[nRem]+=prev[j];
            }
            prev=curr;
            for(int j=0;j<k;j++){
                res[j]+=curr[j];
            }
        }
        return res;
    }
};