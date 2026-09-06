struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
};
class Trie{
private:
Node *root;
public:
 Trie(){
    root=new Node();
 }
 void insert(int num){
    Node* node=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(!node->containsKey(bit)){
            node->put(bit,new Node());
        }
        node=node->get(bit);
    }
 }
 int getMax(int num){
    Node* node=root;
    int maxNum=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(node->containsKey(1-bit)){
            maxNum|=(1<<i);
            node=node->get(1-bit);
        }else{
            node=node->get(bit);
        }

    }
    return maxNum;
 }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](const std::vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int idx=0;
        Trie trie;
        for(int i=0;i<queries.size();i++){
            int xi=queries[i][0];
            int limit=queries[i][1];
            while(idx<nums.size()&&nums[idx]<=limit){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx==0){
                ans[queries[i][2]]=-1;
            }else{
                ans[queries[i][2]]=trie.getMax(xi);
            }


        }
        return ans;
    }
};