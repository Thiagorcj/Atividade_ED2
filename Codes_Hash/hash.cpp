#include "hash.h"


HashTable::HashTable(int n) {
    firstLevel.resize(firstLevelSize);
    for (auto& sublist : firstLevel) {
        sublist.resize( n / firstLevelSize);
    }
}

int HashTable::firstLevelHash(int ra) {
    return ra % firstLevelSize;
}

int HashTable::secondLevelHash(const string& nome) {
    return nome.length() % (secondLevelSize / firstLevelSize);
}

void HashTable::insert(const Aluno& aluno) {
    int firstIndex = firstLevelHash(aluno.ra);
    int secondIndex = secondLevelHash(aluno.nome);

    firstLevel[firstIndex][secondIndex].push_back(aluno);
}

void HashTable::imprimir() {
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

bool HashTable::searchByRA(int ra, Aluno& result) {
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

bool HashTable::searchByName(const string& nome, Aluno& result) {
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

void HashTable::remover(int ra) {
    int firstIndex = firstLevelHash(ra);

    for (auto& aluno : firstLevel[firstIndex]) {
        for (auto& a : aluno) {
            if (a.ra == ra) {
                a.ativo = false;  // Define o aluno como inativo
            }
        }
    }
}