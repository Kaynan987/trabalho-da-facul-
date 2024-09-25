#ifndef USUARIOS_HPP  
#define USUARIOS_HPP
#include <iostream>
#include <vector>
#include "biblioteca.hpp"
using namespace std;


struct Usuario {
    string nome;
    int idade;
    int emprestimos = 0;
    vector<string> livrosEmprestados;
    vector<int> diasParaMulta;
    float multa;
};

 void pesquisarUsuario(vector<Usuario> &usuarios, string nome);
 void mostrarUsuario(Usuario usuarios);
 void cadastrarUsuario(string nome, int idade);
 void pesquisarLivrosPorUsuario(vector<Usuario>& usuarios);
 void listarUsuarios(vector<Usuario> &usuarios);

 #endif