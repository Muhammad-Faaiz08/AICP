/*
#include<iostream>
using namespace std;
class Circle
{
public:
    double radius;
public:
    Circle(){}
    Circle(double r):radius(r){}
    void setradius(double r)
    {
        radius=r;
    }
    double getradius()
    {
        return radius;
    }
    Circle operator+(const Circle& c)
    {
        Circle temp;
        temp.radius=this->radius+c.radius;
        return temp;
    }
};
int main()
{
   Circle c1(9),c2(9),c3;
   system("cls");
   c3=c1+c2;
   cout<<" Radius of third Circle : "<<c3.getradius();
}
*/

#include<iostream>
using namespace std;
class Complex
{
private:
    double real;
    double imaginary;
public:
    Complex():real(0),imaginary(0){}
    friend istream& operator>>(istream& in,Complex& c)
    {
        cout<<"Enter real part: ";
        in>>c.real;
        cout<<"Enter imaginary part: ";
        in>>c.imaginary;
        return in;
    }
    friend ostream& operator<<(ostream& out,const Complex& c)
    {
        out<<c.real<< " + "<<c.imaginary<<"i";
        return out;
    }
};
int main()
{
    Complex com1;
    cin>>com1;
    cout<<"The complex number is: "<<com1<<endl;
    return 0;
}

