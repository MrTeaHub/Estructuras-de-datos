#include <iostream>

using namespace std;

int sumatoria(int n)
{
  if (n <= 0)
  {
    return 0;
  }
  return n + sumatoria(n - 1);
}

int factorial(int n)
{
  if (n <= 0)
  {
    return 1;
  }
  return n * factorial(n - 1);
}

string reverse(string str)
{
  if (str.length() <= 1)
  {
    return str;
  }
  else
  {
    return reverse(str.substr(1, str.length() - 1)) + str.substr(0, 1);
  }
}

bool esPalindromo(string str)
{
  if (str.length() <= 1)
    return true;
  else if (str[0] != str[str.length() - 1])
    return false;
  return esPalindromo(str.substr(1, str.length() - 2));
}

// funciones con helper

int sumHelper(int n, int result)
{
  if (n == 0)
    return result;
  return sumHelper(n - 1, n + result);
}

int sumHelper(int n)
{
  return sumHelper(n, 0);
}

bool esPalindromoHelper(string &str, int left, int right)
{
  if (right <= left)
    return true;
  else if (str[left] != str[right])
    return false;
  return esPalindromoHelper(str, left + 1, right - 1);
}

bool esPalindromoHelper(string &str)
{
  return esPalindromoHelper(str, 0, str.length() - 1);
}

int main()
{
  cout << sumatoria(7);
  return 0;
}
