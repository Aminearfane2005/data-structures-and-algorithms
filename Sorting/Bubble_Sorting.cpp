#include <iostream>   // Allows us to use input/output commands like cout
#include <algorithm>  // Allows us to use built-in functions like swap()

using namespace std;  // Allows us to write cout, endl, swap without std::


// Function that sorts an array using Bubble Sort algorithm
void bubbleSort(int arr[], int size)
{
    // Outer loop controls how many times we go through the array
    // Each pass puts one largest element at the end
    for (int step = 0; step < size - 1; ++step)
    {
        // Inner loop compares neighboring elements
        // size - step - 1 because the last elements are already sorted
        for (int i = 0; i < size - step - 1; i++)
        {
            // If the current element is bigger than the next element
            // they are in the wrong order
            if (arr[i] > arr[i + 1])
            {
                // Swap the two elements to put them in the correct order
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}


int main()
{
    // Create an integer array with 7 numbers
    int num[] = {5, 6, 4, 7, 9, 0, 1};


    // Calculate the number of elements in the array
    // sizeof(num) gives the total memory size of the array
    // sizeof(num[0]) gives the memory size of one element
    // Example: 28 bytes / 4 bytes = 7 elements
    int sizeNumber = sizeof(num) / sizeof(num[0]);


    // Print a message before sorting
    cout << "Original Array before sorting:" << endl;


    // Range-based for loop
    // Goes through every element in the array
    // auto automatically detects the data type (int)
    // & means we use a reference instead of making a copy
    for (auto &number : num)
    {
        // Print each element followed by a space
        cout << number << " ";
    }


    // Move to the next line after printing the array
    cout << endl;


    // Call the bubbleSort function
    // Send the array and its size to be sorted
    bubbleSort(num, sizeNumber);


    // Print the sorted array
    for (auto &number : num)
    {
        // Print each sorted element
        cout << number << " ";
    }


    // Move to the next line
    cout << endl;


    // End of the main function
    return 0;
}