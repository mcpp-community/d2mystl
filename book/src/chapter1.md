# Chapter 1 --- Array Module Implementation

In this chapter, you will implement the foundational **MySTL**.array module, 
which provides a simplified version of std::array with basic functionality. 
This module introduces the design patterns and organization used throughout **MySTL**.

⚠️ **Important:**
All tasks in this chapter must follow the specified interfaces
**exactly**. Module names, exported symbols, and structure must not be
altered. Any deviation may cause module linkage failures or test
incompatibilities.

## Directory Structure

Add the files as follows:

```text
mystl/
└── chapter1/
    └── array/
        └── array.cppm
```

# 1. Global Module

## Objective

Update the **global module** to export the new array module 
alongside the existing meta information module.
After implementation, users should be able to write:

```cpp
import mySTL.array;
```

to access both meta information and array functionality.

## Requirements

Update the existing C++23 module: mySTL

-   Re-export: `mySTL.array`

## Strict Constraints

Do **not**:

-   Add any additional code
-   Declare types, functions, or variables
-   Modify the module name
-   Change the export behavior
-   Include implementation details

The global module must remain minimal and act purely as a module
aggregator.

## Example Usage

```cpp
import mySTL.array;
// Array are now accessible
```

# 2. Array Module Implementation

## Objective

Implement the array module that provides a simplified fixed-size container similar to std::array. 

## Requirements

Create a module named:

    mySTL.array

Follow the reference interface precisely and provide the following functionality.

### API Behavior Requirements

#### Element Access Methods

`operator[](std::size_t index)`

-   Returns: Reference to the element at position index
-   No bounds checking: Must not perform any range validation
-   Exception safety: Must not throw exceptions (marked noexcept)
-   Const correctness: Both const and non-const versions required

`at(std::size_t index)`

-   Returns: Reference to the element at position index
-   Bounds checking: Must validate that index < size()
-   Exception: Must throw std::out_of_range if index >= size()
-   Exception message: Should be "Index out of range"
-   Const correctness: Both const and non-const versions required

#### Capacity Methods

`size()`

-   Returns: The template parameter N value
    -   For Array<T, 0>: Must return 0
-   Exception safety: Must not throw exceptions (marked noexcept)

`capacity()`

-   Returns: The actual storage capacity
    -   For N > 0: Must return N
    -   For N == 0: Must return 1 (to maintain valid storage)
-   Exception safety: Must not throw exceptions (marked noexcept)

`empty()`

-   Returns: true if size() == 0, otherwise false
    -   For Array<T, 0>: Must return true
-   Exception safety: Must not throw exceptions (marked noexcept)

### Implementation Notes

-   Storage: The array must use a fixed-size C-style array for storage
-   Zero-size handling: Special handling required for N == 0 case
-   Value initialization: All elements should be value-initialized
-   constexpr support: All methods should be marked constexpr where appropriate
-   Exception safety: Methods should provide basic exception safety guarantees

## Strict Constraints

-   All **names, types, and values** must match the reference
    implementation exactly.
-   Do not introduce extra symbols.
-   Do not modify the interface.
-   Avoid unrelated code.

Failure to comply may result in:

-   ABI incompatibility\
-   Linker errors\
-   Automated test failures

## Example Usage

```cpp
import mySTL.array;
#include <iostream>

int main() {
    // Basic array usage
    mySTL::Array<int, 5> arr;
    arr[0] = 42;
    arr[1] = 13;
    
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n";
    std::cout << "Empty: " << std::boolalpha << arr.empty() << "\n";
    
    // Bounds-checked access
    try {
        std::cout << "Element at index 0: " << arr.at(0) << "\n";
        std::cout << "Element at index 10: " << arr.at(10) << "\n"; // Throws
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    
    // Zero-sized array
    mySTL::Array<double, 0> emptyArr;
    std::cout << "Zero-sized array size: " << emptyArr.size() << "\n";
    std::cout << "Zero-sized array capacity: " << emptyArr.capacity() << "\n";
    std::cout << "Zero-sized array empty: " << emptyArr.empty() << "\n";
    
    return 0;
}
```

### Expected Output

```text
Size: 5
Capacity: 5
Empty: false
Element at index 0: 42
Caught exception: Index out of range
Zero-sized array size: 0
Zero-sized array capacity: 1
Zero-sized array empty: true
```

## Run Unit Tests

You can run unit tests on your code using the following command:\
`xmake f -m release`\
`xmake run chapter1_tests`\
You can also run unit tests on the reference code to compare it with your implementation:\
`xmake f -m debug`\
`xmake run chapter1_tests`