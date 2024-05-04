
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() {
    Node* newNode = new Node(); // STEP 1: create a new node
    cout << "\nEnter the roll number of student: ";
    cin >> newNode->noMhs;      // assign value to the data field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;       // Assign value to the data field of the new node

    // Insert the new node in the list
    if (START == NULL || newNode->noMhs <= START->noMhs) { // STEP 2: insert the new node

        if (START != NULL && newNode->noMhs == START->noMhs) {
            cout << "\033[31mDuplicate roll not allowed\033[0m" << endl;
            return;
        }
        // If the list is empty, make the new node the START
        newNode->next = START;  //STEP 3: make the new node point to the first node
        if (START != NULL) {
            START->prev = newNode;  //STEP 4: make the first node point to the new node
        }
        newNode->prev = NULL;       //STEP 5: make the new node point to NULL
        START = newNode;            //STEP 6: make the new node the first node
    }
    else {
        // insert the new node in the middle or at the end
        Node* current = START; // STEP 1.a: start from the first
        Node* previous = NULL; // STEP 1.b: previous node is NULL initially

        while (current != NULL && current->noMhs < newNode->noMhs) { // STEP 1.c: traver
            previous = current; // STEP 1.d: move the previous to the current Node
            current = current->next; // STEP 1.e: move the current to the next node
        }

        newNode->next = current; // STEP 4: Make the next field of the new node point to current
        newNode->prev = previous; // STEP 5: Make the previous field of the new node point to previous

        if (current != NULL) {
            current->prev = newNode; // STEP 6: Make the previous field of the current
        }

        if (previous != NULL) {
            previous->next = newNode; // STEP 7 : make the next field of the previous node
        }
        else {
            //If previous is still NULL, it means newNode is now the first node
            START = newNode;
        }
    }
}

bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if (START == NULL)
    {
        cout << "List is empety" << endl;
        return;
    }

    current = START;                                                               //STEP 1: start from the first node
    previous = NULL;

    //locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    //Node to be deleted is the firts node
    if (current == START)
    {
        START = START->next;                                            //STEP 2: update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;                                         //step
        }
    }
    else
    {   //Node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        {   //if there's successor, update is prev pointer
            current->next->prev = previous;
        }
    }

    //release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

bool listEmpty()
{
    return (START == NULL);
}

void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecord is ascending order of roll number are:  " << endl;
        Node* currentNode = START;              //STEP 1
        while (currentNode != NULL)             //STEP 2
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;         //STEP 3
            currentNode = currentNode->next;                                        //STEP 4
        }
    }
}

void revtraverse()

int main()
{
    std::cout << "Hello World!\n";
}
