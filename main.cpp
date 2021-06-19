#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//Estrutura que represanta os dados de um aluno
//numa lista duplamente encadeada
typedef struct Aluno
{
    int matricula;
    char nome[20];
    int idade;
    struct Aluno *proxiA;
    struct Aluno *antA;

} tipoAluno;

//Estrutura que represanta os dados de uma classe
//numa lista simplismente encadeada e guarda informaçoes de um aluno

typedef struct Classe
{
\
    struct Classe *proxmaC;
    tipoAluno *inicioA;
    tipoAluno * fimA;
    int serie;
    char turma[20];
    char etapa[20];
    char prof[20];
    int quant;

} tipoClasse;

//Estrutura que guarde informaçoes de uma classe

typedef struct listaClasse
{

    tipoClasse *inicioC;
    tipoClasse *fimC;
    int quantl;
} tipoLista;

//Funçao que faz a inicializaçao da lista encadeada de classe

void iniciar_variaveisTC (tipoLista *lista)
{
    lista->fimC = NULL;
    lista->inicioC = NULL;
    lista->quantl = 0;
}

//Funçao que verifica se a lista de classe esta vazia

int lista_Vazia(tipoLista *lista)
{

    if (lista->inicioC == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

//Função que faz a inserção de uma classe na lista e inicialisa a lista duplamente encadeada de Aluno

int inserir_ClasseV (tipoLista *lista )
{
    tipoClasse *novaClas;

    novaClas = (tipoClasse*)malloc(sizeof(tipoClasse));
    if (novaClas == NULL)
    {
        return 0;
    }
    else
    {
        fflush(stdin);
        cout << "*Adicionar Classe "<< endl<<endl;
        cout << "Informe o Nome professor(a) responssavel da classe (Professor)"<< endl;
        gets(novaClas->prof);
        cout << "Informe a Serie "<<endl;
        cin >> novaClas->serie;
        fflush(stdin);
        cout << "Informe a Turma "<< endl;
        cin >> novaClas->turma;
        cout << "informe a Etapa "<< endl;
        cin >> novaClas->etapa;
        novaClas->quant = 0;
        novaClas->inicioA = NULL;
        novaClas->fimA = NULL;

        novaClas->proxmaC = NULL;
        lista->inicioC = novaClas;
        lista->fimC = novaClas;
        lista->quantl++;
        return 1;
    }

}

//Função que faz a incerçao no fim da fila de Classe

int inserir_fim_classe (tipoLista *lista)
{
    tipoClasse *novaClas;
    if (lista->inicioC == NULL)
    {
        inserir_ClasseV(lista);
    }
    else
    {
        novaClas = (tipoClasse*)malloc(sizeof(tipoClasse));
        if (novaClas== NULL)
        {
            return 0;
        }
        else
        {
            fflush(stdin);
            cout << "*Adicionar Classe "<< endl<<endl;
            cout << "Informe o Nome professor(a) responssavel da classe (Professor)"<< endl;
            gets(novaClas->prof);
            cout << "Informe a Serie "<<endl;
            cin >> novaClas->serie;
            cout << "Informe a Turma "<< endl;
            cin >> novaClas->turma;
            cout << "informe a Etapa "<< endl;
            cin >> novaClas->etapa;

            novaClas->quant = 0;
            novaClas->inicioA = NULL;
            novaClas->fimA = NULL;
            novaClas->proxmaC = NULL;
            lista->fimC->proxmaC = novaClas;
            lista->fimC = novaClas;
            lista->quantl++;
            return 1;
        }
    }
}

//Funçao que verifica se a Classe esta vazia

int Verifica_Classe (tipoLista *lista, char *busca, int serie)
{
    tipoClasse *aux;

    aux = lista->inicioC;
    if (strcmp(aux->turma, busca)== 0 && aux->serie == serie)
    {
        return 1;
    }
    else
    {
        while (aux != NULL)
        {
            if(strcmp(aux->turma, busca)== 0 && aux->serie == serie)
            {
                return 1;
            }
            aux = aux->proxmaC;
        }
    }
    cout << "Classe nao encontrada "<<endl;
    return 0;
}

// Funçao que busca e Classe e exibe as informaçoes dela


int buscar_Classe (tipoLista *lista, char *busca, int serie)
{
    tipoClasse *aux;

    aux = lista->inicioC;
    if (strcmp(aux->turma, busca)== 0 && aux->serie == serie)
    {
        cout<<endl;
        cout << "* Classe *"<<endl<<endl;
        cout <<"Turma ->"<< aux->turma<<endl;
        cout <<"Etapa ->"<< aux->etapa<< endl;
        cout <<"Serie ->"<< aux->serie<<endl;
        cout << "nome professor ->"<< aux->prof<<endl;
        cout << endl;
        cout << "quantidade de alunos "<<aux->quant<< endl;
        cout <<"================="<<endl;
        return 1;
    }
    else
    {
        while (aux != NULL)
        {
            if(strcmp(aux->turma, busca)== 0 && aux->serie == serie)
            {
                cout<<endl;
                cout << "* Classe *"<<endl;
                cout <<"Turma "<< aux->turma<<endl;
                cout <<"Etapa "<< aux->etapa<< endl;
                cout <<"Serie "<< aux->serie<<endl;
                cout << "nome professor "<< aux->prof<<endl;
                cout << endl;
                cout << "quantidade de alunos "<<aux->quant<< endl;
                cout <<"================="<<endl;
                return 1;
            }
            aux = aux->proxmaC;
        }
    }
    cout << "Nao encontrada "<<endl;
    return 0;
}

//Funçao que busca um Aluno numa Classe que seja informada pelo usuario

tipoClasse* buscar_Aluno(tipoLista *lista, char *buscaT, int buscaS)
{
    tipoClasse *atual;
    if (Verifica_Classe(lista,buscaT,buscaS))
    {
        atual = lista->inicioC;
        while (atual!=NULL)
        {
            if (strcmp(buscaT,atual->turma)==0 && atual->serie == buscaS)
            {
                return atual;
            }
            atual = atual->proxmaC;
        }
    }
    else (cout << "aluno nao encontrado ")<< endl;

}

// verifica se ha aluno em uma classe

int Verificar_aluno (tipoLista *l, char *turma, int serie,int num)
{

    tipoAluno *aux;
    tipoClasse *au;

    au = buscar_Aluno(l,turma,serie);

    aux = au->inicioA;

    while (aux!= NULL)
    {
        if (aux->matricula == num )
        {
            return 1;
        }
        aux = aux->proxiA;
    }
    return 0;

}

//Verifica se ha pelomenos um aluno na lista de uma classe

int Verificar_aluno2 (tipoLista *l, char *turma, int serie)
{

    tipoAluno *aux;
    tipoClasse *au;

    au = buscar_Aluno(l,turma,serie);

    aux = au->inicioA;


    if (au->inicioA == NULL){
           return 0;
    }
    return 1;


}

// funçao que faz a inserçao de um alino numa lista de classe

int inserir_Aluno_Classe_Vazia (tipoClasse *lista)
{
    tipoAluno *novoAluno;

    novoAluno =(tipoAluno*)malloc(sizeof(tipoAluno));
    if (novoAluno ==  NULL)
    {
        return 0;
    }

    cout << "\nInforme o nome do aluno :"<< endl;
    cin>> novoAluno->nome;
    cout << "Informe  a matricula :" << endl;
    cin >> novoAluno->matricula;
    cout <<"informe a idade do aluno :"<< endl;
    cin >> novoAluno->idade;


    novoAluno->antA = NULL;
    novoAluno->proxiA = NULL;
    lista->fimA = novoAluno;
    lista->inicioA = novoAluno;
    lista->quant++;


}


// funçao que faz a inserçao de um aluno no fim de uma lista de classe

int inseri_Aluno_Classe (tipoClasse *lista)
{
    tipoAluno *novoAluno;
    if (lista->inicioA== NULL)
    {
        inserir_Aluno_Classe_Vazia(lista);
    }
    else
    {
        novoAluno = (tipoAluno*)malloc(sizeof(tipoAluno));
        if (novoAluno == NULL)
        {
            return 0;
        }
        else
        {
            cout << "\nInforme o nome do aluno :"<< endl;
            cin>> novoAluno->nome;
            cout << "Informe  a matricula :" << endl;
            cin >> novoAluno->matricula;
            cout <<"informe a idade do aluno :"<< endl;
            cin >> novoAluno->idade;

            novoAluno->proxiA = NULL;
            novoAluno->antA = lista->fimA;
            lista->fimA->proxiA = novoAluno;
            lista->fimA = novoAluno;
            lista->quant++;
            return 1;

        }


    }
}

//Funçao que verifica se a lista de aluno esta vazia

int Aluno_vazia (tipoClasse *lista)
{

    if (lista->inicioA == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// Funçao que remove do inicio de uma classe
void remover_Aluno_inicio(tipoClasse *lista)
{
    tipoAluno *aux;

    if (!lista->inicioA)
    {
        cout<< "lista vazia "<< endl;
    }
    else
    {
        aux = lista->inicioA;
        if (aux->proxiA == NULL)
        {
            lista->fimA = NULL;
            lista->inicioA = NULL;
            lista->quant = 0;
        }
        else
        {
            lista->inicioA = aux->proxiA;
            lista->inicioA->antA = NULL;
            lista->quant--;
        }
    }
    free(aux);


}

//Funçao que remove do fim de uma lista de uma classe
void remover_Aluno_fim (tipoClasse *lista)
{
    tipoAluno *aux;

    if (!lista->fimA)
    {
        cout <<"lista vazia "<< endl;
    }
    else
    {
        aux = lista->fimA;
        if (!aux->antA)
        {
            lista->fimA = NULL;
            lista->inicioA = NULL;
            lista->quant = 0;
        }
        else
        {
            lista->fimA = aux->antA;
            lista->fimA->proxiA = NULL;
            lista->quant --;
        }

    }
    free(aux);

}

//Funçao que remove o aluno de uma determinda posiçao de uma classe

void remover_Aluno_Busca (tipoClasse *lista, int num)
{

    tipoAluno *atual, *fim;
    fim = lista->fimA;
    atual = lista->inicioA;

    if (atual->matricula == num)
    {
        remover_Aluno_inicio(lista);
        cout << "Aluno removido da Classe "<< endl;
    }
    else if (fim->matricula == num)
    {
        remover_Aluno_fim(lista);
        cout << "Aluno removido da Classe "<< endl;
    }
    else
    {

        while (atual != NULL)
        {


            if (atual->matricula == num)
            {
                atual->antA->proxiA = atual->proxiA;
                atual->proxiA->antA = atual->antA;

            }
            atual = atual->proxiA;


        }
        if (atual->matricula != num)
        {
            cout << "Aluno nao encontrado "<< endl;
        }
        else
        {
            cout << "Aluno removido da Classe "<< endl;
            lista->quant--;
            free(atual);
        }
    }

}

// Funçao que remove todos os alunos de uma classe

void remover_Todos_Alunos (tipoClasse *lista)
{
    tipoAluno *aux;
    aux = lista->inicioA;
    while (aux != NULL)
    {
        remover_Aluno_inicio(lista);
        aux = aux->proxiA;
    }free(aux);
}

//Funçao que remove uma classe do inicio

void remove_Classe_Inicio (tipoLista *lista)
{
    tipoClasse *aux;

    aux = lista->inicioC;
    lista->inicioC = lista->inicioC->proxmaC;
    if (lista->quantl == 1)
    {
        lista->inicioC = NULL;

    }
    lista->quantl --;
    free(aux);

}

//Funçao que remove do fim de uma classe

void remover_Classe_fim (tipoLista *lista)
{
    tipoClasse *aux, *ant;



    aux = lista->inicioC;

    if (aux->proxmaC != NULL)
    {
        while (aux->proxmaC!= NULL)
        {

            ant = aux;
            aux = aux ->proxmaC;
        }
        ant->proxmaC = NULL;
        lista->fimC = ant;

    }
    else
    {
        lista->inicioC = NULL;
        lista->fimC = NULL;
    }
    lista->quantl --;

    free(aux);

}

// Funçao que remove uma classe de uma determinada posiçao

void remover_Classe (tipoLista *lista,int serie, char *turma)
{
    tipoClasse *aux, *aux2, *ant;
        aux = lista->inicioC;
        aux2 = lista->fimC;




    if (buscar_Classe(lista,turma,serie))
    {

        if (aux->serie == serie && strcmp(aux->turma,turma)==0 )
        {
        if (!Aluno_vazia(aux))
        {
        remover_Todos_Alunos(aux);

        }
            remove_Classe_Inicio(lista);
            cout << "Classe removida com sucesso "<< endl;
        }
        else if(aux2->serie == serie && strcmp(aux2->turma,turma)==0)
        {
        if (!Aluno_vazia(aux2))
        {
        remover_Todos_Alunos(aux);

        }


            remover_Classe_fim(lista);
            cout << "Classe removida com sucesso "<< endl;
        }
        else
        {

            while (aux != NULL)
            {

                if(aux->serie == serie && strcmp(aux->turma,turma) == 0)
                {
                    if(!Aluno_vazia(aux)){
                        remover_Todos_Alunos(aux);

                    }
                    ant->proxmaC = aux->proxmaC;

                }ant = aux;
                aux = aux->proxmaC;
            }

            cout << "Classe removida com sucesso "<< endl;
            lista->quantl --;
            free(aux);

        }

    }
}


// Funçao que exibe todas as classes de uma lista

void exibi_classe (tipoLista *lista)
{
    tipoClasse *aux;
    int i = 1;
    aux = lista->inicioC;
    while(aux != NULL)
    {
        cout <<"*Classe         ::"<< i<< endl;
        cout <<"*Serie          ::"<<aux->serie<<endl;
        cout <<"*Turma          ::"<< aux->turma<<endl;
        cout <<"*Etapa          ::"<< aux->etapa<< endl;
        cout <<"*Nome Professor ::"<< aux->prof<<endl;
        cout << endl;
        cout << "Quantidade de Alunos ::"<<aux->quant<< endl;
        cout <<"================="<<endl;
        aux = aux->proxmaC;
        i ++;

    }

}

//Funçao que exibe a lista de alunos da classe


void exibir_Aluno (tipoClasse *lista)
{

    tipoAluno *aux;

    if (Aluno_vazia(lista))
    {
        cout << "Lista Vazia"<<endl <<endl;
    }
    else
    {
        aux = lista->inicioA;
        int i = 1;
        cout << "==== Alunos Cadastrados na Classe ====" << endl<< endl;
        while (aux != NULL)
        {


            cout <<i<< "*NOME ALUNO ::"<< aux->nome<<endl;
            cout << " *MATRICULA  ::" << aux->matricula<< endl;
            cout << " *IDADE      ::"<< aux->idade<< endl<< endl;
            i++;
            aux = aux->proxiA;
        }
    }

}


//Estrutura auxiliar pra buscar informaçoes

typedef struct infoAluno
{

    char nome[20];
    char busT[20];
    int serie;
    int matricula;
    int idade;

} Alunos;


int menu ();



int main()
{

    Alunos a;
    int esc;
    tipoClasse *aux;
    tipoLista lista;
    iniciar_variaveisTC(&lista);
    do
    {
        esc = menu();
        switch (esc)
        {
        case 1:
            system("cls");

            fflush(stdin);
            inserir_fim_classe(&lista);
            cout << "*Classe Criada !!!" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            if (lista_Vazia(&lista))
            {
                cout << "Nao ha nenhuma classe cadastrada "<< endl;
            }
            else
            {
                fflush(stdin);
                cout <<"*informaçao da(s) classes "<< endl;
                exibi_classe(&lista);

                cout <<"*informe a Turma ::";
                cin>>a.busT;
                cout<<endl;
                cout <<"*informe a Serie  ::";
                cin>> a.serie;

                if (Verifica_Classe(&lista,a.busT,a.serie))
                {
                    aux = buscar_Aluno(&lista,a.busT,a.serie);
                    fflush(stdin);
                    inseri_Aluno_Classe(aux);
                }
            }
            system("pause");
            break;
        case 3:
            system("cls");

            if (lista_Vazia(&lista))
            {
                cout <<"Nao a nenhuma Classe cadastrada "<< endl;
            }
            else
            {
                exibi_classe(&lista);

                cout << "*informe a Turma ::";
                fflush(stdin);
                cin >> a.busT;
                cout << "\n*Informe a serie ::";
                cin >> a.serie;
                system("cls");
                if (Verifica_Classe(&lista,a.busT,a.serie))
                {
                   if(!Aluno_vazia(buscar_Aluno(&lista,a.busT,a.serie))){
                    cout << "Informaçao do aluno"<< endl;
                    exibir_Aluno(buscar_Aluno(&lista,a.busT,a.serie));
                    cout << "*Informe a matricula do aluno que sera removido "<<endl;
                    cin >>a.matricula;
                    fflush(stdin);
                    if(!Verificar_aluno(&lista,a.busT,a.serie,a.matricula))
                    {
                        cout << "Aluno nao encontrado" << endl;
                    }
                    else
                    {
                        remover_Aluno_Busca(buscar_Aluno(&lista,a.busT,a.serie),a.matricula);
                    }
                }cout << "Nao ha nenhum aluno na classe"<< endl;}
            }
            fflush(stdin);
            system("pause");
            break;
        case 4:
            system("cls");
            if (lista_Vazia(&lista))
            {
                cout <<"Nao a nenhuma Classe cadastrada "<< endl;
            }
            else
            {
                exibi_classe(&lista);
                cout << "*informe a Turma ::";
                fflush(stdin);
                cout<< endl;
                cin >> a.busT;
                cout << "\n*Informe a serie ::";
                cin >> a.serie;
                system("cls");
                if (!Aluno_vazia(buscar_Aluno(&lista,a.busT,a.serie)))
                {
                    if (Verifica_Classe(&lista,a.busT,a.serie))
                    {

                        if (Verificar_aluno2(&lista,a.busT,a.serie))
                        {
                            system("cls");
                            exibir_Aluno((buscar_Aluno(&lista,a.busT,a.serie)));

                        }
                    }
                    else
                    {
                        cout << "Aluno nao encontrado "<< endl;
                    }
                }
                else
                {
                    cout << "A Classe esta vazia "<<endl;
                }
            }

            system("pause");
            break;
        case 5:
            system("cls");
            if (lista_Vazia(&lista)){
                cout<< "Nao a classe cadastrada "<< endl;
            }else {
            exibi_classe(&lista);}
            system("pause");
            break;
        case 6:
            system("cls");
            if (lista_Vazia(&lista))
            {
                cout << "nao ha classe cadastrada "<<endl;
            }
            else
            {
                exibi_classe(&lista);
                fflush(stdin);
                cout <<"*informe a Turma ::";
                cin>>a.busT;
                cout<<endl;
                cout <<"*informe a Serie  ::";
                cin>> a.serie;


                remover_Classe(&lista,a.serie,a.busT);

            }
            system("pause");
            break;
        case 7:
            system("cls");
            if (lista_Vazia(&lista))
            {
                cout << "Nenhuma Classe cadastrada "<< endl;
            }
            else
            {
                fflush(stdin);
                cout <<"*informe a Turma ::";
                cin>>a.busT;
                cout<<endl;
                cout <<"*informe a Serie  ::";
                cin>> a.serie;
                buscar_Classe(&lista,a.busT,a.serie);
            }
            cout << "clsse removida com Sucesso "<< endl;
            system("pause");
            break;
        case 0:
            break;
        default :
            cout << "numero invalido "<< endl;
            break;

        }
    }
    while (esc != 0);

    return 0;

}

// Funçao menu
int menu ()
{
    int esc;
    system("cls");
    cout << "=====MENU====="<<endl;
    cout << "1 - Cadastrar Classe "<< endl;
    cout << "2 - Matricular Aluno "<< endl;
    cout << "3 - Remover Aluno"<< endl;
    cout << "4 - Exbir Aluno de aguma classe"<< endl;
    cout << "5 - Exibir lista de classe e o professor (com quantidade de aluno)"<< endl;
    cout << "6 - Remover classe "<< endl;
    cout << "7 - Pesquisar e exibir qual a classe"<< endl;
    cout << "0 - Sair " << endl;
    cout << ":::::: "<< endl;

    cin>> esc;

    return esc;
}

















