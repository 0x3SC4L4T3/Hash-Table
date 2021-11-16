#pragma once
#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

class Hash
{
private:
    LinkedList* hashTable;     //hashTable is a one-dimensional array of LinkedList
    int m;                     //slots number of the hash table
public:
    Hash(int size);
    ~Hash();
    bool hashInsert(string foodID, string name, string supplierID, double price);
    bool hashDelete(string foodID, string name, string supplierID);
    bool hashSearch(string foodID, string name, string supplierID);
    void hashDisplay();
    int hashFunction(string key);

    //add any other auxiliary functions here
    //----
};

//constructor
Hash::Hash(int size)
{
    hashTable = new LinkedList[size];
    m = size;
}

//Destructor
Hash::~Hash()
{
    delete[]hashTable;
    //----
}

//hashInsert inserts a Food with the relevant info. into the hashTable.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string foodID, string name, string supplierID, double price)
{
    int hashIndex = hashFunction(foodID);
    if (hashTable[hashIndex].insertFood(foodID, name, supplierID, price)) {
        cout << "slot index = " << hashIndex << endl;
        return true;
    }

    return false;
    //----
}

//hashDelete deletes a Food with the relevant key from the hashTable.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashDelete(string foodID, string name, string supplierID)
{

    int hashIndex = hashFunction(foodID);
    if (hashTable[hashIndex].deleteFood(foodID)) {
        //----
        cout << "\n";
        cout << setw(4) << foodID
            << setw(30) << name
            << setw(12) << supplierID
            << " is deleted from hash table." << endl;
        return true;
    }
    return false;
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashSearch(string foodID, string name, string supplierID)
{
    //----
    bool found = true;
    int hashIndex = hashFunction(foodID);
    if (!hashTable[hashIndex].searchFood(foodID)) {
        found = false;
    }

    if (found)
        cout << "\n" << left
        << setw(4) << foodID
        << setw(30) << name
        << setw(12) << supplierID
        << " is found inside the hash table." << endl;
    if (!found)
        cout << "\n" << left
        << setw(4) << foodID
        << setw(30) << name
        << setw(12) << supplierID
        << " is NOT found inside the hash table." << endl;

    return found;
}

//This function prints all the elements from the hash hashTable.
void Hash::hashDisplay()
{
    for (int i = 0; i < m; i++) {
        if (hashTable[i].getSize() == 0) {
            cout << "HashTable[" << i << "] is empty, size = 0" << endl;
        }
        else {
            cout << "HashTable[" << i << "], " << "size = " << hashTable[i].getSize() << endl;
            hashTable[i].displayList();
            cout << endl;
        }

    }
    //----
    //----
}

//This is the hash function you will need to design, test and refine
//Given a Food key, the function should return the slot index where it
//will be hashed to
int Hash::hashFunction(string key)
{
    int sum = 0;
    for (int i = 0; i < key.size(); i++) {
        sum += int(key.at(i));
    }
    return sum % m;
    //----
}