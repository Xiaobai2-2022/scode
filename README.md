# Scode Tools

---

## Scode Compiler
The compiler software, Scode is designed to compile to RISC-V code.

---

## Scode Assembler
#### The Scode Assembler assembles code from RISC-V assembly-like code into RISV-V binary code.
An example of this code would be:
```
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
SVM is a state machine, where each state consists of three parts:
1. Base Registers: SVM is designed to have 32 base registers, which are numbered 0 to 31; each register serves a different purpose.
2. Memories: SVM is designed to have $2^{34}$ bits of memory. To optimize the virtual machine (not allocating the entire memory at once), the memory is represented by a doubly-linked list with a hashmap to all the instructions for jump use.
3. State Machine: SVM will run state to state; each instruction will have an input state and an output state, where we can print the state machines to see how the program is run.

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
  - [ ] State (`state.hpp`)
- [x] Miscellaneous
  - [x] Utilities (`utility.hpp`)
  - [x] Testing (`test_client.cpp`)
  - [x] Basic Storage (`word.hpp`)
  - [x] Error Indicators (`error_output.hpp`)

Note that the testing `test_client.cpp` is the only non-header file and contains main, since `test_interface.hpp` is used to include all header used in the project.
