class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=-1;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(j!=i){
                    temp.push_back(nums[j]);
                }
            }
            vector<int>prefix(temp.size());
            vector<int>suffix(temp.size());
            prefix[0]=temp[0];
            for(int k=1;k<temp.size();k++){
                prefix[k]=gcd(temp[k],prefix[k-1]);
            }
            suffix[temp.size()-1]=temp[temp.size()-1];
            for(int k=temp.size()-2;k>=0;k--){
             suffix[k]=gcd(suffix[k+1],temp[k]);
            }
            int score =0;
            for(int k=0;k<temp.size()-1;k++){
                if(prefix[k]==suffix[k+1]){
                    score++;
                }
            }
            ans=max(ans,score);
        }
        return ans;
    }
};