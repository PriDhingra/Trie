/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        for(int i = 0;i < 26;i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

public:

    /** Initialize your data structure here. */
	public: 
		TrieNode* root;
	
    Trie() {
		root = new TrieNode('\0');
    }
	
	void insertUtil(TrieNode* root, string word) {
		if(word.length() == 0) {
			root -> isTerminal = true;
			return;
		}
		
		int index = word[0] - 'a';
		TrieNode* child;
		
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		} else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}
		
		insertUtil(child, word.substr(1));
	}

    /** Inserts a word into the trie. */
    void insert(string word) {
		insertUtil(root, word);
    }

	bool searchUtil(TrieNode* root, string word) {
		if(word.length() == 0) {
			return root -> isTerminal;
		}
		
		int index = word[0] - 'a';
		TrieNode* child;
		
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		} else {
			return false;
		}
		
		return searchUtil(child, word.substr(1));
	}
	
    /** Returns if the word is in the trie. */
    bool search(string word) {
		return searchUtil(root, word);
    }

	bool prefUtil(TrieNode* root, string prefix) {
		if(prefix.length() == 0)
			return true;
		
		int index = prefix[0] - 'a';
		
		if(root -> children[index] != NULL) {
			return prefUtil(root -> children[index], prefix.substr(1));
		} else {
			return false;
		}
	}
	
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		return prefUtil(root, prefix);
    }
};
