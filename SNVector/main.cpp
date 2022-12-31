#include "SNVector.h"
#include "SNVector.cpp"

int main()
{
    SNVector<int> v1(3);
    int arr[7] = {1, 2 ,3 , 4, 5 , 6 , 7};
    SNVector<int> v2(arr , 7);
    SNVector<int> v3(v2);
    cout << "v2: " << v2 << endl;
    
    v2.pop_back();
    cout << "v2 after pop: " << v2 << endl;

    v2.push_back(4);
    cout << "v2 after push: " << v2 << endl;

    v2.erase(v2.begin());
    cout << "v2 after erase: " << v2 << endl;

    v2.erase(v2.begin()+4,v2.end());
    cout << "v2 after erase: " << v2 << endl;

    v2.clear();
    cout << "v2 after clear: " << v2 << endl;

    v2.push_back(3);
    cout << "v2 after push: " << v2 << ' ' << " size of v2: " << v2.Size() << endl;

    v3.insert(v3.end(), 44);
    v3.insert(v3.begin(), 66);
    v3.insert(v3.begin() + 3, 77);
    cout << "v3 after insert: " << v3 << ' ' << " size of v3: " << v3.Size() << endl;

    cout << "current capacity: " << v2.Capacity() << endl;
    cout << "after resize: " << v2.resize() << endl;

    cout << "v3: " << v3 << endl << "v2: " << v2 << endl;
    cout << "v2.empty(): " << v2.empty() << " / " << "v2 == v3: " << (v2 == v3) << " / " << "v2 < v3: " << (v2 < v3) << endl;
    
    
    cout << "////////////exceptions////////////////\n";

    v2[150] = 99;
    v2.erase(v2.begin(), v2.end() + 22);
    v2.erase(v2.end() + 4);
    
    return 0;
}
