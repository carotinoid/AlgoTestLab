


---

## Project Overview
This project aims to provide a simple, user-friendly environment for learning and implementing algorithms and data structures. It includes an automated testing system based on ctest to verify the correctness of implementations. The initial focus is on implementing algorithms from the POSTECH CSED331 (Algorithms) course.

### Key Features:
- Environment for learning and implementing algorithms and data structures
- Automated testing system based on GoogleTest
- Support for user-defined test cases
- Initial implementation of POSTECH CSED331 algorithms

## Project Structure
```txt
AlgoTestLab
├── CMakeLists.txt              - CMake
├── README.md                   - README
├── docs/                       - Guildline to start this project
├── include/                    - Headerfiles(.hh) directory
│   ├── divide_and_conquer/     - subdir
│   │   └── ...
│   └── ...
├── src/                        - Sourcefiles(.cc) directory
│   ├── divide_and_conquer/     - subdir
│   │   └── ...
│   └── ...
└── tests/                      - Tests
    ├── t_....cc
    └── ...
```

## Getting Started

### Requirements

Cmake, g++(--std=c++2a), git, clang-format(optional)

### Quick Start

Clone thie repository.
```bash
git clone https://github.com/carotinoid/AlgoTestLab
```

To set up your build directory.
```bash
mkdir -p <path/to/project>/build
cd <path/to/project>/build
cmake ..
```

To build:
```bash
make
```

You can use `-j`option to build in parrallel, e.g.,
```bash
make -j`nproc`
```

Follow the instructions in the docs directory to write your code, and evaluate it with the `make check_test_NAME` command.  
*Note. don't forget to build with `make` to apply your codes!*

### Optional

If clang-format is installed in your system, you can use `make format` command.
