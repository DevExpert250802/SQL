// extraction of digits

void extractDigits(int n) {
    if (n < 0) {
        n = -n; // Make n positive for easier digit extraction
    }
    while (n > 0) {
        int lastDigit = n % 10;
  //   Print / store / count  the digit
        n = n / 10;
    }
}
