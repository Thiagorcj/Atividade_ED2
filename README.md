# Atividade prática de Estrutura de dados - Prática Tabela Hash
## Aluno: Thiago Rodrigues Cruz Justino (20220007276)
## Professor: Gilberto Farias
## Questões:
Implementar uma estrutura de tabela hash para armazenar n objetos
com encadeamento separado duplo. No encadeamento duplo existem
dois níveis de endereçamento, nos dois o mapeamento da chave ao
endereço se dá por uma função hash. A figura abaixo ilustra o
esquema de encadeamento separado duplo.

- No primeiro nível crie um vetor com 10 ponteiros para vetores.
Aplique a função hash para direcionar o elemento da chave c
em uma das outras tabelas do segundo nível;

- No segundo nível cada tabela é composta por um vetor de n/10
listas de objetos a serem armazenados. Uma segunda função
hash diferente da primeira deve ser definida para direcionar a
chave c em uma das listas específicas
- Implemente as funções hash específica de cada nível de
endereçamento, além dos métodos de inserção de novos objetos a
partir de suas chaves únicas e recuperação de objetos já cadastrados a
partir da chave única.
## Resposta
Para resolver tais questões, resolvi criar um cenário no qual desejava criar um sistema de cadastro de alunos por meio de sua matrícula e nome, utilizando os conceitos apresentados e requisitados nas questões como tabela hash com encadeamento duplo.
- Funções Hash de primeiro e segundo nível:
```cpp

int HashTable(int n) { // n é o número máximo de alunos que podem ser cadastrados, definido no início do programa
    firstLevel.resize(firstLevelSize); // firstLevelSize vale 10, como definido na questão
    for (auto& sublist : firstLevel) {
        sublist.resize( n / firstLevelSize);
    }
}

int FirstLevelHash(int ra) {
    return ra % firstLevelSize;
}

int SecondLevelHash(const string& nome) {
    return nome.length() % (secondLevelSize / firstLevelSize);
}
```
- Método de inserção e Outros: No cenário que criei, achei interessante criar funções para adicionar alunos, printar os alunos matriculados, pesquisar aluno por matrícula, pesquisa aluno por nome e ,por fim, uma função para desativar o aluno. 

```cpp
// Inserir
void insert(const Aluno& aluno) {
    int firstIndex = firstLevelHash(aluno.ra);
    int secondIndex = secondLevelHash(aluno.nome);

    firstLevel[firstIndex][secondIndex].push_back(aluno);
}
// Imprimir alunos ativos
void print_info() {
    for (int i = 0; i < firstLevelSize; i++) {
        for (int j = 0; j < (secondLevelSize / firstLevelSize); j++) {
            for (const Aluno& aluno : firstLevel[i][j]) {
                if (aluno.ativo) {
                    cout << "Matrícula: " << aluno.ra << ", Nome: " << aluno.nome << endl;
                }
            }
        }
    }
}
// Pesquisar por matrícula
bool searchByRA(int ra, Aluno& result) {
    for (int i = 0; i < firstLevelSize; i++) {
        for (int j = 0; j < (secondLevelSize / firstLevelSize); j++) {
            for (const Aluno& aluno : firstLevel[i][j]) {
                if (aluno.ra == ra && aluno.ativo) {
                    result = aluno;
                    return true;
                }
            }
        }
    }
    return false;
}
// Pesquisar por nome
bool searchByName(const string& nome, Aluno& result) {
    for (int i = 0; i < firstLevelSize; i++) {
        for (int j = 0; j < (secondLevelSize / firstLevelSize); j++) {
            for (const Aluno& aluno : firstLevel[i][j]) {
                if (aluno.nome == nome && aluno.ativo) {
                    result = aluno;
                    return true;
                }
            }
        }
    }
    return false;
}
// Desativar aluno
void remover(int ra) {
    int firstIndex = firstLevelHash(ra);

    for (auto& aluno : firstLevel[firstIndex]) {
        for (auto& a : aluno) {
            if (a.ra == ra) {
                a.ativo = false;  // Define o aluno como inativo
            }
        }
    }
}

```

