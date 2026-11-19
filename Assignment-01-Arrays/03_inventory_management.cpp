#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    int quantity[n];
    float price[n];
    cout << "\nEnter quantity and price of each product:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Quantity: ";
        cin >> quantity[i];
        cout << "Price: ";
        cin >> price[i];
    }
    cout << "\n--- Inventory Details ---\n";
    float totalValue = 0;
    for (int i = 0; i < n; i++) {
        float value = quantity[i] * price[i];
        totalValue += value;
        cout << "Product " << i + 1
             << " | Quantity: " << quantity[i]
             << " | Price: " << price[i]
             << " | Value: " << value << endl;
    }
    cout << "\nTotal Inventory Value = " << totalValue << endl;

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
        if (quantity[i] > quantity[maxIndex]) maxIndex = i;
    cout << "Product with highest stock: Product " << maxIndex + 1 << endl;
    cout << "Quantity: " << quantity[maxIndex] << endl;

    int searchProduct;
    cout << "\nEnter product number to check: ";
    cin >> searchProduct;
    if (searchProduct >= 1 && searchProduct <= n) {
        cout << "Quantity: " << quantity[searchProduct - 1] << endl;
        cout << "Price: " << price[searchProduct - 1] << endl;
    } else cout << "Invalid product number.\n";
    return 0;
}
