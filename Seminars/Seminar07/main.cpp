#include <iostream>

unsigned int toBinary(unsigned int n) {
  unsigned int binary = 0, position = 1;
  while (n > 0) {
    binary += position * (n % 2);
    position *= 10;
    n /= 2;
  }
  return binary;
}

unsigned int toDecimal(unsigned int n) {
  unsigned int decimal = 0, position = 1;
  while (n > 0) {
    decimal += (n % 10) * position;
    position *= 2;
    n /= 10;
  }
  return decimal;
}

unsigned const MAX_SIZE = 32;

unsigned digit(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;
  else
    return 0;
}

unsigned kToDecimal(char const from[], unsigned k, int size) {
  unsigned decimal = 0, position = 1;
  int idx = size-1;
  while (idx >= 0) {
    decimal += digit(from[idx]) * position;
    position *= k;
    idx--;
  }
  return decimal;
}

char symbol(unsigned n) {
  if (n >= 0 && n <= 9)
    return n + '0';
  else if (n <= 15)
    return n + 'A' - 10;
  else
    return '\0';
}

void decimalToS(unsigned n, char to[], unsigned s, int size) {
  int idx = size-1;
  while (n) {
    to[idx] = symbol(n % s);
    n /= s;
    idx--;
  }
}

void fromKtoS(char const from[], char to[], unsigned k, unsigned s, unsigned size) {
  unsigned decimal = kToDecimal(from, k, size);
  decimalToS(decimal, to, s, size);
}


void print(char const str[], unsigned size) {
  unsigned idx = 0;
  while (idx < size)
    std::cout << str[idx++];
}

int main() {

  std::cout << toBinary(1023) << std::endl;
  std::cout << toBinary(1024) << std::endl;

  std::cout << toBinary(27) << std::endl;
  std::cout << toDecimal(11011) << std::endl;

  std::cout << toBinary(toDecimal(11011)) << std::endl;

  char from[MAX_SIZE]{};
  char to[MAX_SIZE]{};

  unsigned k = 2;
  unsigned s = 16;

  // 00..0010001
  from[MAX_SIZE-1] = '1';
  from[MAX_SIZE-2] = '1';
  from[MAX_SIZE-3] = '0';
  from[MAX_SIZE-4] = '1';
  from[MAX_SIZE-5] = '1';

  std::cout << "Convert ";
  print(from, MAX_SIZE);
  std::cout << " from base " << k <<  " to base " << s << ": ";

  fromKtoS(from, to, k, s, MAX_SIZE);

  print(to, MAX_SIZE);
  std::cout << std::endl;

  return 0;
}
