#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
};

template <typename T>
class LList
{
private:
    Node<T> *head;

public:
    LList()
    {
        head = NULL;
    }

    ~LList()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void insert(T value)
    {
        if (head == NULL)
        {
            head = new Node<T>;
            head->data = value;
            head->next = NULL;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node<T>;
        temp->next->data = value;
        temp->next->next = NULL;
    }

    void Delete(int idx)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (idx == 0)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T> *temp = head;
        for (int i = 0; temp != NULL && i < idx - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node<T> *next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    cout << "Testing Integer Linked List." << endl;
    LList<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.insert(40);
    cout << "Initial List: ";
    intList.display();
    cout << "Deleting index 2 (value 30)." << endl;
    intList.Delete(2);
    cout << "List after deletion: ";
    intList.display();
    cout << "\nTesting String Linked List." << endl;
    LList<string> stringList;
    stringList.insert("Apple");
    stringList.insert("Banana");
    stringList.insert("Cherry");
    cout << "String List: ";
    stringList.display();
    return 0;
}