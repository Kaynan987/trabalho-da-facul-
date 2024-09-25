#include <iostream>
#include <vector>
#include "biblioteca.hpp"
#include "usuarios.hpp"
#include <algorithm>
#include <map>
using namespace std;

vector<Livro> acervo;

int fecharDia = 0;

void menu(int &opcao){ 
    cout << "\n--- Menu ---\n";
    cout << "1. Cadastrar Livro\n"; // ok
    cout << "2. Cadastrar Usuario\n"; // ok
    cout << "3. Emprestar Livro\n"; // ok
    cout << "4. Devolver Livro\n"; // ok                                  
    cout << "5. Pesquisar Livro\n"; // ok
    cout << "6. Listar Livros\n"; // ok
    cout << "7. Verificar Livros Emprestados por Usuario\n"; // ok
    cout << "8. Relatorio de Emprestimos\n"; 
    cout << "9. Listar Usuários\n"; // ok
    cout << "10. Fechar o dia\n"; // ok
    cout << "0. Sair\n"; // ok
    cin >> opcao;
    cout << endl;
}

void cadastrarLivro(vector<Livro> &acervo){
  Livro novoLivro;
  string titulo, autor, categoria;
  int ano, paginas, quant;

  cout << "-Cadastrar Livro-\n";
  getline(cin, novoLivro.titulo = titulo);

  cout << "Título: ";
  getline(cin, novoLivro.titulo = titulo);
  cout << "\n";
  
  cout << "Autor: ";
  getline(cin, novoLivro.autor = autor);
  cout << "\n";

  cout << "Categoria: "; 
  getline(cin, novoLivro.categoria = categoria);
  cout << "\n";

  cout << "Ano de Publicação: "; 
  cin >> ano;
  novoLivro.ano = ano;
  cout << "\n";

  cout << "Número de páginas: ";
  cin >> paginas;
  novoLivro.paginas = paginas;
  cout << "\n";

  cout << "Número de Cópias: "; 
  cin >> quant;
  novoLivro.quantidade = quant;
  // novoLivro.emprestimos = 0;
  acervo.push_back(novoLivro);
};

void pesquisarLivros(vector<Livro>& acervo, string criterio){ 
  int i = 0;
  bool encontrado = false;
  if (acervo.empty()){
    cout << "Não há livros cadastrados ainda!";
  } else {
      for (Livro &livro : acervo){
        if (livro.titulo == criterio || livro.autor == criterio || to_string(livro.ano) == criterio || livro.categoria == criterio){
          cout << "-Livros Encontrados:- \n" 
               << "Índice: " << i+1 << endl
               << "Título: " << livro.titulo << endl
               << "Autor: " << livro.autor << endl
               << "Categoria: " << livro.categoria << endl
               << "Ano: " << livro.ano << endl << endl;
            encontrado = true;
        }
      i++;
      } 
    }if(!encontrado){
        cout << "Nenhum registro encontrado." << endl;
      }
} 

void listagemDeLivros(vector<Livro>& acervo) {
  for (const auto& livro : acervo) {
      cout << "Título: " << livro.titulo << endl
           << "Autor: " << livro.autor << endl
           << "Categoria: " << livro.categoria << endl
           << "Número de páginas: " << livro.paginas << endl
           << "Ano: " << livro.ano << endl
           << "Quantidade: " << livro.quantidade << endl
           << "emprestims: " << livro.emprestimoLivro << endl;
  };
}

void emprestarLivro(vector<Livro>& acervo, vector<Usuario> &usuarios, string &criterio) {
  int livroSelecionado, usuarioSelecionado;
  if (usuarios.empty()){
    cout << "Não há usuários cadastrados ainda!" << endl;
  } else if (acervo.empty()){
      cout << "Não há livros cadastrados ainda!" << endl;
  } else {
      listarUsuarios(usuarios);
      cout << "Selecione o usuário (utilizando o ID): ";
      cin >> usuarioSelecionado;
      cout << "Pesquise o livro (titulo, autor ou ano, 0 para listar todos os livros): ";
      cin >> criterio;
      if (criterio == "0"){
        int i = 0;
        for (Livro livro : acervo){
          cout << "Índice: " << i+1 << endl
               << "Titulo: " << livro.titulo << endl
               << "Autor: " << livro.autor << endl
               << "Categoria: " << livro.categoria << endl << endl;
          i++;
        }
        cout << "Selecione o livro (utilizando o índice): " << endl;
        cin >> livroSelecionado;
        acervo[livroSelecionado-1].quantidade--;
        acervo[livroSelecionado-1].emprestimoLivro++;
        usuarios[usuarioSelecionado-1].livrosEmprestados.push_back(acervo[livroSelecionado-1].titulo);
        usuarios[usuarioSelecionado-1].emprestimos++;
        usuarios[usuarioSelecionado-1].diasParaMulta.push_back(fecharDia+2);
      }else {
        pesquisarLivros(acervo, criterio);
        cout << "Selecione o livro (utilizando o índice): " << endl;
        cin >> livroSelecionado;
        acervo[livroSelecionado-1].quantidade--;
        usuarios[usuarioSelecionado-1].livrosEmprestados.push_back(acervo[livroSelecionado-1].titulo);
        usuarios[usuarioSelecionado-1].diasParaMulta.push_back(fecharDia+2);
      }
    }
}


void devolverLivro(vector<Livro> &acervo, vector<Usuario> &usuarios){
  int livroSelecionado;
  size_t usuarioSelecionado;
  if (usuarios.empty()){
    cout << "Não há usuários cadastrados ainda!" << endl;
  } else {
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
        }
        if (usuario.livrosEmprestados.empty()){
          cout << "O usuário não tem livros para devolver!" << endl;
        } else {
            cout << "Selecione um livro para devolver (utilizando o índice): ";
            cin >> livroSelecionado;
            string livroParaDevolver = usuario.livrosEmprestados[livroSelecionado - 1];
            usuario.livrosEmprestados.erase(
                remove(usuario.livrosEmprestados.begin(), usuario.livrosEmprestados.end(), livroParaDevolver),
                usuario.livrosEmprestados.end()
            );
            for (Livro &livro : acervo){
              if (livro.titulo == livroParaDevolver){
                livro.quantidade++;
            }
          }
        }
    } else {
        cout << "Usuário não encontrado." << endl;
    }
  }
}

void aplicarMulta(vector <Usuario> &usuarios, int &fecharDia){
  float multa = 0.5;
  int i = 0;
  for (Usuario &usuario : usuarios){
    if (usuario.diasParaMulta[i] < fecharDia){
      usuario.multa += multa;
    }
    i++;
  }
}


void relatorioDeEmprestimos(vector<Livro> &acervo, vector<Usuario> &usuarios, int &fecharDia) {
    int totalEmprestimos = 0;
    int maiorUsuario, menorUsuario;
    int maiorLivro, menorLivro;

    float mediaIdadeLeitores = 0;
    float mediaEmprestimosPorDia = 0;

    string livroPopularTitulo, livroMenosPopularTitulo;
    string usuarioMaisAtivoNome, usuarioMenosAtivoNome;
    
    maiorLivro = acervo[0].emprestimoLivro;
    menorLivro = acervo[0].emprestimoLivro;

    for (Livro &livro : acervo) {
        if (livro.emprestimoLivro > maiorLivro){
          maiorLivro = livro.emprestimoLivro;
          livroPopularTitulo = livro.titulo;
        }
        if (livro.emprestimoLivro < menorLivro){
          menorLivro = livro.emprestimoLivro;
          livroMenosPopularTitulo = livro.titulo;
        }
    }

    for (Usuario &usuario : usuarios) { 
        totalEmprestimos += usuario.emprestimos;
        int totalEmprestimosUsuario;

        maiorUsuario = usuarios[0].emprestimos;
        menorUsuario = usuarios[0].emprestimos;
        usuarioMaisAtivoNome = usuarios[0].nome;
        usuarioMenosAtivoNome = usuarios[0].nome;

        totalEmprestimosUsuario += usuario.emprestimos;

        int idadeLeitores = usuario.idade;
        mediaIdadeLeitores += idadeLeitores;

        if (usuario.emprestimos > maiorUsuario){
          maiorUsuario = usuario.emprestimos;
          usuarioMaisAtivoNome = usuario.nome;
        }
        if (usuario.emprestimos < menorUsuario){
          menorUsuario = usuario.emprestimos;
          usuarioMenosAtivoNome = usuario.nome;
        }
    }

    if (fecharDia > 0) {
        mediaEmprestimosPorDia = totalEmprestimos / fecharDia;
    } else if (fecharDia == 0){
        mediaEmprestimosPorDia = totalEmprestimos;
    }

    cout << "\n--- Relatório de Empréstimos ---\n";
    cout << "Total de Empréstimos: " << totalEmprestimos << endl;
    cout << "Livro mais Popular: " << livroPopularTitulo << " com " << maiorLivro << " empréstimos." << endl;
    cout << "Usuário mais Ativo: " << usuarioMaisAtivoNome << " com " << maiorUsuario << " empréstimos." << endl;
    cout << "Média de Empréstimos por Dia: " << mediaEmprestimosPorDia << " empréstimos por dia." << endl;
    cout << mediaIdadeLeitores << " " << usuarios.size() << endl;
    cout << "Média da idade dos leitores: " << mediaIdadeLeitores / usuarios.size() << endl;
}