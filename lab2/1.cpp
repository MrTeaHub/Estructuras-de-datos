#include <iostream>
#include <vector>
using namespace std;

int enteroMasPequeño(vector<int> &numeros, int menor, int posicion)
{
  if (posicion < 0)
    return menor;
  if (menor > numeros[posicion - 1])
    menor = numeros[posicion - 1];
  return enteroMasPequeño(numeros, menor, posicion - 1);
}

int enteroMasPequeño(vector<int> &numeros)
{
  return enteroMasPequeño(numeros, numeros[0], numeros.size());
}

int main()
{
  vector<int> arreglo1, arreglo2, arreglo3, arreglo4, arreglo5, arreglo6, arreglo7, arreglo8, arreglo9, arreglo10;
  arreglo1 = {0, 43, 1, 5, 35, 7, 23, 5, 7, 32};           // 0
  arreglo2 = {15, 0, 14, 75, 35, 7, 23, 5, 76, 32};        // 0
  arreglo3 = {10, 43, 0, 54, 35, 7, 23, 2, 70, 32};        // 0
  arreglo4 = {106, 43, 61, 0, 35, 87, 23, 54, 72, 32};     // 0
  arreglo5 = {10, 43, 17, 5, 0, 72, 23, 55, 37, 32};       // 0
  arreglo6 = {10, 43, 143, 25, 6, 0, 23, 5, 67, 32};       //
  arreglo7 = {106, 43, 134, 665, 35, 7, 0, 53, 667, 32};   // 0
  arreglo8 = {106, 436, 221, 556, 35, 72, 233, 0, 27, 32}; // 0
  arreglo9 = {102, 43, 71, 375, 357, 7, 23, 5, 0, 32};     // 0
  arreglo10 = {130, 43, 351, 354, 354, 77, 232, 45, 1, 0}; // 0

  cout << "El numero menor en el arreglo 1 es: " << enteroMasPequeño(arreglo1) << " // input {0,43,1,5,35,7,23,5,7,32}" << endl;
  cout << "El numero menor en el arreglo 2 es: " << enteroMasPequeño(arreglo2) << " // input {15,0,14,75,35,7,23,5,76,32}" << endl;
  cout << "El numero menor en el arreglo 3 es: " << enteroMasPequeño(arreglo3) << " // input {10,43,0,54,35,7,23,2,70,32}" << endl;
  cout << "El numero menor en el arreglo 4 es: " << enteroMasPequeño(arreglo4) << " // input {106,43,61,0,35,87,23,54,72,32}" << endl;
  cout << "El numero menor en el arreglo 5 es: " << enteroMasPequeño(arreglo5) << " // input {10,43,17,5,0,72,23,55,37,32}" << endl;
  cout << "El numero menor en el arreglo 6 es: " << enteroMasPequeño(arreglo6) << " // input {10,43,143,25,6,0,23,5,67,32}" << endl;
  cout << "El numero menor en el arreglo 7 es: " << enteroMasPequeño(arreglo7) << " // input {106,43,134,665,35,7,0,53,667,32}" << endl;
  cout << "El numero menor en el arreglo 8 es: " << enteroMasPequeño(arreglo8) << " // input {106,436,221,556,35,72,233,0,27,32}" << endl;
  cout << "El numero menor en el arreglo 9 es: " << enteroMasPequeño(arreglo9) << " // input {102,43,71,375,357,7,23,5,0,32}" << endl;
  cout << "El numero menor en el arreglo 10 es: " << enteroMasPequeño(arreglo10) << " // input {130,43,351,354,354,77,232,45,1,0}" << endl;

  return 0;
}
