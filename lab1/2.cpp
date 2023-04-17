/*
  2. Si encontramos el elemento más pequeño en un array, podemos 
  ordenar un array usando el algoritmo selection sort. En este 
  algoritmo, encontramos el elemento más pequeño en el array y lo 
  intercambiamos con el primer elemento. Después encontramos el 
  elemento más pequeño de los elementos restantes y lo intercambiamos 
  con el segundo elemento. Continuamos hasta que el array esté 
  completamente ordenado. Escriba un programa que ordene tres arrays de 
  tipo int, double y char.
*/

#include <iostream>

using namespace std;

template <typename T, int N>
void imprimirArreglo(T (&array)[N])
{
  for (int i = 0; i < N; i++)
  {
    cout << array[i] << " ";
  }
}

template <typename T, int N>
void ordenarArray(T (&array)[N])
{
  T menor;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        menor = array[j + 1];
        array[j + 1] = array[j];
        array[j] = menor;
      }
    }
  }

  imprimirArreglo(array);
  cout << endl;
}

int main()
{
  int arr1[4] = {7, 2, 1, 4};
  double arr2[4] = {7.5, 6.1, 4.6, 1.3};
  char arr3[4] = {'a', 'b', 'A', 'g'};

  ordenarArray(arr1);
  ordenarArray(arr2);
  ordenarArray(arr3);
  return 0;
}