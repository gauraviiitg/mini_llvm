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

##Instructions for Use

To use the Memory Analysis LLVM Pass for Python applications, follow these steps:

### Convert Python File to C using Cython: Assume that example.c file is the output of this step.

### Install Clang and LLVM:
sudo apt-get update
sudo apt-get install clang llvm

### Compile the C Code to LLVM IR:
clang -S -emit-llvm example.c -o example.ll

### Optimize the LLVM IR:
opt -O3 -S example.ll -o optimized_example.ll

### Compile the LLVM Pass Code:
clang++ -c -fPIC MemoryAnalysisPass.cpp -o MemoryAnalysisPass.o llvm-config --cxxflags

### Link the LLVM Pass to Create a Shared Library:
clang++ -shared -o MemoryAnalysisPass.so MemoryAnalysisPass.o llvm-config --ldflags

### Run the LLVM Pass:   # may not work due to changes in the pass manager: https://groups.google.com/g/llvm-dev/c/kQYV9dCAfSg?pli=1
opt -load ./MemoryAnalysisPass.so -memory-analysis-pass < example.ll > /dev/null

### Run the LLVM Pass with Legacy Pass Manager Enabled:
opt -enable-new-pm=0 -load ./MemoryAnalysisPass.so -memory-analysis-pass < example.ll > /dev/null
