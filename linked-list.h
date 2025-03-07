#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

struct NodeSingly
{
    int data;
    NodeSingly *next;
};

// Define the linked list class
class LinkedList
{
    // Pointer to the first NodeSingly in the list
    NodeSingly *head;

public:
    // Constructor initializes head to NULL
    LinkedList() : head(nullptr)
    {
        std::cout << "Constructor called!" << std::endl;
    }

    // Function to Insert a new NodeSingly at the beginning of the list
    void insertAtBeginning(int value)
    {
        NodeSingly *newNodeSingly = new NodeSingly();
        newNodeSingly->data = value;
        newNodeSingly->next = head;
        head = newNodeSingly;
    }

    // Function Insert a new NodeSingly at the end of the list
    void insertAtEnd(int value)
    {
        NodeSingly *newNodeSingly = new NodeSingly();
        newNodeSingly->data = value;
        newNodeSingly->next = nullptr;

        // If the list is empty, update the head to the new NodeSingly
        if (!head)
        {
            head = newNodeSingly;
            return;
        }

        // Traverse to the last NodeSingly
        NodeSingly *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        // Update the last NodeSingly's next to the new NodeSingly
        temp->next = newNodeSingly;
    }

    void insertAtPosition(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "position should be >= 1." << endl;
            return;
        }
        if (pos == 1)
        {
            insertAtBeginning(value);
            return;
        }
        NodeSingly *newNodeSingly = new NodeSingly();
        newNodeSingly->data = value;

        // Traverse to the NodeSingly before the desired position
        NodeSingly *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp)
        {
            cout << "Position out of range." << endl;
            delete newNodeSingly;
            return;
        }

        // Insert the new NodeSingly at the desired position
        newNodeSingly->next = temp->next;
        temp->next = newNodeSingly;
    }

    // Function to Delete the first NodeSingly of the list
    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        NodeSingly *temp = head;
        head = head->next;
        delete temp;
    }

    // Function to Delete the last NodeSingly of the list
    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        // Traverse to the second-to-last NodeSingly
        NodeSingly *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }

        //  Delete the last NodeSingly
        delete temp->next;
        // Set the second-to-last NodeSingly's next to nullptr
        temp->next = nullptr;
    }
    // Function to Delete a NodeSingly at a specific position in the list
    void deleteFromPos(int pos)
    {
        if (pos < 1)
        {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (pos == 1)
        {
            deleteFromBeginning();
            return;
        }

        NodeSingly *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }

        if (!temp || !temp->next)
        {
            cout << "position out of range." << endl;
            return;
        }

        // Save the NodeSingly to be deleted
        NodeSingly *NodeSinglyToDelete = temp->next;
        // Update the next pointer
        temp->next = temp->next->next;

        delete NodeSinglyToDelete;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        NodeSingly *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "nullptr" << endl;
    }
};

class NodeDoubly
{
public:
    // Data part of the node.
    int data;
    // Pointer to the next node.
    NodeDoubly *next;
    // Pointer to the previous node.
    NodeDoubly *prev;

    // Constructor to initialize the node with given data.
    NodeDoubly(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Function to insert a node at the beginning of the doubly
// linked list.
void insertAtBeginning(NodeDoubly *&head, int data)
{
    // Create a new node with the given data.
    NodeDoubly *newNode = new NodeDoubly(data);

    // Check if the doubly linked list is empty.
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Update the next and previous pointers to insert the
    // new node at the beginning.
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Function to insert a node at the end of the doubly linked
// list.
void insertAtEnd(NodeDoubly *&head, int data)
{
    // Create a new node with the given data.
    NodeDoubly *newNode = new NodeDoubly(data);

    // Check if the doubly linked list is empty.
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Traverse to the last node of the list.
    NodeDoubly *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specified position in the
// doubly linked list.
void insertAtPosition(NodeDoubly *&head, int data, int position)
{
    if (position < 1)
    {
        cout << "Position should be >= 1." << endl;
        return;
    }

    // If inserting at the head position.
    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    // Create a new node with the given data.
    NodeDoubly *newNode = new NodeDoubly(data);
    NodeDoubly *temp = head;

    // Traverse to the node before the specified position.
    for (int i = 1; i < position - 1 && temp; i++)
    {
        temp = temp->next;
    }

    // Check if the position is greater than the number of
    // nodes.
    if (temp == nullptr)
    {
        cout << "Position greater than the number of nodes."
             << endl;
        return;
    }

    // Update the next and previous pointers to insert the
    // new node at the specified position.
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node from the beginning of the
// doubly linked list.
void deleteAtBeginning(NodeDoubly *&head)
{
    // Check if the doubly linked list is empty.
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    // Update the head pointer and delete the first node.
    NodeDoubly *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
}

// Function to delete a node from the end of the doubly
// linked list.
void deleteAtEnd(NodeDoubly *&head)
{
    // Check if the doubly linked list is empty.
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    NodeDoubly *temp = head;
    // If there is only one node in the list.
    if (temp->next == nullptr)
    {
        head = nullptr;
        delete temp;
        return;
    }

    // Traverse to the last node of the list.
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Update the previous pointer of the second last node
    // and delete the last node.
    temp->prev->next = nullptr;
    delete temp;
}

// Function to delete a node from a specified position in
// the doubly linked list.
void deleteAtPosition(NodeDoubly *&head, int position)
{
    // Check if the doubly linked list is empty.
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    // If deleting the head node.
    if (position == 1)
    {
        deleteAtBeginning(head);
        return;
    }

    NodeDoubly *temp = head;
    // Traverse to the node at the specified position.
    for (int i = 1; temp != nullptr && i < position; i++)
    {
        temp = temp->next;
    }

    // Check if the position is greater than the number of
    // nodes.
    if (temp == nullptr)
    {
        cout << "Position is greater than the number of "
                "nodes."
             << endl;
        return;
    }

    // Update the next and previous pointers and delete the
    // node at the specified position.
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}

// Function to print the doubly linked list in forward
// direction.
void printListForward(NodeDoubly *head)
{
    NodeDoubly *temp = head;
    cout << "Forward List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to print the doubly linked list in reverse
// direction.
void printListReverse(NodeDoubly *head)
{
    NodeDoubly *temp = head;
    if (temp == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    // Move to the end of the list.
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Traverse backwards.
    cout << "Reverse List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Template class for a CircularNode in the circular linked list
template <typename T>
class CircularNode
{
public:
    // Data stored in the CircularNode
    T data;
    // Pointer to the next CircularNode in the list
    CircularNode<T> *next;

    // Constructor to initialize a CircularNode with given data and
    // null next pointer
    CircularNode(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Template class for the circular linked list
template <typename T>
class CircularLinkedList
{
private:
    // Pointer to the head (first CircularNode) of the list
    CircularNode<T> *head;

public:
    // Constructor to initialize an empty list
    CircularLinkedList() { head = nullptr; }

    // Function to insert a CircularNode at the beginning of the
    // list
    void insertAtFirst(T value)
    {
        CircularNode<T> *newNode = new CircularNode<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            CircularNode<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Function to insert a CircularNode at the end of the list
    void insertAtEnd(T value)
    {
        CircularNode<T> *newNode = new CircularNode<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            CircularNode<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to insert a CircularNode at a specific position
    void insertAtPosition(T value, int position)
    {
        CircularNode<T> *newNode = new CircularNode<T>(value);
        if (position <= 1 || head == nullptr)
        {
            insertAtFirst(value);
        }
        else
        {
            CircularNode<T> *temp = head;
            for (int i = 1;
                 i < position - 1 && temp->next != head;
                 i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to delete the first CircularNode of the list
    void deleteFromFirst()
    {
        if (head == nullptr)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            CircularNode<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            CircularNode<T> *tempHead = head;
            temp->next = head->next;
            head = head->next;
            delete tempHead;
        }
    }

    // Function to delete the last CircularNode of the list
    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            CircularNode<T> *temp = head;
            CircularNode<T> *prev = nullptr;
            while (temp->next != head)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    // Function to delete a CircularNode with a specific key
    void deleteByKey(T key)
    {
        if (head == nullptr)
            return;
        if (head->data == key)
        {
            deleteFromFirst();
            return;
        }
        CircularNode<T> *temp = head;
        CircularNode<T> *prev = nullptr;
        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != key);

        if (temp->data == key)
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Function to print the elements of  the list
    void display()
    {
        if (head == nullptr)
            return;
        CircularNode<T> *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

#endif