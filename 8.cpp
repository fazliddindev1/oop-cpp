#include <iostream>
#include <iostream>

using namespace std;

template <typename T>
class Student {
private:
    T IDNumber;
    string Name;
    T Age;
    T Grade;
public:
    // Constructor
    Student(T idNumber,string name,T age,T grade){
        IDNumber = idNumber;
        Name = name;
        Age = age;
        Grade = grade;
    }

    // Setter function

    void setIDNumber(T idNumber){
        IDNumber = idNumber;
    }
    void setName(string name){
        Name = name;
    }
    void setAge(T age){
        Age = age;
    }
    void setGrade(T grade){
        Grade = grade;
    }

    // Getter function

    T getIDNumber(){
        return IDNumber;
    }
    string getName(){
        return Name;
    }
    T getAge(){
        return Age;
    }
    T getGrade(){
        return Grade;
    }

    void displayDetails() const {
        cout << "ID Number: " << IDNumber << endl;
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Grade: " << Grade << endl;
    }

};

int main(){
    Student<int> student1(123,"Fazliddin",19,5);
    Student<int> student2(124,"Bekzod",18,4);
    Student<float> student3(125.5,"Abror",19.4,4.9);


    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << endl;

    cout << "|-----Details-----|" << endl;

    cout << "Student 1: " << endl;
    student1.displayDetails();
    cout << endl;

    cout << "Student 2: " << endl;
    student2.displayDetails();
    cout << endl;

    cout << "Student 3: " << endl;
    student3.displayDetails();
    cout << endl;


    return 0;
}