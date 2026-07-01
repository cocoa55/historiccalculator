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
      std::cerr << "\nEOF entered, exiting program.";
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
    std::cout << '\n';
  }
}

int getNumber(std::string_view order) {

  while (true) {
    int input{};
    std::cout << "Enter the " << order << " number: ";
    std::cin >> input;

    if (clearFailedExtraction()) {
      std::cerr << "Error: Failed extraction. (Enter a valid integer, followed "
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
      std::cerr << "Error: You cannot divide by zero try again.\n";
      second = getNumber("second");
    }
    std::cout << "Answer: " << static_cast<double>(first) / second << '\n';
    return first / second;
  case '*':
    std::cout << "Answer: " << first * second << '\n';
    return first * second;
  }
  return 0;
}

bool calculateAgain() {
  char answer{};
  while (true) {
    std::cout << "Do you want to calculate again? (y/n)" << "\nResponse: ";

    std::cin >> answer;
    ignoreLine();
    switch (answer) {
    case 'y':
      return true;
    case 'n':
      return false;
    default:
      std::cerr << "Error: Enter y or n.\n";
      continue;
    }
  }
}

int printWithPast(int result) {
  char response{};
  while (true) {
    std::cout << "Do you want to use the answer as the first number? (y/n)\n"
              << "Response: ";
    std::cin >> response;
    ignoreLine();
    switch (response) {
    case 'y':
      result = calculate(result);
      break;
    case 'n': {
      int firstsecond{getNumber("first")};
      result = calculate(firstsecond);
      break;
    }
    default:
      std::cerr << "Error: Enter Y or N. \n";
      continue;
    }
    return result;
  }
}

int main() {

  int first{getNumber("first")}; // initialize our first number

  int result{calculate(first)}; // runs first calculate, and stores the result
                                // of the first calculate call

  while (bool goAgain{calculateAgain()}) {

    result = printWithPast(result);
  }

  std::cout << "come back another time.";
  return 0;
}
