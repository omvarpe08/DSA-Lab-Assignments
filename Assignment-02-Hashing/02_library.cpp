#include <iostream>
using namespace std;
int main() {
    int tableSize, n;
    cout << "Enter table size: ";
    cin >> tableSize;
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) hashTable[i] = -1;

    cout << "Enter number of books: ";
    cin >> n;
    // Hashing with linear probing
    for (int i = 0; i < n; i++) {
        int isbn;
        cout << "Enter ISBN number: ";
        cin >> isbn;
        int index = isbn % tableSize;
        int start = index;
        while (hashTable[index] != -1) {
            index = (index + 1) % tableSize;
            if (index == start) {
                cout << "Hash table is full!" << endl;
                break;
            }
        }
        if (hashTable[index] == -1) {
            hashTable[index] = isbn;
            cout << "Book stored at index " << index << endl;
        }
    }
    cout << "\n--- Library Hash Table ---" << endl;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] == -1) cout << "Index " << i << ": Empty" << endl;
        else cout << "Index " << i << ": ISBN " << hashTable[i] << endl;
    }
    return 0;
}
