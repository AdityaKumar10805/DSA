class Solution {
public:
    void solve(int i,string &s,set<string>&st,vector<string>&ans,string curr){
            if(i>=s.size()){
               
                    curr.pop_back();
                    ans.push_back(curr);
               
                
                
                return ;
            }
        for(int l=1;i+l<=s.size();l++){
            if(st.count(s.substr(i,l))){
                
               
                solve(i+l,s,st,ans,curr+s.substr(i,l)+" ");

            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        string curr;
        vector<string>ans;
        solve(0,s,st,ans,curr);
        return ans;
    }
};