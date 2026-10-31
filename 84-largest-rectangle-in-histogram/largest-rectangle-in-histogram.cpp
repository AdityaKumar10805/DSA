class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=-1;
        vector<int>right(heights.size(),heights.size());
        vector<int>left(heights.size(),-1);
        stack<int>s;

        for(int i=0;i<heights.size();i++){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }else{
                left[i]=s.top();
            }
           // cout<<heights[i]<<" "<<left[i]<<" ";
            s.push(i);
        }
        s = stack<int>(); // This completely clears the stack

        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                
            }else{
                right[i]=s.top();
            }
            s.push(i);
        }
        for(int i=0;i<heights.size();i++){
            int ht=heights[i];
            int width=right[i]-left[i]-1;
           
            ans=max(ans,ht*width);

        }
        return ans;
    }
};