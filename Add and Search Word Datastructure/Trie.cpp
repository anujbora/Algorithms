#include <algorithm>
#include <string>
using namespace std;

class TrieNode 
{
public:
    char val;
    bool isWord;
    TrieNode* children[26];
    
    TrieNode(char word) 
    {
        memset(children, 0, sizeof(children));
        isWord = false;
        val = word;
    }
};

class WordDictionary 
{
public:
    WordDictionary() 
    {
        root = new TrieNode(' ');
    }
    
    // Adds a word into the data structure.
    void addWord(string word) 
    {
        TrieNode* temp = root;
        for (char c : word)
        {
            if (temp->children[c - 'a'] == NULL)
            {
                TrieNode* t = new TrieNode(c);
                temp->children[c - 'a'] = t;
            }
            temp = temp->children[c - 'a'];
        }
        temp->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        return query(word, root);
    }

private:
    TrieNode* root;
    
    bool query(string word, TrieNode* ws)
    {
        TrieNode* node = ws;
        
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] != '.' && node != NULL)
            {
                node = node->children[word[i] - 'a'];
            }
            else if (word[i] == '.' && node != NULL)
            {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = tmp->children[j];
                    if (query(word.substr(i+1), node))
                    {
                        return true;
                    }
                }
            }
            else
            {
                break;
            }
        }
        return node && node->isWord;
    }
};

// WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");