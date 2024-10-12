#include <iostream> 
#include <fstream> //biblioteca C++ com classes de manipulação de arquivos.
#include <string>
#include <vector>

using namespace std;
typedef struct {
    int num_palavras;
    vector<string> palavras;
} cont_arq;

int main(){
    ifstream arq("palavras.txt");
    
    if(!arq.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
    
    cont_arq wordle;
    
    arq >> wordle.num_palavras;
    
    string palavra_atual;
    for(int i = 0; i < wordle.num_palavras; i++){
        arq >> palavra_atual;
        wordle.palavras.push_back(palavra_atual); //push_back é uma função que adiciona dinamicamente elementos ao final de um vetor ou string. 
    }
    
    arq.close(); //até aqui foi feita a abertura do arquivo e o armazenamento dele inteiro em um struct baseado em uma estrutura dinâmica do C++, o vetor.
    
    int num_palavra_secreta;
    cin >> num_palavra_secreta; //absorve a palavra a ser adivinhada.
    while(num_palavra_secreta <= 0 || num_palavra_secreta > wordle.num_palavras){
        cout << "Palavra inexistente! Escolha alguma entre 1 e " << wordle.num_palavras << "!";
    }
    
    string palavra_secreta = wordle.palavras[num_palavra_secreta - 1]; //salva a palavra secreta em uma variável. O endereçõ é subtraido de um para se encaixar na lógica da linguagem.
    
    int num_tentativas = 0;
    string tentativa;
    string ch_ausentes;
    
    while(num_tentativas < 5){
        cin >> tentativa;
        num_tentativas++;
        string s = "*****";
        for(int i = 0; i < 5; i++){
            size_t index = palavra_secreta.find(tentativa[i]); //verifica se o caracter do loop está presente na palavra secreta.
            if(index != string::npos && tentativa[i] == palavra_secreta[i]) s[i] = tentativa[i]; 
            else if(index != string::npos && tentativa[i] != palavra_secreta[i]) s[i] = tolower(tentativa[i]);
            else if(index == string::npos && ch_ausentes.find(tentativa[i]) == string::npos) ch_ausentes.push_back(tentativa[i]); //adiona os caracteres ausentes não adicionados a ch_ausentes.
        }
        cout << s << " (" << ch_ausentes << ")" << endl;
        if(s == palavra_secreta){cout << "GANHOU!" << endl; return 0;}
    }
    cout << "PERDEU! " << palavra_secreta << endl;
    
    return 0;
}
