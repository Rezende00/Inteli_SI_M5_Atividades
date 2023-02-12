#include <iostream>
#include "hash.h" 
using namespace std;

void teste1(){ // teste removendo um cliente [no caso o Pedro]
  Hash clientesHash(13); // tamanho da tabela
   int   imeis[13]   = { // quantos IMEI's estou passando
     999369465, 492334388, 546591137, 496238923,
     491123616, 359726845, 121286153, 491154167,
     122812915, 441869585, 517489849, 526423388,
     186967879};
  
  string login[13] = { // quantos emails estou passando 
    "pedro@gmail.com", "raul@gmail.com", "paulo@gmail.com",
    "carlos@gmail.com", "lucas@gmail.com", "maria@gmail.com",
    "samanta@gmail.com", "milena@gmail.com", "izabella@gmail.com", 
    "sofia@gmail.com", "alexandre@gmail.com", "caio@gmail.com",
    "pablo@gmail.com"};
	    
  for (int i = 0; i < 13; i++) { // 'for' para passar todos os valores e inseri-los na tabela.
    Clientes cliente = Clientes(imeis[i], login[i]); //identificação de todos os IMEI's e Logins
    clientesHash.insereItem(cliente); // inserção de todos na tabela hash
  } 
  clientesHash.print(); //print da tabela hash
  cout << "--------------------------------" <<  endl;
  
  Clientes cliente(999369465,""); //busca pelo IMEI definido
  bool     found = false; // criação da variável do tipo booleana 
  clientesHash.buscaItem(cliente, found); // chamada da função buscaItem para buscar o cliente a partir do IMEI passado, além de passar a nova variável para verificar a existência ou não.
  cout << cliente.getLogin() << " -> " << found << endl; // chamada a função getLogin para pegar o Login respectivo com o IMEI repassado e mostrar 1 ou 0 de acordo com a existência ou não daquele login na tabela Hash.
  
  cout << "--------------------------------" <<  endl;

  clientesHash.removeItem(cliente); //com o cliente já identificado, chamei a função de remoção de item para deletar o cliente "Pedro".
  clientesHash.print(); //print da nova tabela hash, com o cliente já excluído
  cout << "Fim" << endl;  
}

void teste2(){ // teste de inserção de um novo cliente [Hayashi], sem colisão.
  Hash clientesHash(15); // tamanho da tabela
   int   imeis[13]   = { // quantos IMEI's estou passando
     999369465, 492334388, 546591137, 496238923,
     491123616, 359726845, 121286153, 491154167,
     122812915, 441869585, 517489849, 526423388,
     186967879};
  
  string login[13] = { // quantos emails estou passando 
    "pedro@gmail.com", "raul@gmail.com", "paulo@gmail.com",
    "carlos@gmail.com", "lucas@gmail.com", "maria@gmail.com",
    "samanta@gmail.com", "milena@gmail.com", "izabella@gmail.com", 
    "sofia@gmail.com", "alexandre@gmail.com", "caio@gmail.com",
    "pablo@gmail.com"};
	    
  for (int i = 0; i < 13; i++) { // 'for' para passar todos os valores e inseri-los na tabela.
    Clientes cliente = Clientes(imeis[i], login[i]); //identificação de todos os IMEI's e Logins
    clientesHash.insereItem(cliente); // inserção de todos na tabela hash
  } 
  clientesHash.print(); //print da tabela hash
  cout << "--------------------------------" <<  endl;
  
  Clientes cliente(517483574,"hayashi@gmail.com"); // aplicação de um novo Imei e de um novo email
  bool     found = false; // criação da variável do tipo booleana 
  clientesHash.buscaItem(cliente, found); //chamada da função buscaItem para buscar o cliente a partir do IMEI passado, além de passar a nova variável para verificar a existência ou não.
  cout << cliente.getLogin() << " -> " << found << endl; // chamada a função getLogin para pegar o Login respectivo com o IMEI repassado e mostrar 1 ou 0 de acordo com a existência ou não daquele login na tabela Hash.
  
  cout << "--------------------------------" <<  endl;

  clientesHash.insereItem(cliente); // inserção do cliente para uma nova posição.
  clientesHash.print(); //print da nova tabela hash, com o cliente já adcionado
  cout << "Fim" << endl;
}

void teste3(){ // teste de inserção de um novo cliente [Gabriel], com colisão (porém a colisão está sendo tratada).
  Hash clientesHash(15); // tamanho da tabela
   int   imeis[13]   = { // quantos IMEI's estou passando
     999369465, 492334388, 546591137, 496238923,
     491123616, 359726845, 121286153, 491154167,
     122812915, 441869585, 517489849, 526423388,
     186967879};
  
  string login[13] = { // quantos emails estou passando 
    "pedro@gmail.com", "raul@gmail.com", "paulo@gmail.com",
    "carlos@gmail.com", "lucas@gmail.com", "maria@gmail.com",
    "samanta@gmail.com", "milena@gmail.com", "izabella@gmail.com", 
    "sofia@gmail.com", "alexandre@gmail.com", "caio@gmail.com",
    "pablo@gmail.com"};
	    
  for (int i = 0; i < 13; i++) { // 'for' para passar todos os valores e inseri-los na tabela.
    Clientes cliente = Clientes(imeis[i], login[i]); //identificação de todos os IMEI's e Logins
    clientesHash.insereItem(cliente); // inserção de todos na tabela hash
  } 
  clientesHash.print(); //print da tabela hash
  cout << "--------------------------------" <<  endl;
  
  Clientes cliente(517483573,"gabriel@gmail.com"); // aplicação de um novo Imei e de um novo email
  bool     found = false; // criação da variável do tipo booleana 
  clientesHash.buscaItem(cliente, found); // chamada da função buscaItem para buscar o cliente a partir do IMEI passado, além de passar a nova variável para verificar a existência ou não.
  cout << cliente.getLogin() << " -> " << found << endl; // chamada a função getLogin para pegar o Login respectivo com o IMEI repassado e mostrar 1 ou 0 de acordo com a existência ou não daquele login na tabela Hash.
  
  cout << "--------------------------------" <<  endl;

  clientesHash.insereItem(cliente); // inserção do cliente para uma posição (com resto 13, então a posição será 13).
  //Porém, já existe um cliente nessa posição, então o novo cliente será adcionado para a posição seguinte.
  clientesHash.print(); //print da nova tabela hash, com o cliente já adcionado
  cout << "Fim" << endl;
}

void teste4(){ // teste de armazenamento de um login já existente na tabela Hash.
  Hash clientesHash(15); // tamanho da tabela
   int   imeis[13]   = { // quantos IMEI's estou passando
     999369465, 492334388, 546591137, 496238923,
     491123616, 359726845, 121286153, 491154167,
     122812915, 441869585, 517489849, 526423388,
     186967879};
  
  string login[13] = { // quantos emails estou passando 
    "pedro@gmail.com", "raul@gmail.com", "paulo@gmail.com",
    "carlos@gmail.com", "lucas@gmail.com", "maria@gmail.com",
    "samanta@gmail.com", "milena@gmail.com", "izabella@gmail.com", 
    "sofia@gmail.com", "alexandre@gmail.com", "caio@gmail.com",
    "pablo@gmail.com"};
	    
  for (int i = 0; i < 13; i++) { // 'for' para passar todos os valores e inseri-los na tabela.
    Clientes cliente = Clientes(imeis[i], login[i]); //identificação de todos os IMEI's e Logins
    clientesHash.insereItem(cliente); // inserção de todos na tabela hash
  } 
  clientesHash.print(); //print da tabela hash
  cout << "--------------------------------" <<  endl;
  
  Clientes cliente(999369465,""); // estou passando o Imei referente ao login "pedro@gmail.com"
  bool found = false; // criação da variável do tipo booleana 
  clientesHash.buscaItem(cliente, found); // chamada da função buscaItem para buscar o cliente a partir do IMEI passado, além de passar a nova variável para verificar a existência ou não.
  cout << cliente.getLogin() << " -> " << found << endl; // chamada a função getLogin para pegar o Login respectivo com o IMEI repassado e mostrar 1 ou 0 de acordo com a existência ou não daquele login na tabela Hash.
  
  cout << "--------------------------------" <<  endl;

  // Teste de armazenamento: Verificando se o login do cliente procurado é "pedro@gmail.com"
  if (cliente.getLogin() == "pedro@gmail.com") { // se o login do cliente for igual ao login passado, então o teste de armazenamento foi um sucesso.
    cout << "Teste de armazenamento: SUCESSO" << endl;
  } else { // caso contrário, o teste de armazenamento falhou.
    cout << "Teste de armazenamento: FALHA" << endl;
  }
cout << "Fim" << endl;
}

void teste5(){ // teste de atualização de um login na tabela Hash, utilizando o mesmo Imei.
  Hash clientesHash(15); // tamanho da tabela
   int   imeis[13]   = { // quantos IMEI's estou passando
     999369465, 492334388, 546591137, 496238923,
     491123616, 359726845, 121286153, 491154167,
     122812915, 441869585, 517489849, 526423388,
     186967879};
  
  string login[13] = { // quantos emails estou passando 
    "pedro@gmail.com", "raul@gmail.com", "paulo@gmail.com",
    "carlos@gmail.com", "lucas@gmail.com", "maria@gmail.com",
    "samanta@gmail.com", "milena@gmail.com", "izabella@gmail.com", 
    "sofia@gmail.com", "alexandre@gmail.com", "caio@gmail.com",
    "pablo@gmail.com"};
	    
  for (int i = 0; i < 13; i++) { // 'for' para passar todos os valores e inseri-los na tabela.
    Clientes cliente = Clientes(imeis[i], login[i]); //identificação de todos os IMEI's e Logins
    clientesHash.insereItem(cliente); // inserção de todos na tabela hash
  } 
  clientesHash.print(); //print da tabela hash
  cout << "--------------------------------" <<  endl;
  
  Clientes cliente(999369465,""); // estou passando o Imei referente ao login "pedro@gmail.com"
  bool found = false; // criação da variável do tipo booleana 
  clientesHash.buscaItem(cliente, found); // chamada da função buscaItem para buscar o cliente a partir do IMEI passado, além de passar a nova variável para verificar a existência ou não.
  cout << cliente.getLogin() << " -> " << found << endl; // chamada a função getLogin para pegar o Login respectivo com o IMEI repassado e mostrar 1 ou 0 de acordo com a existência ou não daquele login na tabela Hash.
  
  cout << "--------------------------------" <<  endl;
  if (found) { // Atualizando o login do cliente
    clientesHash.removeItem(cliente); // Removendo o cliente da tabela hash
    Clientes novoCliente(999369465,"novo_login@gmail.com"); // Criando um novo cliente com o mesmo IMEI, porém com um novo login.
    clientesHash.insereItem(novoCliente); // Inserindo o novo cliente na tabela hash

  // Realizando nova busca para verificar se o login foi atualizado corretamente
  bool novoFound = false; // criação de uma nova variável do tipo booleana
  clientesHash.buscaItem(novoCliente, novoFound); // chamada da função buscaItem para buscar o cliente a partir do IMEI passado, além de passar a nova variável para verificar a existência ou não.
  cout << novoCliente.getLogin() << " -> " << novoFound << endl;

  if (novoFound && novoCliente.getLogin() == "novo_login@gmail.com") { // se o novo login for igual ao login passado, então o teste de atualização foi um sucesso.
    cout << "Teste de atualização: SUCESSO" << endl;
  } else { // caso contrário, o teste de atualização falhou.
    cout << "Teste de atualização: FALHA" << endl;
  }
} else { // Caso o cliente não seja encontrado na tabela hash
  cout << "Não foi possível encontrar o item para atualizar." << endl;
  }
clientesHash.print(); //print da tabela hash
cout << "Fim" << endl;
}


// Chamando cada teste na main
int main() { // Obs: Descomentar cada teste e rodar o código para a verificação
  
  // teste1();
  // teste2();
  // teste3();
  // teste4();
  // teste5();
}