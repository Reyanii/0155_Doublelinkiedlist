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
        // step 2 reapeat until currentNode == NULL
        cout << "\nRecprds in ascending order of roll numjber are:\n";
        int i = 0;
        while (CurrentNode != NULL)
        {
            cout << i + 1 << ". " << CurrentNode->noMhs << " " << endl;
            // step 3 move to next node
            CurrentNode = CurrentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1 move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        // step 2 Traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            //step 3 move to previous node
            currentNode = currentNode->prev;
            i++;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *currnet = START;

        // step 1 Traverse to find matcing roll number
        while (currnet != NULL && currnet->noMhs != rollNo)
        currnet = currnet->next;

        //step 2 output result
        if (currnet == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "roll Number: " << currnet->noMhs << endl;

        }
    }
};

int main()
{
    DoubleLinledList list;
    char choice;

    do
    {
        
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. view Ascending\n";
        cout << "4. view Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid opition\n";
        }
        cout << "\nPress Enter to contine...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
    
}