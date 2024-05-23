# STL In C++

> The Standard Template Library or STL in C++ is a collection of template classes and template functions that provide a generic way of programming. It is a library of container classes, algorithms, and iterators.
> It is commonly used for efficiently programming data structures, algorithms, and functions. Some built-in data structures include arrays, vectors, queues, etc.

## Templates in STL

```C++
#include <iostream>

using namespace std;

// Templates introduction

/*

Non conevnient way
int square(int x)
{
    return x * x;
}

double square(double x){
    return x * x;
}

int main()
{
    cout << square(5) << endl;
    cout << square(5.5) << endl;
}
*/

// using template

template <typename T>
T square(T x)
{
    return x * x;
}

int main()
{
    cout << square<int>(5) << endl; // telling square datatype is of int
    cout << square(5.5) << endl;    // telling square datatype is of flo
}
```

### Class Templates in STL

Class templates in C++ are a powerful feature that allows you to create generic classes that can work with different data types. This promotes code reusability and helps in writing more efficient and maintainable code.

Here's a basic example of a class template:

```C++
template <typename T>
class Box {
private:
    T data;

public:
    void set(T value) {
        data = value;
    }

    T get() {
        return data;
    }
};
```

In this example, `T` is a placeholder for the data type that will be specified when we create an instance of the `Box` class. The `Box` class has a private member data of type `T`, and two member functions set and get to set and retrieve the value of data.

To use this class template, we need to create an instance by specifying the data type:

```C++
Box<int> intBox;
intBox.set(42);
int value = intBox.get(); // value will be 42

Box<double> doubleBox;
doubleBox.set(3.14);
double pi = doubleBox.get(); // pi will be 3.14
```

Here, we create two instances of the `Box` class, one for `int` and one for `double`. The compiler generates the appropriate class definition based on the specified data type.
Class templates can also have multiple type parameters, default type parameters, and member function templates. They can be specialized for specific data types to provide optimized implementations.

## Vectors in STL

Vectors are part of the C++ Standard Template Library (STL) and are widely used sequential containers that store elements in a dynamic array.

Here are some key points about vectors in C++:

1. **Header File:** To use vectors in your C++ program, we need to include the `<vector>` header file.

2. **Declaration:** We can declare a vector like this:

```C++
std::vector<data_type> vector_name;
```

We can replace `data_type` with the type of elements we want to store in the `vector` (e.g., int, double, std::string, or a user-defined class).

3. **Initialization:** We can initialize a vector in several ways:

```C++
std::vector<int> v1; // Empty vector
std::vector<int> v2 {1, 2, 3, 4, 5}; // Initialize with values
std::vector<int> v3(5); // Initialize with 5 default elements (0 for int)
std::vector<int> v4(5, 10); // Initialize with 5 elements, all set to 10
```

4. **Accessing Elements:** We can access vector elements using the `[]` operator or the `at()` member function. `at()` performs bound checking and throws an exception if the index is out of range, while `[]` doesn't.

```C++
v2[0] = 10; // Assign 10 to the first element
int value = v2.at(2); // Get the third element
```

4. **Common Member Functions:**

- `push_back(value)`: Adds a new element at the end of the vector.
- `pop_back():` Removes the last element from the vector.
- `size()`: Returns the number of elements in the vector.
- `empty()`: Returns true if the vector is empty, false otherwise.
- `clear()`: Removes all elements from the vector.

5. **Iterators:** Vectors provide iterator support, which allows us to traverse the elements using iterators. We can use `begin()` and `end()` to get iterators pointing to the beginning and end of the vector, respectively.

6. **Resizing:** We can resize a vector using the `resize()` member function. If the new size is greater than the current size, the vector is expanded, and new elements are added (with default values). If the new size is less than the current size, the vector is truncated.

7. **Capacity:** Vectors have a capacity, which is the total number of elements they can hold before requiring reallocation. We can check the capacity using the `capacity()` member function and reserve space for future elements using the `reserve()` member function.

#### Vector Example:

```C++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers {1, 2, 3, 4, 5};

    // Accessing elements
    std::cout << "First element: " << numbers[0] << std::endl; // Output: First element: 1
    std::cout << "Third element: " << numbers.at(2) << std::endl; // Output: Third element: 3

    // Modifying elements
    numbers[2] = 10;
    numbers.push_back(6);

    // Iterating over the vector
    std::cout << "Vector elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: Vector elements: 1 2 10 4 5 6

    // Resizing
    numbers.resize(8);
    std::cout << "Size after resizing: " << numbers.size() << std::endl; // Output: Size after resizing: 8

    return 0;
}
```

## Containers

The Standard Template Library (STL) in C++ provides a collection of powerful, generic classes and functions, including a variety of container classes. Containers are used to store collections of objects.

### Sequence Containers

1. **`std::vector`**

   - Dynamic array.
   - Elements can be accessed via an index.
   - Supports fast random access and dynamic resizing.
   - Insertion/removal at the end is fast (amortized constant time).

   ```cpp
   std::vector<int> vec = {1, 2, 3, 4};
   vec.push_back(5);
   ```

2. **`std::deque`**

   - Double-ended queue.
   - Allows fast insertion/removal at both ends.
   - Provides indexed access to elements.

   ```cpp
   std::deque<int> deq = {1, 2, 3, 4};
   deq.push_back(5);
   deq.push_front(0);
   ```

3. **`std::list`**

   - Doubly linked list.
   - Allows fast insertion/removal from anywhere in the sequence.
   - No random access (elements must be accessed sequentially).

   ```cpp
   std::list<int> lst = {1, 2, 3, 4};
   lst.push_back(5);
   lst.push_front(0);
   ```

4. **`std::forward_list`**

   - Singly linked list.
   - Allows fast insertion/removal from the front.
   - Uses less memory compared to `std::list` but lacks bidirectional iteration.

   ```cpp
   std::forward_list<int> flst = {1, 2, 3, 4};
   flst.push_front(0);
   ```

### Associative Containers

1. **`std::set`**

   - Collection of unique elements.
   - Elements are ordered.
   - Provides fast search, insertion, and removal (logarithmic complexity).

   ```cpp
   std::set<int> s = {1, 2, 3, 4};
   s.insert(5);
   ```

2. **`std::multiset`**

   - Similar to `std::set`, but allows duplicate elements.

   ```cpp
   std::multiset<int> ms = {1, 2, 2, 3, 4};
   ms.insert(5);
   ```

3. **`std::map`**

   - Collection of key-value pairs.
   - Keys are unique and ordered.
   - Provides fast search, insertion, and removal (logarithmic complexity).

   ```cpp
   std::map<int, std::string> m = {{1, "one"}, {2, "two"}};
   m[3] = "three";
   ```

4. **`std::multimap`**

   - Similar to `std::map`, but allows duplicate keys.

   ```cpp
   std::multimap<int, std::string> mm = {{1, "one"}, {1, "uno"}};
   mm.insert({2, "two"});
   ```

### Unordered Associative Containers

1. **`std::unordered_set`**

   - Collection of unique elements.
   - Elements are not ordered.
   - Provides average constant-time complexity for search, insertion, and removal.

   ```cpp
   std::unordered_set<int> us = {1, 2, 3, 4};
   us.insert(5);
   ```

2. **`std::unordered_multiset`**

   - Similar to `std::unordered_set`, but allows duplicate elements.

   ```cpp
   std::unordered_multiset<int> ums = {1, 2, 2, 3, 4};
   ums.insert(5);
   ```

3. **`std::unordered_map`**

   - Collection of key-value pairs.
   - Keys are unique and not ordered.
   - Provides average constant-time complexity for search, insertion, and removal.

   ```cpp
   std::unordered_map<int, std::string> um = {{1, "one"}, {2, "two"}};
   um[3] = "three";
   ```

4. **`std::unordered_multimap`**

   - Similar to `std::unordered_map`, but allows duplicate keys.

   ```cpp
   std::unordered_multimap<int, std::string> umm = {{1, "one"}, {1, "uno"}};
   umm.insert({2, "two"});
   ```

### Container Adapters

1. **`std::stack`**

   - Adapts a container to provide stack (LIFO) functionality.
   - By default, implemented using `std::deque`.

   ```cpp
   std::stack<int> stk;
   stk.push(1);
   stk.push(2);
   int top = stk.top();
   stk.pop();
   ```

2. **`std::queue`**

   - Adapts a container to provide queue (FIFO) functionality.
   - By default, implemented using `std::deque`.

   ```cpp
   std::queue<int> q;
   q.push(1);
   q.push(2);
   int front = q.front();
   q.pop();
   ```

3. **`std::priority_queue`**

   - Adapts a container to provide priority queue functionality.
   - By default, implemented using `std::vector`.

   ```cpp
   std::priority_queue<int> pq;
   pq.push(5);
   pq.push(1);
   pq.push(3);
   int top = pq.top();
   pq.pop();
   ```

### Container Properties

- **Capacity**: Functions like `size()`, `empty()`, and `max_size()` to check the number of elements and capacity.
- **Element Access**: Functions to access elements, like `front()`, `back()`, `operator[]`, and `at()`.
- **Modifiers**: Functions to modify containers, like `insert()`, `erase()`, `push_back()`, `pop_back()`, `clear()`, `swap()`.

Understanding these containers and their characteristics will help you choose the right one for your specific needs, improving the efficiency and clarity of your code.
