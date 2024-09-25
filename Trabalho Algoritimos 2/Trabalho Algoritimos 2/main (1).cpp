#include <iostream>
#include <vector>
#include "biblioteca.cpp"
#include "usuarios.cpp"
using namespace std;
#define TAM 50

int main() {
    acervo.push_back({"O Senhor dos Anéis", "J.R.R. Tolkien", "Fantasia", 5, 1954, 1008, 0});
    acervo.push_back({"1984", "George Orwell", "Distopia", 5, 1949, 328, 0});
    acervo.push_back({"Dom Casmurro", "Machado de Assis", "Clássico", 5, 1899, 256, 0});
    
    usuarios.push_back({"Carlos", 45, 0, {}, {}, 0.0});
    usuarios.push_back({"Antonio", 40, 0, {}, {}, 0.0});
    usuarios.push_back({"Julia", 19, 0, {}, {}, 0.0});
    
    int opcao;
    string criterio;
    bool sair = false;
    do {
        cout << "Dia " << fecharDia << endl;
        menu(opcao);
        switch (opcao) {

            case 1:{
                cadastrarLivro(acervo);
                break;
            }

            case 2:{
                cadastrarUsuario(usuarios);
                break;
            }

            case 3:{
                emprestarLivro(acervo, usuarios, criterio);
                break;
            }

            case 4:{
                devolverLivro(acervo, usuarios);
                break;
            }

            case 5:{   
                cout << "Pesquisar por título, autor ou ano: "; 
                cin.ignore();
                getline(cin, criterio);
                cout << "\n\n"; 
                pesquisarLivros(acervo, criterio);
                break;
            }


            case 6:{
                listagemDeLivros(acervo);
                break;
            }

            case 7:{
                pesquisarLivrosPorUsuario(usuarios);
                break;
            }

            case 8:{
                relatorioDeEmprestimos(acervo, usuarios, fecharDia);  
                break;
            }

            case 9:{
                listarUsuarios(usuarios);
                break;
            }

            case 10:{
                fecharDia++; 
                aplicarMulta(usuarios, fecharDia);
                break;
            }

            case 0:{
                cout << "Saindo...";
                sair = true;
                break;
            }

            default:{
                cout << "Opção errada! Digite novamente.";
                break;
            }
            }

    } while (!sair);

    return 0;
}