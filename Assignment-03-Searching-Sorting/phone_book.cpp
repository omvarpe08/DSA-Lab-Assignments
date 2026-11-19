// Phone Book: sorted by name (Merge Sort), search using Sentinel Search,
// insert friend if not present.
#include <iostream>
#include <string>
using namespace std;

void merge(string names[], string mobile[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    string tempNames[100];
    string tempMobile[100];
    while (i <= mid && j <= high) {
        if (names[i] < names[j]) {
            tempNames[k] = names[i];
            tempMobile[k] = mobile[i];
            i++;
        } else {
            tempNames[k] = names[j];
            tempMobile[k] = mobile[j];
            j++;
        }
        k++;
    }
    while (i <= mid) { tempNames[k] = names[i]; tempMobile[k] = mobile[i]; i++; k++; }
    while (j <= high) { tempNames[k] = names[j]; tempMobile[k] = mobile[j]; j++; k++; }
    for (i = low, k = 0; i <= high; i++, k++) {
        names[i] = tempNames[k];
        mobile[i] = tempMobile[k];
    }
}

void mergeSort(string names[], string mobile[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(names, mobile, low, mid);
        mergeSort(names, mobile, mid + 1, high);
        merge(names, mobile, low, mid, high);
    }
}

// Sentinel Search
int sentinelSearch(string names[], int n, string key) {
    string last = names[n];
    names[n] = key;
    int i = 0;
    while (names[i] != key) i++;
    names[n] = last;
    if (i < n) return i;
    return -1;
}

void display(string names[], string mobile[], int n) {
    cout << "\n--- Phone Book ---" << endl;
    for (int i = 0; i < n; i++)
        cout << "Name: " << names[i] << " | Mobile: " << mobile[i] << endl;
}

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;
    string names[100];
    string mobile[100];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter friend name: ";
        cin >> names[i];
        cout << "Enter mobile number: ";
        cin >> mobile[i];
    }
    mergeSort(names, mobile, 0, n - 1);

    int choice;
    do {
        cout << "\n===== PHONE BOOK MENU =====" << endl;
        cout << "1. Search Friend" << endl;
        cout << "2. Insert Friend" << endl;
        cout << "3. Display Phone Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            string searchName;
            cout << "Enter friend name to search: ";
            cin >> searchName;
            int index = sentinelSearch(names, n, searchName);
            if (index != -1) {
                cout << "Friend Found!" << endl;
                cout << "Name: " << names[index] << endl;
                cout << "Mobile: " << mobile[index] << endl;
            } else cout << "Friend not found." << endl;
            break;
        }
        case 2: {
            if (n >= 100) {
                cout << "Phone book is full!" << endl;
                break;
            }
            string newName, newMobile;
            cout << "Enter friend name to insert: ";
            cin >> newName;
            int index = sentinelSearch(names, n, newName);
            if (index != -1) {
                cout << "Friend already exists in phone book." << endl;
            } else {
                cout << "Enter mobile number: ";
                cin >> newMobile;
                names[n] = newName;
                mobile[n] = newMobile;
                n++;
                mergeSort(names, mobile, 0, n - 1);
                cout << "Friend inserted successfully." << endl;
            }
            break;
        }
        case 3:
            display(names, mobile, n);
            break;
        case 4:
            cout << "Exiting Phone Book..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
