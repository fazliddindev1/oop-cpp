#include <iostream>
#include <string>
using namespace std;

class Property {
private:
    int propertyId;
    string propertyName;
    string propertyType;
    double propertyValue;
    string propertyAddress;
    int NumberOfBedrooms;

public:
    // Constructor
    Property(int id, const string &name, const string &type, double value, const string &address, int bedrooms) {
        propertyId = id;
        propertyName = name;
        propertyType = type;
        propertyValue = value;
        propertyAddress = address;
        NumberOfBedrooms = bedrooms;
    }

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
    string getPropertyAddress() const {
        return propertyAddress;
    }
    int getNumberOfBedrooms() const {
        return NumberOfBedrooms;
    }

    // Setter functions
    void setPropertyId(int id) {
        propertyId = id;
    }
    void setPropertyName(const string &name) {
        propertyName = name;
    }
    void setPropertyType(const string &type) {
        propertyType = type;
    }
    void setPropertyValue(double value) {
        propertyValue = value;
    }
    void setPropertyAddress(const string &address) {
        propertyAddress = address;
    }
    void setNumberOfBedrooms(int bedrooms) {
        NumberOfBedrooms = bedrooms;
    }

    // Other functions
    double calculatePropertyTax() const {
        const double taxRate = 0.10;
        return propertyValue * taxRate;
    }
};

int main() {
    Property property1(1, "Tashkent", "Turar joy", 80000, "4a-22", 4);

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << "Property Id: " << property1.getPropertyId() << endl;
    cout << "Property Name: " << property1.getPropertyName() << endl;
    cout << "Property Type: " << property1.getPropertyType() << endl;
    cout << "Property Value: $" << property1.getPropertyValue() << endl;
    cout << "Property Address: " << property1.getPropertyAddress() << endl;
    cout << "Property Bedrooms: " << property1.getNumberOfBedrooms() << endl;

    return 0;
}
