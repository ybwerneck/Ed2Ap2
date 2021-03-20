// edap2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include <string>
using namespace std;
string encrypt(string s) {
    string aux="",next="";

    int buffer = 4, c = 0, dic = 6;

    while (s[c] != NULL) {
        int pos=0, len=0;
        next = s[c];
        int  j, k;
        for ( k = c - dic;k<c;k++)
        {
            if(k>=0)
            {
                s[c];
                int l = 0;
                j = c;

                if (s[j] == s[k])
                {
                    do l++; while (s[j + l]!=NULL && s[j+l] == s[k + l%(c-k)] && l  < buffer);

                }
                if (l > len)
                {
                    len = l;
                    pos = c - k;
                    next = s[j + l];
                    
                }

            }

        }
        aux += std::to_string(pos) +","+ std::to_string(len)+"," + next+"\n";
        c++;
        c += len;
        if (c >= s.length())
            break;
     
    }

    return aux;
}
string decrypt(string s) {
    string aux;
    int buffer = 4, c = 0, dic = 6;
    string l = strtok(&s[0], "\n");
    char *end;
    aux += l[4];
    do
    {
        int desloc =  atoi(strtok(NULL, ","));
        int len = atoi(strtok(NULL, ","));
        end=strtok(NULL, "\n");
        string a="";
        int ind = aux.length() - desloc;
        for (int i = 0; i < len; i++) {
            a += aux[ind+i%(desloc)];
        }
        aux += a;
        if (end != NULL)
            aux += *end;
    } while (end != NULL);


    return aux;

}string leArq(string arq) {
    ifstream arquivo(arq);
    string str,aux="";
    while (getline(arquivo, str))
    {
        aux += str;
      
    }
    return aux;

}

int main()
{
    string arquivo;
    cout << "Digite o nome do arquivo a ser codificado " << endl;
    cin >> arquivo;
    string comprimida= encrypt(leArq(arquivo));
    string descomprimida = decrypt(comprimida);
    cout <<"\nResultado comprimido: "<< comprimida << "\n\n" << "Resultado descomprimido : " << descomprimida;
    cout <<"\n \n";
    int op;
    cout << "Digite 1 para salvar em um arquivo 0 para sair " << endl;
    cin >> op;
    if (op == 1)
    {

        cout << "Digite o nome do arquivo de saida " << endl;
        cin >> arquivo;
        ofstream arq(arquivo);
        arq << comprimida;
    }
}
