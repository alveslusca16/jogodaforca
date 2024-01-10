/*

1- Digitar o nome;
2- Perguntar se quer ou nao iniciar o game;
3- começar o game;
4- se acertar: mostrar as posições da letra e perguntar novamente uma outra letra;
5- se erra: dizer que errou e desenhar o desenho de erro;
6- se achar a palavra: printar que acertou e perguntar se deseja iniciar novamente;

*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string escolherpalavra() {
	
	ifstream arquivo("palavras.txt");
	
    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        	cerr << "Erro ao abrir o arquivo." << endl;
        return "Erro";
    }

    // Armazena as palavras do arquivo em um vetor
    vector<string> palavras;
    string palavra;
    while (getline(arquivo, palavra)) {
        palavras.push_back(palavra);
    }

    // Fecha o arquivo
    arquivo.close();

    // Verifica se há palavras no vetor
    if (palavras.empty()) {
        	cerr << "Nenhuma palavra encontrada no arquivo." << endl;
        return "Erro";
    }

    // Inicializa a semente para a geração de números aleatórios
    srand(static_cast<unsigned int>(time(0)));
	
	
    // Escolhe uma palavra aleatória
    int indiceAleatorio = rand() % palavras.size();
    	string palavraAleatoria = palavras[indiceAleatorio];

	
	return palavraAleatoria;
}


int main () {
	
	string nomeUsuario; 
	char resp = 'q';
	// Coletar o nome do usúario
	
	cout << "Digite o nome do usúario: " << endl;
	cin >> nomeUsuario;	
	
	system("clear||cls");
	
	// Area para iniciar o game
	
	while (resp != 's') {
		cout << "-----------------------" << endl;
		cout << "     " << endl;
		cout <<"Iniciar a " << nomeUsuario << " partida? (s/n)"<< endl;
		cout << "     " << endl;
		cout << "-----------------------" << endl;
		cin >> resp;
		
		if (resp != 's') {
			clock_t start_time = clock();
    		clock_t desired_duration = 3 * CLOCKS_PER_SEC;  // 5 segundos em unidades de clock

    		while (clock() - start_time < desired_duration); // Aguarda até que o tempo desejado tenha passado
    		system("clear||cls");
		}
		
		
	}
	
	system("clear||cls");
	
	string palavrasecreta = escolherpalavra();
	cout << "Palavra Aleatória: " << palavrasecreta << endl;
	

	
	
	
	
	return 0;
}
