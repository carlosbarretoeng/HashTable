#include "TabelaHash.h"

int main() {
    int opcoes;
    auto *tabelaHash = new TabelaHash();

    // Operações sobre a tabela;
    do {
        cout << "------------------------------------------" << endl;
        cout << "[   INFO] O QUE DESEJA FAZER?" << endl;
        cout << "[   INFO] 0 - ENCERRAR O PROGRAMA" << endl;
        cout << "[   INFO] 1 - ADICIONAR ELEMENTO NA TABELA" << endl;
        cout << "[   INFO] 2 - EXCLUIR ELEMENTO NA TABELA" << endl;
        cout << "[   INFO] 3 - PROCURAR ELEMENTO NA TABELA" << endl;
        cout << "[   INFO] 4 - VISUALIZAR A TABELA" << endl;
        cin >> opcoes;

        int elemento;
        switch (opcoes) {
            case 0:
                break;
            case 1:
                cout << "[   INFO] QUAL VALOR DESEJA ADICIONA A TABELA?" << endl;
                cin >> elemento;
                tabelaHash->adicionar(elemento);
                break;
            case 2:
                cout << "[   INFO] QUAL VALOR DESEJA REMOVER DA TABELA?" << endl;
                cin >> elemento;
                tabelaHash->remover(elemento);
                break;
            case 3:
                cout << "[   INFO] QUAL VALOR DESEJA LOCALIZAR NA TABELA?" << endl;
                cin >> elemento;
                if(tabelaHash->localizar(elemento)){
                    cout << "[   INFO] ELEMENTO PRESENTE NA TABELA" << endl;
                }else{
                    cout << "[   INFO] ELEMENTO NÃO ENCONTRADO" << endl;
                }
                break;
            case 4:
                tabelaHash->imprimir();
                break;
            default:
                cout << "[WARNING] OPCAO INVALIDA. TENTE NOVAMENTE" << flush;
        }
    } while (opcoes != 0);

    return 0;
}
