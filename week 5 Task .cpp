#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Student
{
public:
    string name;
    int marks;
    Student* next;
    Student(string name,int marks):name(name),marks(marks),next(nullptr){}
};
class Stack
{
private:
    Student* top;
public:
    Stack():top(nullptr) {}
    void push(string name,int marks)
    {
        Student* newStudent=new Student(name,marks);
        newStudent->next=top;
        top=newStudent;
    }
    void pop()
    {
        if(top==nullptr)
        {
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Student* temp=top;
        top=top->next;
        delete temp;
    }
    void display()
    {
        if(top==nullptr)
        {
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Student* current=top;
        while(current!=nullptr)
        {
            cout<<"Name: "<<current->name<<", Marks: "<<current->marks<<endl;
            current=current->next;
        }
    }
    void displayTop3()
    {
        vector<Student*>students;
        Student* current = top;
        while (current != nullptr)
        {
            students.push_back(current);
            current=current->next;
        }
        sort(students.begin(), students.end(), [](Student* a, Student* b)
        {
            return a->marks>b->marks;
        });
        cout<<"Top 3 students:"<<endl;
        int count=0;
        for(Student* student:students)
        {
            if(count>=3)break;
            cout<<"Name: "<<student->name<<", Marks: "<<student->marks<<endl;
            count++;
        }
    }
};
int main()
{
    Stack studentStack;
    Stack topStudentStack;
    int choice;
    string name;
    int marks;
    do
        {
        cout<<endl;
        cout<<"\t\t\t\t |-- Student Portal --|"<<endl;
        cout<<endl;
        cout<<"1. Add a student"<<endl;
        cout<<"2. Remove a student"<<endl;
        cout<<"3. Display all students"<<endl;
        cout<<"4. Display top 3 students"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();
        cout<<endl;
        switch (choice)
        {
            case 1:
                cout<<"Enter student name: ";
                getline(cin, name);
                cout<<"Enter student marks: ";
                cin>>marks;
                studentStack.push(name, marks);
                cout<<endl;
                break;
            case 2:
                studentStack.pop();
                cout<<" Removed the last entry that you have entered "<<endl;
                break;
            case 3:
                studentStack.display();
                break;
            case 4:
                studentStack.displayTop3();
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
                break;
        }
    }
    while(choice!=5);
    return 0;
}
