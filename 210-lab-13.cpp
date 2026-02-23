// COMSC-210 | Lab 13 std:vector | Noel Mier-Luna
// Changing this program to use std::vector instead of std::array.
#include <iostream>
#include <vector>    // For std::vector
#include <fstream>   // For file I/O
#include <algorithm> // For sort and find
#include <numeric>   // For accumulate
using namespace std;

// Features we want to use in this lab:
//   std::vector - A container that dynamically resizes itself as elements are added. (Check)
//   size() - A member function of std::vector that returns the number of elements in the vector. (Check)
//   vector functions - Using functions like push_back to add elements to the vector. (Check)
//   File I/O - Reading from and writing to files using fstream. (Check)
//   Algorithms - Using algorithms like sort from the <algorithm> library. (Check)
//   Accumulate - Using the accumulate function from the <numeric> library to sum elements in a vector.(Check)
//  .begin() and .end() - Member functions of std::vector that return iterators to the beginning and end of the vector, respectively. (Check)
//  rbegin() and rend() - Member functions of std::vector that return reverse iterators to the beginning and end of the vector, respectively. (Check)
//  find() - An algorithm from the <algorithm> library that searches for a specific value in a range of elements using an iterator. (Check)
//  swap() - A function from the <vector> library that swaps the contents of two vectors.
//  clear() - A member function of std::vector that removes all elements from the vector, leaving it with a size of 0.

int main()
{
    vector<int> randomVector;                                             // Declare an empty vector of integers.
    cout << "The size of the vector is: " << randomVector.size() << endl; // Display the size of the vector.

    ifstream inputFile("Random30Elements.txt"); // Open the file containing random numbers.
    if (!inputFile)
    {
        cerr << "Error opening file." << endl;
        return -1; // Exits program if file can't be opened.
    }
    int number;
    while (inputFile >> number) // Reads numbers from the file until the end of the file is reached.
    {
        randomVector.push_back(number); // Adds each number read from the file to the vector using push_back.
    }

    inputFile.close(); // Closes file after reading.

    cout << "Displaying vector elements: \n";
    for (const int num : randomVector)
    {
        cout << num << " "; // Display the elements of the vector using a range-based for loop.
    }
    cout << endl;

    cout << "The size of the vector is: " << randomVector.size() << endl; // Display the size of the vector after adding elements.

    cout << "Sorting the vector in ascending order... \n";
    sort(randomVector.begin(), randomVector.end()); // Sorts the vector in ascending order using the sort algorithm.

    cout << "Displaying sorted vector elements: \n";
    for (const int num : randomVector)
    {
        cout << num << " "; // Display the sorted elements of the vector.
    }

    cout << endl;

    cout << "Sorting the vector in descending order... \n";
    sort(randomVector.rbegin(), randomVector.rend()); // Sorts the vector in descending order using reverse iterators.

    cout << "Displaying sorted vector elements: \n";
    for (const int num : randomVector)
    {
        cout << num << " "; // Display the sorted elements of the vector.
    }
    cout << endl;

    cout << "Calculating the sum of the vector elements... \n";
    int sum = accumulate(randomVector.begin(), randomVector.end(), 0); // Calculates the sum of the vector elements using accumulate.
    cout << "The sum of the vector elements is: " << sum << endl;      // Display the sum of the vector elements.

    cout << "Searching for the number 57 in the vector... \n";
    vector<int>::iterator it = find(randomVector.begin(), randomVector.end(), 57); // Searches for the number 57 in the vector using find.
    if (it != randomVector.end())
    {
        cout << "Number found at index: " << it - randomVector.begin() << endl; // If found, display the index of the number.
    }
    else
    {
        cout << "Number not found in the vector." << endl; // If not found, displays message indicating so.
    }

    cout << "Searching for the number 1 in the vector... \n";
    it = find(randomVector.begin(), randomVector.end(), 1); // Show case where value is not found in the vector.
    if (it != randomVector.end())
    {
        cout << "Number found at index: " << it - randomVector.begin() << endl;
    }
    else
    {
        cout << "Number not found in the vector." << endl;
    }

}