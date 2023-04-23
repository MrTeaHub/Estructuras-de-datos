/*
En un acertijo el problema es encontrar la mayor cantidad de chocolates 
que se pueda comer, siguiendo las recomendaciones:
a. dinero: Dinero que se tiene para comprar chocolates.
b. precio: Precio de un chocolate.
c. envoltura: Número de envolturas a devolver para recibir un chocolate extra.
Se puede suponer que todos los valores dados son números enteros positivos y 
mayores que 1.

Input: dinero = 16, precio = 2, envoltura = 2
Output: 15
Si el precio de un chocolate es 2. Puede comprar 8 chocolates con
16 pesos. Puede devolver esas 8 envolturas y obtener 4 chocolates
más. Luego puede devolver 4 envolturas y obtener 2 chocolates más.
Finalmente puede devolver 2 envolturas para obtener 1 chocolate más.

Input: dinero = 15, precio = 1, envoltura = 3
Output: 22
Se pueden comprar 15 chocolates. Se devuelven 15 envolturas y se
reciben 5 chocolates más. Se devuelve 3 envolturas, se recibe 1
chocolate (se guarda 2 envolturas pendientes). Ahora se tiene 3
envolturas. Devuelve 3 y consigue 1 chocolate más.
Chocolates totales = 15 + 5 + 1 + 1

Un método consiste en contar continuamente la cantidad de chocolates devolviendo
las envolturas hasta que las envolturas que quedan no alcancen para canjear un
chocolate. Probar el programa con 10 entradas diferentes y mostrar los resultados
*/

#include <iostream>
#include <vector>

using namespace std;

int acertijo_chocolates(int precio_envolturas, int envolturas_a_devolver, int posicion, vector<int> &chocolates)
{
  if (envolturas_a_devolver < precio_envolturas)
  {
    int chocolates_comer = 0;
    for (int j = 0; j < chocolates.size(); j++)
    {
      chocolates_comer += chocolates[j];
    }
    return chocolates_comer;
  }
  else
  {
    chocolates.push_back(envolturas_a_devolver / precio_envolturas);
    envolturas_a_devolver = (chocolates[posicion - 1] / precio_envolturas) + (envolturas_a_devolver % precio_envolturas);
  }
  return acertijo_chocolates(precio_envolturas, envolturas_a_devolver, posicion + 1, chocolates);
}

int acertijo_chocolates(int dinero, int precio_chocolate, int precio_envolturas)
{
  vector<int> chocolates;
  chocolates.push_back(dinero / precio_chocolate);
  int envolturas_a_devolver = dinero / precio_chocolate;
  return acertijo_chocolates(precio_envolturas, envolturas_a_devolver, 1, chocolates);
}

int main()
{
  cout << "Te puedes comer " << acertijo_chocolates(16, 2, 2) << " chocolates  // input 16 2 2" << endl; // 15
  cout << "Te puedes comer " << acertijo_chocolates(15, 1, 3) << " chocolates  // input 15 1 3" << endl; // 22
  cout << "Te puedes comer " << acertijo_chocolates(18, 4, 2) << " chocolates  // input 18 4 2" << endl; // 7
  cout << "Te puedes comer " << acertijo_chocolates(2, 1, 2) << " chocolates  // input 2 1 2" << endl;   // 3
  cout << "Te puedes comer " << acertijo_chocolates(40, 5, 8) << " chocolates  // input 40 5 8" << endl; // 9
  cout << "Te puedes comer " << acertijo_chocolates(32, 2, 4) << " chocolates  // input 32 2 4" << endl; // 21
  cout << "Te puedes comer " << acertijo_chocolates(10, 3, 5) << " chocolates  // input 10 3 5" << endl; // 3
  cout << "Te puedes comer " << acertijo_chocolates(25, 5, 2) << " chocolates  // input 25 5 2" << endl; // 9
  cout << "Te puedes comer " << acertijo_chocolates(9, 2, 2) << " chocolates  // input 9 2 2" << endl;   // 7
  cout << "Te puedes comer " << acertijo_chocolates(50, 2, 7) << " chocolates  // input 50 2 7" << endl; // 29
  return 0;
}
