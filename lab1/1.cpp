/*
  1. Escriba una función template para encontrar el índice del elemento más pequeño de un array de cualquier tipo. Pruebe la función con tres 
  arrays de tipo int, double y char. Entonces imprima el valor del 
  elemento más pequeño
  */

#include <iostream>

using namespace std;

// solucion recursiva
template <typename T, int N>
T calcularMenorR(T (&array)[N], T menor, int i)
{
  if (i < N)
    return menor;
  if (menor > array[i])
    menor = array[i];
  return calcularMenorR(array, menor, i++);
}

template <typename T, int N>
T calcularMenorR(T (&array)[N])
{
  return calcularMenorR(array, array[0],0);
}

// solucion iterativa
template <typename T, int N>
T calcularMenor(T (&array)[N])
{
  T menor = array[0];
  for (int i = 0; i < N; i++)
  {
    if (menor > array[i])
      menor = array[i];
  }
  return menor;
}

int main()
{
  int arr1[4] = {7, 2, 1, 4};
  double arr2[4] = {7.5, 6.1, 4.6, 1.3};
  char arr3[4] = {'a', 'b', 'A', 'g'};
  cout << "Solucion recursiva: " << endl;
  cout << "El numero menor es: " << calcularMenor(arr1) << endl;
  cout << "El numero menor es: " << calcularMenor(arr2) << endl;
  cout << "El numero menor es: " << calcularMenor(arr3) << endl << endl;
  cout << "Solucion iterativa: " << endl;
  cout << "El numero menor es: " << calcularMenor(arr1) << endl;
  cout << "El numero menor es: " << calcularMenor(arr2) << endl;
  cout << "El numero menor es: " << calcularMenor(arr3) << endl;
  return 0;
}