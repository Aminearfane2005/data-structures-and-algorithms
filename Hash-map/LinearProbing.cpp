#include <bits/stdc++.h>
using namespace std;

// Class representing a single node in the hash map
class HashNode {
public:
    int key, value;

    // Constructor to initialize key-value pair
    HashNode(int k, int v) {
        key = k;
        value = v;
    }
};
// HashMap class using open addressing with linear probing
class HashMap {
    int capacity;       // Maximum size of the hash table
    int size;           // Current number of elements in the map
    HashNode** arr;     // Array of pointers to HashNode
    HashNode* dummy;    // Dummy node to mark deleted positions

public:
    // Constructor
    HashMap() {
        capacity = 20;  // Initial capacity
        size = 0;       // Initially empty
        arr = new HashNode*[capacity];

        // Initialize all positions as NULL
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;

        // Dummy node represents a deleted slot
        dummy = new HashNode(-1, -1);
    }

    // Simple hash function (modulo operation)
    int hashCode(int key) {
        return key % capacity;
    }
 // Rehashing function to resize the table when load factor >= 0.7
    void rehash(){
        HashNode** oldArr = arr;
        int oldCap = capacity;
        capacity *= 2;
        size =0;
        arr = new HashNode*[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i]= NULL;
        }
        
        for (int i = 0; i < oldCap; i++)
        {
           if(oldArr[i] != NULL && oldArr[i]->key != -1 ){
            insertNode(oldArr[i]->key, oldArr[i]->value);
           }
        }
        
    }


    
    // Insert a key-value pair into the hash map
    void insertNode(int key, int value) {
        // Rehash if load factor exceeds 0.7
        if ((double)size / capacity >= 0.7)
            rehash();

            HashNode* temp = new HashNode(key, value);
        int hashIndex = hashCode(key);
        int counter = 0;

          // Linear probing to find an empty or deleted slot
        while (arr[hashIndex] != NULL &&
               arr[hashIndex]->key != key &&
               arr[hashIndex]->key != -1) {

            if (counter++ >= capacity)  // Prevent infinite loop
                return;

            hashIndex = (hashIndex + 1) % capacity;
        }

         // If inserting into empty or deleted slot, increase size
        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;

        arr[hashIndex] = temp;  // Insert node
    }

    // Delete a key from the hash map
    int deleteNode(int key) {
        int hashIndex = hashCode(key);
        int counter = 0;

        // Linear probing to find the key
        while (arr[hashIndex] != NULL) {

            if (counter++ >= capacity)
                return -1;  // Key not found

            if (arr[hashIndex]->key == key) {
                int val = arr[hashIndex]->value;
                delete arr[hashIndex];     // Free memory
                arr[hashIndex] = dummy;    // Mark as deleted
                size--;
                return val;
            }

            hashIndex = (hashIndex + 1) % capacity;
        }

        return -1;  // Key not found
    }

     // Get value for a key
    int get(int key) {
        int hashIndex = hashCode(key);
        int counter = 0;

        // Linear probing to find the key
        while (arr[hashIndex] != NULL) {

            if (counter++ >= capacity)
                return -1;  // Key not found

            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;

            hashIndex = (hashIndex + 1) % capacity;
        }

        return -1;  // Key not found
    }
// Get current number of elements in the map
    int sizeofMap() {
        return size;
    }
    // Check if the map is empty
    bool isEmpty() {
        return size == 0;
    }
     // Display all key-value pairs
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1)
                cout << arr[i]->key << " " << arr[i]->value << endl;
        }
    }
};
int main() {
    HashMap h;

    // Insert elements
    h.insertNode(1, 10);
    h.insertNode(2, 20);
    h.insertNode(3, 30);
    h.insertNode(22, 220);
    h.insertNode(42, 420);

    cout << "Hash Map Elements:\n";
    h.display();  // Display elements

    cout << "\nSize of map: " << h.sizeofMap() << endl;

    // Delete a key
    cout << "\nDeleting key 2 -> " << h.deleteNode(2) << endl;

    cout << "Size after deletion: " << h.sizeofMap() << endl;

    // Access values
    cout << "\nValue of key 3: " << h.get(3) << endl;
    cout << "Value of key 2: " << h.get(2) << endl;  // Key 2 deleted

    // Check if map is empty
    cout << "\nIs map empty? " << (h.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}