#include <iostream>
#include <string>

class Veicolo {
protected:
    std::string marca;
    std::string modello;
    int cilindrata;

public:
    Veicolo(const std::string& marca, const std::string& modello, int cilindrata)
        : marca(marca), modello(modello), cilindrata(cilindrata) {}

    virtual void print_info() const {
        std::cout << "Marca: " << marca << ", Modello: " << modello << ", Cilindrata: " << cilindrata << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Veicolo& v) {
        os << "Marca: " << v.marca << ", Modello: " << v.modello << ", Cilindrata: " << v.cilindrata;
        return os;
    }
};

class Auto : public Veicolo {
private:
    static const int MAX_NUMERO_PORTE = 5;
    int numeroPorte;

public:
    Auto(const std::string& marca, const std::string& modello, int cilindrata, int numeroPorte)
        : Veicolo(marca, modello, cilindrata), numeroPorte(numeroPorte) {
        if (this->numeroPorte > MAX_NUMERO_PORTE) {
            this->numeroPorte = MAX_NUMERO_PORTE;
        }
    }

    void print_info() const override {
        Veicolo::print_info();
        std::cout << "Numero Porte: " << numeroPorte << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Auto& a) {
        os << static_cast<const Veicolo&>(a) << ", Numero Porte: " << a.numeroPorte;
        return os;
    }
};

int main() {
    Veicolo v("Fiat", "Punto", 1200);
    Auto a("BMW", "Serie 3", 2000, 4);

    v.print_info();
    a.print_info();

    std::cout << v << std::endl;
    std::cout << a << std::endl;

    return 0;
}