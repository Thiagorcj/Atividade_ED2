#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Aluno {
public:
    int ra;
    string nome;
    bool ativo;

    Aluno(int ra, const string& nome) : ra(ra), nome(nome), ativo(true) {}
};

class HashTable {
private:
    static const int firstLevelSize = 10;
    static const int secondLevelSize = 10;

    int firstLevelHash(int ra);
    int secondLevelHash(const string& nome); 

    vector<vector<vector<Aluno>>> firstLevel; 

public:
    HashTable(int n);
    void insert(const Aluno& aluno);
    bool searchByRA(int ra, Aluno& result);
    bool searchByName(const std::string& nome, Aluno& result);
    void remover(int ra); 
    void imprimir();
};

#endif