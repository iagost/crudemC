#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stddef.h>

#define tam 10

// ALUNO
struct cadastroAluno{

    char nome[40];
    int matricula;

};

struct cadastroAluno alunos[tam];

int count = 0;//contador de alunos

void inserirAluno();
void alteraAluno();
void excluiAluno();
void ListarAlunos();
void menu();
void menu2(int op);

// PROFESSOR

struct cadastroProfessor{
    char nome[40];
    int codigo;
};

struct cadastroProfessor professores[tam];

int count2 = 0;

void insereProfessor();
void alteraProfessor();
void excluiProfessor();
void listarProfessores();

// DISCIPLINA

struct cadastroDisciplina{
    char nome[40];
    int codigo;
};

struct cadastroDisciplina disciplinas[tam];

int count3 = 0;

void insereDisciplina();
void alteraDisciplina();
void excluiDisciplina();
void listarDisciplinas();

// TURMA

struct cadastroTurma{

    int codigo; // identificador de turma
    int numAlu; //numero de alunos da turma
    struct cadastroAluno aluno[tam];
    struct cadastroDisciplina disciplina;
    struct cadastroProfessor professor;

};

struct cadastroTurma turmas[tam];

int count4 = 0;

void insereDisciTurma();
void insereProfTurma();
void insereAluTurma();
void insereTurma();
void listarTurmas();
void alteraTurma();
void excluiTurma();


int main(){

    menu();
    return 0;
}

void menu(){

int opcao;

 while(1){

    system("pause");
    system("cls");
    printf(" (1) ALUNO\n");
    printf(" (2) PROFESSOR\n");
    printf(" (3) DISCIPLINA\n");
    printf(" (4) TURMA\n");
    printf(" (0) SAIR\n");
    printf("\n");
    printf("Informe uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");


    switch(opcao){
        case 1:
            system("cls");
            printf("Voce esta no modulo de cadastro de Alunos\n");
            menu2(opcao);
            break;
        case 2:
            system("cls");
            printf("Voce esta no modulo de cadastro de Professores\n");
            menu2(opcao);
            break;
        case 3:
            system("cls");
            printf("Voce esta no modulo de cadastro de Disciplinas\n");
            menu2(opcao);
            break;
        case 4:
            system("cls");
            printf("Voce esta no modulo de cadastro de Turmas\n");
            menu2(opcao);
            break;
        case 0:
            printf("SAINDO...");
            exit(0);
            break;
        default:
            printf("Digite uma opcao valida\n");

    }

 }

}

void menu2(int op){

    int opc;
    printf("\n (1) INSERIR\n");
    printf(" (2) ALTERAR\n");
    printf(" (3) EXCLUIR\n");
    printf(" (4) LISTAR\n");
    printf(" (5) VOLTAR\n");
    printf("\n");
    printf("Digite uma operacao: ");
    scanf("%d", &opc);
    printf("\n");

    switch(opc){
        case 1:
            switch(op){
                case 1:
                    inserirAluno();
                    break;
                case 2:
                    insereProfessor();
                    break;
                case 3:
                    insereDisciplina();
                    break;
                case 4:
                    insereTurma();
                    break;
            }

            break;
        case 2:
            switch(op){
                case 1:
                    alteraAluno();
                    break;
                case 2:
                    alteraProfessor();
                    break;
                case 3:
                    alteraDisciplina();
                    break;
                case 4:
                    alteraTurma();
                    break;
            }
            break;
        case 3:
            switch(op){
                case 1:
                    excluiAluno();
                    break;
                case 2:
                    excluiProfessor();
                    break;
                case 3:
                    excluiDisciplina();
                    break;
                case 4:
                    excluiTurma();
                    break;
            }
            break;
        case 4:
            switch(op){
                case 1:
                    ListarAlunos();
                    break;
                case 2:
                    listarProfessores();
                    break;
                case 3:
                    listarDisciplinas();
                    break;
                case 4:
                    listarTurmas();
                    //imprimeAlunos();
                    break;
            }
            break;
        case 5:

            menu();
            break;
        default:
            printf("Digite uma opcao valida\n\n");
    }


}

// FUNÇÕES ALUNOS

void inserirAluno(){

    srand( (unsigned)time(NULL) );

    if(count<tam){

    fflush(stdin);
    printf("\nInforme o nome do aluno: ");
    gets(alunos[count].nome);
    fflush(stdin);
    alunos[count].matricula = rand() % 1000;
    printf("\nAluno inserido com sucesso\n\n\n\n\n\n\n");

    count++;

    }
    else{
        printf("VAGAS ENCERRADAS\n");
    }
}

void alteraAluno(){

    int mat,i,verificacao;

    printf("\n\nDigite a matricula do aluno que deseja alterar\n");
    scanf("%d", &mat);

    for(i=0;i<count;i++){

        if(mat==alunos[i].matricula){
            char novoNome[40];
            int novaMatricula;
            int options;
            verificacao = 1;

            printf("Aluno: %s", alunos[i].nome);
            printf("\n");
            printf("Matricula: %d", alunos[i].matricula);
            printf("\n");

            printf("O que deseja alterar ?\n");
            printf(" 1. NOME\n");
            printf(" 2. MATRICULA\n");
            scanf("%d", &options);

            switch(options){
                case 1:
                    fflush(stdin);
                    printf("Digite o novo nome\n");
                    gets(novoNome);
                    fflush(stdin);
                    strcpy(alunos[i].nome, novoNome);
                    printf("Alterado com sucesso\n");
                    break;
                case 2:
                    printf("Digite a nova matricula\n");
                    scanf("%d", &novaMatricula);
                    alunos[i].matricula = novaMatricula;
                    printf("Alterado com sucesso\n");
                    break;
                default:
                    printf("Informe uma opcao valida\n");
            }

        }

    }

    if(verificacao!=1){
        printf("Matricula nao encontrada\n");
    }
}

void excluiAluno(){

    int mat,i,verificacao;

    printf("Digite a matricula do aluno que deseja remover\n");
    scanf("%d", &mat);

    for(i=0;i<count;i++){

        if(mat==alunos[i].matricula){
            count--;
            verificacao = 1;

            for(i;i<count;i++){
            strcpy(alunos[i].nome, alunos[i+1].nome);
            alunos[i].matricula = alunos[i+1].matricula;

            }
            printf("Removido com sucesso\n");

        }

    }
    if(verificacao!=1){
        printf("Matricula nao encontrada\n");
    }
}

void ListarAlunos(){

    int i;

    if(count==0){
        printf("\nNenhum aluno cadastrado no sistema\n");
    }
    else{

    for(i=0;i<count;i++){

        printf("\nNOME: %s", alunos[i].nome);
        printf("\nMATRICULA: %d", alunos[i].matricula);
        printf("\n");
    }
    }
}

// FUNÇÕES PROFESSOR

void insereProfessor(){

    srand( (unsigned)time(NULL) );

    if(count2<tam){

    fflush(stdin);
    printf("\nInforme o nome do professor: ");
    gets(professores[count2].nome);
    fflush(stdin);
    professores[count2].codigo = rand() % 100;
    count2++;
    printf("\nProfessor inserido com sucesso\n\n\n\n\n\n\n");

    }
    else{
        printf("Quadro de professores cheio\n");
    }
}

void alteraProfessor(){

    int cod,i,verificacao;

    printf("\n\nDigite o codigo do professor que deseja fazer alteraracao\n");
    scanf("%d", &cod);

    for(i=0;i<count2;i++){

        if(cod==professores[i].codigo){
            char novoNome[40];
            int novoCodigo;
            int options;
            verificacao = 1;

            printf("Professor: %s", professores[i].nome);
            printf("\n");
            printf("Codigo: %d", professores[i].codigo);
            printf("\n");

            printf("O que deseja alterar ?\n");
            printf(" 1. NOME\n");
            printf(" 2. CODIGO\n");
            scanf("%d", &options);

            switch(options){
                case 1:
                    fflush(stdin);
                    printf("Digite o novo nome\n");
                    gets(novoNome);
                    fflush(stdin);
                    strcpy(professores[i].nome, novoNome);
                    printf("Alterado com sucesso\n");
                    break;
                case 2:
                    printf("Digite o novo codigo\n");
                    scanf("%d", &novoCodigo);
                    professores[i].codigo = novoCodigo;
                    printf("Alterado com sucesso\n");
                    break;
                default:
                    printf("Informe uma opcao valida\n");
            }

        }

    }

    if(verificacao!=1){
        printf("Codigo nao encontrado\n");
    }
}

void excluiProfessor(){

    int cod,i,verificacao;

    printf("Digite o codigo do professor que voce deseja remover\n");
    scanf("%d", &cod);

    for(i=0;i<count2;i++){

        if(cod==professores[i].codigo){
            count2--;
            verificacao = 1;

            for(i;i<count2;i++){
            strcpy(professores[i].nome, professores[i+1].nome);
            professores[i].codigo = professores[i+1].codigo;

            }
            printf("Removido com sucesso\n");

        }

    }
    if(verificacao!=1){
        printf("Codigo nao encontrado\n");
    }
}

void listarProfessores(){

    int i;

    if(count2==0){
        printf("\nNenhum professor cadastrado no sistema\n");
    }
    else{

    for(i=0;i<count2;i++){

        printf("\nNOME: %s", professores[i].nome);
        printf("\nCODIGO: %d", professores[i].codigo);
        printf("\n");
    }
    }
}

// FUNCOES DISCIPLINAS

void insereDisciplina(){

    srand( (unsigned)time(NULL) );

    if(count3<tam){

    fflush(stdin);
    printf("\nInforme o nome da disciplina: ");
    gets(disciplinas[count3].nome);
    fflush(stdin);
    disciplinas[count3].codigo = rand() % 100;
    count3++;
    printf("\nDisciplina inserida com sucesso\n\n\n\n\n\n\n");

    }
    else{
        printf("Grade de disciplinas cheia\n");
    }
}

void alteraDisciplina(){

    int cod,i,verificacao;

    printf("\n\nDigite o codigo da disciplina que voce deseja fazer alteraracao\n");
    scanf("%d", &cod);

    for(i=0;i<count3;i++){

        if(cod==disciplinas[i].codigo){
            char novoNome[40];
            int novoCodigo;
            int options;
            verificacao = 1;

            printf("Disciplina: %s", disciplinas[i].nome);
            printf("\n");
            printf("Codigo: %d", disciplinas[i].codigo);
            printf("\n");

            printf("O que deseja alterar ?\n");
            printf(" 1. NOME\n");
            printf(" 2. CODIGO\n");
            scanf("%d", &options);

            switch(options){
                case 1:
                    fflush(stdin);
                    printf("Digite o novo nome\n");
                    gets(novoNome);
                    fflush(stdin);
                    strcpy(disciplinas[i].nome, novoNome);
                    printf("Alterado com sucesso\n");
                    break;
                case 2:
                    printf("Digite o novo codigo\n");
                    scanf("%d", &novoCodigo);
                    disciplinas[i].codigo = novoCodigo;
                    printf("Alterado com sucesso\n");
                    break;
                default:
                    printf("Informe uma opcao valida\n");
            }

        }

    }

    if(verificacao!=1){
        printf("Codigo nao encontrado\n");
    }
}

void excluiDisciplina(){

    int cod,i,verificacao;

    printf("Digite o codigo da disciplina que voce deseja remover\n");
    scanf("%d", &cod);

    for(i=0;i<count3;i++){

        if(cod==disciplinas[i].codigo){
            count3--;
            verificacao = 1;

            for(i;i<count3;i++){
            strcpy(disciplinas[i].nome, disciplinas[i+1].nome);
            disciplinas[i].codigo = disciplinas[i+1].codigo;

            }
            printf("Removida com sucesso\n");

        }

    }
    if(verificacao!=1){
        printf("Codigo nao encontrado\n");
    }
}

void listarDisciplinas(){

    int i;

    if(count3==0){
        printf("\nNenhuma disciplina cadastrada no sistema\n");
    }
    else{

    for(i=0;i<count3;i++){

        printf("\nNOME: %s", disciplinas[i].nome);
        printf("\nCODIGO: %d", disciplinas[i].codigo);
        printf("\n");
    }
    }
}

    //**************FUNCOES TURMA

    void insereDisciTurma(){

    int verifica = 0;
    int cod = 0;
    int i = 0;

    scanf("%d", &cod);

    for(i=0;i<count3;i++){

            if(cod==disciplinas[i].codigo){
                verifica = 1;
                strcpy(turmas[count4].disciplina.nome, disciplinas[i].nome);
                printf("Disciplina inserida na turma\n");
            }

        }
        if(verifica!=1){
            printf("Informe o codigo de uma disciplina cadastrada\n");
            insereDisciTurma();
        }

        verifica = 0; // resetando


}

void insereProfTurma(){

    int verifica = 0;
    int cod = 0;
    int i = 0;

    scanf("%d", &cod);

    for(i=0;i<count2;i++){

            if(cod==professores[i].codigo){
                verifica = 1;
                strcpy(turmas[count4].professor.nome, professores[i].nome);
                printf("Professor inserido na turma\n");
            }

        }
        if(verifica!=1){
            printf("Informe o codigo de um professor cadastrado\n");
            insereProfTurma();
        }

        verifica = 0; // resetando
}

void insereAluTurma(){
    int verifica = 0;
    int mat = 0;
    int i = 0;
    int n = 0;
    printf("Informe a matricula do aluno\n");
    scanf("%d", &mat);

    for(i=0;i<count;i++){

        if(mat==alunos[i].matricula){
            verifica = 1;
            n = turmas[count4].numAlu;
            strcpy(turmas[count4].aluno[n].nome, alunos[i].nome);
            turmas[count4].aluno[n].matricula = alunos[i].matricula;
            printf("Aluno inserido na turma\n");
            turmas[count4].numAlu++;


        }

    }

    if(verifica!=1){
            printf("Informe o codigo de um aluno cadastrado\n");
            insereAluTurma();
        }


    verifica = 0;
}

void insereTurma(){

    int opt=1;

    listarDisciplinas();
    printf("\n");
    printf("Para iniciar o cadastro de uma turma informe o codigo de uma disciplina\n");

    insereDisciTurma();

    system("cls");

    printf("Hora de cadastrar um professor para lecionar essa turma...\n");

    listarProfessores();
    printf("\n");
    printf("Informe o codigo do professor para inseri-lo nessa turma\n");

    insereProfTurma();

    system("cls");

    printf("Agora vamos inscrever alunos na turma\n");

    ListarAlunos();


    insereAluTurma();

    while(opt!=0){
        printf("Digite (1) para inserir outro aluno ou (0) para encerrar o cadastro\n");
        scanf("%d", &opt);
        if(opt!=1&&opt!=0){
            printf("Selecione uma opcao valida\n");
        }else if(opt==1){
            insereAluTurma();
        }
        else{
            printf("\nCadastro da turma finalizado\n");
        }
    }

    srand( (unsigned)time(NULL) );
    turmas[count4].codigo = rand() % 1000;




    count4++;

}

void listarTurmas(){

    int i=0,j=0;

    if(count4==0){
        printf("\nNenhuma turma cadastrada no sistema\n");
    }
    else{

    for(i = 0; i < count4; i++){

        printf("Disciplina: %s\n", turmas[i].disciplina.nome);
        printf("Professor: %s\n", turmas[i].professor.nome);
        printf("Codigo da turma: %d\n", turmas[i].codigo);
        printf("\n");
        printf("Alunos \n");


        for(j = 0;j < count; j++){

            puts(turmas[i].aluno[j].nome);

        }

    }

    }
}

void alteraTurma(){

    int cod=0, i=0, opt=0, j=0, codAlt=0, verifica=0, op2=0, mat=0, verifica2=0;
    int n = 0, l=0, m = 0;
    int k=0;

    printf("Informe o codigo da turma: ");
    scanf("%d", &cod);

    for(i = 0; i < count4; i++){

        if(cod==turmas[i].codigo){

            printf("\n\nDisciplina: %s\n", turmas[i].disciplina.nome);
            printf("Professor: %s\n", turmas[i].professor.nome);
            printf("Codigo da turma: %d\n", turmas[i].codigo);

            printf("O que deseja alterar?: ");
            printf("(1) Disciplina - (2) Professor - (3) Alunos \n");
            scanf("%d", &opt);

            switch(opt){

                case 1:
                    listarDisciplinas();
                    printf("\nPara alterar a disciplina, informe o codigo da nova disciplina para essa turma: ");
                    scanf("%d", &codAlt);
                    for(j=0;j<count3;j++){

                        if(codAlt==disciplinas[j].codigo){
                            verifica = 1;
                            turmas[i].disciplina.codigo = codAlt;
                            strcpy(turmas[i].disciplina.nome, disciplinas[j].nome);
                            printf("\nDisciplina da turma alterada com sucesso\n");

                        }

            }
                if(verifica!=1){
                    printf("Codigo informado nao pertence a uma disciplina cadastrada\n");
                }
            break;

                case 2:

                    listarProfessores();
                    printf("Para alterar o professor, informe o codigo do novo professor para essa turma: ");
                    scanf("%d", &codAlt);
                    for(j=0;j<count2;j++){

                        if(codAlt==professores[j].codigo){
                            verifica = 1;
                            turmas[i].professor.codigo = codAlt;
                            strcpy(turmas[i].professor.nome, professores[j].nome);
                            printf("\nProfessor da turma alterado com sucesso\n");

                        }

                    }
                     if(verifica!=1){
                    printf("Codigo informado nao pertence a uma disciplina cadastrada\n");
                    }
                break;

                    case 3:
                        printf("Digite (1) para adicionar ou (2) para remover um aluno da turma\n");
                        scanf("%d", &op2);

                        switch(op2){

                            case 1:

                                ListarAlunos();

                                printf("\nDigite a matricula do aluno que deseja inserir na turma\n");
                                scanf("%d", &mat);
                                n = turmas[i].numAlu;
                                for(j=0;j<n;j++){

                                    if(mat!=turmas[i].aluno[j].matricula){

                                        for(k=0;k<count;k++){
                                            if(mat==alunos[k].matricula){

                                                strcpy(turmas[i].aluno[n].nome, alunos[k].nome);
                                                turmas[i].aluno[n].matricula = alunos[k].matricula;

                                                turmas[i].numAlu = n + 1;

                                                verifica2 = 1;
                                            }

                                        }

                                    }

                                }
                                   if(verifica2!=1){
                                                printf("Informe a matricula de um aluno cadastro no sistema\n");
                                    }else{
                                            printf("\nAluno inserido na Turma com sucesso\n");
                                        }
                                break;

                                case 2:

                                    n = turmas[i].numAlu;
                                    for(l=0; l < n; l++ ){
                                        printf("Aluno: %s\n", turmas[i].aluno[l].nome);
                                        printf("Matricula: %d\n\n", turmas[i].aluno[l].matricula);
                                    }

                                    printf("Para remover o aluno da turma, informe o numero da matricula\n");
                                    scanf("%d", &mat);

                                    for(l=0; l < n; l++){

                                        if(mat==turmas[i].aluno[l].matricula){
                                            verifica2 = 1;

                                            for(l ;l < n; l++){

                                                strcpy(turmas[i].aluno[l].nome, turmas[i].aluno[l+1].nome);
                                                turmas[i].aluno[l].matricula = turmas[i].aluno[l+1].matricula;

                                            }
                                            printf("Removido com Sucesso\n");

                                        }

                                    }
                                    turmas[i].numAlu--;
                                    if(verifica2!=1){
                                        printf("Aluno nao inscrito nessa turma\n");
                                    }

                                    break;


                        }
                        break;

                    default:
                        printf("Informe uma opcao valida\n");


        }
    }

}
}

void excluiTurma(){

    int i=0,cod=0,verif=0;
    int j=0;

    for(i = 0; i < count4; i++){

        printf("Turma de: %s\n", turmas[i].disciplina.nome);
        printf("Codigo da turma: %d\n", turmas[i].codigo);

    }

    printf("\nInforme o codigo da turma que voce deseja remover\n");
    scanf("%d", &cod);

    for(i = 0; i < count4; i++){

        if(cod==turmas[i].codigo){
                verif = 1;
                for(i; i < count4; i++){

                strcpy(turmas[i].disciplina.nome, turmas[i+1].disciplina.nome);
                strcpy(turmas[i].professor.nome, turmas[i+1].professor.nome);
                turmas[i].codigo = turmas[i+1].codigo;
                turmas[i].numAlu = turmas[i+1].numAlu;
                int n = turmas[i].numAlu;

                for(j=0; j < count; j++){

                    strcpy(turmas[i].aluno[j].nome, turmas[i+1].aluno[j].nome);
                    turmas[i].aluno[j].matricula = turmas[i+1].aluno[j].matricula;

                }
                }

        }
}


 if(verif==1){
        printf("Turma removida com sucesso\n");
        count4--;
    }
    else{
        printf("Codigo da turma nao encontrado\n");
    }

}

