class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long  sum=0;
        for(long long i:source){
            sum=1LL*sum+i;
        }
        long long t=0;
        for(long long i:target){
            t+=i;
        }
        return sum==t;
    }
};