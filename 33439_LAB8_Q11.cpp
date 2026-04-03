#include <iostream>
using namespace std;
template <typename T>
int fequency(T arr[], int size, T element)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            count++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 4;
    cout << "Frequency of " << element << " is : " << fequency(arr, size, element) << endl;

    string words[] = {"apple", "banana", "apple", "cherry", "apple"};
    int wordSize = sizeof(words) / sizeof(words[0]);
    string wordElement = "apple";
    cout << "Frequency of '" << wordElement << "' is : " << fequency(words, wordSize, wordElement) << endl;
    return 0;
}