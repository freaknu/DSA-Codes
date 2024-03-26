class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~Node() {
        cout << "Memory Freed for: " << data << endl;
        delete next;
    }
};

class LinkedList {
public:
    void InsertNodeAtHead(Node *&head, int data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void InsertNodeAtTail(Node *&tail, int data) {
        Node *temp = new Node(data);
        if (tail == nullptr) {
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void PrintNode(Node *head) {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertAtPosition(Node *&head, int Position, int data) {
        if (Position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        Node *node = new Node(data);
        if (Position == 1) {
            InsertNodeAtHead(head, data);
            return;
        }
        Node *temp = head;
        int cnt = 1;
        while (cnt < Position - 1 && temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        if (temp == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        node->next = temp->next;
        temp->next = node;
    }

    void DeleteNode(Node *&head, int Pos) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (Pos == 1) {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        } else {
            Node *currentNode = head;
            Node *PreviousNode = nullptr;
            int Count = 1;
            while (currentNode != nullptr && Count < Pos) {
                PreviousNode = currentNode;
                currentNode = currentNode->next;
                Count++;
            }
            if (currentNode == nullptr) {
                cout << "Position out of range." << endl;
                return;
            }
            PreviousNode->next = currentNode->next;
            currentNode->next = nullptr;
            delete currentNode;
        }
    }
};
