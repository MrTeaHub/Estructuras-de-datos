/*
En un acertijo el problema es encontrar la mayor cantidad de chocolates 
que se pueda comer, siguiendo las recomendaciones : 
a. dinero : Dinero que se tiene para comprar chocolates.
b. precio : Precio de un chocolate.
c. envoltura : Número de envolturas a devolver para recibir un chocolate  extra.
Se puede suponer que todos los valores dados son números enteros 
positivos y mayores que 1. 
Un método consiste en contar continuamente la cantidad de chocolates 
devolviendo las envolturas hasta que las envolturas que quedan no 
alcancen para canjear un chocolate.
*/

#include <iostream>
#include <vector>

using namespace std;

int acertijo_chocolates(int dinero, int precio_envolturas, int envolturas_a_devolver, int posicion, vector<int> &chocolates)
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
  return acertijo_chocolates(dinero, precio_envolturas, envolturas_a_devolver, posicion + 1, chocolates);
}

int acertijo_chocolates(int dinero, int precio_chocolate, int precio_envolturas)
{
  vector<int> chocolates;
  chocolates.push_back(dinero / precio_chocolate);
  int envolturas_a_devolver = dinero / precio_chocolate;
  return acertijo_chocolates(dinero, precio_envolturas, envolturas_a_devolver, 1, chocolates);
}

int main()
{
  cout << acertijo_chocolates(16, 2, 2) << endl;
  return 0;
}
