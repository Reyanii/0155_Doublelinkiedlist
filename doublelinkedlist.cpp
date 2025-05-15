#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinledList
{
    private:
    Node *START;

    public:
    DoubleLinledList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // step 1 allpcate memory foor new node
        Node *newNode = new Node();

        // step 2 assing value to the data fields
        newNode->noMhs = nim;

        // step 3 insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //STEP 4 new node.next = START
            newNode->next = START;

            // step 5 START.prev = newNode (if START existan)
            if (START != NULL)
            START->prev = newNode;

            // Step 6 newNode.prev = NULL
            newNode->prev = NULL;

            //Step 7 START = newNode
            START = newNode;
            return;
        }

        // insert in between node
        // step 8 Locate posotion for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 9 Insert between current and current->
        newNode->next = current->next;
        newNode->prev = current;

        //insert last node
        if (current->next != NULL)
            current->next->prev = newNode;

     current->next = newNode;
    }

    void hapus ()
    { 
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        
        cout << "\nEnter the roll number of the student whose record is to be deleted";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // step 1 Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // step 2 if node is at the beginning
        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev =NULL;
        }
        else
        {
            // step 3 link previous node to next of current
            current->prev->next = current->next;

            //step 4 if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // step 5
        delete current;
        cout << "Record with roll number " << rollNo << "deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1 mark first node as currentNode
        Node *CurrentNode = START;
        
    }
}