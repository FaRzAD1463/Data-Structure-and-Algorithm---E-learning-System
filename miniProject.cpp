#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////// Queue Implementation (Mervinraj)
class QueueNode
{
public:
    string assignment, dueDate;
    QueueNode *next;
};

class Queue
{
private:
    QueueNode *front, *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    bool isEmpty()
    {
        return front == NULL && back == NULL;
    }

    void enQueue(string a, string d)
    {
        QueueNode *newNode = new QueueNode;
        newNode->assignment = a;
        newNode->dueDate = d;
        if (isEmpty())
        {
            newNode->next = NULL;
            front = newNode;
            back = newNode;
        }
        else
        {
            newNode->next = NULL;
            back->next = newNode;
            back = newNode;
        }
    }

    void deQueue()
    {

        QueueNode *temp = new QueueNode;

        temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    void printQueue()
    {
        QueueNode *temp = front;
        int i = 1;

        cout << "Here are your assignments with thier due dates, remember...\n you need to solve them based on first come first serve." << endl
             << endl;

        while (temp->next != NULL)
        {
            cout << i << ".  " << temp->assignment << " (" << temp->dueDate << ")" << endl;
            i++;
            temp = temp->next;
        }
        cout << i << ".  " << temp->assignment << " (" << temp->dueDate << ")" << endl;
    }
};
// end of Mervin's part

////////////////////////////////////////// Linked list implementation (Farzad Khan Chowdhury)
class ListNode
{
public:
    string code, name;
    ListNode *next, *prev;
};

class List
{
private:
    ListNode *head, *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL && tail == NULL;
    }

    void insertBack(string c, string n)
    {
        ListNode *newNode = new ListNode;
        if (isEmpty())
        {
            newNode->code = c;
            newNode->name = n;
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->code = c;
            newNode->name = n;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printForward()
    {
        ListNode *temp = head;

        int i = 1;

        cout << "Here are your list of courses" << endl
             << endl;

        while (temp->next != NULL)
        {
            cout << i << ".  " << temp->code << " (" << temp->name << ")" << endl;
            i++;
            temp = temp->next;
        }
        cout << i << ".  " << temp->code << " (" << temp->name << ")" << endl;
    }
    // End of Farzad's part

    //////////////////////////////////// Search implementation inside the linked list (Mashuk)
    void find(string c)
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            if (temp->code == c)
            {
                cout << "Here we found your desired course: " << temp->code << " (" << temp->name << ")" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->code == c)
        {
            cout << "Here we found your desired course: " << temp->code << " (" << temp->name << ")" << endl;
            return;
        }
        else
        {
            cout << "Sorry, we did not find your desired course" << endl;
        }
    }

    void deleteNode(int i)
    {
        int position = 1;
        ListNode *temp = head;
        while (position != i)
        {
            temp = temp->next;
            position++;
        }
        if (temp == head)
        {
            head = temp->next;
            head->prev = NULL;
            delete temp;
        }
        else if (temp == tail)
        {
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
        }
        else
        {

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }
    // End of Mashuk's part
};

//////////////////////////////////// Stack implementation (Mervinraj)
class StackNode
{
public:
    string materialName;
    StackNode *next;
};

class Stack
{
private:
    StackNode *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(string materialN)
    {
        StackNode *newNode = new StackNode;
        newNode->materialName = materialN;
        newNode->next = top;
        top = newNode;
    }

    string stackTop()
    {
        return top->materialName;
    }

    void pop()
    {
        StackNode *deletedNode = top;
        if (isEmpty())
        {
            cout << "Sorry you there is to materials to delete." << endl;
        }
        else
        {
            cout << "Material that is deleted is: " << stackTop() << endl;
            top = top->next;
            deletedNode->next = NULL;
            delete deletedNode;
        }
    }

    void printStack()
    {

        StackNode *temp = top;

        int i = 1;

        cout << "Here are the latest materials posted by your lecturer" << endl
             << endl;

        while (temp->next != NULL)
        {
            cout << i << ".  " << temp->materialName << endl;
            i++;
            temp = temp->next;
        }
        cout << i << ".  " << temp->materialName << endl;
    }
};
// End of Mervin's part

void printLine()
{
    cout << "__________________________________________" << endl;
    cout << endl;
}

///////////////////////////////////////Main function (Rasheed)
int main()
{
    int choice1, choice2, choice3, choice4;
    string uName, pass;
    //////////////////////////////dashboard's initial state;
    Queue dashBoard;
    dashBoard.enQueue("DSA assignment 1", "18 Jan 2023");
    dashBoard.enQueue("DSA assignment 2", "20 Jan 2023");
    dashBoard.enQueue("DSA assignment 3", "22 Jan 2023");

    ////////////////////////////// My courses initial state
    List myCourses;
    myCourses.insertBack("SECD2535", "Database");
    myCourses.insertBack("SECD2613", "System Analysis and Design");
    myCourses.insertBack("SECD3761", "Technopreneurship");
    cout << "hello world" << endl;
    //////////////////////////// Database course materials initail state
    Stack courseMaterials;
    courseMaterials.push("Chapter 1 Intro to database");
    courseMaterials.push("Chapter 2 Relational data model");
    courseMaterials.push("Chapter 3 Database design");
    //////////////////////////// end of initial declarations

    printLine();
    cout << "Welcome to UTM Elearning" << endl;
    printLine();

    cout << "\n Please enter your Username and Password" << endl
         << endl;
    cout << "Username: ";
    cin >> uName;

    cout << "Password: ";
    cin >> pass;
    printLine();

Menu:
    choice1 = 0;
    choice2 = 0;
    choice3 = 0;
    choice4 = 0;

    while (choice1 != 3)
    {
        cout << endl
             << "Please choose one of the processes below\n"
             << endl;
        cout << "1.  Show Assignments Dashboard tab" << endl;
        cout << "2.  Show My Courses tab" << endl;
        cout << "3.  exit program"
             << endl;
        cout << "Choice: ";
        cin >> choice1;

        if (choice1 == 1)
        {
            while (choice2 != 4)
            {
                choice2 = 0;
                cout << endl
                     << "Please choose one of the processes below\n"
                     << endl;
                cout << "1.  View my assignments" << endl;
                cout << "2.  Mark as done (this will delete the assignment with the nearest due date)" << endl;
                cout << "3.  Add new Assignment (This feature is only allowed for lecturers)\n";
                cout << "4.  Come back to main menu\n"
                     << endl;
                cout << "Choice: ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    dashBoard.printQueue();
                }
                else if (choice2 == 2)
                {
                    dashBoard.deQueue();
                    cout << "Your assignment with the nearest due date is marked as done,\nyou may view your assignments to check" << endl
                         << endl;
                }
                else if (choice2 == 3)
                {
                    string newA, newD; // new assignment and new deadline
                    cout << "New assignment's name: ";
                    cin >> newA;
                    cout << "New assignment's deadline: ";
                    cin >> newD;
                    dashBoard.enQueue(newA, newD);
                    cout << "\n As a lecturer please update the students that they have a new assignment. Thank you!\n\n";
                }
                else if (choice2 == 4)
                {
                    goto Menu;
                }
                else
                {
                    cout << "Invalid input, please try again" << endl;
                }
            }
        }
        else if (choice1 == 2)
        {
            while (choice3 != 4)
            {
                choice3 = 0;
                cout << endl
                     << "In this section, you can choose one of the processes below\n"
                     << endl;
                cout << "1.  Display all my courses" << endl;
                cout << "2.  Delete an existing course(This feature is only allowed for lecturers)\n";
                cout << "3.  Add a new course (This feature is only allowed for lecturers)" << endl;
                cout << "4.  Search for course name using its code " << endl;
                cout << "5.  Come back to main menu\n"
                     << endl;
                cout << "Choice: ";
                cin >> choice3;
                if (choice3 == 1)
                {
                    myCourses.printForward();
                    choice4 = 0;
                    while (choice4 != 6)
                    {
                        cout << "\nYou can enter the number of any subject to view its content based on latest material uploaded." << endl;
                        cout << "Or insert 6 to come back to the previous page." << endl;
                        cout << "If you are a lecturer press 4 to insert material or 5 to delete material." << endl;
                        cin >> choice4;
                        if ((choice4 == 1) || (choice4 == 2) || (choice4 == 3))
                        {
                            courseMaterials.printStack();
                        }
                        else if (choice4 == 4)
                        {
                            string newMaterial;
                            cout << "Enter the name of the new material: ";
                            cin >> newMaterial;
                            courseMaterials.push(newMaterial);
                            cout << "New mateial is uploaded successfully" << endl;
                        }
                        else if (choice4 == 5)
                        {
                            courseMaterials.pop();
                            cout << "the latest material is deleted successfully" << endl;
                        }
                        else
                        {
                            cout << "Invalid input please try again." << endl;
                        }
                    }
                }
                else if (choice3 == 2)
                {
                    int courseNum; // the number of course that needs to be deleted
                    cout << "Please insert the number of the course that you want to delete: ";
                    cin >> courseNum;
                    myCourses.deleteNode(courseNum);
                    cout << "The course is successfully deleted.\nThe student may check the updated list of courses." << endl
                         << endl;
                }
                else if (choice3 == 3)
                {
                    string newC, newN; // course code and course Name
                    cout << "New course's code: ";
                    cin >> newC;
                    cout << "New courses's name: ";
                    cin >> newN;
                    myCourses.insertBack(newC, newN);
                    cout << "\n The new course is added successfully.\nThe student may check the updated list of courses.\n\n";
                }
                else if (choice3 == 4)
                {
                    string desiredCode;
                    cout << "Please key in the course code you want to search for: ";
                    cin >> desiredCode;
                    myCourses.find(desiredCode);
                    choice1 = 0;
                    choice2 = 0;
                    choice3 = 0;
                }
                else if (choice3 == 5)
                {
                    goto Menu;
                }
                else
                {
                    cout << "Invalid input, please try again" << endl;
                }
            }
        }
    }

    return 0;
}
