#include <stdio.h> // Inclui a biblioteca padr�o de entrada e sa�da em C, que fornece funcionalidades para entrada e sa�da de dados.
#include <stdlib.h> // Inclui a biblioteca padr�o em C, que cont�m fun��es para aloca��o de mem�ria, convers�o de tipos, gera��o de n�meros aleat�rios, entre outras.
#include <locale.h> // Inclui a biblioteca que permite a configura��o de localiza��o e formata��o de dados de acordo com a regi�o.
#include <string.h> // Inclui a biblioteca padr�o em C, que cont�m fun��es para manipula��o de strings.

struct Usuario { // Define a estrutura de dados 'Usuario' que ser� utilizada para armazenar informa��es de login e senha.
    char login[40]; // Define uma estrutura 'Usuario' com um campo chamado 'login' que pode armazenar at� 40 caracteres.
    char senha[40]; // Define uma estrutura 'Usuario' com um campo chamado 'senha' que pode armazenar at� 40 caracteres.
};

int registro() { // Fun��o respons�vel por registrar usu�rios
    char arquivo[40]; // Declara uma vari�vel do tipo string chamada 'arquivo' com capacidade para armazenar at� 40 caracteres.
    char cpf[40]; // Declara uma vari�vel do tipo string chamada 'cpf' com capacidade para armazenar at� 40 caracteres.
    char nome[40]; // Declara uma vari�vel do tipo string chamada 'nome' com capacidade para armazenar at� 40 caracteres.
    char sobrenome[40]; // Declara uma vari�vel do tipo string chamada 'sobrenome' com capacidade para armazenar at� 40 caracteres.
    char cargo[40]; // Declara uma vari�vel do tipo string chamada 'cargo' com capacidade para armazenar at� 40 caracteres.

    printf("Digite o CPF: "); // Exibe uma mensagem solicitando ao usu�rio que digite o CPF.
    scanf("%s", cpf); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'cpf'.

    strcpy(arquivo, cpf); // Copia o conte�do da vari�vel 'cpf' para a vari�vel 'arquivo' usando a fun��o strcpy().
    
    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen(arquivo, "w"); // Abre o arquivo com o nome do CPF em modo de escrita, associando-o ao ponteiro 'file'.
    fprintf(file, cpf); // Escreve o valor do CPF no arquivo usando a fun��o fprintf().
    fclose(file); // Fecha o arquivo.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adi��o (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, ","); // Escreve uma v�rgula no arquivo.
    fclose(file); // Fecha o arquivo.

    printf("Digite o NOME: "); // Exibe uma mensagem solicitando ao usu�rio que digite o nome.
    scanf("%s", nome); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'nome'.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adi��o (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, nome); // Escreve o valor do nome no arquivo.
    fclose(file); // Fecha o arquivo.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adi��o (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, ","); // Escreve uma v�rgula no arquivo.
    fclose(file); // Fecha o arquivo.

    printf("Digite o SOBRENOME: "); // Exibe uma mensagem solicitando ao usu�rio que digite o sobrenome.
    scanf("%s", sobrenome); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'sobrenome'.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adi��o (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, sobrenome); // Escreve o valor do sobrenome no arquivo.
    fclose(file); // Fecha o arquivo.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adi��o (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, ","); // Escreve uma v�rgula no arquivo.
    fclose(file); // Fecha o arquivo.

    printf("Digite o CARGO: "); // Exibe uma mensagem solicitando ao usu�rio que digite o cargo.
    scanf("%s", cargo); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'cargo'.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adi��o (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, cargo); // Escreve o valor do cargo no arquivo.
    fclose(file); // Fecha o arquivo.

    system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
}
int consulta() { // Fun��o respons�vel por consultar usu�rios
    setlocale(LC_ALL, "Portuguese"); // Define o local como "Portuguese" para exibir mensagens em portugu�s.

    char cpf[40]; // Declara uma vari�vel para armazenar o CPF digitado pelo usu�rio.
    char conteudo[200]; // Declara uma vari�vel para armazenar o conte�do lido do arquivo.

    printf("Digite o CPF: "); // Exibe uma mensagem solicitando ao usu�rio que digite o CPF.
    scanf("%s", cpf); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'cpf'.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen(cpf, "r"); // Abre o arquivo com o nome do CPF em modo de leitura, associando-o ao ponteiro 'file'.

    if (file == NULL) { // Verifica se o arquivo n�o foi encontrado.
        printf("N�o foi localizado o arquivo.\n"); // Exibe uma mensagem informando que o arquivo n�o foi encontrado.
    }

    while (fgets(conteudo, 200, file) != NULL) { // L� uma linha do arquivo e armazena em 'conteudo', enquanto n�o chegar ao final do arquivo.
        printf("\nOs dados do usu�rio s�o:\n%s\n\n", conteudo); // Exibe o conte�do lido do arquivo.
    }

    system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
}

int deletar() { // Fun��o respons�vel por deletar usu�rios
    char cpf[40]; // Declara uma vari�vel para armazenar o CPF do usu�rio que ser� deletado.

    printf("Digite o CPF do usu�rio que ser� deletado: "); // Exibe uma mensagem solicitando ao usu�rio que digite o CPF do usu�rio a ser deletado.
    scanf("%s", cpf); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'cpf'.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen(cpf, "r"); // Abre o arquivo com o nome do CPF em modo de leitura, associando-o ao ponteiro 'file'.

    system("cls"); // Limpa a tela do console.

    if (file == NULL) { // Verifica se o arquivo n�o foi encontrado.
        printf("\t\t\t*N�O foi encontrado no sistema nenhum CPF com esse n�mero!*\n\n"); // Exibe uma mensagem informando que n�o foi encontrado um CPF com o n�mero digitado.
        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
    } else {
        fclose(file); // Fecha o arquivo.
        remove(cpf); // Remove o arquivo com o nome do CPF, excluindo o usu�rio do sistema.
        printf("\t\t\t*CPF DELETADO do sistema!*\n\n"); // Exibe uma mensagem informando que o CPF foi deletado com sucesso.
        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
    }
}

int criarUsuario() { // Fun��o respons�vel por criar um novo usu�rio
    char login[40]; // Declara uma vari�vel para armazenar o login do novo usu�rio.
    char senha[40]; // Declara uma vari�vel para armazenar a senha do novo usu�rio.

    printf("Digite o login: "); // Exibe uma mensagem solicitando ao usu�rio que digite o login do novo usu�rio.
    scanf("%s", login); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'login'.

    printf("Digite a senha: "); // Exibe uma mensagem solicitando ao usu�rio que digite a senha do novo usu�rio.
    scanf("%s", senha); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'senha'.

    system("cls"); // Limpa a tela do console.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen("usuarios.txt", "a"); // Abre o arquivo "usuarios.txt" em modo de adi��o (append), associando-o ao ponteiro 'file'.

    fprintf(file, "%s %s\n", login, senha); // Escreve no arquivo o login e senha do novo usu�rio, seguidos de uma quebra de linha.
    fclose(file); // Fecha o arquivo.

    printf("Usu�rio criado com sucesso!\n\n"); // Exibe uma mensagem informando que o usu�rio foi criado com sucesso.
    system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
}

int login() { // Fun��o respons�vel por fazer o login
    char login[40]; // Declara uma vari�vel para armazenar o login fornecido pelo usu�rio.
    char senha[40]; // Declara uma vari�vel para armazenar a senha fornecida pelo usu�rio.

    system("cls"); // Limpa a tela do console.

    printf("Fa�a seu login:\n\n"); // Exibe uma mensagem de boas-vindas ao usu�rio.
    printf("Digite o seu login: "); // Solicita ao usu�rio que digite o login.
    scanf("%s", login); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'login'.

    printf("Digite a senha: "); // Solicita ao usu�rio que digite a senha.
    scanf("%s", senha); // L� uma string digitada pelo usu�rio e armazena na vari�vel 'senha'.

    system("cls"); // Limpa a tela do console.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen("usuarios.txt", "r"); // Abre o arquivo "usuarios.txt" em modo de leitura, associando-o ao ponteiro 'file'.

    if (file == NULL) { // Verifica se o arquivo n�o p�de ser aberto.
        printf("Nenhum usu�rio cadastrado!\n"); // Exibe uma mensagem informando que n�o h� usu�rios cadastrados.
        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
        return 0; // Retorna 0 para indicar falha no login.
    }

    struct Usuario usuario; // Declara uma vari�vel do tipo 'Usuario' para armazenar temporariamente as informa��es de login e senha lidas do arquivo.

    while (fscanf(file, "%s %s", usuario.login, usuario.senha) == 2) { // L� as informa��es de login e senha do arquivo e armazena na vari�vel 'usuario', enquanto houver registros v�lidos.
        if (strcmp(login, usuario.login) == 0 && strcmp(senha, usuario.senha) == 0) { // Compara o login e a senha fornecidos pelo usu�rio com os registros lidos do arquivo.
            fclose(file); // Fecha o arquivo.
            return 1; // Retorna 1 para indicar sucesso no login.
        }
    }

    fclose(file); // Fecha o arquivo.
    return 0; // Retorna 0 para indicar falha no login.
}

int main() {
    int opcao = 0; // Vari�vel para armazenar a op��o selecionada pelo usu�rio.
    int laco = 1; // Vari�vel de controle para o loop principal.

    setlocale(LC_ALL, "Portuguese"); // Configura o local para exibi��o de caracteres acentuados.

    printf("\t\t ----- C�RTORIO EBAC -----\n\n"); // Exibe o cabe�alho do programa.

    while (laco == 1) { // Loop principal que ser� executado enquanto 'laco' for igual a 1.
        if (login()) { // Verifica se o login foi bem-sucedido.
            for (laco = 1; laco == 1;) { // Loop interno para exibir o menu e processar as op��es.
                setlocale(LC_ALL, "Portuguese"); // Configura novamente o local para exibi��o de caracteres acentuados.

                printf("\t\t ----- C�RTORIO EBAC -----\n\n"); // Exibe o cabe�alho do programa.
                printf("\t *Escolha abaixo a op��o desejada:*\n\n"); // Exibe o menu de op��es.
                printf(" 1 - Registrar usu�rios\n");
                printf(" 2 - Consultar usu�rios\n");
                printf(" 3 - Deletar usu�rios\n");
                printf(" 4 - Sair do sistema\n\n");
                printf(" Op��o: ");

                scanf("%d", &opcao); // L� a op��o selecionada pelo usu�rio.

                system("cls"); // Limpa a tela do console.

                switch (opcao) { // Realiza a a��o correspondente � op��o selecionada.
                    case 1:
                        registro(); // Chama a fun��o para registrar usu�rios.
                        break;
                    case 2:
                        consulta(); // Chama a fun��o para consultar usu�rios.
                        break;
                    case 3:
                        deletar(); // Chama a fun��o para deletar usu�rios.
                        break;
                    case 4:
                        printf("Obrigado por utilizar o sistema.\n"); // Exibe uma mensagem de despedida.
                        return 0; // Encerra o programa.
                    default:
                        printf("Essa op��o n�o est� dispon�vel. Escolha uma op��o entre 1 e 4!\n\n"); // Exibe uma mensagem de erro para op��es inv�lidas.
                        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execu��o do programa (dependendo do sistema operacional).
                        break;
                }
            }
        } else {
            system("cls"); // Limpa a tela do console.
            printf("Usu�rio ou senha incorretos!\n"); // Exibe uma mensagem de erro para login incorreto.
            printf("Por favor, crie uma conta de administrador.\n\n"); // Solicita a cria��o de uma conta de administrador.
            criarUsuario(); // Chama a fun��o para criar um novo usu�rio.
        }
    }
}
