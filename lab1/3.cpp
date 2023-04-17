/*
  3. Escriba una función template para encontrar un valor en un array. 
  Pruebe la función con dos arrays de tipo int y char.
*/

#include <iostream>

using namespace std;

template <typename T, int N>
void buscar(T (&array)[N])
{
  T buscar;
  int flag = 0;
  cout << "Buscar: " << endl;
  cin >> buscar;

  for (int i = 0; i < N; i++)
  {
    if (buscar == array[i])
    {
      cout << "Si esta en el arreglo" << endl;
      flag = 1;
      break;
    }
  }
  if (flag == 0)
  {
    cout << "No esta en el arreglo" << endl;
  }
}

int main()
{
  int arr1[4] = {7, 2, 1, 4};
  char arr2[4] = {'a', 'b', 'A', 'g'};

  buscar(arr1);
  buscar(arr2);
  return 0;
}