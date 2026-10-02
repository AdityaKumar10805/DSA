class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left=0;
        HashMap<Character,Integer>mp=new HashMap<>();
        int ans=0;
        for(int right=0;right<s.length();right++){
            mp.put(s.charAt(right),mp.getOrDefault(s.charAt(right),0)+1);
            while(mp.get(s.charAt(right))>1){
                mp.put(s.charAt(left),mp.get(s.charAt(left))-1);
                left++;
            }
            ans=Math.max(ans,right-left+1);

        }
        return ans;
    }
}