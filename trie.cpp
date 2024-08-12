#include<iostream>
#include<vector>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int wordCount;        // Number of times a word ends at this node
    int prefixCount;      // Number of times this node is part of a prefix

    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        wordCount = 0;
        prefixCount = 0;
    }
};

class Trie {
private:
    void insertUtil(TrieNode *root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            root->wordCount++;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        child->prefixCount++;
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode *root, string word) {
        if (!root) return false;
        if (word.size() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        return searchUtil(root->children[index], word.substr(1));
    }

    bool prefixUtil(TrieNode *root, string word) {
        if (!root) return false;
        if (word.size() == 0)
            return true;

        int index = word[0] - 'a';
        return prefixUtil(root->children[index], word.substr(1));
    }
    
    int countWordsEqualToUtil(TrieNode *root, string word) {
        if (!root) return 0;
        if (word.size() == 0)
            return root->wordCount;

        int index = word[0] - 'a';
        return countWordsEqualToUtil(root->children[index], word.substr(1));
    }
    
    int countWordsStartingWithUtil(TrieNode *root, string prefix) {
        if (!root) return 0;
        if (prefix.size() == 0)
            return root->prefixCount;

        int index = prefix[0] - 'a';
        return countWordsStartingWithUtil(root->children[index], prefix.substr(1));
    }

    bool deleteUtil(TrieNode *root, string word) {
        if (!root) return false;
        if (word.size() == 0) {
            if (root->isTerminal) {
                root->wordCount--;
                root->isTerminal = (root->wordCount > 0);
                return true;
            }
            return false;
        }

        int index = word[0] - 'a';
        TrieNode *child = root->children[index];
        
        if (deleteUtil(child, word.substr(1))) {
            child->prefixCount--;

            // If no words pass through this node and it's not terminal, delete it
            if (child->prefixCount == 0 && !child->isTerminal) {
                delete child;
                root->children[index] = NULL;
            }
            return true;
        }
        return false;
    }

public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }

    int countWordsEqualTo(string word) {
        return countWordsEqualToUtil(root, word);
    }

    int countWordsStartingWith(string prefix) {
        return countWordsStartingWithUtil(root, prefix);
    }

    void deleteWord(string word) {
        deleteUtil(root, word);
    }
};
