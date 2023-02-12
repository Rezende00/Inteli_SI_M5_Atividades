// Organização de logins de clientes, pela busca de seus IMEIs (que é a chave de busca).

#include <iostream>
#include <string>
using namespace std;

class Clientes{ // classe que representa os clientes

private : // atributos privados
  int         imei; // chave de busca
  std::string login; // login do cliente

public: // métodos públicos
  Clientes(); // construtor sem nenhum parâmetro, para alocação dinâmica de memória
  Clientes(int imei, std::string login); // construtor com parâmetros, para configuração do jeito a desejar pelo usuário.
  string getLogin() const; // método que retorna o login do cliente (string pois o login é uma sequência de caracteres)
  int getImei() const; // método que retorna o IMEI do cliente (int pois o IMEI é um número inteiro)
};