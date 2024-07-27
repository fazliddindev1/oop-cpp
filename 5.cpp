#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
    char accountName[50];
    int accountNumber;
    char accountType[20];
    double balanceAmount;

public:
    // Default constructor
    Account() : accountName(""), accountNumber(0), accountType(""), balanceAmount(0.0) {}

    // Parameterized constructor
    Account(const char* name, int number, const char* type, double balance) {
        strcpy(accountName, name);
        accountNumber = number;
        strcpy(accountType, type);
        balanceAmount = balance;
    }

    // Copy constructor
    Account(const Account& other) {
        strcpy(accountName, other.accountName);
        accountNumber = other.accountNumber;
        strcpy(accountType, other.accountType);
        balanceAmount = other.balanceAmount;
    }

    // Overload multiplication operator (*) to multiply balanceAmount
    Account operator*(double multiplier) const {
        Account temp = *this;
        temp.balanceAmount *= multiplier;
        return temp;
    }

    // Overload stream insertion operator (<<) for output
    friend ostream& operator<<(ostream& os, const Account& account) {
        os << "Account Name:" << account.accountName << endl;
        os << "Account Number:" << account.accountNumber << endl;
        os << "Account Type:" << account.accountType << endl;
        os << "Balance Amount: $" << account.balanceAmount << endl;
        return os;
    }

    // Overload stream extraction operator (>>) for input
    friend istream& operator>>(istream& is, Account& account) {
        cout << "Enter Account Name:";
        is >> ws; // To consume any leading whitespace
        is.getline(account.accountName, 50);
        cout << "Enter Account Number:";
        is >> account.accountNumber;
        cout << "Enter Account Type:";
        is >> ws; // To consume any leading whitespace
        is.getline(account.accountType, 20);
        cout << "Enter Balance Amount:";
        is >> account.balanceAmount;
        return is;
    }
};

class AccountArray {
private:
    Account* accounts;
    int size;

public:
    // Constructor
    AccountArray(int s) : size(s) {
        accounts = new Account[size];
    }

    // Copy constructor
    AccountArray(const AccountArray& other) {
        size = other.size;
        accounts = new Account[size];
        for (int i = 0; i < size; ++i) {
            accounts[i] = other.accounts[i];
        }
    }

    // Destructor
    ~AccountArray() {
        delete[] accounts;
    }

    // Overload subscript operator to access accounts
    Account& operator[](int index) {
        if (index >= 0 && index < size) {
            return accounts[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    // Get size of the array
    int getSize() const {
        return size;
    }
};

int main() {
    // Create an account array with 2 accounts
    AccountArray accountArray(2);

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << endl;

    // Input details for the accounts
    for (int i = 0; i < accountArray.getSize(); ++i) {
        cin >> accountArray[i];
    }

    // Output details for the accounts
    for (int i = 0; i < accountArray.getSize(); ++i) {
        cout << accountArray[i] << endl;
    }

    // Test the multiplication operator
    Account multipliedAccount = accountArray[0] * 2;
    cout << "Multiplied Account Balance: " << multipliedAccount << endl;

    return 0;
}
