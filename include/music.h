#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <string>

class Music
{
private:
  std::string titulo;
  std::string autor;

public:
  Music(){};
  Music(std::string titulo, std::string autor)
  {
    this->titulo = titulo;
    this->autor = autor;
  }
  /**
   * @brief Pega o membro titulo
   *
   * @return std::string
   */
  std::string getTitulo() { return titulo; }
  /**
   * @brief Pega o membro autor
   *
   * @return std::string
   */
  std::string getAutor() { return autor; }
  /**
   * @brief Metodo para comparar objetos do tipo musica
   *
   * @param outra
   * @return true
   * @return false
   */
  bool operator==(const Music &outra) const
  {
    return (titulo == outra.titulo && autor == outra.autor);
  }
};

#endif