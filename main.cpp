/* 
First run [make] in  terminal.
To execcute -> ./main 
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "func.h"

using namespace std;

// Define a macro to print a value
#define PRINT(x) cout << "Value is: " << x << "\n" << endl

/* 
Parameters in classes are by  default private.
Parameters in struct are by  default public.
*/

class Intel
{
    int number;
    public:Intel();
    void mutl(){
        PRINT(101);
    }
};

class User
{
    bool paid = false;
    public: //  Encapsulation
        string id;
        string name;
        double bill;
        User(string id, string name, double bill)
        {
            this->id = id;
            this->name = name;
            this->bill  = bill;
        }
        bool get_paid_status() //  Abstraction
        {
            return paid;
        }
        void set_paid_status(bool paid) //  Abstraction
        {
            this->paid = paid;
        }
};

class Customer : public  User  // Inheritance
{
    private:  //  Encapsulation
        int num_of_rooms;
    public: //  Encapsulation
        Customer(string id, string name, double bill, int num_of_rooms)
        : User(id, name, bill)  // Call base class constructor
        {
            this->num_of_rooms = num_of_rooms;
        }
        int get_num_of_rooms()  //  Abstraction
        {
            return num_of_rooms;
        }
};

struct Rectangle
{
    double l;
    double w;
    double status(){ // example of a getter
        return  len;
    }
    void set_status(double len) // example of a setter
    {
        this->len  = len;
    }
    private: //  Abstraction
        double len = 2;
};

int main(){
    const double pi_math = 22/7.0;
    enum { v=5, b=90}; // multiple  constants
    double sls  = 4E-2; //10/4.0;
    long lg  = 444444444;
    int it = 444444777;
    short st  = 4444;
    int num;
    string  greet;
    vector<int> items  = {12, 45};

    cout<<"Enter your salutation :  ";
    getline(cin, greet);
    cout<<"I am  osinachi  " << sls <<  "  " <<  greet << endl;
    cout<<"Enter  your prefered number : ";
    cin>>num;
    cout<<"Your number is " << num  <<endl << endl;
    cout<<"the multiplied numbers "<< multiply(5.7, 10.0) << endl;
    cout<<"the subtracted numbers "<< subtract(5, 10) << endl;
    
    cout<<"size of double "<< sizeof(sls) << " -> " << sls << endl;
    cout<<"size of int "<< sizeof(num) << endl;
    cout<<"size of short "<< sizeof(st) << endl;
    cout<<"I \v am \v Osinachi " << endl;
    cout<<"v is: " << v << endl;

    cout<<"vector is: " << items[0] << endl;
    PRINT(it);

    /* Readinng  and writing to files */
    ofstream dbase;
    dbase.open("hello.txt", ios::app);
    dbase << "Check this out"  << endl; //  Write to file
    dbase.close();

    ifstream dbaser ("hello.txt");
    string input;
    dbaser >> input; //  read  first word/string
    cout <<  input  << endl;
    getline(dbaser, input);  // read entire line
    cout <<  input  << endl << endl;

    /* Class and  structures */

    Rectangle rect;
    rect.l = 2;
    rect.w = 5;
    cout << "Rectangle  size is " << multiply(rect.l, rect.w) << endl;
    cout << "Rectangle status len is " << rect.status() << endl << endl;
    rect.set_status(22);
    cout << "Rectangle status new len is " << rect.status() << endl << endl;
    // Intel prop = Intel();
    // cout<<"prop number is " << prop.mutl() << endl;

    User sadaf("0012345","Sadaf",373.45);
    cout <<  "Sadaf id  is " << sadaf.id << endl;

    Customer mert("212345","Mert",1253.9, 3);
    cout <<  "Mert leaves in " << mert.get_num_of_rooms() << " bedroom flat." << endl;
    // mert.id  = "233";

    // User& usman = mert("212345","Mert",1253.9, 3);



    return 0;
}

// Intel::Intel(int num)
// {
// }
