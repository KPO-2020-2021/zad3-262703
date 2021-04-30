// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include "../include/lacze_do_gnuplota.hh"


void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream& StrmWy, Rectangle tmpR2)
{
for (int i = 0; i < WIER;  ++i){
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[i][0] 
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[i][1] << std::endl;
}
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[0][0] 
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[0][1] << std::endl;
 // Jeszcze raz zapisujemy pierwszy punkt,
 // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Rectangle  tmpR2)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, tmpR2);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void Menu(){
  std::cout << "o - obrot prostokata o zadany kat" << std::endl;
  std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
  std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout << "m - wyswietl menu" << std::endl;
  std::cout << "d - demonstracja prostokata w gnuplocie " << std::endl;
  std::cout << "b - dlugosc bokow" << std::endl;
  std::cout << "k - koniec dzialania programu" << std::endl << std::endl;
}

int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D
  char a = ' ';
  Rectangle tmpR2 = Rectangle();
  double VekA[] = {100.0, 60.0};
  Vector A = Vector(VekA);
  double VekB[] = {200.0, 60.0};
  Vector B = Vector(VekB);
  double VekC[] = {200.0, 10.0};
  Vector C = Vector(VekC);
  double VekD[] = {100.0, 10.0};
  Vector D = Vector(VekD);
  tmpR2 = Rectangle(A, B, C, D);
  Vector tmpV;
  double Vec[SIZE];
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
  while (a != 'k'){
    std::cout << "Twoj wybor? (m - menu) > ";
    std::cin >> a;
    std::cout << std::endl;
    switch (a)
    {
    case 'o':
      double kat;
      int raz;
      std::cout << "Podaj wartosc kata obrotu w stopniach" << std::endl;
      std::cin >> kat;
      std::cout << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
      std::cin >> raz;
      tmpR2 = tmpR2.Obrot(kat,raz);
      break;
    case 'p':
    double x, y;
      std::cout << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb" << std::endl;
      std::cout << "tzn. wspolrzednej x oraz wspolrzednej y." << std::endl;
      std::cin >> x >> y;
      Vec[0] = x;
      Vec[1] = y;
      tmpV = Vector(Vec);
      tmpR2 = tmpR2.Przesuniencie(tmpV);
      break;
    case 'w':
      std::cout << tmpR2 << std::endl;
      break;
    case 'm':
      Menu();
      break;
    case 'b':
      tmpR2.Dlugosc();
      break;
    case 'd':
      //-------------------------------------------------------
      //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
      //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
      //  na dwa sposoby:
      //   1. Rysowane jako linia ciagl o grubosci 2 piksele
      //
      Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,0.2);
      //
      //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
      //      których połowa długości boku wynosi 2.
      //
      Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,0.2);
      //
      //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
      //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
      //  jako wspolrzedne punktow podajemy tylko x,y.
      //
      Lacze.ZmienTrybRys(PzG::TR_2D);

      PrzykladZapisuWspolrzednychDoStrumienia(std::cout,tmpR2);
      if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",tmpR2)) return 1;
      Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
      std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl << std::endl;
      std::cin.ignore(100000,'\n');
      break;
    case 'k':
      std::cout << "Koniec dzialania program" << std::endl;
      break;
    default:
      std::cout << ":(  Blad: Nie ma takiej opcji." << std::endl;
      break;
  }
  }
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
