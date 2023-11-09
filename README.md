# Scode Tools

---

## Scode Compiler
The compiler software, Scode is designed to compile to RISC-V code.

---

## Scode Assembler
#### The Scode Assembler assembles code from RISC-V assembly-like code into RISV-V binary code.
An example of this code would be:
```s
Scode Assembly 1: For test purpose only; Valid Case label and comments
# for loop using x16 as i, x17 as n
# initialize i to 0
addi 16 0 0
# initialize n to 10
addi 17 0 10
# define start of the loop
define label_start
# if i >= n jump to end of the loop
bge 16 17 label_end
# increment i by 1
addi 16 16 1
# jump to start of the loop
jal 1 label_start
# define the end of the loop
define label_end
# terminate the program
end
```

---

## Scode Virtual Machine (SVM)
#### The SVM is a virtual machine designated for executing binary files generated by the assembler.
##### SVM structure
SVM is a state machine, where each state consists of four parts:
1. Base Registers: SVM is designed to have 32 base registers, which are numbered 0 to 31; each register serves a different purpose.
2. Memories: SVM is designed to have $2^{34}$ bits of memory. To optimize the virtual machine (not allocating the entire memory at once), the memory is represented by a doubly-linked list with a hashmap to all the instructions for jump use.
3. State Machine: SVM will run state to state; each instruction will have an input state and an output state, where we can print the state machines to see how the program is run.
4. IO Ports: SVM will support IO instructions as an extension; each state will accept input and output from those ports.

---
## Scode Files
This section introduces the purpose of each file that exists in the repository, as well as the function that has already been implemented.

- [ ] Scode Compiler
- [x] Scode Assembler
  - [x] Code Interpreter (`construct_risc_v.hpp`)
  - [x] Binary Code Generator (`generate_code.hpp`)
- [ ] Scode Virtual Machine
  - [x] Basic Memory Cell (`memory_cell.hpp`)
  - [x] Base Registers (`reg.hpp`)
  - [x] Memories (`memory.hpp`)
  - [x] Ports (`ports.hpp`)
  - [ ] State Structure (`state.hpp`)
  - [ ] State Generator (`generate_state.hpp`)
- [x] Miscellaneous
  - [x] Utilities (`utility.hpp`)
  - [x] Testing (`test_client.cpp`)
  - [x] Basic Storage (`word.hpp`)
  - [x] Error Indicators (`error_output.hpp`)

Note that the testing `test_client.cpp` is the only non-header file and contains main, since `test_interface.hpp` is used to include all header used in the project.

---
## Scode Testing (STests)
#### STests are designed for suite testing for Scode/RISC-V/C++ development.
##### Prerequisites
1. STests are shell scripts, meaning that they are designed to run under Linux environments.[^1]
2. STests require Makefile; thus, Makefile must be installed in your Linux distribution.
3. STests test for memory leaks in C++ with Valgrind; thus, Valgrind must be installed in your Linux distribution.

[^1]: Note that the development of Scode is down under WSL2 (Windows Subsystem for Linux) with Ubuntu.

##### How to use STests
In order to use STests, you must have your folders layout as follows:
```bash
.
├── bin
├── scripts
│   ├── makefile
│   └── run_test.sh
├── src
└── tests
    ├── files
    ├── inputs
    ├── outputs-actual
    ├── outputs-expected
    └── valgrind-actual
```

The commands for running STests are `bash run_test.sh` or simply `./run_test.sh`. However, you must give permission for using `./`. The command to give permission is `chmod +x run_test.sh`. Note that you have to `cd` into `scripts` to test.

To run STests, you would need to put all your source files (C++) into the `src` folder. As well as your Makefile into the `scripts` folder.

You have the option to change the Makefile for your program to compile different files. The default C++ version is C++11 for the tests; you also have the option to change that in the Makefile.

The compiled files, including `*.o`, '*.d', and the executable file, will be generated automatically into the `bin` folder. These files will be deleted automatically after tests are completed.

It is optional to use automatic test suites where you put `*.in` files in the `tests/inputs` folder, as well as the `*.out` files in the `tests/outputs-expected` folder.

If you use the automatic test suites, the result `*.out` file will be generated in the `tests/outputs-actual` folder. `*.val` files will be generated in the `tests/valgrind-actual` folder. These files are generated for you to verify program correctness and test for memory leaks, respectively.

Note that the script would compare the difference between files in the `tests/outputs-expected` folder and the `tests/outputs-actual` folder. Valgrind errors will also be explicitly displayed so that it is helpful to debug with STests.
