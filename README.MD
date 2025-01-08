# Multi-File Obfuscator

## C-Based Obfuscator 
2.1 Overview
The C code is split into multiple files:

  check_terminal.c

  (Optional example) Checks if Git Bash (or another terminal with PowerShell support) is installed on Windows.
  If missing, tries to download/install.
 You can remove or tailor this as needed.
 main_controller.c

   The main entry point for the C obfuscator.
  Presents a menu for Python, C++, or C# obfuscation.
   Reads user code from stdin, calls the appropriate function, and prints the obfuscated output.
  obfuscate_python.c

  Contains functions that “obfuscate” Python code (via line-by-line transformations, shuffling, base64, etc.).
 obfuscate_cpp_csharp.c

  Contains similar transformations for C++ and C# code.
  obfuscate_utils.h

   Shared function prototypes (e.g., for string manipulation, helper routines).
   Example usage flow:

  User runs the compiled executable (main_controller.exe on Windows or ./main_controller on Unix).
  Menu appears asking which language to obfuscate (1=Python, 2=C++, 3=C#).
  User pastes code and signals end of input (Ctrl+D on Unix/macOS, Ctrl+Z on Windows).
  Tool prints the obfuscated result.

  ## Ruby-Based Obfuscator

  3.1 Overview
 The Ruby side is similarly split into multiple files:

 r_main.rb

  The main script that presents a menu (Python, C++, C#) and reads user code.
  rb_obf_python.rb

  Handles the Python obfuscation logic.
  rb_obf_cpp.rb

  Handles the C++ obfuscation logic.
  rb_obf_csharp.rb

  Handles the C# obfuscation logic.
  rb_utils.rb

  Shared helper functions (e.g., base64 encoding, string manipulation, random insertion).
  Just like the C version, you run r_main.rb, select a language, paste code, and get the obfuscated output.
