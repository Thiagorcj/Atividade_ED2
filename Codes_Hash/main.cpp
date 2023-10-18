/*                     Atividade Estrutura de dados
                
                Aluno: Thiago Rodrigues Cruz Justino
                Matrícula: 20220007276
            
                                                                            */
                                                                            
#include "hash.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int maxAlunos;
    cout << "Defina o número máximo de alunos que a tabela pode conter: ";
    cin >> maxAlunos;

    HashTable tabelaHash(maxAlunos);

    int escolha;
    do {
        cout << "\nMenu:\n";
        cout << "1. Inserir Aluno\n";
        cout << "2. Deletar Aluno\n";
        cout << "3. Buscar Aluno por RA\n";
        cout << "4. Buscar Aluno por Nome\n";
        cout << "5. Imprimir Tabela\n";
        cout << "6. Sair\n";
        cout << "Escolha a opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                // Insere Aluno
                int matricula;
                string nome;
                cout << "Digite a matrícula do aluno: ";
                cin >> matricula;
                cout << "Digite o nome do aluno: ";
                cin.ignore();
                getline(cin, nome);
                Aluno aluno(matricula, nome);
                tabelaHash.insert(aluno);
                cout << "Aluno inserido com sucesso." << endl;
                break;
            }
            case 2: {
                // Deleta Aluno
                int matricula;
                cout << "Digite a matrícula do aluno a ser deletado: ";
                cin >> matricula;
                tabelaHash.remover(matricula);
                cout << "Aluno deletado com sucesso." << endl;
                break;
            }
            case 3: {
                // Busca Aluno por RA
                int matricula;
                cout << "Digite a matrícula do aluno a ser buscado: ";
                cin >> matricula;
                Aluno result(0, "");
                if (tabelaHash.searchByRA(matricula,result)) {
                    cout << "Aluno encontrado: Matrícula = " << result.ra << ", Nome = " << result.nome << endl;
                } else {
                    cout << "Aluno não encontrado." << endl;
                }
                break;
            }
            case 4: {
                // Busca Aluno por Nome
                string nome;
                cout << "Digite o nome do aluno a ser buscado: ";
                cin.ignore(); // Limpa o buffer de entrada antes de ler a string
                getline(cin, nome);
                Aluno result(0, "");
                if (tabelaHash.searchByName(nome, result)) {
                    cout << "Aluno encontrado: Matrícula = " << result.ra << ", Nome = " << result.nome << endl;
                } else {
                    cout << "Aluno não encontrado." << endl;
                }
                break;
            }
            case 5:
                // Imprimir Tabela
                tabelaHash.imprimir();
                break;
            case 6:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (escolha != 6);

    return 0;
}