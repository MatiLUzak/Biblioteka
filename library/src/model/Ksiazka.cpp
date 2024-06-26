//
// Created by student on 08.06.23.
//
#include "Ksiazka.h"
#include "sstream"

Ksiazka::Ksiazka(const std::string &wydawnictwo, const std::string &jezyk, const std::string &tytul,
                 const std::vector<std::string> &autor) : Wolumin(wydawnictwo, jezyk, tytul), autor(autor) {
    if(autor.empty()){
        throw WoluminException("Brak autora książki");
    }
}

const std::vector<std::string> &Ksiazka::getAutor() const {
    return autor;
}

void Ksiazka::setAutor(const std::vector<std::string> &autor) {
    if(autor.empty()){
        throw WoluminException("Brak autora książki");
    }
    Ksiazka::autor = autor;
}
