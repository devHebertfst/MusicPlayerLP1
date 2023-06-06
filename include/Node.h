#ifndef NODE_H
#define NODE_H
#include "music.h"
template <typename T>
class Node
{

private:
  Node<T> *prox;
  T valor;

public:
  Node(T valor)
  {
    this->valor = valor;
    this->prox = nullptr;
  }
  /**
   * @brief Pega o objeto valor
   *
   * @return T
   */
  T getValor() { return valor; }
  /**
   * @brief Pega o proximo objeto
   *
   * @return Node*
   */
  Node *getProx() { return prox; }
  /**
   * @brief Define o proximo objeto
   *
   * @param p
   */
  void setProx(Node<T> *p)
  {
    prox = p;
  }
};

#endif