class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sx=source[0];
        int sy=source[1];
        int tx=target[0];
        int ty=target[1];
        if(sx==tx&&sy==ty){
            return 0;
        }
        if(sx==tx||sy==ty){
            return 1;
        }
        if(abs(sx-tx)==abs(sy-ty)){
            return 1;
        }
        return 2;
    }
};