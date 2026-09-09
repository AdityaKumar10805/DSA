struct Node{
    Node* links[10];
    bool flag=false;
    bool containsKey(int digit){
        return links[digit]!=NULL;
    }
    void put(int digit,Node *node){
        links[digit]=node;
    }
    Node *get(int digit){
        return links[digit];
    }
    void setEnd(){
        flag=true;
    }
};
class Trie{
private:Node *root;
public:
Trie(){
    root=new Node();
}
void insert(int n){
    Node *node=root;
    int temp=n;
    vector<int>digits;
    while(temp>0){
        int d=temp%10;
        digits.push_back(d);
        temp/=10;
    }
    reverse(digits.begin(),digits.end());
    for(int i=0;i<digits.size();i++){
        if(!node->containsKey(digits[i])){
            node->put(digits[i],new Node());
        }
        node=node->get(digits[i]);
    }
    node->setEnd();
}
void solveUtil(Node *node,int curr,vector<int>&ans){
    if(node==NULL){
       
        return ;
    }
    if(node->flag){
        ans.push_back(curr);
    }
    for(int i=0;i<10;i++){
        if(node->containsKey(i)){
            solveUtil(node->get(i),curr*10+i,ans);
        }
    }
}
void solve(vector<int>&ans){
    solveUtil(root,0,ans);
}
};
class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        Trie trie;
        for(int i=1;i<=n;i++){
            trie.insert(i);
        }
        vector<int>ans;
        trie.solve(ans);
        return ans;

    }
};