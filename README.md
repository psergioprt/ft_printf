# 🖨️ ft_printf

**ft_printf** is a custom implementation of the standard C `printf` function, developed as part of the 42 curriculum.  
It supports formatted output with various conversion specifiers and flags.

---

## 🧩 Project Overview

- Recreates the behavior of the standard `printf` function for formatted output.
- Supports conversion specifiers like `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, and `%%`.
- Handles flags such as width, precision, left/right alignment, and zero-padding.
- Manages variable argument lists using `stdarg.h`.
- Focuses on robustness and efficiency in formatting output.

---

## ⚙️ Compilation

Compile using the provided Makefile:

```bash
make

## ▶️ Usage

Include the compiled library in your C projects and use ft_printf similarly to the standard printf:

ft_printf("Hello %s! Number: %d\n", "world", 42);

Outputs:

Hello world! Number: 42

📌 Learning Outcomes

    Mastery of variadic functions and va_list handling.

    Deep understanding of string formatting and output conversion.

    Implementation of parsing logic for format specifiers and flags.

    Enhanced skills in memory and buffer management in C.
