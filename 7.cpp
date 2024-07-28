#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
    string Name;
    int Age;
    string Gender;
public:
    // Constructor
    Person(string name,int age,string gender){
        Name = name;
        Age = age;
        Gender = gender;
    }

    // Virtual function

    virtual void displayDetails() const {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
    }

    // Setter function

    void setName(string name){
        Name = name;
    }
    void setAge(int age){
        Age = age;
    }
    void setGender(string gender){
        Gender = gender;
    }

    // Getter function

    string getName(){
        return Name;
    }
    int getAge(){
        return Age;
    }
    string getGender(){
        return Gender;
    }
};

class Student : public Person{
private:
    int IDNumber;
    string Grade;
public:
    // Constructor
    Student(string name, int age,string gender,int idNumber,string grade)
    : Person(name, age, gender), IDNumber(idNumber), Grade(grade) {}

    void displayDetails() const override{
        Person::displayDetails();
        cout << "ID Number: " << IDNumber << endl;
        cout << "Grade: " << Grade << endl;
    }

    // Setter function

    void setIDNumber(int idNumber){
        IDNumber = idNumber;
    }
    void setGrade(string grade){
        Grade = grade;
    }
};

class Teacher : public Person{
private:
    string Subject;
public:
    // Constructor
    Teacher(string name,int age,string gender, string subject) : Person(name,age,gender){
        Subject = subject;
    }

    void displayDetails() const override{
        Person::displayDetails();
        cout << "Subject: " << Subject << endl;
    }

    // Setter function
    void setSubject(string subject){
        Subject = subject;
    }

    // Getter function
    string getSubject(){
        return Subject;
    }
};

int main(){
    Person person1("Fazliddin", 19, "Male");
    Student student1("Bekzod", 19, "Male", 2310079, "C+");
    Teacher teacher1("Sarvar", 35, "Male","IT");

    Person* p1 = &person1;
    Person* p2 = &student1;
    Person* p3 = &teacher1;

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << endl;

    cout << "--Person--" << endl;
    p1->displayDetails();
    cout << endl;

    cout << "--Student--" << endl;
    p2->displayDetails();
    cout << endl;

    cout << "--Teacher--" << endl;
    p3->displayDetails();
    cout << endl;

    return 0;
}