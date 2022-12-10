#include "SNVector.h"
#include "SNVector.cpp"

int main()
{
    SNVector<int> v1(3);
    int arr[3] = { 1, 3 ,5 };
    SNVector<int> v2;
    //SNVector<int> v3(v2);
    v2 = move(v1);
    
}