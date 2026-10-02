class Solution {
    void solve(int curr,int cnt0,int cnt1,int len,String s,List<String> ans){
        if(curr==len){
            if(cnt0==cnt1&& cnt0==len/2){
                ans.add(s);
            }
            return ;
        }
        if(cnt0==cnt1){
            s+='(';
             solve(curr+1,cnt0+1,cnt1,len,s,ans);
             return;
        }
        String temp1=s;
        String temp2=s;
        temp1+='(';
        solve(curr+1,cnt0+1,cnt1,len,temp1,ans);
        temp2+=')';
        solve(curr+1,cnt0,cnt1+1,len,temp2,ans);
    }
    public List<String> generateParenthesis(int n) {
        List<String>ans=new ArrayList<>();
        solve(0,0,0,2*n,"",ans);
        return ans;
    }
}