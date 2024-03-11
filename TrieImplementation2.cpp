struct Node {
    Node* children[26];
    bool isTerminal = false;

    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    bool isEnd() {
        return isTerminal;
    }

    void put(char ch, Node* node) {
        children[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return children[ch - 'a'];
    }

    void setEnd() {
        isTerminal = true;
    }
};

class Trie {
public:
    Node* root;

    Trie() 
    {
        root = new Node();
    }
     ~Trie() {
        delete_node(root);
    }
    void delete_node(Node* node)
    {
        if(root==nullptr) return;
        for(int i = 0; i<26; i++)
        {
            delete_node(node->children[i]);
        }
        delete node;
    }

    void Insert_Word(string word) {
        Node* node = root;
        int size = word.length();
        for (int i = 0; i < size; i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool Search_Word(string word) {
        Node* node = root;
        int size = word.length();
        for (int i = 0; i < size; i++) {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool Start_Prefix(string word) {
        Node* node = root;
        int size = word.length();
        for (int i = 0; i < size; i++) {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
};
