#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#define TAM 50
#include "usuarios.hpp"
#include <string> 
#include <vector>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    string categoria;
    int quantidade;
    int ano;
    int paginas;
    int emprestimoLivro;
};

void menu(int &opcao);
void listagemDeLivros(vector<Livro>& acervo, string criterio);
void pesquisarLivros(vector<Livro>& acervo, string criterio);
void cadastrarLivro(vector<Livro>& acervo);
void emprestarLivro(vector<Livro> &acervo, vector<Usuario> &usuarios, string &criterio);  // dentro do empréstimo deve-se aparecer uma pesquisa, para poder escolher qual livro
void devolverLivro(vector<Livro> &acervo, vector<Usuario> &usuarios);  // escolher qual usuário vai devolver, depois escolher o livro
void aplicarMulta(vector<Usuario> &usuarios, int &fecharDia);
void relatorioDeEmprestimos(vector<Livro> &acervo, vector<Usuario> &usuarios, int &fecharDia);  // Novo protótipo
#endif