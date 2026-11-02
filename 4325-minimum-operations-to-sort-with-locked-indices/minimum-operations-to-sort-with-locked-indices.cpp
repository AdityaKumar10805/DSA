class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1]){
                    if(locked[j]==0&&locked[j+1]==0){
                        
                        

                    }else if(locked[j]==0){
                        if(k==0){
                            return -1;
                        }
                        locked[j+1]=0;
                        ans++;
                        k--;


                    }else if(locked[j+1]==0){
                        if(k==0){
                            return -1;
                        }
                        locked[j]=0;
                        ans++;
                        k--;
                    }else{
                        if(k<=1){
                            return -1;
                        }
                        ans+=2;
                        k-=2;
                        locked[j]=0;
                        locked[j+1]=0;
                    }
                    swap(nums[j],nums[j+1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};