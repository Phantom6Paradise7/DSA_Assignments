#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void InsertFront(int x)
    {
        Node *newnode = new Node(x);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void InsertBack(int x)
    {
        Node *newnode = new Node(x);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void DeleteFront()
    {
        if (head == NULL)
        {
            cout << "ll is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void DeleteEnd()
    {
        if (head == NULL)
        {
            cout << "ll is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void Insert(int p, int x)
    {
        if (p < 0)
        {
            cout << "Position Invalid\n";
            return;
        }
        if (p == 0)
        {
            InsertFront(x);
            return;
        }

        Node *temp = head;
        Node *newnode = new Node(x);

        for (int i = 0; i < p - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position Invalid\n";
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position Inavlid\n";
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;

        if (newnode->next == NULL)
        {
            tail = newnode;
        }
    }

    void Search(int x)
    {
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }

        Node *temp = head;
        int id = 0;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                cout << id << endl;
                return;
            }
            temp = temp->next;
            id++;
        }
        cout << "Not found" << endl;
    }

    void Len()
    {
        if (head == NULL)
        {
            cout << 0 << endl;
            return;
        }
        Node *temp = head;
        int ct = 0;
        while (temp != NULL)
        {
            ct++;
            temp = temp->next;
        }
        cout << ct << endl;
    }
};

int main()
{
    List Ll;
    Ll.InsertFront(183);
    Ll.InsertFront(234);
    Ll.InsertFront(31);
    Ll.InsertFront(413);
    Ll.InsertBack(52);
    Ll.InsertBack(91);
    Ll.InsertFront(63);

    Ll.Display();

    Ll.DeleteFront();
    Ll.Display();

    Ll.DeleteEnd();
    Ll.Display();

    Ll.Insert(1, 0);
    Ll.Display();

    Ll.Search(3);

    Ll.Len();

    return 0;
}
