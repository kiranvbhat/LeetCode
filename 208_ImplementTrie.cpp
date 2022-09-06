// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char ch : word) {
            if (cur->children.count(ch) == 0) cur->children[ch] = new Node();
            cur = cur->children[ch];
        }
        cur->wordEnded = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char ch : word) {
            if (cur->children.count(ch) == 0) return false;
            cur = cur->children[ch];
        }
        return (cur->wordEnded);
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char ch : prefix) {
            if (cur->children.count(ch) == 0) return false;
            cur = cur->children[ch];
        }
        return true;
    }

private:
    struct Node {
        unordered_map<char, Node*> children;
        bool wordEnded;
        Node() : children({}), wordEnded(false) {}
    };
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
