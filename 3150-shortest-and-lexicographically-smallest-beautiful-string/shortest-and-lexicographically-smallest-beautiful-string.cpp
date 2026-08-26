class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int cnt=0;
        vector<string>ans;
        for(int right=0;right<s.size();right++){
           
            if(s[right]=='1'){
                cnt++;

            }
            while(cnt>k){
                if(s[left]=='1'){
                    cnt--;

                }
                left++;
            }
            while(s[left]=='0'&&left<right){
                left++;
            }
            if(cnt==k){
                ans.push_back(s.substr(left,right-left+1));
            }


        }
        
        sort(ans.begin(),ans.end());
        int len=s.size();
       
        string temps;
        for(int i=0;i<ans.size();i++){
           int  temp=ans[i].size();
           if(temp==len &&temps.size()==0){
            temps=ans[i];
           }
           if(temp<len){
            len=temp;
            temps=ans[i];
           }

        }
        return temps;
    }
};