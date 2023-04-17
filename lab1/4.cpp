/*
  4. Defina una función para revertir el orden de los elementos de un 
  array de cualquier tipo. Pruebe el programa con un array de int, 
  double, char y string. Use una función auxiliar para intercambiar dos 
  elementos cualesquiera. Use una función auxiliar para imprimir el 
  contenido de un arreglo antes y después del intercambio.
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
void revertir(T (&array)[N])
{
  T aux[N];
  for (int i = 0; i < N; i++)
  {
    aux[i] = array[N - i - 1];
  }
  cout << "Original: " << endl;
  imprimirArreglo(array);
  cout << endl
       << "Revertido: " << endl;
  imprimirArreglo(aux);
  cout << endl << endl;
}

int main()
{
  int arr1[4] = {7, 2, 1, 4};
  double arr2[4] = {7.5, 6.1, 4.6, 1.3};
  char arr3[4] = {'a', 'b', 'A', 'g'};
  string arr4[4] = {"jesus", "camilo", "jack", "juan"};

  revertir(arr1);
  revertir(arr2);
  revertir(arr3);
  revertir(arr4);
  return 0;
}