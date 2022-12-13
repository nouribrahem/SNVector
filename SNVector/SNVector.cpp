#include "SNVector.h"

template <class T>
SNVector<T>::SNVector(int num)
{
    capacity = 2;
    while (capacity < num)
    {
        capacity *= 2;
    }
    vec = new T[capacity];
    size = num;
    for (int i = 0; i < size; i++)
    {
        vec[i] = 0;
    }
}
template <class T>
SNVector<T>::~SNVector()
{
    delete[] vec;
}
template <class T>
SNVector<T>::SNVector(T* arr, int n)
{
    capacity = 2;
    while (capacity < n)
    {
        capacity *= 2;
    }
    vec = new T[capacity];
    size = n;
    for (int i = 0; i < size; i++)
    {
        vec[i] = arr[i];
    }
}
template <class T>
SNVector<T>::SNVector(const SNVector& vector)
{
    size = vector.size;
    capacity = 2;
    while (capacity < size)
    {
        capacity *= 2;
    }
    vec = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        vec[i] = vector.vec[i];
    }
}
template <class T>
SNVector<T>& SNVector<T>::operator=(const SNVector& vector)
{
    if (this != &vector)
    {
        
        size = vector.size;
        capacity = 2;
        while (capacity < size)
        {
            capacity *= 2;
        }
        vec = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            vec[i] = vector.vec[i];
        }
    }
    return *this;
}
template <class T>
SNVector<T>& SNVector<T>::operator=(SNVector&& vector) noexcept
{
    if (this != &vector)
    {
        size = vector.size;
        vector.size = 0;
        capacity = 2;
        while (capacity < size)
        {
            capacity *= 2;
        }
        vector.capacity = 0;
        vec = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            vec[i] = vector.vec[i];
        }
        vector.vec = nullptr;
        
    }
    return *this;
}
template <class T>
int SNVector<T>::Size()
{
    return size;
}
template <class T>
int SNVector<T>::Capacity()
{
    return capacity;
}
template <class T>
ostream& operator << (ostream& out, SNVector<T> vector)
{
    for (int i = 0; i < vector.size; i++)
    {
        out << vector.vec[i] << endl;   
    }
    return out;
}
template <class T>
T& SNVector<T>::operator[](int index)
{
    return vec[index];
}
template <class T>
int SNVector<T>::push_back(T item)
{
    if (capacity == 0)
    {
        capacity = 2;
        vec = new T[capacity];
    }
   if(capacity == size)
    {
        SNVector<T> temp(*this);
        size++;
        while (capacity < size)
        {
            capacity *= 2;
        }
        vec = new T[capacity];
        for(int i = 0 ; i < size-1 ; i++)
        {
            vec[i] = temp[i];
        }
        vec[size - 1] = item;
    }
   else
   {
       vec[size] = item;
       size++;
   }
    return size;
}
template <class T>
T SNVector<T>::pop_back()
{
    SNVector<T> temp(*this);
    size--;
    for(int i = 0 ; i < size-1 ; i++)
    {
        vec[i] = temp[i];
    }
    return vec[size - 1];
}
template <class T>
void SNVector<T>::erase(int iterator)
{
    SNVector<T> temp(size - 1);
    for(int i = 0 , j = 0; i < size ; i++ )
    {
        if(i != iterator)
        {
            temp[j] = vec[i];
            j++;
        }
    }
    *this = temp;
}
template <class T>
void SNVector<T>::erase(int iterator1, int iterator2)
{
    SNVector<T> temp(size - iterator2 + iterator1);
    for(int i = 0 , j = 0; i < size ; i++ )
    {
        if(i < iterator1 || i >= iterator2)
        {
            temp[j] = vec[i];
            j++;
        }
    }
    *this = temp;
}
template <class T>
void SNVector<T>::clear()
{
    size = 0;
    capacity = 0;
    vec = nullptr;
}
template <class T>
void SNVector<T>::insert(int iterator, T item)
{
    if (iterator == size)
    {
        this->push_back(item);
    }
    else
    {
        SNVector<T> temp(*this);
        if (capacity == size)
        {
            capacity *= 2;
            vec = new T[capacity];
        }

        size++;
        for (int i = 0, j = 0; i < size; i++, j++)
        {
            if (i == iterator)
            {
                vec[i] = item;
                i++;
            }
            vec[i] = temp[j];
        }
    }
    
}
