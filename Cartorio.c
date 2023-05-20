#include <stdio.h>      // Biblioteca de comunicação com o usuário
#include <stdlib.h>     // Biblioteca de alocação de espaço em memória
#include <locale.h>     // Biblioteca de alocação de texto por região
#include <string.h>     // Biblioteca responsável por cuidar de strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
    char arquivo[40];   // Variável para armazenar o nome do arquivo
    char cpf[40];       // Variável para armazenar o CPF
    char nome[40];      // Variável para armazenar o nome
    char sobrenome[40]; // Variável para armazenar o sobrenome
    char cargo[40];     // Variável para armazenar o cargo

    printf("Digite o CPF: "); // Coletando informação do usuário
    scanf("%s", cpf);   // Lê o CPF fornecido pelo usuário

    strcpy(arquivo, cpf);   // Copia o valor de 'cpf' para 'arquivo'

    FILE *file;     // Ponteiro para o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo para escrita
    fprintf(file, cpf);  // Salva o valor do CPF no arquivo
    fclose(file);    // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização (modo de adição)
    fprintf(file, ","); // Escreve uma vírgula no arquivo
    fclose(file);   // Fecha o arquivo

    printf("Digite o NOME: "); // Coletando informação do usuário
    scanf("%s", nome);  // Lê o nome fornecido pelo usuário

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização (modo de adição)
    fprintf(file, nome); // Escreve o nome no arquivo
    fclose(file);   // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização (modo de adição)
    fprintf(file, ","); // Escreve uma vírgula no arquivo
    fclose(file);   // Fecha o arquivo

    printf("Digite o SOBRENOME: "); // Coletando informação do usuário
    scanf("%s", sobrenome); // Lê o sobrenome fornecido pelo usuário

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização (modo de adição)
    fprintf(file, sobrenome); // Escreve o sobrenome no arquivo
    fclose(file);   // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização (modo de adição)
    fprintf(file, ","); // Escreve uma vírgula no arquivo
    fclose(file);   // Fecha o arquivo

    printf("Digite o CARGO: "); // Coletando informação do usuário
    scanf("%s", cargo); // Lê o cargo fornecido pelo usuário

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização (modo de adição)
    fprintf(file, cargo); // Escreve o cargo no arquivo
    fclose(file);   // Fecha o arquivo

    system("pause"); // Pausa a execução do programa e aguarda o usuário pressionar uma tecla antes de continuar
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Define o idioma para Português

    char cpf[40];   // Variável para armazenar o CPF
    char conteudo[200]; // Variável para armazenar o conteúdo lido do arquivo

    printf("Digite o CPF: "); // Coletando informação do usuário
    scanf("%s", cpf);   // Lê o CPF fornecido pelo usuário

    FILE *file; // Ponteiro para o arquivo que será manipulado
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    if (file == NULL) // Verifica se o arquivo não pôde ser aberto ou não existe
    {
        printf("Não foi localizado o arquivo.\n"); // Exibe uma mensagem de erro quando o arquivo não é encontrado
    }

    while (fgets(conteudo, 200, file) != NULL) // Lê o conteúdo do arquivo linha por linha
    {
        printf("\nOs dados do usúario são: \n%s\n\n", conteudo); // Imprime o conteúdo lido em uma linha separada
    }

    system("pause"); // Pausa a execução do programa e aguarda o usuário pressionar uma tecla antes de continuar
}

int deletar()
{
    char cpf[40];   // Variável para armazenar o CPF

    printf("Digite o CPF do usuário que será deletado: "); // Solicita ao usuário que digite o CPF do usuário a ser deletado
    scanf("%s", cpf); // Lê o CPF fornecido pelo usuário e armazena na variável 'cpf'

    FILE *file; // Ponteiro para o arquivo que será manipulado
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    system("cls"); // Limpa a tela

    if (file == NULL) // Verifica se o arquivo não pôde ser aberto ou não existe
    {
        printf("\t\t\t*NÃO foi encontrado no sistema nenhum CPF com esse número!*\n\n"); // Exibe uma mensagem informando que o CPF não foi encontrado no sistema
        system("pause"); // Aguarda o usuário pressionar uma tecla
    }
    else // Caso o arquivo exista
    {
        fclose(file); // Fecha o arquivo
        remove(cpf); // Remove o arquivo
        printf("\t\t\t*CPF DELETADO do sistema!*\n\n"); // Exibe uma mensagem informando que o CPF foi deletado do sistema
        system("pause"); // Aguarda o usuário pressionar uma tecla
    }
}

int main()
{
    int opcao = 0; // Variável para armazenar a opção escolhida pelo usuário
    int laco = 1;  // Variável para controlar o loop do menu

    for (laco = 1; laco == 1;) // Loop infinito
    {
        system("cls"); // Limpa a tela

        setlocale(LC_ALL, "Portuguese"); // Define o idioma para Português

        printf("\t\t ----- CÁRTORIO EBAC -----\n\n"); // Título do menu
        printf("\t *Escolha abaixo a opção desejada:*\n\n");
        printf(" 1 - Registrar usuários\n");
        printf(" 2 - Consultar usuários\n");
        printf(" 3 - Deletar usuários\n\n");
        printf(" 4 - Sair do sistema\n\n");
        printf("\n Opção: "); // Solicita a opção ao usuário

        scanf("%d", &opcao); // Armazena a escolha do usuário

        system("cls"); // Limpa a tela do console

        switch (opcao) // Início da seleção
        {
        case 1: // Caso a opção escolhida seja 1
            registro(); // Chama a função de registro
            break; // Encerra o bloco de código do switch e sai do loop

        case 2: // Caso a opção escolhida seja 2
            consulta(); // Chama a função de consulta
            break; // Encerra o bloco de código do switch e sai do loop

        case 3: // Caso a opção escolhida seja 3
            deletar(); // Chama a função de deletar
            break; // Encerra o bloco de código do switch e sai do loop
            
        case 4: // Caso a opção escolhida seja 3
        	printf("Obrigado por utilizar o sistema.\n");
        	return 0;
        	break;

        default: // Caso nenhuma das opções anteriores seja selecionada
            printf("Essa opção não está disponível. Escolha uma opção entre 1 e 4!\n\n"); // Exibe uma mensagem de opção inválida ao usuário
            system("pause"); // Aguarda o usuário pressionar uma tecla
            break; // Fim da seleção
        }
    }
}
