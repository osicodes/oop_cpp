#include <iostream>
using namespace std;

int update(int x)
{
    return x = 10;
}
void  updateP(int* x)
{
    *x = 25;
}

int main()
{
    int a = 5;
    int* p = &a;
    updateP(p);
    cout<< "a is : "<<a<<endl;

    return 0;
}