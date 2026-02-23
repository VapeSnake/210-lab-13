// COMSC-210 | Lab 13 std:vector | Noel Mier-Luna
// Changing this program to use std::vector instead of std::array.
#include <iostream>
#include <array>     // For std::array
#include <fstream>   // For file I/O
#include <algorithm> // For sort and find
#include <numeric>   // For accumulate
using namespace std;



// Features we want to use in this lab:
//   std::array - A container that encapsulates fixed size arrays. (Check)
//   size() - A member function of std::array that returns the number of elements in the array. (Check)
//   File I/O - Reading from and writing to files using fstream. (Check)
//   Algorithms - Using algorithms like sort from the <algorithm> library. (Check)
//   Accumulate - Using the accumulate function from the <numeric> library to sum elements in an array. (Check)
//  .at() - A member function of std::array that provides bounds-checked access to elements. (Check)
//  .begin() and .end() - Member functions of std::array that return iterators to the beginning and end of the array, respectively. (Check)
//  rbegin() and rend() - Member functions of std::array that return reverse iterators to the beginning and end of the array, respectively. (Check)
//  find() - An algorithm from the <algorithm> library that searches for a specific value in a range of elements using an iterator. (Check).

int main()
{
    array<int, SIZE> randomArray;                                       // Declare an empty array of integers with size 30.
int main() {
    array < int, SIZE > randomArray; // Declare an empty array of integers with size 30.
    cout << "The size of the array is: " << randomArray.size() << endl; // Display the size of the array.

    ifstream inputFile("Random30Elements.txt"); // Open the file containing random numbers.
    if (!inputFile)
    {
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return -1; // Exits program if file can't be opened.
    }
    int i = 0;
    int element;
    while (inputFile >> element && i < SIZE)
    {                                // Read integers from the file and store them in the array until the end of the file or the array is full.
    while (inputFile >> element && i < SIZE) { // Read integers from the file and store them in the array until the end of the file or the array is full.
        randomArray.at(i) = element; // Use .at() for bounds-checked access to store elements in the array.
        i++;
    }

    inputFile.close(); // Closes file after reading.

    cout << "Displaying array elements: \n";
    for (const int num : randomArray)
    {
    for (const int num: randomArray) {
        cout << num << " "; // Display the elements of the array using a range-based for loop.
    }

    cout << "\n\nSorting the array in ascending order... \n";
    sort(randomArray.begin(), randomArray.end()); // Sorts the array in ascending order using sort function and .begin & .end iterators.

    cout << "Sorted array elements: \n";
    for (const int num : randomArray)
    {
    for (const int num: randomArray) {
        cout << num << " "; // Display the sorted elements of the array.
    }

    cout << "\n\nReversing the array... \n";
    sort(randomArray.rbegin(), randomArray.rend()); // Reverses the order of the elements in the array using reverse iterators.

    cout << "Reversed array elements: \n";
    for (const int num : randomArray)
    {
    for (const int num: randomArray) {
        cout << num << " "; // Display the reversed elements of the array.
    }

    cout << "\n\nCalculating the sum of the array elements... \n";
    int sum = accumulate(randomArray.begin(), randomArray.end(), 0); // Calculate the sum of the elements in the array using accumulate function.

    cout << "The sum of the array elements is: " << sum << endl; // Display the sum of the array elements.

    cout << "\n\nSearching for a specific value (e.g., 42) in the array... \n";
    int target = 78;                                                                      // Example target value to search for in the array.
    array<int, SIZE>::iterator it = find(randomArray.begin(), randomArray.end(), target); // Searches for target value in the array using find function.
    cout << "\n\nSearching for a specific value in the array... \n";
    int target = 78; // Example target value to search for in the array.
    array < int, SIZE > ::iterator it = find(randomArray.begin(), randomArray.end(), target); // Searches for target value in the array using find function.
    cout << "Value " << target;
    if (it != randomArray.end())
    {
    if (it != randomArray.end()) {
        cout << " found at index: " << it - randomArray.begin() << endl; // If found, display the index of the target value.
    }
    else
    {
    } else {
        cout << " not found in the array." << endl; // If not found, indicate that the value is not in the array.
    }

    int target = 99;                                                                      // Example target that is not in the array to demonstrate the not found case.
    array<int, SIZE>::iterator it = find(randomArray.begin(), randomArray.end(), target); // Searches for target value in the array using find function.
    target = 99; // Example target that is not in the array to demonstrate the not found case.
    it = find(randomArray.begin(), randomArray.end(), target); // Searches for target value in the array using find function.
    cout << "Value " << target;
    if (it != randomArray.end())
    {
    if (it != randomArray.end()) {
        cout << " found at index: " << it - randomArray.begin() << endl; // If found, display the index of the target value.
    }
    else
    {
    } else {
        cout << " not found in the array." << endl; // If not found, indicate that the value is not in the array.
    }
    return 0;
}