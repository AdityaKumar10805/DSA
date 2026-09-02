class Solution {
public:
    string solve(int n ,char curr){
        if(curr=='z'){
            string s(n,curr);
            return s;
        }
        if(n==0){
            return "";
        }
        int x=n/2;
        int y=0;
        if(n%2){
            y=1;
        }
        string ans;
        string check=solve(x,(char)(curr+1));
        ans=ans+check;
        if(y){
            return ans+curr;
        }
        return ans;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            string curr=solve(nums[i],'a');
            ans.push_back(curr);
        }
        return ans;
    }
};