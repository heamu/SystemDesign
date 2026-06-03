#include<bits/stdc++.h>
using namespace std;

/*                          FACADE DESIGN PATTERN

 1. we will use facade design pattern whenever we need to hide the complexity from the client
 2. we dont need to force the client for using facade class now we will discuss use cases of facade

 3. suppose that we have a class named as EmployeDAO (data access object) which will have many different 
 4. functions that can manipulate the emplye database 
 5. we have a client which doesnot require those many functionalites but insertion and retrival of emplye
 6 in this case we will create a facade class which "has-a" employeDAO object and exposes only client necessary funcions
 7. in the client we will make that client "has-a" employeeFacade class this how we will hide complexity from the client
 
 8.another use case for performing a certain task imagine we have to interact with multiple classes suppose you want place an order
 9.the client should interact with produtcDAO to update count , payment class for payment , invoice to generate 
 10. invoice and shipment class for shipment related details. instead of our client directly managing all the classes
 11. we will make a orderFacade class to handle all this interaction logic and exposing create order functionality to 
 12 client. this is another use case

 13. a facade can interact with another facade this is another use case.
 
*/



// ---- Subsystems ----
class EmployeeDAO {
public:
    void insertEmployee(string name) {
        cout << "Employee " << name << " inserted into DB.\n";
    }
    void getEmployee(int id) {
        cout << "Fetching employee with id " << id << " from DB.\n";
    }
    void deleteEmployee(int id) {
        cout << "Deleting employee with id " << id << " from DB.\n";
    }
};

// ---- Facade ----
class EmployeeFacade {
    EmployeeDAO dao;
public:
    void addEmployee(string name) {
        dao.insertEmployee(name);
    }
    void showEmployee(int id) {
        dao.getEmployee(id);
    }
    // notice: no deleteEmployee exposed (hides complexity for client)
};

// ---- Another Use Case: Order System ----
class ProductDAO {
public:
    void updateStock(string product) {
        cout << "Stock updated for " << product << endl;
    }
};
class Payment {
public:
    void makePayment(double amount) {
        cout << "Payment of $" << amount << " completed.\n";
    }
};
class Invoice {
public:
    void generateInvoice(string product) {
        cout << "Invoice generated for " << product << endl;
    }
};
class Shipment {
public:
    void shipProduct(string product) {
        cout << "Product " << product << " shipped successfully.\n";
    }
};

// Facade for order handling
class OrderFacade {
    ProductDAO product;
    Payment payment;
    Invoice invoice;
    Shipment shipment;
public:
    void createOrder(string productName, double price) {
        product.updateStock(productName);
        payment.makePayment(price);
        invoice.generateInvoice(productName);
        shipment.shipProduct(productName);
    }
};

// ---- Client ----
int main() {
    cout << "----- Employee Example -----\n";
    EmployeeFacade empFacade;
    empFacade.addEmployee("John");
    empFacade.showEmployee(101);

    cout << "\n----- Order Example -----\n";
    OrderFacade orderFacade;
    orderFacade.createOrder("Laptop", 1200.50);

    return 0;
}
