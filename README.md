# 🗜️ Huffman File Compression (C++)

A C++ implementation of **Huffman Encoding and Decoding** — a classic **Greedy Algorithm** used for **lossless data compression**.  
This project demonstrates how text can be efficiently encoded into binary form to save storage space and later decoded back to its original form without any loss.

---

## 🚀 Features

- Builds a **Huffman Tree** using character frequency  
- Generates **prefix-free binary codes** for each character  
- Encodes and decodes any given text input  
- Achieves up to **70% compression** on repetitive data  
- Uses **priority queue (min-heap)** and **recursion** for efficient processing  

---

## 🧩 Algorithm Overview

1. Count frequency of each character in the input string or file  
2. Insert each character node into a **min-heap** (priority queue)  
3. Repeatedly extract two smallest nodes and merge them until one root node remains (Huffman Tree)  
4. Traverse the tree to assign binary codes  
   - Left edge → `0`  
   - Right edge → `1`  
5. Encode the text using the generated binary codes  
6. Decode the binary back into the original text  

## Example
text=abacabad
Min-heap of nodes:
[a:4, b:2, c:1, d:1]
After heapify:
[c:1, d:1, b:2, a:4]
         
          [abcd:8]
        /         \
     [a:4]       [bcd:4]
                /       \
             [b:2]     [cd:2]
                       /     \
                    [c:1]   [d:1]

Assign Codes by Traversing
From root:
a → 0
b → 10
c → 110
d → 111
Encoding "abacabad":

Original: "a b a c a b a d"
Binary: 0 10 0 110 0 10 0 111
Compressed: 0100110001000111
