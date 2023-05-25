#include "Cola.cpp"
#include "Comedor.h"
#include "Lista.cpp"
#include <cstdlib>
#include <ctime>
#include <list>

int sum(Lista<int> &lista)
{
  int sumatoria = 0;
  for (int i = 0; i < lista.size(); i++)
  {
    sumatoria = sumatoria + lista.get(i);
  }
  return sumatoria;
}

bool nuevoEstudiante()
{
  int numero, S = 11;      // 11 o 6
  numero = 1 + rand() % S; // 1 + es el minimo % S el maximo
  if (numero == S)
    return true;
  else
  {
    return false;
  }
}

list<int> simulacion(int numeroSegundos, int tasaServicio)
{
  Comedor comedorUniversitario(tasaServicio);
  Cola<Estudiante> colaComedor;
  Lista<int> tiemposEspera;
  list<int> resultados;
  list<Estudiante> numeroEstudiantesQuePasanAlComedor;

  for (int segundoActual = 0; segundoActual < numeroSegundos; segundoActual++)
  {
    if (nuevoEstudiante())
    {
      Estudiante estudiante = Estudiante(segundoActual);
      colaComedor.push(estudiante);
      numeroEstudiantesQuePasanAlComedor.push_back(estudiante);
    }
    if ((!comedorUniversitario.ocupada()) && (colaComedor.size() > 0))
    {
      Estudiante estudianteSiguiente = colaComedor.front();
      colaComedor.pop();
      tiemposEspera.insert(tiemposEspera.size(), estudianteSiguiente.tiempoEspera(segundoActual));
      comedorUniversitario.iniciarNueva(&estudianteSiguiente);
    }
    comedorUniversitario.ticTac();
  }

  int esperaPromedio = sum(tiemposEspera) / tiemposEspera.size();
  resultados.push_back(esperaPromedio);
  resultados.push_back(numeroEstudiantesQuePasanAlComedor.size());
  resultados.push_back(colaComedor.size());
  return resultados;
}

int main()
{
  srand(time(nullptr));
  list<int> resultados;
  int promedioEspera = 0, promedioEstudiantesRestantes = 0, n = 0;
  for (int i = 0; i < 100; i++)
  {
    resultados = simulacion(3600, 47); // tasa de servicio 47 y 9
    promedioEspera += resultados.front();
    promedioEstudiantesRestantes += resultados.back();
    cout << i + 1 << " Tiempo de espera promedio: " << resultados.front() << " segundos, " << resultados.back() << " estudiantes restantes." << endl;
    if (i == 99)
    {
      resultados.pop_back();
      n = resultados.back();
    }
  }
  cout << endl
       << "Promedio de las 100 simulaciones: " << endl;
  cout << "Tiempo de espera promedio: " << promedioEspera / 100 << " segundos, " << promedioEstudiantesRestantes / 100 << " estudiantes restantes." << endl;
  cout << "El numero de estudiantes que pasaron al comedor en 1 hora fue de: " << n;
  return 0;
}
