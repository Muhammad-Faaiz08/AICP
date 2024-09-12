#include<iostream>
using namespace std;
class Base
{
private:
    int secret;
protected:
    int protect;
public:
    int access;
    Base()
    {
        secret=1;
        protect=2;
        access=3;
    }
};
class Derived_Private:private Base
{
public:
    void show()
    {
        cout<<"Protect: "<<protect<<endl;
        cout<<"Access: "<<access<<endl;
    }
};
class Derived_Protected:protected Base
{
public:
    void show()
    {
        cout<<"Protect: "<<protect<<endl;
        cout<<"Access: "<<access<<endl;
    }
};
class Derived_Public:public Base
{
public:
    void show()
    {
        cout<<"Protect: "<<protect<<endl;
        cout<<"Access: "<<access<<endl;
    }
};
int main()
{
    Derived_Private dp;
    Derived_Protected dpr;
    Derived_Public dpu;
    cout<<"Derived_Private show:"<<endl;
    dp.show();
    cout<<"\nDerived_Protected show:"<<endl;
    dpr.show();
    cout<<"\nDerived_Public show:"<<endl;
    dpu.show();
    return 0;
}
