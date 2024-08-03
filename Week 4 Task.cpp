
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Patient
{
public:
    int age;
    Patient(int a):age(a){}
};
class PatientComparator
{
public:
   public:
    int getPriority(int age)
    {
        if(age>=60)
        {
            return 1;
        }
        if(age>50)
        {
           return 2;
        }
        if(age>40)
        {
            return 3;
        }
        if(age>30)
        {
            return 4;
        }
        return 5;
    }
    bool operator()(Patient& p1,Patient& p2)
    {
        return getPriority(p1.age)>getPriority(p2.age);
    }
};
class Hospital
{
private:
    priority_queue<Patient,vector<Patient>,PatientComparator>pq;

public:
    void addPatient(int age)
    {
        pq.push(Patient(age));
    }
    void deletePatient()
    {
        if(pq.empty())
        {
            cout<<"\t\t\tNo patients to delete."<<endl;
            return;
        }
        Patient topPatient=pq.top();
        pq.pop();
        cout<<"Patient with age "<<topPatient.age<<" deleted."<<endl;
    }
    void displayPatients()
    {
        if(pq.empty())
        {
            cout<<"\t\t\tNo patients in the queue."<<endl;
            return;
        }
        priority_queue<Patient,vector<Patient>,PatientComparator>temp=pq;
        cout<<"Queue is:"<<endl;
        while(!temp.empty())
        {
            Patient topPatient=temp.top();
            temp.pop();
            cout<<topPatient.age<<endl;
        }
    }
};
void TOP()
{
  cout<<"Welcome to Patient Information System"<<endl;
  cout<<"Enter your choice of the activity"<<endl;
}
void displayed()
{
  cout<<"1. Insert"<<endl;
  cout<<"2. Delete"<<endl;
  cout<<"3. Display"<<endl;
  cout<<"4. Exit"<<endl;
  cout<<"Enter your choice: ";
}
int main()
{
    Hospital hospital;
    int choice, age;
     TOP();
    while (true)
        {
        displayed();
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the age value to be added in the queue : ";
                cin>>age;
                hospital.addPatient(age);
                break;
            case 2:
                hospital.deletePatient();
                break;
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}
