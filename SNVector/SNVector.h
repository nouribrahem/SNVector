#ifndef SNVECTOR_SNVECTOR_H
#define SNVECTOR_SNVECTOR_H

#include <iostream>


using namespace std;
template <class T>
class SNVector;
template <class T>
ostream& operator << (ostream& out, SNVector<T> vector);
template <class T>

class SNVector {
private:
    int size;
    int capacity;
    T* vec;

public:
    // Constructors and Big 4
    SNVector(int num = 2);		        	            // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    SNVector(T* arr, int  n);	                // Initialize by n items from array
    SNVector(const SNVector& vector);             	// Initialize with a copy
    ~SNVector();			                    // Delete allocated memory
    SNVector& operator=(const SNVector& vector);           // Copy assignment
    SNVector& operator=(SNVector&& vector)noexcept;          // Move assignment

    // Access operations
    T& operator[](int);                          // Access item by reference
    // Throw an exception if out of range

// Modifying operations
    int push_back(T);                                // Add item to end of vec & return # of items
    // Increase capacity of needed
    T pop_back();                                        // Remove and return last element in vec
    void erase(SNVector<T> iterator);                               // Remove item at iterator
    // Throw exception if invalid iter
    void erase(SNVector<T> iterator1, SNVector<T> iterator2);                   // Remove items between
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range
    void clear();                                            // Delete all vector content
    void insert(SNVector<T> iterator, T);                              // Insert item at iterator
    // Throw exception if invalid

// Iterators 		// Supports *, + and ++ operations at least
// Can use: typedef T* iterator
    // Or u can use std::iterator so you can
// apply STL algorithms on XYVector
    T* begin();	                                     // Return an iterator (T*)
    T* end();                                 	// Return an iterator (T*)

    // Comparison operations
    bool operator==(const SNVector<T>& vector);                     // Return true if ==
    bool operator< (const SNVector<T>& vector);                     // Compares item by item
    // Return true if first different item in this is < in other

// Capacity operations
    int Size();                                         // Return current size of vec
    int Capacity();                                       // Return size of current allocated array
    int resize();                                            // Relocate to bigger space
    bool empty();                                        // Return true if size is 0

    // Friends
    friend ostream& operator << <T> (ostream& out, SNVector<T> vector);
};

#endif //SNVECTOR_SNVECTOR_H