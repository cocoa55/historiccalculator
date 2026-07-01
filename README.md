# Historic Calculator

A command-line calculator written in C++ that lets you chain calculations together by using the previous answer as the first number in the next equation. Useful for multi-step calculations without having to re-enter intermediate results.

## Features

- Supports addition, subtraction, multiplication, and division
- Input validation: rejects invalid operators and re-prompts until valid input is given
- Division by zero protection: detects and re-prompts before crashing
- After each calculation, choose to:
  - Calculate again using the previous answer as the first number
  - Calculate again with a new first number
  - Exit

## How to Compile

```bash
g++ main.cpp -o calculator
./calculator
```

## Example Usage

```
Enter the first number: 10
Enter operator (+, -, *, /): *
Enter the second number: 5
Answer: 50

Do you want to calculate again? (y/n)
Response: y
Do you want to use the answer as the first number? (y/n)
Response: y
Enter operator (+, -, *, /): +
Enter the second number: 25
Answer: 75
```

## Built With

- C++17
- Standard library only, no external dependencies

---

*First project built after 1 month of programming 
