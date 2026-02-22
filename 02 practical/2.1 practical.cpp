#include<iostream>
using namespace std;

class rectangular
{
private:
    float length;
    float breadth;

public:
    void enter_dimensions();
    void update_dimensions();
    float calculate_area();
    float calculate_perimeter();
    void display_results();
};

void rectangular::enter_dimensions()
{
    cout << "Length: ";
    cin >> length;

    while(length <= 0)
    {
        cout << "Invalid! Enter positive length: ";
        cin >> length;
    }

    cout << "Breadth: ";
    cin >> breadth;

    while(breadth <= 0)
    {
        cout << "Invalid! Enter positive breadth: ";
        cin >> breadth;
    }
}

void rectangular::update_dimensions()
{
    cout << "Update Length: ";
    cin >> length;

    while(length <= 0)
    {
        cout << "Invalid! Enter positive length: ";
        cin >> length;
    }

    cout << "Update Breadth: ";
    cin >> breadth;

    while(breadth <= 0)
    {
        cout << "Invalid! Enter positive breadth: ";
        cin >> breadth;
    }

    cout << "Dimensions Updated Successfully!\n";
}

float rectangular::calculate_area()
{
    return length * breadth;
}

float rectangular::calculate_perimeter()
{
    return 2 * (length + breadth);
}

void rectangular::display_results()
{
    cout << "\n---- Results ----" << endl;
    cout << "Length      : " << length << endl;
    cout << "Breadth     : " << breadth << endl;
    cout << "Area        : " << calculate_area() << endl;
    cout << "Perimeter   : " << calculate_perimeter() << endl;
    cout << "------------------" << endl;
}

int main()
{
    rectangular r[100];
    int count = 0;
    int ch, n;

    do
    {
        cout << "1. Add Rectangle";
        cout << "\n2. Update Dimension";
        cout << "\n3. Display Results";
        cout << "\n4. Exit";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                if(count < 100)
                {
                    cout << "\nRectangle " << count + 1 << endl;
                    r[count].enter_dimensions();
                    count++;
                }
                else
                {
                    cout << "Storage Full!" << endl;
                }
                break;

            case 2:
                if(count == 0)
                {
                    cout << "No rectangles to update!\n";
                }
                else
                {
                    cout << "Enter rectangle number to update (1 to " << count << "): ";
                    cin >> n;

                    if(n >= 1 && n <= count)
                    {
                        r[n - 1].update_dimensions();
                    }
                    else
                    {
                        cout << "Invalid rectangle number!\n";
                    }
                }
                break;

            case 3:
                for(int i = 0; i < count; i++)
                {
                    cout << "\nRectangle " << i + 1;
                    r[i].display_results();
                }
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }while(ch!=4);
}
