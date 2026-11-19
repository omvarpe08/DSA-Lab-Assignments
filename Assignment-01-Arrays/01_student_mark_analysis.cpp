#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int marks[n];
    cout << "\nEnter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
    cout << "\n--- Student Marks ---\n";
    for (int i = 0; i < n; i++)
        cout << "Student " << i + 1 << ": " << marks[i] << endl;

    int sum = 0, maximum = marks[0], minimum = marks[0];
    for (int i = 0; i < n; i++) {
        sum += marks[i];
        if (marks[i] > maximum) maximum = marks[i];
        if (marks[i] < minimum) minimum = marks[i];
    }
    float average = (float)sum / n;
    cout << "\n--- Analysis ---\n";
    cout << "Total Marks = " << sum << endl;
    cout << "Average Marks = " << average << endl;
    cout << "Highest Marks = " << maximum << endl;
    cout << "Lowest Marks = " << minimum << endl;

    int searchMark;
    bool found = false;
    cout << "\nEnter marks to search: ";
    cin >> searchMark;
    for (int i = 0; i < n; i++) {
        if (marks[i] == searchMark) {
            cout << "Marks found at Student " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) cout << "Marks not found.\n";

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (marks[j] > marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
    cout << "\n--- Marks in Ascending Order ---\n";
    for (int i = 0; i < n; i++) cout << marks[i] << " ";
    cout << endl;
    return 0;
}
