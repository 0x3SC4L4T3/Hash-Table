#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Food
{
    string foodID, name, supplierID;
    double price;
    struct Food* next;
};

class LinkedList
{
private:
    struct Food* head;
    int size;
public:
    LinkedList();
    ~LinkedList();
    Food* getHead();
    int getSize();
    bool insertFood(string foodID, string name, string supplierID, double price);
    bool deleteFood(string foodID);
    bool searchFood(string foodID);
    void displayList();
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList()
{
    if (!head) {
        return;
    }
    struct Food* current = head;
    struct Food* next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    //----
    head = NULL;
}

//Accessor for the head
Food* LinkedList::getHead()
{
    return head;
}

//Return number of foods inside the Linked list
int LinkedList::getSize()
{
    return size;
}

//Insert the parameter food at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insertFood(string foodID, string name, string supplierID, double price)
{
    //----

    Food *toInsert = new Food;
    toInsert->foodID = foodID;
    toInsert->name = name;
    toInsert->supplierID = supplierID;
    toInsert->price = price;

    if (head == NULL) {
        head = toInsert;
        toInsert->next = NULL;
        size++;
        return true;
    }
    else {
        toInsert->next = head;
        head = toInsert;
        size++;
        return true;
    }

    return false;
}

//Delete the food with the given foodID from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteFood(string foodID)
{
    
    //----
    if (head->foodID.compare(foodID) == 0) {
        if (head->next) {
            head = head->next;
        }
        else {
            head = NULL;
        }
    }
    else {
        Food* itr = head;
        Food* prev = NULL;
        while (itr && itr->foodID.compare(foodID)!= 0) {
            prev = itr;
            itr = itr->next;
        }
        if (itr == NULL) {
            return false;
        } 

        prev->next = itr->next;
        free(itr);
    }
    size--;
    return true;
}

//This function searches the food list with the given foodID
//returns true if it is found, otherwise return false.
bool LinkedList::searchFood(string foodID)
{
    if(!head){
        return false;
    }
    else {
        Food* itr = head;
        while (itr) {

            if (itr->foodID.compare(foodID) == 0) {
                return true;
            }
            itr = itr->next;
        }
    }

    return false;
    
    //----
}

//This function displays the content of the linked list.
void LinkedList::displayList()
{
    struct Food* temp = head;
    if (head == NULL)
    {
        return;
    }
    while (temp != NULL)
    {
        cout << left;
        cout << setw(4) << temp->foodID
            << setw(30) << temp->name
            << setw(12) << temp->supplierID
            << setw(5) << temp->price << endl;
        temp = temp->next;
    }
}