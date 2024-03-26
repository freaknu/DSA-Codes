class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
   ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
           delete next;
           next = NULL;
        }
        cout << "Memory Freed for: " << value << endl;
    }
};

class LinkedList {
public:
    void InsertNodeAtHead(Node *&head, int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void InsertNodeAtTail(Node *&tail, int data)
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }

    void PrintNode(Node *&head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertAtPosition(Node *&head, int Position, int data)
    {
        Node *node = new Node(data);
        if (Position == 1)
        {
            InsertNodeAtHead(head, data);
            return;
        }
        Node *temp = head;
        int cnt = 1;
        while (cnt < Position - 1 && temp != nullptr)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp == nullptr)
        {
            cout << "Position out of range." << endl;
            return;
        }
        node->next = temp->next;
        temp->next = node;
    }
void DeleteNode(Node *&head, int Pos)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (Pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *currentNode = head;
        Node *PreviousNode = NULL;
        int Count = 1;
        while (currentNode != NULL && Count < Pos)
        {
            PreviousNode = currentNode;
            currentNode = currentNode->next;
            Count++;
        }
        if (currentNode == NULL)
        {
            cout << "Position out of range." << endl;
            return;
        }
        PreviousNode->next = currentNode->next;
        currentNode->next = NULL;
        delete currentNode;
    }
  }
};
