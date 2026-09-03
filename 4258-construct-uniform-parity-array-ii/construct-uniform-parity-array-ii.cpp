class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2){
            return true;
        }
        int cnte=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                cnte++;
            }
        }
        if(cnte==nums1.size()){
            return true;
        }
        return false;
    }
};