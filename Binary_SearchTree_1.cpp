class Node {
public:
    int data;
    Node *Right;
    Node *Left;

    Node(int d) {
        this->data = d;
        this->Right = this->Left = NULL;
    }
};
class BinarySearchTree {
public:
    Node *insertToBst(Node *root, int data) {
        if (root == NULL) {
            root = new Node(data);
            return root;
        }
        if (data > root->data) {
            root->Right = insertToBst(root->Right, data);
        } else {
            root->Left = insertToBst(root->Left, data);
        }
        return root;
    }

    Node *MaxVAL(Node *root) {
        Node *temp = root;
        while (temp != NULL && temp->Right != NULL) {
            temp = temp->Right;
        }
        return temp;
    }

    Node *MinVAL(Node *root) {
        Node *temp = root;
        while (temp != NULL && temp->Left != NULL) {
            temp = temp->Left;
        }
        return temp;
    }

    void takeInput(Node *&root) {
        int data;
        cin >> data;
        while (data != -1) {
            root = insertToBst(root, data);
            cin >> data;
        }
    }

    void LevelOrderTraversal(Node *root) {
        queue<Node *> q;
        if (root == NULL)
            return;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL) {
                cout << endl;
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                cout << temp->data << " ";
                if (temp->Left != NULL) {
                    q.push(temp->Left);
                }
                if (temp->Right != NULL) {
                    q.push(temp->Right);
                }
            }
        }
    }

    Node *deleteNode(Node *root, int X) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == X) {
            if (root->Left == NULL && root->Right == NULL) {
                delete root;
                return NULL;
            }
            if (root->Left != NULL && root->Right == NULL) {
                Node *temp = root->Left;
                delete root;
                return temp;
            }
            if (root->Right != NULL && root->Left == NULL) {
                Node *temp = root->Right;
                delete root;
                return temp;
            }
            if (root->Left != NULL && root->Right != NULL) {
                int max = MaxVAL(root->Right)->data;
                root->data = max;
                root->Right = deleteNode(root->Right, max);
                return root;
            }
        } else if (root->data > X) {
            root->Left = deleteNode(root->Left, X);
            return root;
        } else {
            root->Right = deleteNode(root->Right, X);
            return root;
        }
        return root;
    }
    Node* findPredecessor(Node* root) {
        while (root->Right != nullptr) {
            root = root->Right;
        }
        return root;
    }

    void morrisTraversal(Node* root) {
        Node* current = root;
        while (current != nullptr) {
            if (current->Left == nullptr) {
                cout << current->data << " ";
                current = current->Right;
            } else {
                Node* predecessor = findPredecessor(current->Left);
                if (predecessor->Right == nullptr) {
                    predecessor->Right = current;
                    current = current->Left;
                } else {
                    predecessor->Right = nullptr;
                    cout << current->data << " ";
                    current = current->Right;
                }
            }
        }
    }
};
