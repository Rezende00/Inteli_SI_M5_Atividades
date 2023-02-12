// Montando a classe Hash, estrutura abstrata de dados, com busca, inserção e remoção.

#include "logins_imei.h" // importando a classe Clientes.

class Hash { // classe Hash
 public: // métodos/atributos públicos
  Hash(int max_items = 100); // construtor da classe Hash, que recebe como parâmetro o tamanho máximo da tabela hash.
  ~Hash(); // destrutor da classe Hash, para desalocar a memória alocada dinamicamente.
  bool estaCheio() const; // método que retorna se a tabela hash está cheia ou não (no caso se já preencheu os 100 itens).
  int tamanhoHash() const; // método que retorna o tamanho da tabela hash. (pra saber quantos tem na estrutura da tabela hash)
  
  void buscaItem(Clientes& cliente, bool& found);   
  void insereItem(Clientes cliente); 
  void removeItem(Clientes cliente);  
  void print(); // método que imprime a tabela hash.

 private: // métodos/atributos privados
  int getHash(Clientes cliente); // método que retorna o hash do cliente.
  int   max_items; // tamanho máximo da tabela hash.
  int   length; // tamanho da tabela hash.
  Clientes* structure; // é um ponteiro para um vetor de Clientes. [IMPORTANTE]
};