#include <iostream>
using namespace std;
int main() {
    int tableSize, n;
    cout << "Enter hash table size: ";
    cin >> tableSize;
    int code[tableSize];
    int stock[tableSize];
    float price[tableSize];
    for (int i = 0; i < tableSize; i++) {
        code[i] = -1;
        stock[i] = 0;
        price[i] = 0;
    }
    cout << "Enter number of products: ";
    cin >> n;
    // Insert products using hashing and linear probing
    for (int i = 0; i < n; i++) {
        int productCode, productStock;
        float productPrice;
        cout << "\nEnter product code: ";
        cin >> productCode;
        cout << "Enter stock: ";
        cin >> productStock;
        cout << "Enter price: ";
        cin >> productPrice;

        int index = productCode % tableSize;
        int start = index;
        while (code[index] != -1) {
            index = (index + 1) % tableSize;
            if (index == start) {
                cout << "Hash table is full!" << endl;
                break;
            }
        }
        if (code[index] == -1) {
            code[index] = productCode;
            stock[index] = productStock;
            price[index] = productPrice;
            cout << "Product stored at index " << index << endl;
        }
    }
    cout << "\n--- Inventory ---" << endl;
    for (int i = 0; i < tableSize; i++) {
        if (code[i] == -1) cout << "Index " << i << ": Empty" << endl;
        else
            cout << "Index " << i
                 << " | Code: " << code[i]
                 << " | Stock: " << stock[i]
                 << " | Price: " << price[i] << endl;
    }
    // Search product
    int searchCode;
    cout << "\nEnter product code to search: ";
    cin >> searchCode;
    int index = searchCode % tableSize;
    int start = index;
    bool found = false;
    while (code[index] != -1) {
        if (code[index] == searchCode) {
            cout << "Product Found!" << endl;
            cout << "Stock: " << stock[index] << endl;
            cout << "Price: " << price[index] << endl;
            found = true;
            break;
        }
        index = (index + 1) % tableSize;
        if (index == start) break;
    }
    if (!found) cout << "Product not found." << endl;
    return 0;
}
