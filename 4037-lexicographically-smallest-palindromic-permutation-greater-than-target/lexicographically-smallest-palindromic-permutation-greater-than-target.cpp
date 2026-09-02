class Solution {
public:
    bool solve(int i,bool great,string target,char &odd,unordered_map<char,int>&mp,string &res){
        if(i>=target.size()/2){
           string ans;
  
    string rev=res;
    reverse(rev.begin(),rev.end());
   
    if(odd!='$'){
        ans=res+odd+rev;
       
    }else{
        ans=res+rev;
    }
    
   if(ans>target){
    res=ans;
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
             ans=solve(i+1,true,target,odd,mp,res);
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
        ans=solve(i+1,false,target,odd,mp,res);
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
             ans=solve(i+1,true,target,odd,mp,res);
             if(ans){
               
        return ans;
       }
       mp[c]++;
       res.pop_back();
        }
       }
        return ans;
    }
    string lexPalindromicPermutation(string s, string target) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        char odd='$';
        for(auto &it:mp){
            if(it.second%2){
                if(odd=='$'){
                    odd=it.first;
                }else{
                    return "";
                }
            }
            it.second/=2;
          
        }
        string res;
       
 bool check=solve(0,0,target,odd,mp,res);
 //cout<<check;
  if(check){
    return res;
  }
  
 return "";


    }
};