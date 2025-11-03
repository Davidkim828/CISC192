```cpp
// Name: Heesoo (David) Kim
// Course: CISC 192 - C++ Programming
// Date: 10/30/2025

#include <iostream>
#include <array>
using namespace std;

int main() {
    const int N = 5;
    array<int, N> numbers;
    int input;

    cout << "Enter " << N << " unique integers:\n";

    for (int i = 0; i < N; i++) {
        bool duplicate;
        do {
            duplicate = false;
            cout << "Element " << i + 1 << ": ";
            cin >> input;

            // Check for duplicates
            for (int j = 0; j < i; j++) {
                if (numbers[j] == input) {
                    cout << "Duplicate found! Enter a different number.\n";
                    duplicate = true;
                    break;
                }
            }

        } while (duplicate);

        numbers[i] = input;
    }

    cout << "\nChoose an operation:\n";
    cout << "1. Sort Ascending\n";
    cout << "2. Sort Descending\n";
    cout << "3. Find Maximum\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Bubble sort (ascending)
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N - i - 1; j++) {
                    if (numbers[j] > numbers[j + 1]) {
                        int temp = numbers[j];
                        numbers[j] = numbers[j + 1];
                        numbers[j + 1] = temp;
                    }
                }
            }
            cout << "\nArray sorted in ascending order:\n";
            for (int num : numbers) cout << num << " ";
            cout << endl;
            break;
        }

        case 2: {
            // Bubble sort (descending)
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N - i - 1; j++) {
                    if (numbers[j] < numbers[j + 1]) {
                        int temp = numbers[j];
                        numbers[j] = numbers[j + 1];
                        numbers[j + 1] = temp;
                    }
                }
            }
            cout << "\nArray sorted in descending order:\n";
            for (int num : numbers) cout << num << " ";
            cout << endl;
            break;
        }

        case 3: {
            // Find maximum manually
            int maxVal = numbers[0];
            for (int i = 1; i < N; i++) {
                if (numbers[i] > maxVal)
                    maxVal = numbers[i];
            }
            cout << "\nThe maximum number is: " << maxVal << endl;
            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}
<img width="303" height="262" alt="Screenshot 2025-11-02 at 11 36 15 PM" src="https://github.com/user-attachments/assets/108efdf9-16f5-4ea5-904a-12ec55882585" />
<img width="303" height="192" alt="Screenshot 2025-11-02 at 11 36 49 PM" src="https://github.com/user-attachments/assets/20abd759-ce68-4374-aac8-c93860ab1c6d" />
<img width="303" height="209" alt="Screenshot 2025-11-02 at 11 37 13 PM" src="https://github.com/user-attachments/assets/7dacf568-1718-4f65-9ec7-00fa606ab14a" />
