struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
};
class WordDictionary {
private:Node *root;

public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool searchUtil(Node *node,string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                for(int ch='a';ch<='z';ch++){
                    if(node->containsKey(ch)){
                        if(searchUtil(node->get(ch),s.substr(i+1))){
                            return true;
                        }
                    }
                }
                return false;
            }else{
                if(!node->containsKey(s[i])){
                    return false;
                }
                node=node->get(s[i]);
            }
            
        }
        return node->flag;
    }
    bool search(string word) {
      return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */