# CS-210 Portfolio – Corner Grocer Item Frequency Analyzer

## Project Summary
This C++ program analyzes grocery purchase data from a text file (`CS210_Project_Three_Input_File.txt`). It counts the frequency of each item purchased and provides an interactive menu allowing the user to:
- Search for a specific item’s frequency
- Print all items with their frequencies
- Display a visual histogram of frequencies
- Exit the program

It solves the real-world problem of quickly understanding purchasing trends and generating reports for a corner grocery store.

## What I Did Particularly Well
- Designed a clean, object-oriented solution using a `GroceryTracker` class.
- Implemented robust file handling with multiple fallback paths and clear error messages.
- Used `std::map` for efficient item tracking and automatic sorting.
- Added professional menu system with input validation and exception handling.
- Wrote clear, well-commented code with consistent formatting.

## Areas for Enhancement
- Could add case-insensitive searching (currently case-sensitive).
- Could implement data validation to handle malformed input lines.
- Could add the ability to update frequencies during runtime or save new purchases.
- Could create a simple GUI instead of console-only.

These improvements would make the program more user-friendly, robust against bad data, and easier to extend in the future.

## Most Challenging Parts & How I Overcame Them
The most challenging part was reliably loading the input file regardless of where the program is run from (different IDEs and folder structures).  
I overcame this by creating a vector of possible file paths and trying each one, plus using proper exception handling with `try/catch`.

**Tools & resources added to my support network:**
- cppreference.com
- LearnCpp.com
- Visual Studio Debugger
- Stack Overflow (for specific C++ file I/O questions)

## Transferable Skills
- File I/O and data processing
- Using STL containers (`std::map`, `std::vector`)
- Building interactive menu-driven programs
- Exception handling and defensive programming
- Writing modular, maintainable C++ code

These skills will be very useful in future courses (especially data structures, algorithms, and software engineering projects).

## How I Made This Program Maintainable, Readable, and Adaptable
- Used meaningful class and function names (`loadDataFromFile`, `printHistogram`, etc.).
- Broke functionality into small, single-responsibility methods.
- Added detailed comments at the top of the file and throughout complex sections.
- Separated concerns (data loading, menu logic, output formatting).
- The class design makes it easy to add new features (e.g., new report types) without rewriting core logic.

---

**Repository Link:** https://github.com/My-Studioe/CS-210-Portfolio

SNHU CS-210 Programming Languages – Rolfe H. Green
