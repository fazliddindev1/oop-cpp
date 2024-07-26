#include <iostream>
#include <string>
using namespace std;

class Owner {
private:
    int ownerId;
    string ownerName;

public:
    // Constructors
    Owner(int id, const string &name) {
        ownerId = id;
        ownerName = name;
    }

    // Getter functions
    int getOwnerId() const {
        return ownerId;
    }

    string getOwnerName() {
        return ownerName;
    }

    // Setter functions
    void setOwnerId(int id) {
        ownerId = id;
    }

    void setOwnerName(const string &name) {
        ownerName = name;
    }
};

class Property {
private:
    int propertyId;
    string propertyName;
    string propertyType;
    double propertyValue;
    Owner *propertyOwner;
    static int totalProperties;

public:
    // Constructors
    Property(int id, const string &name, const string &type, double value, Owner *owner) {
        propertyId = id;
        propertyName = name;
        propertyType = type;
        propertyValue = value;
        propertyOwner = owner;
        ++totalProperties;
    }

    // Distractors
    ~Property() {
        delete propertyOwner;
        --totalProperties;
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

    Owner* getPropertyOwner() const {
        return propertyOwner;
    }

    // Setter functions
    void setPropertyId(int id) {
        propertyId = id;
    }

    void setPropertyName(string &name) {
        propertyName = name;
    }

    void setPropertyType(string &type) {
        propertyType = type;
    }

    void setPropertyValue(double &value) {
        propertyValue = value;
    }

    void setPropertyOwner(Owner *owner) {
        propertyOwner = owner;
    }
    static int getTotalProperties() {
        return totalProperties;
    }
};

int Property::totalProperties = 0;

int main() {
    Owner* owner1 = new Owner(1, "Fazliddin");

    Property property1(1, "Toshkent", "Turar joy", 50000, owner1);

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;

    cout << "|----------PROPERTY INFORMATION----------|" << endl;
    cout << "Property ID: " << property1.getPropertyId() << endl;
    cout << "Property Name: " << property1.getPropertyName() << endl;
    cout << "Property Type: " << property1.getPropertyType() << endl;
    cout << "Property Value: $" << property1.getPropertyValue() << endl;

    cout << "|----------OWNER INFORMATION----------|" << endl;
    cout << "Owner ID: " << property1.getPropertyOwner()->getOwnerId() << endl;
    cout << "Owner Name: " << property1.getPropertyOwner()->getOwnerName() << endl;

    cout << "|----------TOTAL PROPERTIES----------|" << endl;
    cout << "Total Properties: " << Property::getTotalProperties() << endl;

    return 0;
}
