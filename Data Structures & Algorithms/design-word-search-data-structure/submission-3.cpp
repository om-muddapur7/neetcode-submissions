class WordDictionary {
public:
    struct Node {
        Node* child[26];
        bool end;

        Node() {
            for(int i = 0; i < 26; i++)
                child[i] = nullptr;
            end = false;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(curr->child[idx] == nullptr)
                curr->child[idx] = new Node();

            curr = curr->child[idx];
        }

        curr->end = true;
    }

    bool dfs(string &word, int pos, Node* node) {

        if(pos == word.size())
            return node->end;

        char ch = word[pos];

        if(ch == '.') {

            for(int i = 0; i < 26; i++) {
                if(node->child[i] &&
                   dfs(word, pos + 1, node->child[i]))
                    return true;
            }

            return false;
        }
        else {

            int idx = ch - 'a';

            if(node->child[idx] == nullptr)
                return false;

            return dfs(word, pos + 1, node->child[idx]);
        }
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};