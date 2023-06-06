#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include "ListaEncadeada.h"
#include "music.h"

class Playlist
{
private:
  std::string nome;
  ListaEncadeada<Music> listaMusicas;

public:
  Playlist();
  ~Playlist();
  Playlist(std::string nome);
  /**
   * @brief Pega o membro titulo
   *
   * @return std::string nome
   */
  std::string getTitulo() { return nome; }
  /**
   * @brief Muda o nome da playlist
   *
   * @param nome
   */
  void setNome(std::string nome) { this->nome = nome; }
  /**
   * @brief Metodo para comparar objetos do tipo playlist
   *
   * @param outra
   * @return true
   * @return false
   */
  bool operator==(const Playlist &outra) const;
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, cria um objeto musica e o adiciona a playlist atraves da função inserir() da lista encadeada
   *  @param titulo
   * @param autor
   */

  void adicionarMusica(std::string titulo, std::string autor);
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, cria um objeto musica e o remove da playlist atraves da função remover() da lista encadeada.
   * @param titulo
   * @param autor
   */
  void removerMusica(std::string titulo, std::string autor);
  /**
   * @brief Metodo da classe playlist que imprimi as musicas de uma playlist traves da função imprimir() da lista encadeada.
   */
  void imprimirMusicas();
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, e passa os parametros para o metodo buscarNodeM() da lista encadada e retorna true para caso a musica esteja na playlist e false para oposto.
   * @param titulo
   * @param autor
   * @return bool
   */

  bool buscarMusica(std::string titulo, std::string autor);
  /**
   *@brief Metodo da classe playlist que imprime as musicas da playlist uma de cada vez, de forma que o usuario possa controlar a passagem das musicas ou voltar para o menu.
   *@param nome
   */
  void play(std::string nome);
  /**
   * @brief Metodo recursivo que imprime as musicas de uma playlist
   *
   * @param node
   */
  void imprimirMus(Node<Music> *node);
  /**
   * @brief Pega o primeiro no musica da playlist
   *
   * @return Node<Music>*
   */
  Node<Music> *getPrimeiraMusica();
  /**
   * @brief Adiciona os elementos de uma playlist em outra playlist
   *
   * @param outraPlaylist
   */
  void adicionarPlaylist(Playlist &outraPlaylist);
  /**
   * @brief Remove os elementos de uma playlist de outra playlist
   *
   * @param outraPlaylist
   * @return int
   */
  int removerPlaylist(Playlist &outraPlaylist);
  /**
   * @brief Copia uma playlist
   *
   * @param outraPlaylist
   */
  void copiaPlaylist(Playlist &outraPlaylist);
  /**
   * @brief Remove a última música da playlist
   *
   * @param no
   */
  void operator>>(Node<Music> *&no);
  /**
   * @brief Insere a música na ultima posiçao da playlist
   *
   * @param no
   */
  void operator<<(Node<Music> *no);
  /**
   * @brief Retorna uma playlist com uma musica removida
   *
   * @param musica
   * @return Playlist*
   */
  Playlist *operator-(Music &musica);
  /**
   * @brief Retorna uma playlist da diferença de outras duas playlists
   *
   * @param outraPlaylist
   * @return Playlist*
   */
  Playlist *operator-(Playlist &outraPlaylist);
  /**
   * @brief Retorna uma playlist com uma musica adicionada no final
   *
   * @param musica
   * @return Playlist*
   */
  Playlist *operator+(Music &musica);
  /**
   * @brief Retorna uma playlist da união dos elementos de duas playlists
   *
   * @param outraPlaylist
   * @return Playlist*
   */
  Playlist *operator+(Playlist &outraPlaylist);
};

#endif
