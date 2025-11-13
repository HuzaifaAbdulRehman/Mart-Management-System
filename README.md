# Mart Management System

A comprehensive C++ application for managing retail store operations including inventory, employees, billing, and sales monitoring.

## Contributors / Group Members

- Saad Shakeel — 23k-0614  
- Abdul Moiz Hossain — 23k-0553  
- Huziafa Abdul Rehman — 23k-0782

## Description

This Mart Management System is an Object-Oriented Programming (OOP) project built in C++ that provides a complete solution for managing a retail mart. The system features user authentication, product and employee management, billing, and sales monitoring.

## Features

- **User Authentication**: Secure login system with username and password validation
- **Inventory Management**:
  - Add, update, delete, and view products
  - Support for multiple product categories:
    - Toys (with age group and battery information)
    - Electronics (with type and warranty details)
    - Groceries (with expiration date and origin)
    - Cosmetics (with brand and skin type)
  - File-based persistent storage for each category

- **Employee Management**:
  - Add and remove cashiers and clerks
  - Track employee details (ID, name, salary, contact, hours worked)
  - Calculate salaries based on hourly rates
  - View all employee information
  - Persistent storage in text files

- **Billing System**:
  - Add items to bill from any product category
  - Calculate total bill amount
  - Print detailed bills
  - Save and load billing history
  - Dynamic array resizing for unlimited items

- **Sales Monitoring**:
  - Track sales by product category
  - Persistent sales data storage
  - View total sales statistics

- **Mart Details Management**:
  - Store and retrieve mart information
  - Track number of employees and products
  - Maintain mart location details

## Technologies Used

- **Language**: C++ (C++11 or later)
- **Standard Libraries**:
  - `<iostream>` - Input/output operations
  - `<string>` - String handling
  - `<fstream>` - File operations
  - `<vector>` - Dynamic arrays
  - `<sstream>` - String stream operations
- **Compiler**: Any C++ compiler (GCC, Clang, MSVC)
- **File I/O**: Binary and text file handling for data persistence

## Installation

### Prerequisites
- C++ compiler (GCC 5.0+, Clang 3.4+, or MSVC 14.0+)
- Make or any build system (optional)
- Windows/Linux/macOS

### Steps

1. Clone the repository:
```bash
git clone https://github.com/HuzaifaAbdulRehman/Mart-Management-System.git
cd Mart-Management-System
```

2. Compile the program:
```bash
# Using g++
g++ -std=c++11 Project_Main_Complete.cpp -o MartManagement

# Or using clang++
clang++ -std=c++11 Project_Main_Complete.cpp -o MartManagement
```

3. Run the executable:
```bash
# On Windows
MartManagement.exe

# On Linux/macOS
./MartManagement
```

## Usage

### Login Credentials
Default authorized users:
- Username: `Alice`, `Bob`, or `Charlie`
- Password: `password123`

### Main Menu Options

1. **Inventory Management**
   - Add products to inventory
   - Update existing products
   - Delete products
   - View all products

2. **Employee Management**
   - Add clerk or cashier
   - Remove employees
   - View all employee details

3. **Billing**
   - Add items to bill
   - Calculate total
   - Print bill
   - Save/Load bills
   - View sales statistics

4. **Mart Details**
   - Display mart information
   - Save mart details
   - Load mart details

### Example Workflow

1. Login with authorized credentials
2. Navigate to Inventory Management to add products
3. Use Employee Management to add cashiers and clerks
4. Process customer purchases through Billing system
5. Monitor sales through Sales Monitoring feature

## Folder Structure

```
Mart-Management-System/
│
├── Project_Main_Complete.cpp    # Main source code file
├── README.md                     # Project documentation
├── .gitignore                    # Git ignore rules
│
├── Data Files (generated at runtime):
│   ├── Toy.txt                  # Toy inventory data
│   ├── Electronics.txt          # Electronics inventory data (generated)
│   ├── Grocery.txt              # Grocery inventory data (generated)
│   ├── Cosmetic.txt             # Cosmetics inventory data (generated)
│   ├── employees.txt            # Employee records
│   ├── Billing.txt              # Billing history
│   ├── sales.txt                # Sales statistics
│   └── mart_details.txt         # Mart information
│
└── Documentation Images:
    ├── outline.JPG              # System outline
    ├── inventory.1.JPG          # Inventory interface
    ├── inventory_2.JPG          # Inventory details
    ├── billing.JPG              # Billing interface
    └── martdetaisl.JPG          # Mart details screen
```

## OOP Concepts Implemented

- **Inheritance**: Product class hierarchy (Toy, Electronics, Grocery, Cosmetic), Employee class hierarchy (Cashier, Clerk, Manager)
- **Polymorphism**: Virtual functions for display and update operations
- **Encapsulation**: Private data members with public interfaces
- **Abstraction**: Pure virtual functions in base classes
- **Operator Overloading**: Post-increment operator for saving products
- **Friend Functions**: For accessing private data across classes
- **Static Members**: Shared employee arrays in Manager class
- **Dynamic Memory Management**: Dynamic array allocation in Billing class

## Data Persistence

The system uses file-based storage:
- **Binary files** for product data (efficient storage)
- **Text files** for employee records and sales data (human-readable)
- All data persists between program executions

## Known Limitations

- Authentication system uses hardcoded credentials
- Binary file storage may not be portable across different systems
- Limited error handling for invalid inputs
- No database integration
- Single-user system (no concurrent access support)

## Future Enhancements

- Database integration (MySQL/PostgreSQL)
- GUI implementation (Qt/wxWidgets)
- Advanced reporting and analytics
- Barcode scanning support
- Multi-user access with role-based permissions
- Network capabilities for multi-branch support
- Receipt printing functionality

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Credits

Developed as an Object-Oriented Programming project demonstrating practical implementation of OOP concepts in C++.

## Author

**Huzaifa Abdul Rehman**
- GitHub: [@HuzaifaAbdulRehman](https://github.com/HuzaifaAbdulRehman)

## License

This project is open source and available for educational purposes.

## Contact

For questions or suggestions, please open an issue on GitHub or contact the repository owner.

---

**Note**: This is an academic project developed for learning purposes. It demonstrates various OOP concepts and file handling techniques in C++.