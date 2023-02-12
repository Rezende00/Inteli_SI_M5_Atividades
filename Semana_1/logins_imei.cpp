// A implementação da classe 'Clientes' vai ser feita da seguinte forma:

#include "logins_imei.h" // importando a classe Clientes

Clientes::Clientes(){ // construtor sem nenhum parâmetro, para alocação dinâmica de memória. (todo IMEI é um número inteiro, logo, não tem como ser negativo)
  this->imei   = -1; // vai demonstrar que a posição referente do vetor está vazia
  this->login = ""; // caso o valor do IMEI seja -1, o login vai ser uma string vazia pois não há login para um IMEI que não existe.
  // isso significa que o IMEI -1 é um valor inválido para o IMEI de um cliente, o que vai demonstrar uma posição vazia na tabela hash.
};  

Clientes::Clientes(int imei, std::string login){ // esse outro construtor vai ser usado para configurar o IMEI e o login do cliente.
  // ele está recebendo um imei como parâmetro, e um login como parâmetro, e vai alocá-los nos atributos da classe. Dessa forma, está instanciando um objeto com Imei e login.
  this->imei    = imei;
  this->login  = login;
}

// Métodos get, que retornam o login e o IMEI do cliente.
// Caso queira obter um login ou um IMEI, basta chamar o método getLogin() ou getImei(), respectivamente.
string Clientes::getLogin() const {
  return login;
}

int Clientes::getImei() const{
  return imei;
}