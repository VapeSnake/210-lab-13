// COMSC-210 | Lab 13 std:vector | Noel Mier-Luna
// Changing this program to use std::vector instead of std::array.
#include <iostream>
#include <vector>     // For std::vector
#include <fstream>   // For file I/O
#include <algorithm> // For sort and find
#include <numeric>   // For accumulate
using namespace std;

// Features we want to use in this lab:
//   std::vector - A container that dynamically resizes itself as elements are added. (Check)
//   size() - A member function of std::vector that returns the number of elements in the vector.
//   vector functions - Using functions like push_back to add elements to the vector.
//   File I/O - Reading from and writing to files using fstream.
//   Algorithms - Using algorithms like sort from the <algorithm> library.
//   Accumulate - Using the accumulate function from the <numeric> library to sum elements in a vector.
//  .at() - A member function of std::vector that provides bounds-checked access to elements.
//  .begin() and .end() - Member functions of std::vector that return iterators to the beginning and end of the vector, respectively.
//  rbegin() and rend() - Member functions of std::vector that return reverse iterators to the beginning and end of the vector, respectively.
//  find() - An algorithm from the <algorithm> library that searches for a specific value in a range of elements using an iterator.

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
}