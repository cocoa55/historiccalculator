#include <cstdlib>

#include <iostream>
#include <limits>
#include <string_view>

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction() {
  if (!std::cin) {

    if (std::cin.eof()) {
      std::exit(0);
    }

    std::cin.clear();
    ignoreLine();
    return true;
  }
  return false;
}

char enterOp() {
  char op{};
  while (true) {
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    switch (op) {
    case '+':
    case '-':
    case '*':
    case '/':
      return op;
    }
  }
}

int getNumber(std::string_view order) {

  while (true) {

    int input{};
    std::cout << "Enter the " << order << " number: ";
    std::cin >> input;

    if (clearFailedExtraction()) {
      std::cout << "Error: Failed extraction. (Enter a valid integer, followed "
                   "by ENTER)\n";
      continue;
    }
    return input;
  }
}

int calculate(int first) {

  char op{enterOp()};
  int second{getNumber("second")};

  switch (op) {
  case '+':
    std::cout << "Answer: " << first + second << '\n';
    return first + second;
  case '-':
    std::cout << "Answer: " << first - second << '\n';
    return first - second;
  case '/':
    while (second == 0) {
      std::cout << "Error: You cannot divide by zero try again.\n";
      second = getNumber("second");
    }
    std::cout << "Answer: " << first / second << '\n';
    return first / second;
  case '*':
    std::cout << "Answer: " << first * second << '\n';
    return first * second;
  }
  return 0;
}

bool calculateAgain() {
  char answer{};
  std::cout << "Do you want to calculate again? (y/n)\n" << "Response: ";
  while (true) {
    std::cin >> answer;
    switch (answer) {
    case 'y':
      return true;
    case 'n':
      return false;
    }
  }
}

int main() {

  int first{getNumber("first")}; // initialize our first number

  int result{calculate(first)}; // runs first calculate, and stores the result
                                // of the first calculate call

  while (bool playAgain{calculateAgain()}) {

    if (playAgain) {
      std::cout << "Do you want to use the answer as the first number? (y/n)\n"
                << "Response: ";
      char response{};
      std::cin >> response;
      switch (response) {
      case 'y':
        result = calculate(result);
        break;
      case 'n':
        int firstsecond{getNumber("first")};
        result = calculate(firstsecond);
        break;
      }
    }
  }

  std::cout << "come back another time.";
  return 0;
}
