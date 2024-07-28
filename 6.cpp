#include <iostream>
using namespace std;

class Student{
protected:
    int ID;
    string Name;
    string School;
    string GroupNumber;
public:
    // Constructor
    Student(int id,const string &name,const string &school,const string &groupNumber){
        ID = id;
        Name = name;
        School = school;
        GroupNumber = groupNumber;
    }

    // Setter function

    void setID(int id){
        ID = id;
    }
    void setName(const string &name){
        Name = name;
    }
    void setSchool(const string &school){
        School = school;
    }
    void setGroupNumber(const string &groupNumber){
        GroupNumber = groupNumber;
    }

    // Getter function

    int getID() const{
        return ID;
    }
    string getName(){
        return Name;
    }
    string getSchool(){
        return School;
    }
    string getGroupNumber(){
        return GroupNumber;
    }
};

class Test : public Student{
protected:
    int Physics;
    int OOP;
    int English;
public:
    // Constructor
    Test(int id, const string &name, const string &school, const string &groupNumber,const int &physics, const int &oop,const int &english)
    : Student(id, name, school, groupNumber) {
        Physics = physics;
        OOP = oop;
        English = english;
    }

    // Setter function

    void setPhysics(const int &physics){
    }
    void setOOP(const int &oop){
        OOP = oop;
    }
    void setEnglish(const int &english){
        English = english;
    }

    // Getter function

    int getPhysics() const{
        return Physics;
    }
    int getOOP() const{
        return OOP;
    }
    int getEnglish() const{
        return English;
    }
};

class Result : public Test{
private:
    int Total;
    float GPI;
public:
    // Constructor
    Result(int id, const string& name, const string& school, const string& groupNumber, int physics, int oop, int english)
            : Test(id, name, school, groupNumber, physics, oop, english) {
        Total = physics + oop + english;
        GPI = Total / 3.0;
    }

    // Setter function

    void setTotal(const int &total){
        Total = total;
    }
    void setGPI(const int &gpi){
        GPI = gpi;
    }

    // Getter function

    int getTotal() const{
        return Total;
    }
    int getGPI() const{
        return GPI;
    }

    void display(){
        cout << "Id: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "School: " << School << endl;
        cout << "Group Number: " << GroupNumber << endl;
        cout << endl;
        cout << "Physics: " << Physics << endl;
        cout << "OOP: " << OOP << endl;
        cout << "English: " << English << endl;
        cout << endl;
        cout << "Total" << Total << endl;
        cout << "GPI: " << GPI << endl;
    }
};

int main(){
    Result result1(2310080, "Fazliddin", "INHA", "SOCIE", 90,86,95);

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << endl;

    result1.display();
    return 0;
}