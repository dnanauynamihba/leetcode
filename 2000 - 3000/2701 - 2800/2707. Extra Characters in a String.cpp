// top-down dp + trie
struct TrieNode { 
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        std::fill(child, child + 26, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }
    ~Trie() { delete root; }
    
    void build(std::string& word) {
        TrieNode* node = root;
        
        for(char& ch: word){
            if(node->child[ch - 'a'] == nullptr) {
                node->child[ch - 'a'] = new TrieNode();
            }
            node = node->child[ch - 'a'];
        }
        node->isEnd = true;
    }
};

class Solution {
private:
    int n;
    std::unordered_map<int, int> memo;

public:
    int minExtraChar(std::string str, std::vector<std::string>& dictionary) {
        n = str.size();
        
        Trie trie; 
        for(std::string& word: dictionary) {
            trie.build(word);
        }
        
        std::function<int(int)> compute = [&](int idx) {
            if(idx == n) return 0;
        
            if(memo.count(idx)) return memo[idx];

            TrieNode* node = trie.root;

            int ans = compute(idx + 1) + 1;
            for(int i = idx; i < n; i++) {
                char ch = str[i];
                if(node->child[ch - 'a'] == nullptr) {
                    break;
                }
                node = node->child[ch - 'a'];
                
                if(node->isEnd) {
                    ans = std::min(ans, compute(i + 1));
                }
            }

            return memo[idx] = ans;
        };

        return compute(0);
    }
};
