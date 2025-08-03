# OOP Concepts in C++ - Delivery App Example

This repository demonstrates key Object-Oriented Programming (OOP) concepts in C++ through a simple Delivery App implementation. Below is an explanation of the concepts and instructions to run the program.

## Table of Contents
1. [OOP Concepts Explained](#oop-concepts-explained)
   - [Class](#class)
   - [Constructors](#constructors)
   - [Destructors](#destructors)
   - [Inheritance](#inheritance)
   - [Operator Overloading](#operator-overloading)
   - [Function Overloading](#function-overloading)
2. [Delivery App Implementation](#delivery-app-implementation)
3. [How to Run](#how-to-run)

## OOP Concepts Explained

### Class
A class is a blueprint for creating objects. It defines properties (data members) and behaviors (member functions) that the objects will have.

```cpp
class Package {
private:
    string content;
    float weight;
public:
    void setDetails(string c, float w);
    void displayDetails();
};
```

### Constructors
Special member functions called when an object is created. They initialize objects.

```cpp
class Package {
public:
    // Default constructor
    Package() {
        content = "Unknown";
        weight = 0.0;
    }
    
    // Parameterized constructor
    Package(string c, float w) : content(c), weight(w) {}
};
```

### Destructors
Special member functions called when an object is destroyed. Used for cleanup.

```cpp
class Package {
public:
    ~Package() {
        cout << "Package object destroyed" << endl;
    }
};
```

### Inheritance
A mechanism where a new class (derived) inherits properties and behaviors from an existing class (base).

```cpp
class Base {
    // base class members
};

class Derived : public Base {
    // derived class members
};
```

### Operator Overloading
Giving special meaning to an operator for a user-defined type.

```cpp
class Package {
    float weight;
public:
    // Overload + operator
    Package operator+(Package& p) {
        Package temp;
        temp.weight = this->weight + p.weight;
        return temp;
    }
};
```

### Function Overloading
Multiple functions with the same name but different parameters.

```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    float add(float a, float b) { return a + b; }
};
```


## Delivery App Implementation

The delivery app implementation demonstrates several core OOP concepts through a hierarchical delivery management system. Here's how each concept is implemented:

### 1. Class Implementation
- **Base Class**: `delivery_app` handles customer details, items, price, and availability
- **Data Members**: Private (`customer`, `items`), Public (`price`, `availability`)
- **Member Functions**: Constructor for initialization, `display()` for showing details

### 2. Constructors
- **Default Constructor**: In `delivery_app`, collects all customer data through console input
- **Parameterized Constructor**: Not explicitly defined but could be added
- **Constructor Chaining**: `deliver` class constructor automatically calls parent (`delivery_app`) constructor first

### 3. Destructors
- **Explicit Destructors**: 
  - `~deliver()` displays "Can't be delivered"
  - `~rating()` displays "No activity"
- **Destruction Order**: Child destructors called before parent destructors

### 4. Inheritance
- **Single Inheritance**: `deliver` inherits from `delivery_app`
- **Multilevel Inheritance**: `rating` inherits from `deliver` which inherits from `delivery_app`
- **Access Control**: 
  - `protected` member `numlogins` in `deliver` accessible by `rating`
  - `private` members remain inaccessible to derived classes

### 5. Polymorphism
- **Virtual Function**: `last()` in `lastpart` base class
- **Runtime Polymorphism**: Using base class pointer to call derived class method

### 6. Friend Function
- `app_name_comments()` can access private/protected members of `rating` class

### 7. Exception Handling
- In `rating::review()`, throws exception for invalid customer ratings

---

## How to Run

### Prerequisites
- C++ compiler (g++ recommended)
- Make (optional)

### Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/Anoop7K/OOP-Concepts-Implementation.git
   ```

2. **Compile the program**
   - Using g++ directly:
     ```bash
     g++ delivery_app.cpp -o delivery_app
     ```