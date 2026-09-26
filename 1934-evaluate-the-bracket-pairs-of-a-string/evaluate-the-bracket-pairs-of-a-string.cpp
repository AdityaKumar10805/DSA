class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            string key=knowledge[i][0];
            string value=knowledge[i][1];
            mp[key]=value;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                string key;
                int j=i+1;
                while(s[j]!=')'){
                    key+=s[j];
                    j++;
                }
                i=j;
                if(mp.count(key)){
                    ans+=mp[key];
                }else{
                    ans+='?';
                }
                
            }else{
                ans+=s[i];
        }
            }
            
        return ans;
    }
};