#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Abstract Base Class
class Payment
{
protected:
    double amountDue;

public:
    Payment(double amount) : amountDue(amount) {}
    /* 
    "virtual" means that if there is implementation of the function "process_payment()" in my derived class,
     call that, else if there is no implementation, call this function
    */
    virtual void process_payment() = 0; // Pure virtual function
    virtual ~Payment() {}
};

// Derived Class: Cash Payment
class CashPayment : public Payment
{
private:
    double cashAmount;

public:
    CashPayment(double amount) : Payment(amount), cashAmount(0) {}

    void process_payment() override
    {
        cout << "Enter cash amount: $";
        cin >> cashAmount;

        if (cashAmount >= amountDue)
        {
            cout << "Payment successful. Change: $" << cashAmount - amountDue << endl;
            amountDue = 0;
        }
        else
        {
            cout << "Insufficient cash. $" << amountDue - cashAmount << " remaining.\n";
            amountDue -= cashAmount;
        }
    }
};

// Derived Class: Card Payment
class CardPayment : public Payment
{
private:
    string cardHolderName;
    string cardNumber;
    double cardAmount;

public:
    CardPayment(double amount) : Payment(amount), cardAmount(0) {}

    void process_payment() override
    {
        cout << "Enter card holder name: ";
        cin.ignore(); // flush newline
        getline(cin, cardHolderName);
        cout << "Enter card number: ";
        getline(cin, cardNumber);
        cout << "Enter amount to pay: $";
        cin >> cardAmount;

        if (cardAmount >= amountDue)
        {
            cout << "Card payment successful. Remaining balance on service: $0.00\n";
            amountDue = 0;
        }
        else
        {
            cout << "Partial payment. $" << amountDue - cardAmount << " remaining on service.\n";
            amountDue -= cardAmount;
        }
    }
};

int main()
{
    double serviceAmount = 100.00;
    cout << "Service charge: $" << serviceAmount << endl;

    cout << "Select payment method (1 = Cash, 2 = Card): ";
    int choice;
    cin >> choice;

    // Polymorphism is the ability  of an object  to have multiple forms

    Payment *payment = nullptr;
    // or
    // unique_ptr<Payment> payment;

    if (choice == 1)
    {
        payment = new CashPayment(serviceAmount); // object "payment"  has the form "CashPayment"
        // or
        // payment = unique_ptr<CashPayment>(new CashPayment(serviceAmount));

    }
    else if (choice == 2)
    {
        payment = new CardPayment(serviceAmount);  // object "payment"  has the form "CardPayment"
        // or
        // payment = unique_ptr<CardPayment>(new CardPayment(serviceAmount));
    }
    else
    {
        cout << "Invalid choice.\n";
        return 1;
    }

    payment->process_payment();

    // delete payment; // if  you use unique_ptr and make_unique, "delete payment"  is not needed
    return 0;
}
