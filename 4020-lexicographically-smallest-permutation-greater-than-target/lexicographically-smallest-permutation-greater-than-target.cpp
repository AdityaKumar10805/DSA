class Solution {
public:
    bool solve(int i,bool great,string target,unordered_map<char,int>&mp,string &res){
        if(i>=target.size()){
            if(great){
                return true;
            }
            return false;
            
        }
         bool ans;
       if(great){
        for(char c='a';c<='z';c++){
            if(mp[c]>0){
            mp[c]--;
            res+=c;
             ans=solve(i+1,true,target,mp,res);
            if(ans){
                return ans;
            }
            res.pop_back();
       mp[c]++;
        }
        }
       } 
      
       if(mp[target[i]]>0){
        mp[target[i]]--;
        res+=target[i];
        ans=solve(i+1,false,target,mp,res);
        if(ans){
            
        return ans;
       }
       res.pop_back();
       mp[target[i]]++;
       }
       
       for(char c=char(target[i]+1);c<='z';c++){
        if(mp[c]>0){
            mp[c]--;
            res+=c;
             ans=solve(i+1,true,target,mp,res);
             if(ans){
               
        return ans;
       }
       mp[c]++;
       res.pop_back();
        }
       }
        return ans;
    }
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string res;
        bool ans=solve(0,false,target,mp,res);
     if(ans){
        return res;
     }
      return "";
        
    }
};