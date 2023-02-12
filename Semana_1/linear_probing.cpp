// Implementação da classe Hash (vindo do arquivo hash.h):

#include "hash.h"  // inclui a definição da classe Hash
#include <iostream>
using namespace std;

Hash::Hash(int max) {  // construtor
  length = 0; // inicializa o tamanho da tabela hash com 0.
  max_items = max; // inicializa o tamanho máximo da tabela hash com o valor passado como parâmetro.
  structure = new Clientes[max_items]; // aloca dinamicamente um vetor de Clientes com o tamanho máximo da tabela hash.
}

Hash::~Hash(){ // destrutor da classe Hash
  delete [] structure; // desaloca a memória alocada dinamicamente.
}

bool Hash::estaCheio() const { // método que retorna se a tabela hash está cheia ou não (no caso se já preencheu os 100 itens).
  return (length == max_items); // retorna se o tamanho da tabela hash é igual ao tamanho máximo da tabela hash.
}

int Hash::tamanhoHash() const { // método que retorna o tamanho da tabela hash. (pra saber quantos tem na estrutura da tabela hash)
  return length; // retorna o tamanho da tabela hash.
}

void Hash::buscaItem(Clientes& cliente, bool& found) { // método que busca um item na tabela hash.
  int pegaCliente = getHash(cliente); // pega o hash do cliente.
  bool buscarMais = true;  // variável booleana que indica se ainda tem mais itens para serem buscados.
  int localizacao = pegaCliente; // variável que indica a localização do cliente na tabela hash.
  do { // laço que busca o cliente na tabela hash.
    if (structure[localizacao].getImei() == cliente.getImei() || // se o IMEI do cliente na tabela hash for igual ao IMEI do cliente passado como parâmetro OU
	structure[localizacao].getImei() == -1) // se o IMEI do cliente na tabela hash for igual a -1 (que indica que o cliente foi removido).
      buscarMais = false; // então não tem mais itens para serem buscados.
    else
      localizacao = (localizacao + 1) % max_items; // senão, incrementa a localização do cliente na tabela hash.
  } while (localizacao != pegaCliente && buscarMais); // enquanto a localização do cliente na tabela hash for diferente do hash do cliente e ainda tiver mais itens para serem buscados.
  
  found = (structure[localizacao].getImei() == cliente.getImei() ); // se o IMEI do cliente na tabela hash for igual ao IMEI do cliente passado como parâmetro, então o cliente foi encontrado.   
  if (found) { // se o cliente foi encontrado.
    cliente = structure[localizacao]; // então o cliente passado como parâmetro recebe o 'cliente' encontrado na tabela hash.
  }
}

void Hash::insereItem(Clientes cliente) { // método que insere um item na tabela hash.
  int localizacao; // variável que indica a localização do cliente na tabela hash.
  localizacao = getHash(cliente); // pega o hash do cliente.
  while (structure[localizacao].getImei() > 0) // enquanto o IMEI do cliente na tabela hash for maior que 0 (que indica que o cliente já foi inserido).
    localizacao = (localizacao + 1) % max_items; // incrementa a localização do cliente na tabela hash.
  structure[localizacao] = cliente;  // insere o cliente na tabela hash.
  length++; // incrementa o tamanho da tabela hash.
}

void Hash::removeItem(Clientes cliente) { // método que remove um item na tabela hash.
  int pegaCliente = getHash(cliente); // pega o hash do cliente.
  bool buscarMais = true; // variável booleana que indica se ainda tem mais itens para serem buscados.
  int localizacao = pegaCliente; // variável que indica a localização do cliente na tabela hash.
  do { 
    if (structure[localizacao].getImei() == cliente.getImei() ||
	structure[localizacao].getImei() == -1)
      buscarMais = false;
    else
      localizacao = (localizacao + 1) % max_items;
  } while (localizacao != pegaCliente && buscarMais);

  if (structure[localizacao].getImei() == cliente.getImei()) { // se o IMEI do cliente na tabela hash for igual ao IMEI do cliente passado como parâmetro.       
    structure[localizacao] = Clientes(-2,""); // então o cliente é removido da tabela hash.
    length--; // decrementa o tamanho da tabela hash.
  }
}

void Hash::print() { // método que imprime a tabela hash.
  for (int i = 0; i < max_items; i++) { // laço que percorre a tabela hash.
    cout << i <<":"<< structure[i].getImei()<<", "<<structure[i].getLogin()<<endl; // imprime a posição do cliente na tabela hash, o IMEI do cliente e o login do cliente.
  }
}

int Hash::getHash(Clientes cliente){ // método que retorna o hash do cliente.
  return cliente.getImei() % max_items; // retorna o resto da divisão do IMEI do cliente pelo tamanho máximo da tabela hash.
}