#include <stdio.h>      // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>     // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>     // Biblioteca de aloca��o de texto por regi�o
#include <string.h>     // Biblioteca respons�vel por cuidar de strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
    char arquivo[40];   // Vari�vel para armazenar o nome do arquivo
    char cpf[40];       // Vari�vel para armazenar o CPF
    char nome[40];      // Vari�vel para armazenar o nome
    char sobrenome[40]; // Vari�vel para armazenar o sobrenome
    char cargo[40];     // Vari�vel para armazenar o cargo

    printf("Digite o CPF: "); // Coletando informa��o do usu�rio
    scanf("%s", cpf);   // L� o CPF fornecido pelo usu�rio

    strcpy(arquivo, cpf);   // Copia o valor de 'cpf' para 'arquivo'

    FILE *file;     // Ponteiro para o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo para escrita
    fprintf(file, cpf);  // Salva o valor do CPF no arquivo
    fclose(file);    // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o (modo de adi��o)
    fprintf(file, ","); // Escreve uma v�rgula no arquivo
    fclose(file);   // Fecha o arquivo

    printf("Digite o NOME: "); // Coletando informa��o do usu�rio
    scanf("%s", nome);  // L� o nome fornecido pelo usu�rio

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o (modo de adi��o)
    fprintf(file, nome); // Escreve o nome no arquivo
    fclose(file);   // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o (modo de adi��o)
    fprintf(file, ","); // Escreve uma v�rgula no arquivo
    fclose(file);   // Fecha o arquivo

    printf("Digite o SOBRENOME: "); // Coletando informa��o do usu�rio
    scanf("%s", sobrenome); // L� o sobrenome fornecido pelo usu�rio

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o (modo de adi��o)
    fprintf(file, sobrenome); // Escreve o sobrenome no arquivo
    fclose(file);   // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o (modo de adi��o)
    fprintf(file, ","); // Escreve uma v�rgula no arquivo
    fclose(file);   // Fecha o arquivo

    printf("Digite o CARGO: "); // Coletando informa��o do usu�rio
    scanf("%s", cargo); // L� o cargo fornecido pelo usu�rio

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o (modo de adi��o)
    fprintf(file, cargo); // Escreve o cargo no arquivo
    fclose(file);   // Fecha o arquivo

    system("pause"); // Pausa a execu��o do programa e aguarda o usu�rio pressionar uma tecla antes de continuar
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Define o idioma para Portugu�s

    char cpf[40];   // Vari�vel para armazenar o CPF
    char conteudo[200]; // Vari�vel para armazenar o conte�do lido do arquivo

    printf("Digite o CPF: "); // Coletando informa��o do usu�rio
    scanf("%s", cpf);   // L� o CPF fornecido pelo usu�rio

    FILE *file; // Ponteiro para o arquivo que ser� manipulado
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    if (file == NULL) // Verifica se o arquivo n�o p�de ser aberto ou n�o existe
    {
        printf("N�o foi localizado o arquivo.\n"); // Exibe uma mensagem de erro quando o arquivo n�o � encontrado
    }

    while (fgets(conteudo, 200, file) != NULL) // L� o conte�do do arquivo linha por linha
    {
        printf("\nOs dados do us�ario s�o: \n%s\n\n", conteudo); // Imprime o conte�do lido em uma linha separada
    }

    system("pause"); // Pausa a execu��o do programa e aguarda o usu�rio pressionar uma tecla antes de continuar
}

int deletar()
{
    char cpf[40];   // Vari�vel para armazenar o CPF

    printf("Digite o CPF do usu�rio que ser� deletado: "); // Solicita ao usu�rio que digite o CPF do usu�rio a ser deletado
    scanf("%s", cpf); // L� o CPF fornecido pelo usu�rio e armazena na vari�vel 'cpf'

    FILE *file; // Ponteiro para o arquivo que ser� manipulado
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    system("cls"); // Limpa a tela

    if (file == NULL) // Verifica se o arquivo n�o p�de ser aberto ou n�o existe
    {
        printf("\t\t\t*N�O foi encontrado no sistema nenhum CPF com esse n�mero!*\n\n"); // Exibe uma mensagem informando que o CPF n�o foi encontrado no sistema
        system("pause"); // Aguarda o usu�rio pressionar uma tecla
    }
    else // Caso o arquivo exista
    {
        fclose(file); // Fecha o arquivo
        remove(cpf); // Remove o arquivo
        printf("\t\t\t*CPF DELETADO do sistema!*\n\n"); // Exibe uma mensagem informando que o CPF foi deletado do sistema
        system("pause"); // Aguarda o usu�rio pressionar uma tecla
    }
}

int main()
{
    int opcao = 0; // Vari�vel para armazenar a op��o escolhida pelo usu�rio
    int laco = 1;  // Vari�vel para controlar o loop do menu

    for (laco = 1; laco == 1;) // Loop infinito
    {
        system("cls"); // Limpa a tela

        setlocale(LC_ALL, "Portuguese"); // Define o idioma para Portugu�s

        printf("\t\t ----- C�RTORIO EBAC -----\n\n"); // T�tulo do menu
        printf("\t *Escolha abaixo a op��o desejada:*\n\n");
        printf(" 1 - Registrar usu�rios\n");
        printf(" 2 - Consultar usu�rios\n");
        printf(" 3 - Deletar usu�rios\n\n");
        printf(" 4 - Sair do sistema\n\n");
        printf("\n Op��o: "); // Solicita a op��o ao usu�rio

        scanf("%d", &opcao); // Armazena a escolha do usu�rio

        system("cls"); // Limpa a tela do console

        switch (opcao) // In�cio da sele��o
        {
        case 1: // Caso a op��o escolhida seja 1
            registro(); // Chama a fun��o de registro
            break; // Encerra o bloco de c�digo do switch e sai do loop

        case 2: // Caso a op��o escolhida seja 2
            consulta(); // Chama a fun��o de consulta
            break; // Encerra o bloco de c�digo do switch e sai do loop

        case 3: // Caso a op��o escolhida seja 3
            deletar(); // Chama a fun��o de deletar
            break; // Encerra o bloco de c�digo do switch e sai do loop
            
        case 4: // Caso a op��o escolhida seja 3
        	printf("Obrigado por utilizar o sistema.\n");
        	return 0;
        	break;

        default: // Caso nenhuma das op��es anteriores seja selecionada
            printf("Essa op��o n�o est� dispon�vel. Escolha uma op��o entre 1 e 4!\n\n"); // Exibe uma mensagem de op��o inv�lida ao usu�rio
            system("pause"); // Aguarda o usu�rio pressionar uma tecla
            break; // Fim da sele��o
        }
    }
}
