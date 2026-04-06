
![PRINTF(1)](https://user-images.githubusercontent.com/97880395/178113082-7681e4c4-4cc0-4d03-b386-b4e50f6c8469.png)


This README file have the fully description of our first group project in holberton-school, the project is about the implementation of printf function, it means we gonna write our own printf function. Below you'll find how printf works, and how to design the proper formatting specification for any occasion Prototype of printf function int _printf(const char *format, ...); Returns: the number of characters printed (excluding the null byte used to end output to strings



## Usage && Examples 
Include main.h Call _printf, passing a formatted string with any format specifiers and optional arguments Upon success, it writes desired output to stdout Upon error, it returns -1 If NULL is passed in as a string argument, it prints (null) Format Specifier.

To use the _printf function you simply need to compile all files .c including the header holberton.h with a main function.

```c
'#include "main.h"

int main(void) { _printf("let's print hello world!");

return (0); }
```
Compilation:

```sh
$ gcc *.c -o
```
Output: 
```sh
let's print hello world!
```
You can do much more, by combining specifiers like string or integer.

## Files
Below a list of the used files during project:

- [_printf.c] - produces output according to a format.
- [get_printf.c] - containing functions for specifiers _putchar.c.
- [function.c] - containing function that writes a char to stdout.
- [main.h] - header file with function prototypes and struct for specifiers.


## Authors
**Mahdi Bani** 
+ (https://github.com/Mahdi3Bani)

**Malek Mayeh** 
+  (https://github.com/malekje)

**Med Ali Krifa**
+  (https://github.com/MedAliKrifa)