#include "SNVector.h"
#include "SNVector.cpp"

int main()
{
   SNVector<int> v1(3);
    int arr[7] = {1, 2 ,3 , 4,5 , 6 , 7};
    SNVector<int> v2(arr , 7);
    //SNVector<int> v3(v2);
    //v2 = move(v1);
    //cout << v2[2];
    //v2.push_back(4);
    //cout << v2.pop_back();
    //v2.erase(1);
    v2.erase(5 , 6);
    cout << v2;
}
