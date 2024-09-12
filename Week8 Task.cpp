#include <iostream>
using namespace std;
class Student
{
public:
    int marks;
    string gender;
    Student(int m,string g):marks(m),gender(g){}
};
class Node
{
public:
    Student *student;
    Node *left;
    Node *right;
    Node(int marks,string gender)
    {
        student = new Student(marks,gender);
        left=right=nullptr;
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        root=nullptr;
    }
    Node* insert(Node* node, int marks,string gender)
    {
        if(node==nullptr)
        {
            return new Node(marks,gender);
        }
        if(marks<node->student->marks)
        {
            node->left=insert(node->left,marks,gender);
        }
        else
        {
            node->right=insert(node->right,marks,gender);
        }
        return node;
    }
    void insert(int marks,string gender)
    {
        root=insert(root,marks,gender);
    }
    void inOrderTraversal(Node* node)
    {
        if (node!=nullptr)
        {
            inOrderTraversal(node->left);
            cout<<"("<<node->student->marks << ",    " <<node->student->gender<<")"<< endl;
            inOrderTraversal(node->right);
        }
    }
    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }
};
int main()
{
    int x,marks[]={10, 5, 14, 3, 7, 9, 18, 15, 13, 17, 100};
    string gender[]={"Female", "Male", "Male", "Male", "Male", "Female", "Female", "Female", "Female", "Male", "Male"};
    BST maleBST;
    BST femaleBST;
    cout<<"Given Data"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Marks: ";
    for(int z=0;z<=10;z++)
    {
        if(z==10)
        {
           cout<<marks[z];
        }
        else
        {
           cout<<marks[z]<<", ";
        }
    }
    cout<<endl;
    cout<<"Gender: ";
    for(int z=0;z<=10;z++)
    {
        if(z==10)
        {
           cout<<gender[z];
        }
        else
        {
           cout<<gender[z]<<", ";
        }
    }
    cout<<endl;
    int size=sizeof(marks)/sizeof(marks[0]);
    for (int i=0;i<size;++i)
    {
        if (gender[i]=="Male")
        {
            maleBST.insert(marks[i],gender[i]);
        }
        else if (gender[i]=="Female")
        {
            femaleBST.insert(marks[i],gender[i]);
        }
    }
    do
    {
    cout<<"Enter the choice"<<endl;
    cout<<"Enter 1 to create BSTs"<<endl;
    cout<<"Enter 2 to see Male student BST"<<endl;
    cout<<"Enter 3 to see Female student BST"<<endl;
    cout<<"Enter 0 to terminate the program"<<endl;
    cin>>x;
    switch(x)
    {
  case 1:
    cout<<endl;
    cout<<"BST of male student is being created..."<<endl;
    cout<<"Done"<<endl;
    cout<<"BST of female student is being created..."<<endl;
    cout<<"Done"<<endl;
    cout<<endl;
    break;
  case 2:
    cout<<endl;
    cout<<"\nIn Order Traversal of Male Students BST"<<endl;
    maleBST.inOrderTraversal();
    cout<<endl;
    break;
  case 3:
    cout<<endl;
    cout<< "\nIn Order Traversal of Female Students BST"<<endl;
    femaleBST.inOrderTraversal();
    cout<<endl;
    break;
    }
    }
    while(x!=0);
    return 0;
}
