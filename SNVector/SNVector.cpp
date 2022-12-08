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
        delete[] vec;
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
//template <class T>
//SNVector<T>& SNVector<T>::operator=(const SNVector&& vector)