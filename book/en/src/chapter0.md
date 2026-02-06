<div align=right>

  🌎 [中文] | [English]
</div>

[中文]: ../chapter0.html
[English]: ./chapter0.html

# Chapter 0 --- Global Module and Meta Information

In this chapter, you will bootstrap the **MySTL** library by
implementing its global module entry point and a meta information
module. These components establish the foundation of a modular C++23
library and define the public interface that other modules and user code
will rely on.

⚠️ **Important:**
All tasks in this chapter must follow the specified interfaces
**exactly**. Module names, exported symbols, and structure must not be
altered. Any deviation may cause module linkage failures or test
incompatibilities.

## Directory Structure

Organize your files as follows:
```text
mystl/
└── chapter0/
    ├── global.cppm
    └── metaInfo/
        └── metaInfo.cppm
```

# 1. Global Module

## Objective

Implement the **global module** for MySTL.\
This module serves as the primary entry point of the library and
aggregates public-facing modules for convenient importing.

After implementation, users should be able to write:

``` cpp
import mySTL;
```

to access exported functionality.

## Requirements

-   Create a C++23 module named: `mySTL`
-   Re-export the meta information module named: `mySTL.metaInfo`

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

``` cpp
import mySTL;
import mySTL.metaInfo;

// Meta information is now accessible.
```

# 2. Meta Information Module

## Objective

Implement the **meta information module** that describes the library.\
Providing structured metadata is a common practice in production-grade
libraries and helps users quickly identify the library version and
purpose.

## Requirements

Create a module named:

    mySTL.metaInfo

Follow the reference interface precisely and provide the following
metadata.

### Library Name

Accessible via:

``` cpp
mySTL::metaInfo::name
```

Expected value:

    MySTL

### Version Information

Accessible via:

``` cpp
mySTL::metaInfo::version.major
mySTL::metaInfo::version.minor
mySTL::metaInfo::version.patch
```

Expected version:

    0.1.0

### Description

Accessible via:

``` cpp
mySTL::metaInfo::description
```

Expected value:

    My Standard Template Library

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

``` cpp
import mySTL.metaInfo;
#include <iostream>

int main() {
    std::cout << mySTL::metaInfo::name << "\n";

    std::cout << mySTL::metaInfo::version.major << "."
              << mySTL::metaInfo::version.minor << "."
              << mySTL::metaInfo::version.patch << "\n";

    std::cout << mySTL::metaInfo::description << "\n";

    return 0;
}
```

### Expected Output
```text
MySTL
0.1.0
My Standard Template Library
```

## Run Unit Tests

You can run unit tests on your code using the following command:\
`xmake f -m release`\
`xmake run chapter0_tests`\
You can also run unit tests on the reference code to compare it with your implementation:\
`xmake f -m debug`\
`xmake run chapter0_tests`