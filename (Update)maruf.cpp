#include<bits/stdc++.h>
using namespace std;

//Abstract class
class Book { 

//Encapsulation
private:
    string title;
    string author;
    double price;

public:
    Book(string t, string a, double p) : title(t), author(a), price(p) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    double getPrice() { return price; }
};

//Abstract class
class User {

//Encapsulation
protected:
    string username;
    string password;

public:
   
    User(string u, string p) : username(u), password(p) {}

    string getUsername() { return username; }
    
    //Abstraction
    virtual void displayMenu() = 0;
};

//Inheritance
class Customer : public User {
public:
    Customer(string u, string p) : User(u, p) {}
    
    //Polymorphism
    void displayMenu() override {
        cout << "Welcome, " << getUsername() << "! Choose an option:\n"
             << "1. View Books\n"
             << "2. Purchase Book\n";
    }
};

//Inheritance
class Admin : public User {
public:
    Admin(string u, string p) : User(u, p) {}
    
    //Polymorphism
    void displayMenu() override {
        cout << "Welcome, Admin " << getUsername() << "! Choose an option:\n"
             << "1. Add Book\n"
             << "2. Remove Book\n";
    }
};





int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 12.99);
    Book book2("To Kill a Mockingbird", "Harper Lee", 9.99);

    Customer customer("john123", "pass123");
    Admin admin("admin", "adminpass");

    User* currentUser;

    // Simulate user interaction
    currentUser = &customer;
    currentUser->displayMenu();

    currentUser = &admin;
    currentUser->displayMenu();

    return 0;
}
