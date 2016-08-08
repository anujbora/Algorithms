#include <algorithm>
#include <string>
using namespace std;

class TrieNode 
{
public:
    TrieNode* children[26];
    bool isWord;
    char value;

    TrieNode(char c) 
    {
        value = c;
        memset(children, 0, sizeof(children));
        isWord = false;
    }
};

class Trie 
{
private:
    TrieNode* root;

public:
    Trie() 
    {
        root = new TrieNode(' '); 
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode* ws = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (ws->children[word[i] - 'a'] == NULL)
            {
                ws->children[word[i] - 'a'] = new TrieNode(word[i]);
            }
            ws = ws->children[word[i] - 'a']; 
        }
        ws->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        TrieNode* ws = root;
        
        for (int i = 0; i < word.size(); i++)
        {
            if (ws->children[word[i] - 'a'] == NULL)
            {
                return false;
            }
            ws = ws->children[word[i] - 'a'];
        }
        return ws->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string word) 
    {
        TrieNode* ws = root;
        
        for (int i = 0; i < word.size(); i++)
        {
            if (ws->children[word[i] - 'a'] == NULL)
            {
                return false;
            }
            ws = ws->children[word[i] - 'a'];
        }
        return true;
    }
};

// Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");