bool isPrime(int num) {
  // Numbers less than 1 cannot be prime
  if (num <= 1) return false;

  // 2 and 3 are known to be prime
  if (num <= 3) return true;

  // To iterate in increments of 6, ensure the number is not divisible by 2 or 3
  if (num % 2 == 0 || num % 3 == 0) return false;
  
  // Loop until the greatest common factor
  for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) return false;
  }

  // The number is prime if an integer quotient could not be attained above
  return true;
}

int main()
{
  isPrime(113);
}