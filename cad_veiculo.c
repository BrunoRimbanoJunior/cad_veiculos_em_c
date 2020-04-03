//
//  main.c
//  Cad_Veiculo
//
//  Created by Juba Rimbano on 27/03/20.
//  Copyright © 2020 rimbano.com. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam 100

int cont = 0;


struct DB_DADOS{
        
    struct veiculo{
        char modelo[30];
        char fabricante[30];
        char cor[20];
        int ano;
        char placa[10];
    }db_veiculo;
    
    struct condutor{
        char nome[30];
        char dt_nascimento[13];
        char rg[11];
        char cpf[15];
    }db_condutor;
    
    struct endereco{
        char logradouro[50];
        char cidade[30];
        char uf[3];
        int cep;
    }db_endereco;
    
}cad_dados[tam];

struct fila{
int itens[tam];
int front, rear ;
};


int main() {
    setlocale(LC_ALL,"portuguese");
    
    void imprime_menu(void);
    int vazio(struct fila * pf);
    int inserir(struct fila *pf, int x );
    int excluir(struct fila * pf);
    int consulta(struct fila * pf);
    int alterar(struct fila * pf, int x);
    int posicao(struct fila *pf);
    
    //struct DB_DADOS * p;
    
    int op, ind;
    struct fila f;
    f.front = -1;
    f.rear = -1;
    
     /*
    imprime_menu();
    scanf("%i", &op);
    setbuf(stdin, NULL);*/
    
    while(1){
        imprime_menu();
        scanf("%i", &op);
        setbuf(stdin, NULL);
                
        switch (op) {
            case 1:
                
                inserir(&f, f.rear);
                break;
            
            case 2:
                
                excluir(&f);
                imprime_menu();
                break;
             
            case 3:
               
                printf("Digite o Numero do Registro a ser alterado: ");
                scanf("%i", &ind);
                setbuf(stdin, NULL);
                //fgets(&ind,1,stdin);
               
                
                alterar(&f, ind);
                imprime_menu();
                break;
                
            case 4:
               
                consulta(&f);
                imprime_menu();
                break;
                
            
            
            case 5:
                printf("\n\nAte logo.........\n\n");
                exit(0);
            
            
            
            case 6:
                posicao(&f);
                break;

            default:
                printf("Opção invalida, digite uma opção valida....\n");
                
        }
    };
    return 0;
}

void imprime_menu(void){
      
    system("cls");
    printf("\n******SISTEMA DE CADASTRO DE VEICULOS E CONDUTORES******");
    printf("\nOpção \t01 - CADASTRAR");
    printf("\nOpção \t02 - EXCLUIR");
    printf("\nOpção \t03 - ALTERAR");
    printf("\nOpção \t04 - CONSULTAR");
    printf("\nOpção \t05 - SAIR\n");
    printf("\nOpção? :");
    return;
    
}

int inserir(struct fila *pf, int x ){

int i, t;
//printf("\nValor de x recebido pela funcao: %i", x);
//recebe o tamanho da fila tras - frente
t = pf->rear - pf->front;
// se tras for igual ao tamanho da fila, verificamos o item zero e realocamos a fila
if(pf->rear == tam-1){
    if(pf->itens[0]==1){
        for (i=0;i<t;i++){
        pf->itens[i]=pf->itens[++pf->front];
        }
        //após fazer a passagem de front para posição zero, informamos que front é zero e rear é front mais o tamanho
        pf->front = 0;
        pf->rear = (pf->front+tam);
        pf->front = -1;
        
    }else{
        printf("\nValor na posição 0 %i", pf->itens[0]);
        printf("\nEstouro de Pilha xxx");
        return 1;
        
    }
    
}else{
        pf->rear++;
        }
    
    //dados do veiculos
    printf("\nDigite o Modelo do Veiculo:");
    fgets(cad_dados[pf->rear].db_veiculo.modelo,30, stdin);
    printf("\nDigite o Fabricante do Veiculo:");
    fgets(cad_dados[pf->rear].db_veiculo.fabricante,30, stdin);
    printf("\nDigite o Cor do Veiculo:");
    fgets(cad_dados[pf->rear].db_veiculo.cor,20, stdin);
    printf("\nDigite o Ano do Veiculo:");
    scanf("%i", &cad_dados[pf->rear].db_veiculo.ano);
    setbuf(stdin,NULL);
    printf("\nDigite a Placa do Veiculo:");
    fgets(cad_dados[pf->rear].db_veiculo.placa,10, stdin);
    
    //dados do condutor
    printf("\nDigite o Nome do Condutor: ");
    fgets(cad_dados[pf->rear].db_condutor.nome,30, stdin);
    printf("\nDigite a data de Nascimento do Condutor: ");
    fgets(cad_dados[pf->rear].db_condutor.dt_nascimento,12, stdin);
    printf("\nDigite o RG do Condutor: ");
    fgets(cad_dados[pf->rear].db_condutor.rg,10, stdin);
  
    printf("\nDigite o CPF do Condutor: ");
    fgets(cad_dados[pf->rear].db_condutor.cpf,14, stdin);
   
    //dados de endereco
    printf("\nDigite o Endereco (logradouro), rua, est, rod...: ");
    fgets(cad_dados[pf->rear].db_endereco.logradouro,50, stdin);
    printf("\nDigite a Cidade: ");
    fgets(cad_dados[pf->rear].db_endereco.cidade,30, stdin);
    printf("\nDigite o Estado: ");
    fgets(cad_dados[pf->rear].db_endereco.uf,3, stdin);
    printf("\nDigite o Cep: ");
    scanf("%i", &cad_dados[pf->rear].db_endereco.cep);
    setbuf(stdin, NULL);
    
    pf->itens[pf->rear] = x;
    return 0;
    }
    


int excluir(struct fila * pf){
  
    char q[2];
    
    if(vazio(pf)){
        pf->front=-1;
        pf->rear=-1;
        printf("\nNão existem dados, Banco de Dados Vazio");
        return 1;
    }
    pf->front++;
    printf("\nOs seguintes dados serão excluidos, Confirma s/n?");
    printf("\nRegistro Numero: %i", pf->front);
    printf("\nVeiculo Modelo: %s", cad_dados[pf->front].db_veiculo.modelo);
    printf("\nNome do Conditor: %s\n", cad_dados[pf->front].db_condutor.nome);
    printf("\nCor do Veiculo: %s",cad_dados[pf->front].db_veiculo.cor);
    printf("\nAno do Veiculo: %i", cad_dados[pf->front].db_veiculo.ano);
    printf("\nPlaca do Veiculo: %s", cad_dados[pf->front].db_veiculo.placa);
      
    //dados do condutor
    printf("\nNome do Condutor: %s",cad_dados[pf->front].db_condutor.nome );
    printf("\nData de Nascimento: %s",cad_dados[pf->front].db_condutor.dt_nascimento);
    printf("\nRG numero: %s", cad_dados[pf->front].db_condutor.rg);
    printf("\nCPF Numero: %s", cad_dados[pf->front].db_condutor.cpf);
        
    //dados de endereco
    printf("\nEndereço: %s", cad_dados[pf->front].db_endereco.logradouro);
    printf("\nCidade: %s \tEstado: %s",cad_dados[pf->front].db_endereco.cidade,cad_dados[pf->front].db_endereco.uf );
    printf("\nCep: %i\n",cad_dados[pf->front].db_endereco.cep );
    printf("\nOpção ?: ");
    
    
    scanf("%s", q);
    if ((q=="n")){
        printf("Dados não excluidos");
        getchar();
        setbuf(stdin,NULL);
        return 1;
        
    };
    printf("Dados Excluidos");
    getchar();
    setbuf(stdin,NULL);
    return (pf->itens[pf->front]);
}

int alterar(struct fila * pf, int x){
    
    if(x>=pf->front && x<=pf->rear){
    
    printf("\nDigite o Modelo do Veiculo:");
    fgets(cad_dados[x].db_veiculo.modelo,30, stdin);
    printf("\nDigite o Fabricante do Veiculo:");
    fgets(cad_dados[x].db_veiculo.fabricante,30, stdin);
    printf("\nDigite o Cor do Veiculo:");
    fgets(cad_dados[x].db_veiculo.cor,20, stdin);
    printf("\nDigite o Ano do Veiculo:");
    scanf("%i", &cad_dados[x].db_veiculo.ano);
    setbuf(stdin, NULL);
    printf("\nDigite a Placa do Veiculo:");
    fgets(cad_dados[x].db_veiculo.placa,10, stdin);
    
    //dados do condutor
    printf("\nDigite o Nome do Condutor: ");
    fgets(cad_dados[x].db_condutor.nome,30, stdin);
    printf("\nDigite a data de Nascimento do Condutor: ");
    fgets(cad_dados[x].db_condutor.dt_nascimento,12, stdin);
    printf("\nDigite o RG do Condutor: ");
    fgets(cad_dados[x].db_condutor.rg,10, stdin);
    printf("\nDigite o CPF do Condutor: ");
    fgets(cad_dados[x].db_condutor.cpf,10, stdin);
    //dados de endereco
    printf("\nDigite o Endereco (logradouro), rua, est, rod...: ");
    fgets(cad_dados[x].db_endereco.logradouro,50, stdin);
    printf("\nDigite a Cidade: ");
    fgets(cad_dados[x].db_endereco.cidade,30, stdin);
    printf("\nDigite o Estado: ");
    fgets(cad_dados[x].db_endereco.uf,3, stdin);
    printf("\nDigite o Cep: ");
    scanf("%i", &cad_dados[x].db_endereco.cep);
    setbuf(stdin, NULL);
    }else{
        printf("\nNumero de registro Invalido\n\n");
        return 1;
    };
    
    return 0;
}

int consulta(struct fila * pf){
    
    /*variaveis pra funcao, i para para for que recebe o front +1, cont recebe o tamanho da fila, x para receber
    front -1, caso seja a primeira execucao e front tenha valor -1
    reg para fazer um contator de registros processados*/
    
    int i, cont,x, reg;
    //verificar o tamanho da fila
    cont= pf->rear - pf->front;
    reg = 1;
    
    
    if(vazio(pf)){
        pf->front=-1;
        pf->rear=-1;
        printf("\nNão existem dados, Banco de Dados Vazio");
        return 1;
     }
       
        printf("\nNumero de Registros: %i", cont);
        for(i=pf->front+1; i<cont; i++){
            printf("\n***********Registro  : %i****************\n", reg);
            printf("\nRegistro: %i", i);
            printf("\nVeiculo Modelo: %s", cad_dados[i].db_veiculo.modelo);
            printf("\nFabricante: %s", cad_dados[i].db_veiculo.modelo);
            printf("\nCor do Veiculo: %s",cad_dados[i].db_veiculo.cor);
            printf("\nAno do Veiculo: %i", cad_dados[i].db_veiculo.ano);
            printf("\nPlaca do Veiculo: %s", cad_dados[i].db_veiculo.placa);
              
            //dados do condutor
            printf("\nNome do Condutor: %s",cad_dados[i].db_condutor.nome );
            printf("\nData de Nascimento: %s",cad_dados[i].db_condutor.dt_nascimento);
            printf("\nRG numero: %s", cad_dados[i].db_condutor.rg);
            printf("\nCPF Numero: %s", cad_dados[i].db_condutor.cpf);
                
            //dados de endereco
            printf("\nEndereço: %s", cad_dados[i].db_endereco.logradouro);
            printf("\nCidade: %s - Estado: %s",cad_dados[i].db_endereco.cidade,cad_dados[i].db_endereco.uf );
            printf("\nCep: %i",cad_dados[i].db_endereco.cep );
            reg++;
        };
  
    
        printf("\nTotal de registros Processados: %i\n", i);
        printf("\n\n***********FIM DOS REGISTROS***************\n\n");
        getchar();
        setbuf(stdin,NULL);
        return 0;
}

//verifica se a fila esta vazia, se o primeiro da fila for igual ao ultimo a fila esta vazia, retornamos ao valor inicial
int vazio(struct fila * pf){
if( pf->front == pf->rear){
    pf->front = -1;
    pf->rear = -1;
    return 1;
}
    return 0;
}

int posicao(struct fila *pf){
    printf("\nValor na Posição Front: %i", pf->front);
    printf("\nValor na Posição Rear: %i", pf->rear);
    getchar();
    setbuf(stdin,NULL);

    return 0;
}
