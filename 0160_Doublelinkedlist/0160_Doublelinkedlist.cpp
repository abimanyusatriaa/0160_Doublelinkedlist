
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

int main()
{
    std::cout << "Hello World!\n";
}
