#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    struct TrieNode {
        map<char, TrieNode*> next;
        bool isEnd = false;
    };
    
    TrieNode* root = NULL;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next.find(word[i]) == current->next.end())
                current->next[word[i]] = new TrieNode();
            current = current->next[word[i]];
        }
        
        current->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next.find(word[i]) == current->next.end())
                return false;
            current = current->next[word[i]];
        }
        
        return current->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (current->next.find(prefix[i]) == current->next.end())
                return false;
            current = current->next[prefix[i]];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */