#include <iostream>
#include <string>
using namespace std;

class Property {
private:
    int propertyId;
    string propertyName;
    string propertyType;
    double propertyValue;

public:
    // Getter functions
    int getPropertyId() const {
        return propertyId;
    }
    string getPropertyName() const {
        return propertyName;
    }
    string getPropertyType() const {
        return propertyType;
    }
    double getPropertyValue() const {
        return propertyValue;
    }

    // Setter functions
    void setPropertyId(const int &id) {
        if (id > 0)
            propertyId = id;
    }
    void setPropertyName(const string &name) {
        propertyName = name;
    }
    void setPropertyType(const string &type) {
        propertyType = type;
    }
    void setPropertyValue(const double &value) {
        if (value > 0)
            propertyValue = value;
    }
};

int main() {
    Property property1;

    property1.setPropertyId(1);
    property1.setPropertyName("Toshkent");
    property1.setPropertyType("Turar joy");
    property1.setPropertyValue(50000);

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << "Property ID: " << property1.getPropertyId() << endl;
    cout << "Property Name: " << property1.getPropertyName() << endl;
    cout << "Property Type: " << property1.getPropertyType() << endl;
    cout << "Property Value: $" << property1.getPropertyValue() << endl;

    return 0;
}
