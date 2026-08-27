class Solution {
public:
bool checkPalindrome(string s){
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}
   void getAllParts(string s,vector<string>&partitions,vector<vector<string>>&ans){
    if(s.size()==0){
        ans.push_back(partitions);
        return ;
    }
    for(int i=0;i<s.size();i++){
        string part=s.substr(0,i+1);
        if(checkPalindrome(part)){
            partitions.push_back(part);
            getAllParts(s.substr(i+1),partitions,ans);
            partitions.pop_back();
        }
    }
    return;
   }
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        vector<vector<string>>ans;
        getAllParts(s,partitions,ans);
        return ans;
    }
};