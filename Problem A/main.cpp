#include<iostream>
#include<iomanip>
using namespace std;
class StudentLinkedList
{
private:
    struct Course
    {
        string CourseName;
        int total;
        char Grade;
        float point;
        Course* cnext;
        Course* cprev;
    };
    struct Node
    {
        string  Name;
        string Department;
        int Number_Of_Registered_Course;
        Course CourseName;
        Node* next;
        Node* prev;
    };

    Node* First;
    Node* Last;
    Node*Current;
    int length;

    Course* CFirst;
    Course* CLast;
    int Clength;

public:
    StudentLinkedList()
    {
        First = NULL;
        Last = NULL;
        length = 0;
        CFirst=NULL;
        CLast=NULL;
        Clength=0;
    }
    bool IsEmpty()
    {
        return (First == NULL);
    }
    ~StudentLinkedList()
    {
        Node *temp;
        while (First != NULL)
        {
            temp = First;
            First = First->next;
            delete temp;
        }
        Last = NULL;
        length = 0;
    }

    void AddStudent(string name,string department,int number_of_registered_courses)
    {
        Node* NewNode = new Node;
        NewNode->Name=name;
        NewNode->Department=department;
        NewNode->Number_Of_Registered_Course=number_of_registered_courses;
        if (length == 0)
        {
            First = Last = NewNode;
            NewNode->next = NewNode->prev = NULL;
        }
        else
        {
            NewNode->next = NULL;
            NewNode->prev = Last;
            Last->next = NewNode;
            Last = NewNode;
        }
        length++;
    }
    void AddCourses(string SubjectName,int  total,char grade,float point)
    {
        Course*NewCourse =new Course;
        NewCourse->CourseName=SubjectName;
        NewCourse->total=total;
        NewCourse->Grade=grade;
        NewCourse->point=point;
        if(Clength==0)
        {
            CFirst = CLast = NewCourse;
            NewCourse->cnext = NewCourse->cprev = NULL;
        }
        else
        {
            NewCourse->cnext = NULL;
            NewCourse->cnext = CLast;
            CLast->cnext = NewCourse;
            CLast = NewCourse;
        }
        Clength++;

    }
    void Print()
    {
        if (IsEmpty())
        {
            cout << "The List is Empty";
        }
        else
        {
            Node* temp = First;
            Course* Ctemp=CFirst;
            while (temp != NULL)
            {
                cout << temp->Name << setw(6)<<temp->Department<<setw(6);
                cout<<temp->Number_Of_Registered_Course<<endl;
                if(Clength==0)
                    cout<<"There is no courses for this student !"<<endl;
                else
                {
                    for(int i = 0 ; i < temp->Number_Of_Registered_Course; i++)
                    {
                        cout<< Ctemp->CourseName<<setw(6)<< Ctemp->total<<setw(6);
                        cout<<Ctemp->Grade<<setw(6)<<Ctemp->point<<endl;
                        Ctemp=Ctemp->cnext;
                    }
                    cout<<"==================================="<<endl;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};
int main()
{
    StudentLinkedList test;
    test.AddStudent("Tarek","BIO",3);
    test.AddCourses("DS",88,'A',3.7);
    test.AddCourses("BIO",70,'B',3.3);
    test.AddCourses("MaT",72,'c',2.2);
    test.AddStudent("Mohamad","cs",2);
    test.AddCourses("MB",80,'B',3.4);
    test.AddCourses("BIO",75,'c',2.5);
    test.AddStudent("Ahmed","IT",1);
    test.AddCourses("BIO",100,'A',4.0);
    test.AddStudent("Ali","DS",3);
    test.AddCourses("cs",95,'A',3.8);
    test.AddCourses("DS",80,'B',3.4);
    test.AddCourses("it",70,'c',2.5);


    test.Print();
    return 0;
}
