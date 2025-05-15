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
            START->prev = newNode
        }
    }
}