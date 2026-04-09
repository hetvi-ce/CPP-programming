#include <iostream>
using namespace std;

// Display array
template <class T>
void display(T arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Reverse array
template <class T>
void reverseArray(T arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

// Find maximum
template <class T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Find leaders
template <class T>
void findLeaders(T arr[], int n) {
    T max_from_right = arr[n-1];
    cout << max_from_right << " ";

    for(int i = n-2; i >= 0; i--) {
        if(arr[i] > max_from_right) {
            max_from_right = arr[i];
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int ch;

    do {
        cout << "\nMenu:\n";
        cout << "1. Integer Array\n";
        cout << "2. Float Array\n";
        cout << "3. Character Array\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        int n;

        switch(ch) {
            case 1: {
                cout << "Enter size: ";
                cin >> n;
                int arr[n];

                cout << "Enter elements:\n";
                for(int i = 0; i < n; i++) cin >> arr[i];

                cout << "Array: ";
                display(arr, n);

                cout << "Max: " << findMax(arr, n) << endl;

                cout << "Leaders: ";
                findLeaders(arr, n);

                reverseArray(arr, n);
                cout << "Reversed: ";
                display(arr, n);
                break;
            }

            case 2: {
                cout << "Enter size: ";
                cin >> n;
                float arr[n];

                cout << "Enter elements:\n";
                for(int i = 0; i < n; i++) cin >> arr[i];

                cout << "Array: ";
                display(arr, n);

                cout << "Max: " << findMax(arr, n) << endl;

                cout << "Leaders: ";
                findLeaders(arr, n);

                reverseArray(arr, n);
                cout << "Reversed: ";
                display(arr, n);
                break;
            }

            case 3: {
                cout << "Enter size: ";
                cin >> n;
                char arr[n];

                cout << "Enter elements:\n";
                for(int i = 0; i < n; i++) cin >> arr[i];

                cout << "Array: ";
                display(arr, n);

                cout << "Max (ASCII): " << findMax(arr, n) << endl;

                cout << "Leaders: ";
                findLeaders(arr, n);

                reverseArray(arr, n);
                cout << "Reversed: ";
                display(arr, n);
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(ch != 4);

    return 0;
}
