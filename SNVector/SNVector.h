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

    typedef T* iterator;
    typedef T* iterator1;
    typedef T* iterator2;

public:
    SNVector(int num = 2);		        	            
    SNVector(T* arr, int  n);	                
    SNVector(const SNVector& vector);             	
    ~SNVector();			                    
    SNVector& operator=(const SNVector& vector);           
    SNVector& operator=(SNVector&& vector)noexcept;          

    T& operator[](int);                          
    
    int push_back(T);                               
    T pop_back();                                        
    void erase(iterator);                               
    void erase(iterator1, iterator2);                  
    void clear();                                            
    void insert(iterator, T item);                             

    iterator begin();
    iterator end();                                 	

    bool operator==(const SNVector<T>& vector);                     
    bool operator< (const SNVector<T>& vector);                     
    
    int Size();                                       
    int Capacity();                                       
    int resize();                                            
    bool empty();                                        


    friend ostream& operator << <T> (ostream& out, SNVector<T> vector);
};


#endif //SNVECTOR_SNVECTOR_H
