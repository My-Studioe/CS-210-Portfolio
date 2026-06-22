# CS-210 Portfolio – Grocer Project

## Project Summary
This project simulates a grocery store inventory and checkout system. It reads item data from a text file, allows users to add items to a virtual cart, calculates totals with tax, and generates a receipt. The program demonstrates file I/O, data structures, user input validation, and modular code design.

## What I Did Particularly Well
- Clean, consistent code style and meaningful variable/function names
- Strong input validation and error handling (especially file opening)
- Well-organized modular structure with separate functions for different tasks
- Clear, professional comments throughout the code

## Areas for Enhancement
- Could implement a more efficient data structure (e.g., `std::unordered_map` instead of `std::vector` for lookups)
- Add unit tests for critical functions
- Improve receipt formatting and make it more professional
- Add configuration file support for tax rates and store information

These improvements would make the code faster, more maintainable, and easier to extend.

## Most Challenging Parts
The most difficult part was properly handling file I/O errors and ensuring the program gracefully exits or gives useful feedback when files are missing or corrupted. I overcame this by carefully researching C++ exception handling and using defensive programming techniques (checking if files opened successfully before proceeding).

## Transferable Skills
- Reading and processing data from external files
- Breaking large problems into smaller, reusable functions
- Input validation and error handling
- Writing clean, documented, maintainable code

These skills are directly applicable to almost any future C++ or software development project.

## How I Made the Program Maintainable, Readable, and Adaptable
- Used consistent naming conventions
- Added detailed comments explaining the purpose of each function and major code blocks
- Kept functions short and single-purpose
- Used constants for magic numbers
- Separated concerns (data loading, menu handling, calculations, output)

## Final Thoughts
This project was a great capstone for the course. It forced me to combine everything I learned about C++ into one cohesive program. I’m proud of how it turned out and feel much more confident in my programming abilities.
