#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class AccessControl
{
private:
    string password;
    string authorizedUsers[3];

public:
    AccessControl(string password, string array[3]) : password(password)
    {
        for (int i = 0; i < 3; ++i)
        {
            authorizedUsers[i] = array[i];
        }
    }

    bool authenticate(const string &username, const string &enteredPassword) const
    {
        for (const auto &user : authorizedUsers)
        {
            if (user == username && enteredPassword == password)
            {
                return true;
            }
        }
        return false;
    }
};
class Product
{
protected:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product(string name = "", int quantity = 0, double price = 0.0)
        : name(name), quantity(quantity), price(price) {}

    virtual void update(string newName, int newQuantity, double newPrice)
    {
        name = newName;
        quantity = newQuantity;
        price = newPrice;
    }
    double getPrice() const { return price; }
    virtual void display() {}

    virtual void deleteProduct(int p_id, const string &fileName)
    {
        ifstream fin;
        ofstream fout;
        fin.open(fileName, ios::in);
        if (!fin)
        {
            cout << "File Is Not Found" << endl;
        }
        else
        {
            fout.open("tempfile.txt", ios::out);
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                if (p_id != id)
                {
                    fout.write((char *)this, sizeof(*this));
                    fin.read((char *)this, sizeof(*this));
                }
            }
            fin.close();
            fout.close();
            remove(fileName.c_str());
            rename("tempfile.txt", fileName.c_str());
        }
    }
};

class Toy : public Product
{
private:
    string ageGroup;
    bool hasBatteries;

public:
    Toy(string name = "", int quantity = 0, double price = 0.0, string ageGroup = "", bool hasBatteries = false)
        : Product(name, quantity, price), ageGroup(ageGroup), hasBatteries(hasBatteries) {}

    void display() override
    {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
        cout << "Age Group: " << ageGroup << endl;
        cout << "Has Batteries: " << (hasBatteries ? "Yes" : "No") << endl;
    }

    void update(int p_id, string newName, int newQuantity, double newPrice, string newAgeGroup, bool newHasBatteries)
    {
        deleteProduct(p_id, "Toy.txt");
        Product::update(newName, newQuantity, newPrice);
        ageGroup = newAgeGroup;
        hasBatteries = newHasBatteries;
        deleteProduct(p_id, "Toy.txt");
        (*this)++;
    }

    void operator++(int)
    {
        if (name == "" && price == 0)
        {
            cout << "Data Not Initialized" << endl;
            return;
        }

        ofstream fout;
        fout.open("Toy.txt", ios::app);
        if (fout.is_open())
        {
            fout.write((char *)this, sizeof(*this));
            fout.close();
        }
        else
        {
            cout << "Error opening file" << endl;
        }
    }
    void viewAllProd()
    {
        ifstream fin;
        fin.open("Toy.txt", ios_base::in | ios_base::binary);
        if (!fin)
        {
            cout << "File Not Found" << endl;
        }
        else
        {
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                display();
                fin.read((char *)this, sizeof(*this));
            }
            fin.close();
        }
    }
    void deleteToy(int p_id)
    {
        deleteProduct(p_id, "Toy.txt");
    }

    string gettype()
    {
        return "Toy";
    }
};

class Electronics : public Product
{
private:
    string electronicType;
    string warrantyPeriod;

public:
    Electronics(string name = "", int quantity = 0, double price = 0.0, string electronicType = "", string warrantyPeriod = "")
        : Product(name, quantity, price), electronicType(electronicType), warrantyPeriod(warrantyPeriod) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
        cout << "Electronic Type: " << electronicType << endl;
        cout << "Warranty Period: " << warrantyPeriod << endl;
    }

    void update(int p_id, string newName, int newQuantity, double newPrice, string newElectronicType, string newWarrantyPeriod)
    {
        deleteProduct(p_id, "Electronics.txt");
        Product::update(newName, newQuantity, newPrice);
        electronicType = newElectronicType;
        warrantyPeriod = newWarrantyPeriod;
        (*this)++;
    }

    void operator++(int)
    {
        if (name == "" && price == 0)
        {
            cout << "Data Not Initialized" << endl;
            return;
        }

        ofstream fout;
        fout.open("Electronics.txt", ios::app);
        if (fout.is_open())
        {
            fout.write((char *)this, sizeof(*this));
            fout.close();
        }
        else
        {
            cout << "Error opening file" << endl;
        }
    }

    void deleteElectronics(int p_id)
    {
        deleteProduct(p_id, "Electronics.txt");
    }
    void viewAllProd()
    {
        ifstream fin;
        fin.open("Electronics.txt", ios_base::in | ios_base::binary);
        if (!fin)
        {
            cout << "File Not Found" << endl;
        }
        else
        {
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                display();
                fin.read((char *)this, sizeof(*this));
            }
            fin.close();
        }
    }
    string gettype() const
    {
        return "Electronics";
    }
};

class Grocery : public Product
{
private:
    string expirationDate;
    string origin;

public:
    Grocery(string name = "", int quantity = 0, double price = 0.0, string expirationDate = "", string origin = "")
        : Product(name, quantity, price), expirationDate(expirationDate), origin(origin) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Origin: " << origin << endl;
    }

    void update(int p_id, string newName, int newQuantity, double newPrice, string newExpirationDate, string newOrigin)
    {
        deleteProduct(p_id, "Grocery.txt");
        Product::update(newName, newQuantity, newPrice);
        expirationDate = newExpirationDate;
        origin = newOrigin;
        (*this)++;
    }

    void operator++(int)
    {
        if (name == "" && price == 0)
        {
            cout << "Data Not Initialized" << endl;
            return;
        }

        ofstream fout;
        fout.open("Grocery.txt", ios::app);
        if (fout.is_open())
        {
            fout.write((char *)this, sizeof(*this));
            fout.close();
        }
        else
        {
            cout << "Error opening file" << endl;
        }
    }

    void deleteGrocery(int p_id)
    {
        deleteProduct(p_id, "Grocery.txt");
    }
    void viewAllProd()
    {
        ifstream fin;
        fin.open("Grocery.txt", ios_base::in | ios_base::binary);
        if (!fin)
        {
            cout << "File Not Found" << endl;
        }
        else
        {
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                display();
                fin.read((char *)this, sizeof(*this));
            }
            fin.close();
        }
    }
    string gettype() const
    {
        return "Grocery";
    }
};

class Cosmetic : public Product
{
private:
    string brand;
    string skinType;

public:
    Cosmetic(string name = "", int quantity = 0, double price = 0.0, string brand = "", string skinType = "")
        : Product(name, quantity, price), brand(brand), skinType(skinType) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
        cout << "Brand: " << brand << endl;
        cout << "Skin Type: " << skinType << endl;
    }

    void update(int p_id, string newName, int newQuantity, double newPrice, string newBrand, string newSkinType)
    {
        deleteProduct(p_id, "Cosmetic.txt");
        Product::update(newName, newQuantity, newPrice);
        brand = newBrand;
        skinType = newSkinType;
        (*this)++;
    }

    void operator++(int)
    {
        if (name == "" && price == 0)
        {
            cout << "Data Not Initialized" << endl;
            return;
        }

        ofstream fout;
        fout.open("Cosmetic.txt", ios::app);
        if (fout.is_open())
        {
            fout.write((char *)this, sizeof(*this));
            fout.close();
            fout.close();
        }
        else
        {
            cout << "Error opening file" << endl;
        }
    }

    void deleteCosmetic(int p_id)
    {
        deleteProduct(p_id, "Cosmetic.txt");
    }
    void viewAllProd()
    {
        ifstream fin;
        fin.open("Grocery.txt", ios_base::in | ios_base::binary);
        if (!fin)
        {
            cout << "File Not Found" << endl;
        }
        else
        {
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                display();
                fin.read((char *)this, sizeof(*this));
            }
            fin.close();
        }
    }

    string gettype() const
    {
        return "Cosmetics";
    }
};

class SalesMonitoring
{
private:
    int toySales;
    int electronicsSales;
    int grocerySales;
    int cosmeticSales;

public:
    SalesMonitoring() : toySales(0), electronicsSales(0), grocerySales(0), cosmeticSales(0)
    {
        loadSales();
    }

    void incrementToySales(int quantity)
    {
        toySales += quantity;
        saveSales();
    }

    void incrementElectronicsSales(int quantity)
    {
        electronicsSales += quantity;
        saveSales();
    }

    void incrementGrocerySales(int quantity)
    {
        grocerySales += quantity;
        saveSales();
    }

    void incrementCosmeticSales(int quantity)
    {
        cosmeticSales += quantity;
        saveSales();
    }

    void displaySales()
    {
        cout << "Total Toy Sales: " << toySales << endl;
        cout << "Total Electronics Sales: " << electronicsSales << endl;
        cout << "Total Grocery Sales: " << grocerySales << endl;
        cout << "Total Cosmetic Sales: " << cosmeticSales << endl;
    }

    void saveSales()
    {
        ofstream file("sales.txt");
        file << toySales << endl;
        file << electronicsSales << endl;
        file << grocerySales << endl;
        file << cosmeticSales << endl;
        file.close();
    }

    void loadSales()
    {
        ifstream file("sales.txt");
        if (file.is_open())
        {
            string line;
            getline(file, line);
            stringstream(line) >> toySales;
            getline(file, line);
            stringstream(line) >> electronicsSales;
            getline(file, line);
            stringstream(line) >> grocerySales;
            getline(file, line);
            stringstream(line) >> cosmeticSales;
            file.close();
        }
    }
};
class Billing
{
private:
    Product **items;
    int itemCount;
    int capacity;
    string fileName;
    SalesMonitoring salesMonitoring;

public:
    Billing(string fileName = "Billing.txt", int capacity = 10) : fileName(fileName), itemCount(0), capacity(capacity)
    {
        items = new Product *[capacity];
    }

    ~Billing()
    {
        for (int i = 0; i < itemCount; ++i)
        {
            delete items[i];
        }
        delete[] items;
    }
    void addItem(Product *item)
    {
        if (itemCount == capacity)
        {
            capacity *= 2;
            Product **newItems = new Product *[capacity];
            for (int i = 0; i < itemCount; ++i)
            {
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
        }
        items[itemCount++] = item;

        if (dynamic_cast<Toy *>(item))
        {
            salesMonitoring.incrementToySales(1); // assuming quantity is 1
        }
        else if (dynamic_cast<Electronics *>(item))
        {
            salesMonitoring.incrementElectronicsSales(1); // assuming quantity is 1
        }
        else if (dynamic_cast<Grocery *>(item))
        {
            salesMonitoring.incrementGrocerySales(1); // assuming quantity is 1
        }
        else if (dynamic_cast<Cosmetic *>(item))
        {
            salesMonitoring.incrementCosmeticSales(1); // assuming quantity is 1
        }
    }
    double calculateTotal()
    {
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i)
        {
            total += items[i]->getPrice();
        }
        return total;
    }

    void printBill()
    {
        cout << "Bill: " << endl;
        for (int i = 0; i < itemCount; ++i)
        {
            items[i]->display();
        }
        cout << "Total: $" << calculateTotal() << endl;
    }

    void saveBill()
    {
        ofstream fout;
        fout.open("Billing.txt", ios::app);
        if (fout.is_open())
        {
            for (int i = 0; i < itemCount; ++i)
            {
                fout.write((char *)items[i], sizeof(*items[i]));
            }
            fout.close();
        }
        else
        {
            cout << "Error opening file" << endl;
        }
    }

};
class Employee
{
protected:
    string name;
    int empId;
    double salary;
    string contactNo;
    int hrs;

public:
    Employee(string n, int id, double s, string c, int h)
    {
        name = n;
        empId = id;
        salary = s;
        c = contactNo;
        hrs = h;
    }
    Employee()
    {
    }
    string getName() const { return name; }
    int getEmpId() const { return empId; }
    double getSalary() const { return salary; }
    string getContactNo() const { return contactNo; }
    int getHours() const { return hrs; }
};
class Cashier : public Employee
{
    double hourlyRate;

public:
    Cashier(string n, int id, double s, string c, int h) : Employee(n, id, s, c, h)
    {
        hourlyRate = 20;
    }
    Cashier()
    {
    }
    int calculateSalary()
    {
        return (hrs * hourlyRate);
    }
    // Write details to file
    friend void displayAllDetails();
};
class Clerk : public Employee
{
    double hourlyRate;

public:
    Clerk(string n, int id, double s, string c, int h) : Employee(n, id, s, c, h)
    {
        hourlyRate = 10;
    }
    Clerk()
    {
    }
    int calculateSalary()
    {
        return (hrs * hourlyRate);
    }
    friend void displayAllDetails();
};
class Manager : public Employee
{
    static const int MAX_EMPLOYEES = 100;
    static int cashierSize;
    static int clerkSize;
    static Cashier cashiers[MAX_EMPLOYEES];
    static Clerk clerks[MAX_EMPLOYEES];

public:
    Manager(string n, int id, double s, string c, int h) : Employee(n, id, s, c, h) {}

    void addEmployeeCashier(Cashier c)
    {
        cashiers[cashierSize++] = c;
        ofstream outfile("employees.txt", ios::app);
        if (outfile.is_open())
        {
            outfile << "Cashier Details:" << endl;
            outfile << "Name: " << c.getName() << endl;
            outfile << "Employee ID: " << c.getEmpId() << endl;
            outfile << "Salary: " << c.getSalary() << endl;
            outfile << "Contact Number: " << c.getContactNo() << endl;
            outfile << "Hours Worked: " << c.getHours() << endl;
            outfile << "Hourly Rate: " << c.calculateSalary() / c.getHours() << endl
                    << endl;
            outfile.close();
            cout << "Employee added" << endl;
        }
    }

    void addEmployeeClerk(Clerk c)
    {
        clerks[clerkSize++] = c;
        ofstream outfile("employees.txt", ios::app);
        if (outfile.is_open())
        {
            outfile << "Clerk Details:" << endl;
            outfile << "Name: " << c.getName() << endl;
            outfile << "Employee ID: " << c.getEmpId() << endl;
            outfile << "Salary: " << c.getSalary() << endl;
            outfile << "Contact Number: " << c.getContactNo() << endl;
            outfile << "Hours Worked: " << c.getHours() << endl;
            outfile << "Hourly Rate: " << c.calculateSalary() / c.getHours() << endl
                    << endl;
            outfile.close();
            cout << "Employee added" << endl;
        }
    }
    void removeEmployeeCashier(string n)
    {
        for (int i = 0; i < cashierSize; i++)
        {
            if (cashiers[i].getName() == n)
            {

                for (int j = i; j < cashierSize - 1; j++)
                {
                    cashiers[j] = cashiers[j + 1];
                }
                cashierSize--;

                ofstream outfile("employees.txt");
                if (outfile.is_open())
                {
                    for (int k = 0; k < cashierSize; k++)
                    {
                        outfile << "Cashier Details:" << endl;
                        outfile << "Name: " << cashiers[k].getName() << endl;
                        outfile << "Employee ID: " << cashiers[k].getEmpId() << endl;
                        outfile << "Salary: " << cashiers[k].getSalary() << endl;
                        outfile << "Contact Number: " << cashiers[k].getContactNo() << endl;
                        outfile << "Hours Worked: " << cashiers[k].getHours() << endl;
                        outfile << "Hourly Rate: " << cashiers[k].calculateSalary() / cashiers[k].getHours() << endl
                                << endl;
                    }
                    outfile.close();
                }
                cout << "Cashier removed " << endl;
                return;
            }
        }
        cout << "Cashier with name " << n << " not found." << endl;
    }

    void removeEmployeeClerk(string n)
    {
        for (int i = 0; i < clerkSize; i++)
        {
            if (clerks[i].getName() == n)
            {

                for (int j = i; j < clerkSize - 1; j++)
                {
                    clerks[j] = clerks[j + 1];
                }
                clerkSize--;

                ofstream outfile("employees.txt");
                if (outfile.is_open())
                {
                    for (int k = 0; k < clerkSize; k++)
                    {
                        outfile << "Clerk Details:" << endl;
                        outfile << "Name: " << clerks[k].getName() << endl;
                        outfile << "Employee ID: " << clerks[k].getEmpId() << endl;
                        outfile << "Salary: " << clerks[k].getSalary() << endl;
                        outfile << "Contact Number: " << clerks[k].getContactNo() << endl;
                        outfile << "Hours Worked: " << clerks[k].getHours() << endl;
                        outfile << "Hourly Rate: " << clerks[k].calculateSalary() / clerks[k].getHours() << endl
                                << endl;
                    }
                    outfile.close();
                }
                cout << "Clerk removed " << endl;
                return;
            }
        }
        cout << "Clerk with name " << n << " not found." << endl;
    }

    friend void displayAllDetails();
};
int Manager::cashierSize = 0;
int Manager::clerkSize = 0;
Cashier Manager::cashiers[MAX_EMPLOYEES];
Clerk Manager::clerks[MAX_EMPLOYEES];

void displayAllDetails()
{
    cout << "Details for cashiers: " << endl;
    for (int i = 0; i < Manager::cashierSize; i++)
    {
        cout << "Name: " << Manager::cashiers[i].getName() << endl;
        cout << "Employee ID: " << Manager::cashiers[i].getEmpId() << endl;
        cout << "Salary: " << Manager::cashiers[i].getSalary() << endl;
        cout << "Contact Number: " << Manager::cashiers[i].getContactNo() << endl;
        cout << "Hours Worked: " << Manager::cashiers[i].getHours() << endl;
        cout << "Hourly Rate: " << Manager::cashiers[i].calculateSalary() / Manager::cashiers[i].getHours() << endl;
        cout << endl;
    }

    cout << "Details for clerks: " << endl;
    for (int i = 0; i < Manager::clerkSize; i++)
    {
        cout << "Name: " << Manager::clerks[i].getName() << endl;
        cout << "Employee ID: " << Manager::clerks[i].getEmpId() << endl;
        cout << "Salary: " << Manager::clerks[i].getSalary() << endl;
        cout << "Contact Number: " << Manager::clerks[i].getContactNo() << endl;
        cout << "Hours Worked: " << Manager::clerks[i].getHours() << endl;
        cout << "Hourly Rate: " << Manager::clerks[i].calculateSalary() / Manager::clerks[i].getHours() << endl;
        cout << endl;
    }
}
class MartDetails
{
private:
    string name;
    string location;
    int numEmployees;
    int numProducts;

public:
    MartDetails(string name = "", string location = "", int numEmployees = 0, int numProducts = 0)
        : name(name), location(location), numEmployees(numEmployees), numProducts(numProducts) {}

    void displayDetails()
    {
        cout << "Mart Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Number of Employees: " << numEmployees << endl;
        cout << "Number of Products: " << numProducts << endl;
    }

    void saveDetails()
    {
        cout << "Enter Mart Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Location: ";
        getline(cin, location);
        cout << "Enter Number of Employees: ";
        cin >> numEmployees;
        cout << "Enter Number of Products: ";
        cin >> numProducts;

        ofstream fout("mart_details.txt");
        fout << name << endl;
        fout << location << endl;
        fout << numEmployees << endl;
        fout << numProducts << endl;
        fout.close();
    }

    void loadDetails()
    {
        ifstream fm("mart_details.txt");
        if (fm.is_open())
        {
            getline(fm, name);
            getline(fm, location);
            fm >> numEmployees;
            fm >> numProducts;
            fm.close();
        }
        else
        {
            cout << "Failed to open mart_details.txt" << endl;
        }
    }
};
int main()
{
    string names[3] = {"Alice", "Bob", "Charlie"};
    AccessControl access("password123", names);
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    MartDetails martDetails;

    // if (access.authenticate(username, password))
    // {
    int choice = 1;
    while (choice != 0)
    {
        cout << "\nWelcome To Mart Management System" << endl;
        cout << "Press 1 For Inventory Management" << endl
             << "Press 2 For Employee Management" << endl
             << "Press 3 For Billing" << endl
             << "Press 4 For Mart Details" << endl
             << "Press 0 To Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            char productType;
            cout << "Press T For Toys" << endl
                 << "Press E For Electronics" << endl
                 << "Press G For Grocery" << endl
                 << "Press C For Cosmetics" << endl
                 << "Press O To Go Back " << endl;
            cin >> productType;
            switch (productType)
            {
            case 'T':
            {
                string name, ageGroup;
                int quantity;
                double price;
                bool hasBatteries;

                cout << "Enter Toy Name: ";
                cin >> name;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: $";
                cin >> price;
                cout << "Enter Age Group: ";
                cin >> ageGroup;
                cout << "Does it have batteries? (1 for Yes / 0 for No): ";
                cin >> hasBatteries;

                Toy toy(name, quantity, price, ageGroup, hasBatteries);
                toy++;
                break;
            }
            case 'E':
            {
                string name, electronicType, warrantyPeriod;
                int quantity;
                double price;

                cout << "Enter Electronics Name: ";
                cin >> name;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: $";
                cin >> price;
                cout << "Enter Electronic Type: ";
                cin >> electronicType;
                cout << "Enter Warranty Period: ";
                cin >> warrantyPeriod;

                Electronics electronics(name, quantity, price, electronicType, warrantyPeriod);
                electronics++;
                break;
            }
            case 'G':
            {
                string name, expirationDate, origin;
                int quantity;
                double price;

                cout << "Enter Grocery Name: ";
                cin >> name;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: $";
                cin >> price;
                cout << "Enter Expiration Date: ";
                cin >> expirationDate;
                cout << "Enter Origin: ";
                cin >> origin;

                Grocery grocery(name, quantity, price, expirationDate, origin);
                grocery++;
                break;
            }
            case 'C':
            {
                string name, brand, skinType;
                int quantity;
                double price;

                cout << "Enter Cosmetic Name: ";
                cin >> name;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: $";
                cin >> price;
                cout << "Enter Brand: ";
                cin >> brand;
                cout << "Enter Skin Type: ";
                cin >> skinType;

                Cosmetic cosmetic(name, quantity, price, brand, skinType);
                cosmetic++;
                break;
            }
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
            break;
        case 2:
        {
            int choiceEmployee;
            int loopCondition = 0;
            while (loopCondition == 0)
            {
                Manager m("abc", 1, 5000, "1234567890", 40);
                cout << "Welcome to Employee management system" << endl;
                cout << "Press 1 to add clerk" << endl;
                cout << "Press 2 to add cashier" << endl;
                cout << "Press 3 to view details of all the employees" << endl;
                cout << "Press 4 to remove clerk" << endl;
                cout << "Press 5 to remove cashier" << endl;
                cin >> choiceEmployee;
                switch (choiceEmployee)
                {
                case 1:
                {
                    string empName, contactNo;
                    int id, hrs;
                    double salary, rate;
                    cout << "Enter Name: " << endl;
                    cin >> empName;
                    cout << "Enter id" << endl;
                    cin >> id;
                    cout << "Enter salary" << endl;
                    cin >> salary;
                    cout << "Enter hrs" << endl;
                    cin >> hrs;

                    Clerk c(empName, id, salary, contactNo, hrs);
                    m.addEmployeeClerk(c);
                    cout << "press 0 to return to previuos menu. Any other button to return to main menu" << endl;
                    cin >> loopCondition;
                    break;
                }
                case 2:
                {
                    string empName, contactNo;
                    int id, hrs;
                    double salary, rate;
                    cout << "Enter Name: " << endl;
                    cin >> empName;
                    cout << "Enter id" << endl;
                    cin >> id;
                    cout << "Enter salary" << endl;
                    cin >> salary;
                    cout << "Enter hrs" << endl;
                    cin >> hrs;

                    Cashier cs(empName, id, salary, contactNo, hrs);
                    m.addEmployeeCashier(cs);
                    cout << "press 0 to return to previuos menu. Any other button to return to main menu" << endl;
                    cin >> loopCondition;
                    break;
                }
                case 3:
                {
                    displayAllDetails();
                    cout << "press 0 to return to previuos menu. Any other button to return to main menu" << endl;
                    cin >> loopCondition;
                    break;
                }
                case 4:
                {
                    string tempName;
                    cout << "Enter name of clerk you want to remove" << endl;
                    cin >> tempName;
                    m.removeEmployeeClerk(tempName);
                    cout << "press 0 to return to previuos menu. Any other button to return to main menu" << endl;
                    cin >> loopCondition;
                    break;
                }
                case 5:
                {
                    string tempName;
                    cout << "Enter name of cashier you want to remove" << endl;
                    cin >> tempName;
                    m.removeEmployeeCashier(tempName);
                    cout << "press 0 to return to previuos menu.Any other button to return to main menu" << endl;
                    cin >> loopCondition;
                    break;
                }
                default:
                {
                    cout << "Invalid" << endl;
                    cout << "press 0 to return to previuos menu. Any other button to return to main menu" << endl;
                    cin >> loopCondition;
                    break;
                }
                }
            }

            break;
        }
        // Employee Management code
        break;
        case 3:
        {
            int subChoice = 1;
            Billing billing;
            SalesMonitoring salesMonitoring;

            while (subChoice != 0)
            {
                cout << "\nWelcome To Billing System" << endl;
                cout << "Press 1 To Add Item to Bill" << endl
                     << "Press 2 To Calculate Total" << endl
                     << "Press 3 To Print Bill" << endl
                     << "Press 4 To Save Bill" << endl
                     << "Press 5 To Display Sales" << endl
                     << "Press 0 To Go Back" << endl;
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                {
                    int productType;
                    cout << "Press 1 For Toys" << endl
                         << "Press 2 For Electronics" << endl
                         << "Press 3 For Grocery" << endl
                         << "Press 4 For Cosmetics" << endl
                         << "Press 0 To Go Back " << endl;
                    cin >> productType;

                    switch (productType)
                    {
                    case 1:
                    {
                        string name, ageGroup;
                        int quantity;
                        double price;
                        bool hasBatteries;

                        cout << "Enter Toy Name: ";
                        cin >> name;
                        cout << "Enter Quantity: ";
                        cin >> quantity;
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Age Group: ";
                        cin >> ageGroup;
                        cout << "Does it have batteries? (1 for Yes / 0 for No): ";
                        cin >> hasBatteries;
                         cout << "Successfully added " << quantity << " toys." << endl;
                        Toy toy(name, quantity, price, ageGroup, hasBatteries);
                        billing.addItem(&toy);
                        salesMonitoring.incrementToySales(quantity);
                       
                        break;
                    }
                    case 2:
                    {
                        string name, electronicType, warrantyPeriod;
                        int quantity;
                        double price;

                        cout << "Enter Electronics Name: ";
                        cin >> name;
                        cout << "Enter Quantity: ";
                        cin >> quantity;
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Electronic Type: ";
                        cin >> electronicType;
                        cout << "Enter Warranty Period: ";
                        cin >> warrantyPeriod;
                         cout << "Successfully added " << quantity << " electronics." << endl;
                        Electronics electronics(name, quantity, price, electronicType, warrantyPeriod);
                        billing.addItem(&electronics);
                        salesMonitoring.incrementElectronicsSales(quantity);
                       
                        break;
                    }
                    case 3:
                    {
                        string name, expirationDate, origin;
                        int quantity;
                        double price;

                        cout << "Enter Grocery Name: ";
                        cin >> name;
                        cout << "Enter Quantity: ";
                        cin >> quantity;
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Expiration Date: ";
                        cin >> expirationDate;
                        cout << "Enter Origin: ";
                        cin >> origin;
                         cout << "Successfully added " << quantity << " groceries." << endl;
                        Grocery grocery(name, quantity, price, expirationDate, origin);
                        billing.addItem(&grocery);
                        salesMonitoring.incrementGrocerySales(quantity);
                       
                        break;
                    }
                    case 4:
                    {
                        string name, brand, skinType;
                        int quantity;
                        double price;

                        cout << "Enter Cosmetic Name: ";
                        cin >> name;
                        cout << "Enter Quantity: ";
                        cin >> quantity;
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Brand: ";
                        cin >> brand;
                        cout << "Enter Skin Type: ";
                        cin >> skinType;
                        cout << "Successfully added " << quantity << " cosmetics." << endl;

                        Cosmetic cosmetic(name, quantity, price, brand, skinType);
                        billing.addItem(&cosmetic);
                        salesMonitoring.incrementCosmeticSales(quantity);
                        
                        break;
                    }
                    default:
                        cout << "Invalid Choice" << endl;
                        break;
                    }
                    break;
                }
                case 2:
                {
                    double total = billing.calculateTotal();
                    cout << "Total: $" << total << endl;
                    break;
                }
                case 3:
                    billing.printBill();
                    break;
                case 4:
                    billing.saveBill();
                    cout<<"Bill saved successfully"<<endl;
                    break;
                case 5:
                    salesMonitoring.displaySales();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    break;
                }
            }
            break;
        }
        case 4:
            cout << "\nMart Details Menu:" << endl;
            cout << "1. Display mart details" << endl;
            cout << "2. Save mart details" << endl;
            cout << "3. Load mart details" << endl;
            cout << "0. Go back" << endl;
            int martDetailsChoice;

            cin >> martDetailsChoice;
            if (martDetailsChoice == 0)
            {
                break; // Exit the loop and go back to the main menu
            }
            switch (martDetailsChoice)
            {
            case 1:
                martDetails.displayDetails();
                break;
            case 2:
                martDetails.saveDetails();
                break;
            case 3:
                martDetails.loadDetails();
                cout<<"Mart details loaded succeesfully"<<endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
                break;
            }
            break;
        }
    }
    // }
}
