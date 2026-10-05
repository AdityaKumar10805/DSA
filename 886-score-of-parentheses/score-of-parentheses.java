class Solution {
    int solve(int st,int end,int link[],String s){
        if(st>end){
            return 0;
        }
        int inside;
        boolean case1=false;
        if(link[st]-st==1){
                inside= 1;
                case1=true;
        }else{
             inside=solve(st+1,link[st]-1,link,s);
        }
           
       int outside=solve(link[st]+1,end,link,s);
       if(case1){
        return inside+outside;
       }
       return 2*inside+outside;
    }
    public int scoreOfParentheses(String s) {
        int link[] =new int[s.length()];
        Stack<Integer>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push(i);
            }else{
                link[i]=st.peek();
                link[link[i]]=i;
                st.pop();
            }
        }
        return solve(0,s.length()-1,link,s);

    }
}