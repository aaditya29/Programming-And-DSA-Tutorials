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
