class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //mik bhai code 
        int d=0;
        vector<int>res(seq.size());
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                d++;
                res[i]=d%2==0?0:1;
            }else{
                res[i]=d%2==0?0:1;
                d--;
            }
        }
        return res;
    }
};