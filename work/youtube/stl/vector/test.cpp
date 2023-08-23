
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v({1,2,3});
    v.push_back(4);
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
    v[4]=100;
    cout<<*(v.begin()+4);
}