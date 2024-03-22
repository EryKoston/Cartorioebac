#include <stdio.h> // comunicação com o usuario
#include <stdlib.h> // alocação de memoria
#include <locale.h> // biblioteca para textos mais completos
#include <string.h> //biblioteca de strings

int registro()//Função para cadastrar usuarios em arquivo de texto ou strings
{
    //Inicio: Variaveis necessarias para o funcionamento da funçao
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Fim:

    printf("Digite o cpf para cadastro: \n");// Mostrar na tela do dispositivo uma mensagem e uma ordem
    scanf("%s", &cpf);// Armazena oq foi digitado na variavel cpf

    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings

    FILE *file;//cria arquivo
    file = fopen(arquivo, "w");//cria arquivo e o w é write de escrever
    fprintf(file, cpf);//salva o valor da variavel
    fclose(file);//fecha o arquivo

    file = fopen(arquivo, "a"); // abre o arquivo e o a significa atualizar
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome para ser cadastrado: \n");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: \n");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: \n");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");

}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];

  printf("Digite o cpf a ser a ser consultado: \n");
  scanf("%s", cpf);

  FILE *file;
  file = fopen(cpf, "r"); // abrimos o arquivo e o r é o comando para read, ler

  if (file == NULL)
    {
        printf("Cpf não encontrado \n");
    }
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("Essas são as informações do usuario: \n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int deletar()
{
    char cpf[40];
    printf("Digite o cpf a ser deletado \n");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("O usuario  foi deletado do sistema\n");
        system("pause");

    }
}

int main()
{
    int opcao = 0; //variaveis
    int laco = 1;

    for(laco=1;laco=1;){

        setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto


        printf("###Cartório da EBAC### \n\n");
        printf("Escolha opção desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Este sofware é do Erick Hermano\n");
        printf("Opção:\t");
        scanf("%d", &opcao);

        system("cls"); //responsavel por limpar a tela
        switch(opcao)//Inicio do menu1
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            default:
            printf("Essa opcao não esta disponivel\n");
            system("pause");
            break;
        }


}

}
