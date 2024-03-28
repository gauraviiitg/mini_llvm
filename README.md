# Memory Analysis LLVM Pass for Python Applications

## Overview
This project implements an LLVM Pass to analyze Python applications and determine the memory requirements for each basic block of the program. The pass calculates the memory usage by inspecting the alloca instructions within each basic block and determining the size of allocated types.

## LLVM Pass Design
The Memory Analysis Pass is designed to traverse through the LLVM IR representation of Python applications and analyze memory usage at the basic block level. It iterates over each basic block of a function, calculates the memory requirements, and prints the basic block ID along with the corresponding memory usage.

## Implementation Details
Pass Identification: The pass is identified by a static ID.
Run on Function: The runOnFunction method is called for each function in the LLVM IR. It iterates through the basic blocks of the function and calculates memory requirements for each.
Memory Calculation: Memory requirements are calculated by summing up the size of allocated types within each basic block. The calculateMemoryRequirements function handles this calculation.you can freely change it since its filld with comments to help.
Basic Block ID: Basic blocks are assigned unique IDs, allowing identification during analysis. The getBasicBlockID function manages this assignment.
Memory Analysis Code
The core logic of the memory analysis pass is implemented in the MemoryAnalysisPass class. Here's a brief overview of its components:

Header Inclusions: Necessary header files from the LLVM framework are included.
Namespace: The pass is defined within an anonymous namespace to prevent naming conflicts.
MemoryAnalysisPass Struct: Defines the LLVM pass as a subclass of FunctionPass.
runOnFunction Method: Implements the main logic of the pass. It iterates over basic blocks and calculates memory requirements.
calculateMemoryRequirements Method: Computes the memory usage of a basic block by inspecting alloca instructions.
getTypeSize Method: Determines the size of allocated types.
getBasicBlockID Method: Assigns a unique ID to each basic block.

## Instructions for Use (Linux:Debian)

To use the Memory Analysis LLVM Pass for Python applications, follow these steps:

### 1) Convert Python File to C using Cython: Assume that example.c file is the output of this step.

### 2) Install Clang and LLVM:
sudo apt-get update  
sudo apt-get install clang llvm

### 3) Compile the C Code to LLVM IR:
clang -S -emit-llvm example.c -o example.ll

### 4) Optimize the LLVM IR:
opt -O3 -S example.ll -o optimized_example.ll

### 5) Compile the LLVM Pass Code:
clang++ -c -fPIC MemoryAnalysisPass.cpp -o MemoryAnalysisPass.o llvm-config --cxxflags

### 6) Link the LLVM Pass to Create a Shared Library:
clang++ -shared -o MemoryAnalysisPass.so MemoryAnalysisPass.o llvm-config --ldflags

### 7) Run the LLVM Pass:   # may not work due to changes in the pass manager, skip to step 8 if "could not find pass" error occurs or [click here to learn more about the bug](https://groups.google.com/g/llvm-dev/c/kQYV9dCAfSg?pli=1)
opt -load ./MemoryAnalysisPass.so -memory-analysis-pass < optimized_example.ll > /dev/null

### 8) Run the LLVM Pass with Legacy Pass Manager Enabled:
opt -enable-new-pm=0 -load ./MemoryAnalysisPass.so -memory-analysis-pass < optimized_example.ll > /dev/null
## Troubleshooting

If you encounter any issues or have questions about the project, please don't hesitate to reach out for support. You can contact m via:

- GitHub Issues: [Link to GitHub Issues page](https://github.com/gauraviiitg/mini_llvm/issues)

Please provide as much detail as possible when reporting problems, including error messages, screenshots, and steps to reproduce the issue.
  
