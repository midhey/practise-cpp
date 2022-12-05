#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter size:";
    cin >> size;

    int bufferSize;
    cout << "Enter buffer size:";
    cin >> bufferSize;

    int *buffer = new int[bufferSize]{0};

    int bufferIteration = 0;

    for (int i = 0; i < size; i++) {
        int num;
        cout << "Enter number:";
        cin >> num;
        buffer[bufferIteration] = num;
        if (bufferIteration == (bufferSize-1)) bufferIteration = 0;
        else bufferIteration++;
    }
    for (int i = 0; i < bufferSize; i++) {
        cout << buffer[i] << " ";
    }


    delete[] buffer;
    return 0;
}