# Summary of Advanced C++ Concepts

## Static in C++

In C++, static is a keyword that can be applied to variables, functions, and class members. It alters the behavior and scope of these entities in different ways.

1. **Static Local Variables:**

Static local variables are variables declared within a function, and they retain their value between function calls. Normally, local variables are created on the stack when the function is called and destroyed when the function returns. However, static local variables are stored in static memory, which means they are initialized only once and persist until the program ends.

```C++
void incrementCounter() {
    static int counter = 0; // Static local variable
    counter++;
    std::cout << "Counter: " << counter << std::endl;
}
```

In this example, the `counter` variable retains its value across multiple calls to the `incrementCounter` function.

2. **Static Global Variables:**

Static global variables are variables declared outside of any function or class, with the static keyword. They have global scope, but their visibility is limited to the translation unit (the current source file) in which they are defined. This means that two different translation units can have static global variables with the same name without causing a naming conflict.

```C++
// file1.cpp
static int globalValue = 42; // Static global variable

// file2.cpp
static int globalValue = 10; // A different static global variable
```

In this case, `file1.cpp` and `file2.cpp` each have their own static global variable `globalValue`, which are independent of each other.

## Constructors in C++

Constructors in C++ are special member functions of a class that are automatically called when an object of that class is instantiated. They are used to initialize objects, allocate resources, and perform any setup required for the object.

Here’s a detailed overview of constructors in C++:

### Key Features of Constructors

1. **Same Name as Class:** Constructors have the same name as the class they belong to.
2. **No Return Type:** Constructors do not have a return type, not even `void`.
3. **Automatic Invocation:** Constructors are called automatically when an object is created.

### Types of Constructors

#### 1. Default Constructor:

A constructor that can be called with no arguments. If no constructor is explicitly defined, the compiler provides a default constructor.

```C++
class MyClass {
public:
    MyClass() {
        // Default constructor
    }
};

```

#### 2. Parameterized Constructor:

A constructor that takes arguments to initialize an object with specific values.

```C++
class MyClass {
public:
    MyClass(int x, int y) {
        // Parameterized constructor
    }
};

```

#### 3. Copy Constructor:

A constructor that initializes an object using another object of the same class. The copy constructor is called when an object is passed by value.

```C++
class MyClass {
public:
    MyClass(const MyClass &obj) {
        // Copy constructor
    }
};

```

#### Constructor Example:

```C++
#include <iostream>
using namespace std;

class MyClass {
    int x, y;
public:
    // Default constructor
    MyClass() : x(0), y(0) {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    MyClass(int a, int b) : x(a), y(b) {
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    MyClass(const MyClass &obj) {
        x = obj.x;
        y = obj.y;
        cout << "Copy constructor called" << endl;
    }

    // Move constructor
    MyClass(MyClass &&obj) noexcept : x(obj.x), y(obj.y) {
        obj.x = 0;
        obj.y = 0;
        cout << "Move constructor called" << endl;
    }

    void display() {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    MyClass obj1; // Calls default constructor
    obj1.display();

    MyClass obj2(10, 20); // Calls parameterized constructor
    obj2.display();

    MyClass obj3 = obj2; // Calls copy constructor
    obj3.display();

    MyClass obj4 = std::move(obj2); // Calls move constructor
    obj4.display();

    return 0;
}

```

## Virtual Functions in C++

Virtual functions in C++ are a key feature that enables polymorphism, allowing derived classes to override methods of base classes and enabling dynamic binding at runtime. This is crucial for achieving runtime polymorphism and ensuring that the correct method is called based on the actual object type, not the type of the pointer or reference.

### Key Concepts of Virtual Functions

1. **Polymorphism:** Virtual functions allow a base class to declare a function that can be overridden by derived classes. This enables polymorphic behavior, where the function that gets called is determined at runtime based on the actual type of the object.

2. **Dynamic Binding:** With virtual functions, the function call is resolved at runtime rather than at compile time. This is also known as late binding or dynamic dispatch.

3. **Virtual Table (vtable):** The compiler maintains a table of pointers to virtual functions, known as the vtable, for each class with virtual functions. Each object of such a class contains a pointer to the vtable, which is used to resolve virtual function calls at runtime.

### Declaring Virtual Functions

To declare a virtual function, use the `virtual` keyword in the base class method declaration.

```C++
class Base {
public:
    virtual void show() {
        cout << "Base class show function" << endl;
    }
    virtual ~Base() {} // Virtual destructor for proper cleanup
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function" << endl;
    }
};
```

### Example of Virtual Functions

```C++
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show function" << endl;
    }
    virtual void display() {
        cout << "Base class display function" << endl;
    }
    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function" << endl;
    }
    void display() override {
        cout << "Derived class display function" << endl;
    }
};

void demonstrate(Base &obj) {
    obj.show();    // Calls the overridden method based on the actual object type
    obj.display(); // Calls the overridden method based on the actual object type
}

int main() {
    Base base;
    Derived derived;
    demonstrate(base);    // Calls Base class methods
    demonstrate(derived); // Calls Derived class methods
    return 0;
}

```

## `new` Keyword in C++

The `new` keyword in C++ is used for dynamic memory allocation. It allocates memory on the heap for an object or an array of objects and returns a pointer to the beginning of the allocated memory. Unlike automatic (stack) memory allocation, the memory allocated using `new` remains allocated until it is explicitly deallocated using the `delete` keyword.

### Syntax and Usage of new

#### 1. Allocating a Single Object:

```C++
int* p = new int;        // Allocates memory for an int
*p = 5;                  // Assigns value to the allocated memory

// Using a constructor for a class object
class MyClass {
public:
    MyClass() { /* Constructor code */ }
};

MyClass* obj = new MyClass();  // Allocates memory for an object of MyClass

```

#### 2. Allocating an Array of Objects:

```C++
int* arr = new int[10];  // Allocates memory for an array of 10 ints

// Allocating an array of objects
MyClass* objArray = new MyClass[5];  // Allocates memory for an array of 5 MyClass objects

```

### Deallocating Memory with `delete`

#### 1. Deleting a Single Object:

```c++
delete p;        // Deallocates memory allocated for a single int
delete obj;      // Deallocates memory for the MyClass object

```

#### 2. Deleting an Array of Objects:

```c++
delete[] arr;    // Deallocates memory allocated for an array of ints
delete[] objArray;  // Deallocates memory for an array of MyClass objects

```

## Operator Overloading in C++

Operator overloading in C++ allows you to redefine the way operators work for user-defined types (classes). This provides a way to make your custom types behave like built-in types with respect to operators such as `+, -, \*, ==`, and so on. Operator overloading can make our classes more intuitive and easier to use.

### Basics of Operator Overloading

1. **Syntax:** We can define how an operator works for a class by writing a special member function or a friend function.
2. **Member Function:** The operator function is defined inside the class.
3. **Non-Member Function:** The operator function is defined outside the class but is often declared as a friend function.

### Rules and Guidelines

- Only existing operators can be overloaded. We cannot create new operators.
- The precedence and associativity of operators cannot be changed.
- Some operators cannot be overloaded, such as `::`, `.*`, `.`, `? :`, `sizeof`, `typeid`, `static_cast`, `const_cast`, `dynamic_cast`, `reinterpret_cast`.

### Example of Operator Overloading

#### Overloading the + Operator

Let's define a simple `Complex` class and overload the `+` operator to add two complex numbers.

```C++
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator using member function
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const Complex& c);
};

// Definition of << operator
ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.real << ", " << c.imag << ")";
    return os;
}

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2; // Calls overloaded + operator
    cout << "c1 + c2 = " << c3 << endl; // Calls overloaded << operator
    return 0;
}

```

- The `Complex` class is defined with two private data members: `real` and `imag`, representing the real and imaginary parts of a complex number, respectively.
- The class has a constructor that initializes the real and imag data members. If no arguments are provided, the constructor initializes both components to `0`.
- The `operator+` function is overloaded as a member function of the Complex class. It takes another Complex object (`other`) as a parameter and returns a new Complex object whose components are the sums of the corresponding components of the two operands.
- The `operator<<` function is overloaded as a friend function of the Complex class. It takes an ostream object (`os`) and a Complex object (`c`) as parameters. It outputs the complex number in the format (real, imag) to the specified output stream (`os`).
- In the `main` function:
  - Two Complex objects, `c1` and `c2`, are created with the values `(3.0, 4.0)` and `(1.0, 2.0)`, respectively.
  - A third Complex object, `c3`, is created by adding `c1` and `c2` using the overloaded `+` operator `(c3 = c1 + c2;)`.
  - The sum of `c1` and `c2` (stored in `c3`) is printed to the console using the overloaded << operator `(cout << "c1 + c2 = " << c3 << endl;)`.

#### The output of the program will be:

```C++
c1 + c2 = (4, 6)
```
