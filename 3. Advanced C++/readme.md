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
