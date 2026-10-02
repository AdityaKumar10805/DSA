class Solution {
public:
    void solve(int i,int cnt0,int cnt1,int len,string s,vector<string>&ans){
        if(i==len){
            if(cnt0==cnt1&& cnt1==len/2){
                 ans.push_back(s);
                 
            }
           return ;
        }
        if(cnt0==cnt1){
            s+='(';
           return solve(i+1,cnt0+1,cnt1,len,s,ans);
        }
        string temp1=s;
        string temp2=s;
        temp1+='(';
        solve(i+1,cnt0+1,cnt1,len,temp1,ans);
        temp2+=')';
        solve(i+1,cnt0,cnt1+1,len,temp2,ans);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         solve(0,0,0,2*n,"",ans);
         return ans;
    }
};