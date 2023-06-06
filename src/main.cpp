#include <iostream>
#include <fstream>
#include <sstream>
#include "ListaEncadeada.h"
#include "func.h"

int main(int argc, char *argv[])
{
  // Verifica se o usuario iniciou o arquivo
  if (argc != 2)
  {
    std::cout << "Use o arquivo play.txt" << std::endl;
    return 1;
  }

  ListaEncadeada<Playlist *> listaPlaylist;
  std::ifstream arquivo(argv[1]);
  // Verifica se o arquivo foi aberto corretamente
  if (!arquivo.is_open())
  {
    std::cout << "Erro ao abrir o arquivo." << std::endl;
    return 1;
  }
  // Cria as playlists
  std::string linha;
  while (std::getline(arquivo, linha))
  {
    std::stringstream ss(linha);
    std::string playlistNome;
    std::getline(ss, playlistNome, ';');

    Playlist *playlist = new Playlist(playlistNome);

    std::string musica;
    while (std::getline(ss, musica, ','))
    {
      std::string musicaNome, artistaNome;
      std::stringstream musicaSS(musica);
      std::getline(musicaSS, musicaNome, ':');
      std::getline(musicaSS, artistaNome, ':');
      playlist->adicionarMusica(musicaNome, artistaNome);
    }

    listaPlaylist.inserir(playlist);
  }

  arquivo.close();

  menu(listaPlaylist);

  // Grava as informações atuais no arquivo
  std::ofstream arquivoSaida(argv[1]);
  if (arquivoSaida.is_open())
  {
    Node<Playlist *> *playlist = listaPlaylist.getHead();
    while (playlist != nullptr)
    {
      arquivoSaida << playlist->getValor()->getTitulo() << ";";
      Node<Music> *musica = playlist->getValor()->getPrimeiraMusica();
      while (musica != nullptr)
      {
        arquivoSaida << musica->getValor().getTitulo() << ":" << musica->getValor().getAutor() << ",";
        musica = musica->getProx();
      }

      arquivoSaida << std::endl;

      playlist = listaPlaylist.buscarNode(playlist->getValor()->getTitulo())->getProx();
    }

    arquivoSaida.close();
  }
  else
  {
    std::cout << "Erro ao abrir o arquivo de saída." << std::endl;
  }
  // Desaloca as playlists ao final do programa
  auto atual = listaPlaylist.getHead();
  while (atual != nullptr)
  {
    delete atual->getValor();
    atual = atual->getProx();
  }

  return 0;
}
