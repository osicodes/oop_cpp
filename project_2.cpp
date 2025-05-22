#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Abstract base class for Payment (Abstraction)
class Payment {
protected:
    double amount;
    double originalAmount;
    
public:
    Payment(double original) : originalAmount(original), amount(0) {}
    virtual ~Payment() {}
    
    // Pure virtual function (makes this class abstract)
    virtual void processPayment() = 0;
    
    double getRemainingAmount() const {
        return originalAmount - amount;
    }
    
    // Encapsulation: protected setter
protected:
    void setAmount(double amt) {
        if (amt > 0 && amt <= originalAmount) {
            amount = amt;
        } else {
            cout << "Invalid amount! Must be positive and not exceeding original amount.\n";
        }
    }
};

// Derived class for Card Payment (Inheritance)
class CardPayment : public Payment {
private:
    string cardHolderName;
    string cardNumber;
    
public:
    CardPayment(double original) : Payment(original) {}
    
    void processPayment() override {
        cout << "\nProcessing Card Payment...\n";
        cout << "Original amount due: $" << originalAmount << endl;
        
        // Input validation
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter cardholder name: ";
        getline(cin, cardHolderName);
        
        cout << "Enter card number: ";
        getline(cin, cardNumber);
        
        double paymentAmount;
        cout << "Enter payment amount: $";
        while (!(cin >> paymentAmount) || paymentAmount <= 0 || paymentAmount > originalAmount) {
            cout << "Invalid amount! Please enter a positive value not exceeding $" << originalAmount << ": $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        setAmount(paymentAmount);
        
        cout << "\nPayment Details:\n";
        cout << "Cardholder: " << cardHolderName << endl;
        cout << "Card Number: ****-****-****-" << cardNumber.substr(cardNumber.length() - 4) << endl;
        cout << "Amount Paid: $" << amount << endl;
        cout << "Remaining Amount: $" << getRemainingAmount() << endl;
    }
};

// Derived class for Cash Payment (Inheritance)
class CashPayment : public Payment {
public:
    CashPayment(double original) : Payment(original) {}
    
    void processPayment() override {
        cout << "\nProcessing Cash Payment...\n";
        cout << "Original amount due: $" << originalAmount << endl;
        
        double paymentAmount;
        cout << "Enter cash amount: $";
        while (!(cin >> paymentAmount) || paymentAmount <= 0 || paymentAmount > originalAmount) {
            cout << "Invalid amount! Please enter a positive value not exceeding $" << originalAmount << ": $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        setAmount(paymentAmount);
        
        cout << "\nPayment Details:\n";
        cout << "Amount Paid: $" << amount << endl;
        cout << "Remaining Amount: $" << getRemainingAmount() << endl;
    }
};

int main() {
    const double SERVICE_COST = 100.0; // Original amount defined in code
    
    cout << "Welcome to the Payment System\n";
    cout << "Service cost: $" << SERVICE_COST << endl;
    
    while (true) {
        cout << "\nSelect payment method:\n";
        cout << "1. Credit/Debit Card\n";
        cout << "2. Cash\n";
        cout << "3. Exit\n";
        cout << "Enter choice (1-3): ";
        
        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (choice == 3) {
            cout << "Exiting payment system. Goodbye!\n";
            break;
        }
        
        // Polymorphism: Using base class pointer to call derived class methods
        Payment* payment = nullptr;
        
        switch (choice) {
            case 1:
                payment = new CardPayment(SERVICE_COST);
                break;
            case 2:
                payment = new CashPayment(SERVICE_COST);
                break;
        }
        
        if (payment) {
            payment->processPayment(); // Polymorphic call
            
            if (payment->getRemainingAmount() == 0) {
                cout << "\nPayment completed successfully! Thank you.\n";
                delete payment;
                return 0;
            } else {
                cout << "\nPartial payment received. Remaining balance: $" 
                     << payment->getRemainingAmount() << endl;
            }
            
            delete payment; // Clean up
        }
    }
    
    return 0;
}