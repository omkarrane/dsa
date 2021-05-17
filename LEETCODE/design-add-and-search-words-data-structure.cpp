#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-add-and-search-words-data-structure/
/**
  * We can solve this using Tries.
  * addWord function remains the same as a usual Trie.
  * In search function, we have to also check if the current word[i] == '.', then we need to check for all possibilities to replace this '.'.
  * This can be done recursively.
 */
class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool isEnd = false;
        TrieNode() {}
    };
    TrieNode* root = new TrieNode();
    
    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next.find(word[i]) == current->next.end())
                current->next[word[i]] = new TrieNode();
            current = current->next[word[i]];
        }
        
        current->isEnd = true;
    }
    
    bool search(TrieNode* rt, string &word, int index) {
        TrieNode* current = rt;
        for (int i = index; i < word.size(); i++) {
            if (word[i] == '.') {
                bool flag = false;
                for (char a = 'a'; a <= 'z'; a++) {
                    if (current->next.find(a) != current->next.end())
                        flag = flag || search(current->next[a], word, i + 1);
                    if (flag)
                        return true;
                }
                
                return false;
            }
            if (current->next.find(word[i]) == current->next.end())
                return false;
            
            current = current->next[word[i]];
        }
        
        return current->isEnd;
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */