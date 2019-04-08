#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

double f(double x)
{
  return (pow(x,3)+2);
  //return (pow(x,3) + 4*(pow(x,2)) + 8);
}

double metoda_simpsona(double n, double x_1, double x_2)
{
  double dx = (x_2 - x_1)/n;
  double tmp1 = x_1;
  double tmp2 = x_1 + 2 * dx;
  double wynik = 0;
  while(tmp2 <= x_2)
  {
    wynik += ((f(tmp1) + 4*f((tmp1+tmp2)/2) + f(tmp2))*dx)/3;
    //cout  << f(tmp1) << " " << 4 * f((tmp1+tmp2)/2) << " " << f(tmp2) << " " << wynik << endl;
    tmp1 = tmp2;
    tmp2 += 2*dx;
  }
  return wynik;

}

double metoda_MonteCarlo(double n, double x_1, double x_2)
{
  srand(time(NULL));
  double TabX[(int)n];
  for(int i = 0; i < n;i++)
  {
    int tmp = rand() % ((int)x_2*100);
    //cout << tmp << endl;
    TabX[i] = ((double)tmp/100);
    cout << TabX[i] << endl;
  }
  double f_srednie = 0;
  double wynik = 0;
  for(int j = 0; j < n;j++)
  {
    f_srednie += f(TabX[j])/n;
  }
  wynik = f_srednie * abs((x_2-x_1));
  return wynik;
}

int main()
{
  //cout << "twoja funkacja to: x^3 + 4*x^2 + 8" << endl;
  cout << "twoja funkacja to: x^3 + 2" << endl;
  cout << "podaj przedzial calkowania:" << endl;
  double x_1,x_n;
  cin >> x_1 >> x_n;
  cout << "podaj na ile podprzedzialow chcesz podzielic calke" << endl;
  double n;
  cin >> n;
  cout << "wynik za pomoca metody simpsona: " << metoda_simpsona(n,x_1,x_n) << endl;
  cout << "wynik za pomoca metody metoda_MonteCarlo: " << metoda_MonteCarlo(n,x_1,x_n) << endl;

  return 0;
}
