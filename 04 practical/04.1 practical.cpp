#include <iostream>
using namespace std;
class DynamicArray
{
private:
    int* arr;
    int capacity;
    int size;
    void resize()
    {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
    }
public:
    DynamicArray(int cap = 2)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    ~DynamicArray()
    {
        delete[] arr;
    }
    void insert(int value);
    void deleteAt(int pos);
    void display();
};
void DynamicArray::insert(int value)
{
    if (size == capacity)
        resize();
    arr[size++] = value;
    cout << value << " inserted successfully.\n";
}
void DynamicArray:: deleteAt(int pos)
{
    if (size == 0)
    {
        cout << "Array is empty!\n";
        return;
    }
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    cout << "Element at position " << pos << " deleted.\n";
}

void DynamicArray::display()
{
    if (size == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array contents: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    DynamicArray da;
    int choice, value, pos;

    while (true)
    {
        cout << "\n--- Dynamic Array Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                da.insert(value);
                break;
            case 2:
                cout << "Enter position to delete (0-indexed): ";
                cin >> pos;
                da.deleteAt(pos);
                break;
            case 3:
                da.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
