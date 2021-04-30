#include "rectangle.hh"

Rectangle::Rectangle() {
    Vector W = Vector();
    for (int i = 0; i < WIER; ++i) {
            rect[i] = W;
    }
}

Rectangle::Rectangle(Vector A, Vector B,Vector C,Vector D){
    rect[0] = A;
    rect[1] = B;
    rect[2] = C;
    rect[3] = D;
    
}

std::ostream &operator << (std::ostream &out, Rectangle const &tmp){
    for (int i = 0; i < WIER; ++i) { 
        out << "| " << tmp[i] << "| "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        if (i == 1){
        std::cout << std::endl;
    }
    }
    return out;
}

const Vector &Rectangle::operator [] (int index) const {
    if (index < 0 || index >= WIER) {
        std::cerr << "Error: Rectangle jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return rect[index];
}

Vector &Rectangle::operator[](int index) {
    return const_cast<Vector &>(const_cast<const Rectangle *>(this)->operator[](index));
}

Rectangle Rectangle::Przesuniencie(Vector const Vec){
    for(int i = 0; i < WIER; ++i){
        rect[i][0] = rect[i][0] += Vec[0];
        rect[i][1] = rect[i][1] += Vec[1];  
    }
    return *this;
}

Rectangle Rectangle::Obrot(double const kat, int const raz){
    Matrix Mkat = Mkat.ObrKat(kat);
    for (int i = 0; i < raz; ++i){
        for (int x = 0; x < WIER; ++x){
            rect[x] = Mkat * rect[x];
        }
    }
    return *this;
}

void Rectangle::Dlugosc(){
    double DlBok1, DlBok2, KrBok1, KrBok2;
    DlBok1 = sqrt(pow(rect[1][0] - rect[0][0],2) + pow(rect[1][1] - rect[0][1],2));
    DlBok2 = sqrt(pow(rect[3][0] - rect[2][0],2) + pow(rect[3][1] - rect[2][1],2));
    KrBok1 = sqrt(pow(rect[2][0] - rect[1][0],2) + pow(rect[2][1] - rect[1][1],2));
    KrBok2 = sqrt(pow(rect[0][0] - rect[3][0],2) + pow(rect[0][1] - rect[3][1],2));
    if (DlBok1 == DlBok2){
        std::cout << ":)  Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << DlBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << DlBok2 << std::endl << std::endl;
    }
    else{
        std::cout << ":o  Dluzsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << DlBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << DlBok2 << std::endl << std::endl;      
    }
    if (KrBok1 == KrBok2){
        std::cout << ":)  Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << KrBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << KrBok2 << std::endl << std::endl;
    }
    else{
        std::cout << ":o  Krotsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << KrBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << KrBok2 << std::endl << std::endl;      
    }
}