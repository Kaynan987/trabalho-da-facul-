#include <iostream>
#include <vector>
#include "usuarios.hpp"
#include "biblioteca.hpp"  
using namespace std;

float multa;
vector<Usuario> usuarios;
void cadastrarUsuario(vector<Usuario> & usuarios) {
    Usuario novoUsuario;
    string nome;
    int idade;

    cout << "Nome do Usuário: "; 
    cin.ignore();
    getline(cin, novoUsuario.nome = nome);

    cout << "Idade: ";
    cin >> idade;
    novoUsuario.idade = idade;
    novoUsuario.multa = 0.0;
    usuarios.push_back(novoUsuario);
}

void mostrarUsuario (vector<Usuario> usuarios, string &nome){
  bool encontrado = false;
  for (const Usuario &usuario : usuarios){
    if (usuario.nome == nome){
        cout << "-Usuários Encontrados:- \n"; 
        cout << "Nome: " << usuario.nome << endl;
        cout << "Livros: ";
        encontrado = true;
    }
    if(!encontrado){
      cout << "Nenhum registro encontrado." << endl;
    }
  }
}

void pesquisarLivrosPorUsuario(vector<Usuario> &usuarios){
  size_t usuarioSelecionado;
  if (usuarios.empty()){
    cout << "Não há usuários cadastrados!";
  } else{
      listarUsuarios(usuarios);
      cout << "Selecione o usuário (utilizando o ID): ";
      cin >> usuarioSelecionado;
      if (usuarioSelecionado > 0 && usuarioSelecionado <= usuarios.size()) {
        int i = 0;
        Usuario& usuario = usuarios[usuarioSelecionado - 1];
        cout << "Livros emprestados pelo usuário " << usuario.nome << ": " << endl;
        for (const string& livroTitulo : usuario.livrosEmprestados) {
            cout << i+1 << " "
                 << livroTitulo << endl;
            i++;
        }
    } 
  }
}



 void pesquisarUsuario(vector<Usuario> &usuarios, string nome){
    int i = 0;
    bool encontrado = false;
    for (const Usuario &usuario : usuarios){
      if (usuario.nome == nome){
        cout << "-Usuários Encontrados- \n" 
             << "Usuario: " << i+1 << usuario.nome << endl << endl; 
        encontrado = true;
    }
    i++;
    if(!encontrado){
      cout << "Nenhum registro encontrado." << endl;
    }
  }
 }

 void listarUsuarios(vector<Usuario> &usuarios){
  int i = 0;
  if (usuarios.empty()){
        cout << "Não há usuários cadastrados!";
  } else {
    for (Usuario &usuario : usuarios) { 
      cout << "-Usuários Cadastrados- \n"
           << "ID: " << i+1 << endl
           << "Nome: " << usuario.nome << endl
           << "Multa: R$" << usuario.multa << endl 
           << "emprestimos: " << usuario.emprestimos << endl;
      i++;
    };
  }
 }