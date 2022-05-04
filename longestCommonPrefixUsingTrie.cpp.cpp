class TrieNode {
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		int count;
	
	TrieNode(char data) {
		this -> data = data;
		for(int i = 0;i < 26;i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		count = 0;
	}
};

class Tree {
	public:
		TrieNode* root;
	
	Tree() {
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
			root -> count++;
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}
		
		insertUtil(child, word.substr(1));
	}
	
	void insert(string word) {
		insertUtil(root, word);
	}
	
	void lcp(string first, string &ans) {
		for(int i = 0;i < first.length();i++) {
			char ch = first[i];
			if(root -> count == 1) {
				ans.push_back(ch);
				int index = ch - 'a';
				root = root -> children[index];
			} else {
				break;
			}
			
			if(root -> isTerminal) {
				break;
			}
		}
	}
	
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
	Tree* t = new Tree();
// 	string ans = "";
	
	for(int i = 0;i < arr.size();i++) {
		t -> insert(arr[i]);
	}
	
	string first = arr[0];
	string ans = "";
	
	t -> lcp(first, ans);
	
	return ans;
}


