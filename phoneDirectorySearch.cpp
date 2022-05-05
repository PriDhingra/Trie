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
	
	void insert(string word) {
		insertUtil(root, word);
	}
	
	void printSuggestions(TrieNode* curr, vector<string> &ans, string prefix) {
		if(curr -> isTerminal) {
			ans.push_back(prefix);
		}
		
		for(char i = 'a';i <= 'z';i++) {
			if(curr -> children[i - 'a'] != NULL) {
				prefix.push_back(i);
				printSuggestions(curr -> children[i - 'a'], ans, prefix);
				prefix.pop_back();
			}
		}
	}
	
	void preSearch(string queryStr, vector<vector<string>> &result) {
		TrieNode* prev = root;
		string prefix = "";
		
		for(int i = 0;i < queryStr.length();i++) {
			char lastCh = queryStr[i];
			prefix.push_back(lastCh);
			
			TrieNode* curr = prev -> children[lastCh - 'a'];
			if(curr == NULL) {
				break;
			} 
				
			vector<string> ans;
			printSuggestions(curr, ans, prefix);
			result.push_back(ans);
			ans.clear();
			prev = curr;
		}
	}
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
	Trie* t = new Trie();
	
	for(int i = 0;i < contactList.size();i++) {
		t -> insert(contactList[i]);
	}
	
	vector<vector<string>> result;
	
	t -> preSearch(queryStr, result);
	
	return result;
	
}
