#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    double salary;

public:
    // Constructor
    Person(string name, int age, double salary) : name(name), age(age), salary(salary) {}

    // Getter functions
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    double getSalary() const {
        return salary;
    }

    // Overloading equality operator (==)
    bool operator==(const Person& other) const {
        return this->name == other.name;
    }

    // Overloading addition operator (+)
    Person operator+(const Person& other) const {
        return Person(this->name, this->age, this->salary + other.salary);
    }

    // Overloading subtraction operator (-)
    Person operator-(const Person& other) const {
        return Person(this->name, this->age, this->salary - other.salary);
    }

    // Overloading stream insertion operator (<<)
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Person name: " << person.name << "\n"
           << "Person age: " << person.age << "\n"
           << "Person salary: " << person.salary;
        return os;
    }

    // Display function
    void display() const {
        cout << "Person name: " << name << endl;
        cout << "Person age: " << age << endl;
        cout << "Person salary: " << salary << endl;
    }
};

int main() {
    Person person1("Fazliddin", 19, 500);
    Person person2("John", 20, 550);

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << endl;
    if (person1 == person2) {
        cout << "The people have the same name." << endl;
    } else {
        cout << "The people have different names." << endl;
    }
    cout << endl;
    Person person3 = person1 + person2;
    cout << "After combining properties:\n" << person3 << endl;
    cout << endl;
    Person person4 = person1 - person2;
    cout << "After subtracting properties:\n" << person4 << endl;

    return 0;
}
