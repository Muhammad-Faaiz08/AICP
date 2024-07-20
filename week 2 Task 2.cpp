#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
   string name,gender,address,phone;
   int age;
public:
    Person(string n,int a,string g,string ads,string ph):name(n),age(a),gender(g),address(ads),phone(ph){}
    void setname(string n)
    {
        name=n;
    }
    void setage(int a)
    {
        age=a;
    }
    void setgender(string g)
    {
        gender=g;
    }
    void setaddress(string ads)
    {
        address=ads;
    }
    void setphone(string ph)
    {
        phone=ph;
    }
    string getname()
    {
       return name;
    }
    int getage()
    {
       return age;
    }
    string getgender()
    {
       return gender;
    }
    string getaddress()
    {
       return address;
    }
    string getphone()
    {
       return phone;
    }
    virtual void display()
    {
        cout<<" Name: "<<name<<endl;
        cout<<" Gender: "<<gender<<endl;
        cout<<" Age: "<<age<<endl;
        cout<<" Address: "<<address<<endl;
        cout<<" Phone Number: "<<phone<<endl;
    }
};
class Teacher:public Person
{
private:
    string qualification;
    double salary;
public:
    Teacher(string n,int a,string g,string ads,string ph,string q,double s):Person(n,a,g,ads,ph),qualification(q),salary(s){}
    void setqualification(string q)
    {
       qualification=q;
    }
    void setsalary(double s)
    {
        salary=s;
    }
    string getqualification()
    {
       return qualification;
    }
    double getsalary()
    {
        return salary;
    }
    void display()
    {
        cout<<"Teacher's Name: "<<getname()<<endl;
        cout<<"Teacher's Gender: "<<getgender()<<endl;
        cout<<"Teacher's Age: "<<getage()<<endl;
        cout<<"Teacher's Address: "<<getaddress()<<endl;
        cout<<"Teacher's Phone Number: "<<getphone()<<endl;
        cout<<"Teacher's Qualification: "<<qualification<<endl;
        cout<<"Teacher's Salary: "<<salary<<endl;
    }
};
class Student:public Person
{
private:
    string education;
    int obtained_marks,total_marks;
public:
    Student(string n,int a,string g,string ads,string ph,string edu,int obtm,int tm):Person(n,a,g,ads,ph),education(edu),obtained_marks(obtm),total_marks(tm){}
    void seteducation(string edu)
    {
       education=edu;
    }
    void setobtained_marks(int obtm)
    {
      obtained_marks=obtm;
    }
    void settotal_marks(int tm)
    {
      total_marks=tm;
    }
    string geteducation()
    {
        return education;
    }
    int getobtained_marks()
    {
        return obtained_marks;
    }
    int gettotal_marks()
    {
        return total_marks;
    }
    void display()
    {
        cout<<"Student's Name: "<<getname()<<endl;
        cout<<"Student's Gender: "<<getgender()<<endl;
        cout<<"Student's Age: "<<getage()<<endl;
        cout<<"Student's Address: "<<getaddress()<<endl;
        cout<<"Student's Phone Number: "<<getphone()<<endl;
        cout<<"Student's Education: "<<education<<endl;
        cout<<"Student's Obtained Marks: "<<obtained_marks<<endl;
        cout<<"Student's Total Marks: "<<total_marks<<endl;
    }
};
void strtup()
{
    cout<<endl;
    cout<<"Enter following Data for Teacher: "<<endl;
    cout<<endl;
}
void strtupp()
{
    cout<<endl;
    cout<<"Enter following Data for Student: "<<endl;
    cout<<endl;
}
void out()
{
    cout<<"Displaying Patient's information: "<<endl;
    cout<<"--------------------------------"<<endl;
}
int main()
{
    string t_n,t_g,t_ads,t_ph,t_q,s_n,s_g,s_ads,s_ph,s_e;
    int t_a,s_a,s_obtm,s_tm;
    double t_s;
    char ch,z;
    cout<<endl;
    cout<<"Enter Choice: T for Teacher, S for Student: "<<endl;
    cin>>ch;
    if(ch=='T' || ch=='t')
        {
       strtup();
       cin.ignore();
       cout<<"Enter Name: ";
       getline(cin,t_n);
       cout<<endl;
       cout<<"Enter Gender: ";
       cin>>t_g;
       cout<<endl;
       cout<<"Enter Age: ";
       cin>>t_a;
       cout<<endl;
       cin.ignore();
       cout<<"Enter Address: ";
       getline(cin,t_ads);
       cout<<endl;
       cout<<"Enter Phone Number: ";
       cin>>t_ph;
       cout<<endl;
       cout<<"Enter Qualification: ";
       cin>>t_q;
       cout<<endl;
       cout<<"Enter Salary: ";
       cin>>t_s;
       Teacher t(t_n,t_a,t_g,t_ads,t_ph,t_q,t_s);
       cout<<"Do you want to enter more data <Y for Yes, N for No>: ";
       cin>>z;
       cout<<endl;
       if(z=='Y')
       {
          out();
          t.display();
       }
       else
       {
           cout<<endl;
           cout<<" Data Saved Successfully!! "<<endl;
           cout<<endl;
       }
        }
    else if(ch=='S' || ch=='s')
        {
       strtupp();
       cin.ignore();
       cout<<"Enter Name: ";
       getline(cin,s_n);
       cout<<endl;
       cout<<"Enter Gender: ";
       cin>>s_g;
       cout<<endl;
       cout<<"Enter Age: ";
       cin>>s_a;
       cout<<endl;
       cin.ignore();
       cout<<"Enter Address: ";
       getline(cin,s_ads);
       cout<<endl;
       cout<<"Enter Phone Number: ";
       cin>>s_ph;
       cout<<endl;
       cout<<"Enter Education: ";
       cin>>s_e;
       cout<<endl;
       cout<<"Enter Obtained Marks: ";
       cin>>s_obtm;
       cout<<endl;
       cout<<"Enter Total Marks: ";
       cin>>s_tm;
       Student s(s_n,s_a,s_g,s_ads,s_ph,s_e,s_obtm,s_tm);
       cout<<"Do you want to enter more data <Y for Yes, N for No>: ";
       cin>>z;
       if(z=='Y')
       {
          out();
          s.display();
       }
       else
       {
           cout<<endl;
           cout<<" Data Saved Successfully!! "<<endl;
           cout<<endl;
       }
        }
    else
        {
            cout<<"\t\t\t\t |-- Wrong Input ~ Try Again --|"<<endl;
        }
    return 0;
}
