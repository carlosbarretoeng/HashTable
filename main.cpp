#include "TabelaHash.h"

#include "Lista.h"

void adicionarElementoNaTabela(TabelaHash *tabelaHash) {
    int elemento;
    cout << "QUAL VALOR DESEJA ADICIONA A TABELA?";
    cin >> elemento;
    tabelaHash->adicionar(elemento);
}

void removerElementoNaTabela(TabelaHash *tabelaHash) {
    int elemento;
    cout << "QUAL VALOR DESEJA REMOVER DA TABELA?";
    cin >> elemento;
    tabelaHash->remover(elemento);
}

void localizarElementoNaTabela(TabelaHash *tabelaHash) {
    int elemento;
    cout << "QUAL VALOR DESEJA LOCALIZAR NA TABELA?";
    cin >> elemento;
    if(tabelaHash->localizar(elemento)){
        cout << "ELEMENTO PRESENTE NA TABELA" << endl;
    }else{
        cout << "ELEMENTO AUSENTE DA TABELA" << endl;
    }
}

int main() {
    int slots = 0;
    int opcoes = 0;

    // Obtem o número de slots da tabela hash
    do{
        cout << "QUANTOS SLOTS EXISTIRAO NA TABELA HASH? (1...100)" << endl;
        cin >> slots;

        if (slots < 1 || slots > 100) {
            cout << "VALOR INVALIDO. POR FAVOR ATENHA-SE AOS LIMITES." << endl;
        }
    } while (slots < 1 || slots > 100);

    // Instancia a tabela
    auto *tabelaHash = new TabelaHash(slots);

    // Operações sobre a tabela;
    do {
        cout << "O QUE DESEJA FAZER?" << endl;
        cout << "0 - ENCERRAR O PROGRAMA" << endl;
        cout << "1 - ADICIONAR ELEMENTO NA TABELA" << endl;
        cout << "2 - EXCLUIR ELEMENTO NA TABELA" << endl;
        cout << "3 - PROCURAR ELEMENTO NA TABELA" << endl;
        cout << "4 - VISUALIZAR A TABELA" << endl;
        cout << "5 - FATOR DE CARGA DA TABELA" << endl;
        cin >> opcoes;

        switch (opcoes) {
            case 0:
                break;
            case 1:
                adicionarElementoNaTabela(tabelaHash);
                break;
            case 2:
                removerElementoNaTabela(tabelaHash);
                break;
            case 3:
                localizarElementoNaTabela(tabelaHash);
                break;
            case 4:
                tabelaHash->imprimir();
                break;
            case 5:
                cout << "Fator de Carga: " << tabelaHash->obterFatorDeCarga() << endl;
                break;
            default:
                cout << "OPCAO INVALIDA. TENTE NOVAMENTE" << flush;
        }
    } while (opcoes != 0);

    return 0;
}
