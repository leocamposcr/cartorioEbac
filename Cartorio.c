#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C, que fornece funcionalidades para entrada e saída de dados.
#include <stdlib.h> // Inclui a biblioteca padrão em C, que contém funções para alocação de memória, conversão de tipos, geração de números aleatórios, entre outras.
#include <locale.h> // Inclui a biblioteca que permite a configuração de localização e formatação de dados de acordo com a região.
#include <string.h> // Inclui a biblioteca padrão em C, que contém funções para manipulação de strings.

struct Usuario { // Define a estrutura de dados 'Usuario' que será utilizada para armazenar informações de login e senha.
    char login[40]; // Define uma estrutura 'Usuario' com um campo chamado 'login' que pode armazenar até 40 caracteres.
    char senha[40]; // Define uma estrutura 'Usuario' com um campo chamado 'senha' que pode armazenar até 40 caracteres.
};

int registro() { // Função responsável por registrar usuários
    char arquivo[40]; // Declara uma variável do tipo string chamada 'arquivo' com capacidade para armazenar até 40 caracteres.
    char cpf[40]; // Declara uma variável do tipo string chamada 'cpf' com capacidade para armazenar até 40 caracteres.
    char nome[40]; // Declara uma variável do tipo string chamada 'nome' com capacidade para armazenar até 40 caracteres.
    char sobrenome[40]; // Declara uma variável do tipo string chamada 'sobrenome' com capacidade para armazenar até 40 caracteres.
    char cargo[40]; // Declara uma variável do tipo string chamada 'cargo' com capacidade para armazenar até 40 caracteres.

    printf("Digite o CPF: "); // Exibe uma mensagem solicitando ao usuário que digite o CPF.
    scanf("%s", cpf); // Lê uma string digitada pelo usuário e armazena na variável 'cpf'.

    strcpy(arquivo, cpf); // Copia o conteúdo da variável 'cpf' para a variável 'arquivo' usando a função strcpy().
    
    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen(arquivo, "w"); // Abre o arquivo com o nome do CPF em modo de escrita, associando-o ao ponteiro 'file'.
    fprintf(file, cpf); // Escreve o valor do CPF no arquivo usando a função fprintf().
    fclose(file); // Fecha o arquivo.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adição (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, ","); // Escreve uma vírgula no arquivo.
    fclose(file); // Fecha o arquivo.

    printf("Digite o NOME: "); // Exibe uma mensagem solicitando ao usuário que digite o nome.
    scanf("%s", nome); // Lê uma string digitada pelo usuário e armazena na variável 'nome'.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adição (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, nome); // Escreve o valor do nome no arquivo.
    fclose(file); // Fecha o arquivo.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adição (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, ","); // Escreve uma vírgula no arquivo.
    fclose(file); // Fecha o arquivo.

    printf("Digite o SOBRENOME: "); // Exibe uma mensagem solicitando ao usuário que digite o sobrenome.
    scanf("%s", sobrenome); // Lê uma string digitada pelo usuário e armazena na variável 'sobrenome'.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adição (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, sobrenome); // Escreve o valor do sobrenome no arquivo.
    fclose(file); // Fecha o arquivo.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adição (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, ","); // Escreve uma vírgula no arquivo.
    fclose(file); // Fecha o arquivo.

    printf("Digite o CARGO: "); // Exibe uma mensagem solicitando ao usuário que digite o cargo.
    scanf("%s", cargo); // Lê uma string digitada pelo usuário e armazena na variável 'cargo'.

    file = fopen(arquivo, "a"); // Abre o arquivo com o nome do CPF em modo de adição (append), associando-o novamente ao ponteiro 'file'.
    fprintf(file, cargo); // Escreve o valor do cargo no arquivo.
    fclose(file); // Fecha o arquivo.

    system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
}
int consulta() { // Função responsável por consultar usuários
    setlocale(LC_ALL, "Portuguese"); // Define o local como "Portuguese" para exibir mensagens em português.

    char cpf[40]; // Declara uma variável para armazenar o CPF digitado pelo usuário.
    char conteudo[200]; // Declara uma variável para armazenar o conteúdo lido do arquivo.

    printf("Digite o CPF: "); // Exibe uma mensagem solicitando ao usuário que digite o CPF.
    scanf("%s", cpf); // Lê uma string digitada pelo usuário e armazena na variável 'cpf'.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen(cpf, "r"); // Abre o arquivo com o nome do CPF em modo de leitura, associando-o ao ponteiro 'file'.

    if (file == NULL) { // Verifica se o arquivo não foi encontrado.
        printf("Não foi localizado o arquivo.\n"); // Exibe uma mensagem informando que o arquivo não foi encontrado.
    }

    while (fgets(conteudo, 200, file) != NULL) { // Lê uma linha do arquivo e armazena em 'conteudo', enquanto não chegar ao final do arquivo.
        printf("\nOs dados do usuário são:\n%s\n\n", conteudo); // Exibe o conteúdo lido do arquivo.
    }

    system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
}

int deletar() { // Função responsável por deletar usuários
    char cpf[40]; // Declara uma variável para armazenar o CPF do usuário que será deletado.

    printf("Digite o CPF do usuário que será deletado: "); // Exibe uma mensagem solicitando ao usuário que digite o CPF do usuário a ser deletado.
    scanf("%s", cpf); // Lê uma string digitada pelo usuário e armazena na variável 'cpf'.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen(cpf, "r"); // Abre o arquivo com o nome do CPF em modo de leitura, associando-o ao ponteiro 'file'.

    system("cls"); // Limpa a tela do console.

    if (file == NULL) { // Verifica se o arquivo não foi encontrado.
        printf("\t\t\t*NÃO foi encontrado no sistema nenhum CPF com esse número!*\n\n"); // Exibe uma mensagem informando que não foi encontrado um CPF com o número digitado.
        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
    } else {
        fclose(file); // Fecha o arquivo.
        remove(cpf); // Remove o arquivo com o nome do CPF, excluindo o usuário do sistema.
        printf("\t\t\t*CPF DELETADO do sistema!*\n\n"); // Exibe uma mensagem informando que o CPF foi deletado com sucesso.
        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
    }
}

int criarUsuario() { // Função responsável por criar um novo usuário
    char login[40]; // Declara uma variável para armazenar o login do novo usuário.
    char senha[40]; // Declara uma variável para armazenar a senha do novo usuário.

    printf("Digite o login: "); // Exibe uma mensagem solicitando ao usuário que digite o login do novo usuário.
    scanf("%s", login); // Lê uma string digitada pelo usuário e armazena na variável 'login'.

    printf("Digite a senha: "); // Exibe uma mensagem solicitando ao usuário que digite a senha do novo usuário.
    scanf("%s", senha); // Lê uma string digitada pelo usuário e armazena na variável 'senha'.

    system("cls"); // Limpa a tela do console.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen("usuarios.txt", "a"); // Abre o arquivo "usuarios.txt" em modo de adição (append), associando-o ao ponteiro 'file'.

    fprintf(file, "%s %s\n", login, senha); // Escreve no arquivo o login e senha do novo usuário, seguidos de uma quebra de linha.
    fclose(file); // Fecha o arquivo.

    printf("Usuário criado com sucesso!\n\n"); // Exibe uma mensagem informando que o usuário foi criado com sucesso.
    system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
}

int login() { // Função responsável por fazer o login
    char login[40]; // Declara uma variável para armazenar o login fornecido pelo usuário.
    char senha[40]; // Declara uma variável para armazenar a senha fornecida pelo usuário.

    system("cls"); // Limpa a tela do console.

    printf("Faça seu login:\n\n"); // Exibe uma mensagem de boas-vindas ao usuário.
    printf("Digite o seu login: "); // Solicita ao usuário que digite o login.
    scanf("%s", login); // Lê uma string digitada pelo usuário e armazena na variável 'login'.

    printf("Digite a senha: "); // Solicita ao usuário que digite a senha.
    scanf("%s", senha); // Lê uma string digitada pelo usuário e armazena na variável 'senha'.

    system("cls"); // Limpa a tela do console.

    FILE *file; // Declara um ponteiro para um objeto do tipo FILE, usado para manipular arquivos.
    file = fopen("usuarios.txt", "r"); // Abre o arquivo "usuarios.txt" em modo de leitura, associando-o ao ponteiro 'file'.

    if (file == NULL) { // Verifica se o arquivo não pôde ser aberto.
        printf("Nenhum usuário cadastrado!\n"); // Exibe uma mensagem informando que não há usuários cadastrados.
        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
        return 0; // Retorna 0 para indicar falha no login.
    }

    struct Usuario usuario; // Declara uma variável do tipo 'Usuario' para armazenar temporariamente as informações de login e senha lidas do arquivo.

    while (fscanf(file, "%s %s", usuario.login, usuario.senha) == 2) { // Lê as informações de login e senha do arquivo e armazena na variável 'usuario', enquanto houver registros válidos.
        if (strcmp(login, usuario.login) == 0 && strcmp(senha, usuario.senha) == 0) { // Compara o login e a senha fornecidos pelo usuário com os registros lidos do arquivo.
            fclose(file); // Fecha o arquivo.
            return 1; // Retorna 1 para indicar sucesso no login.
        }
    }

    fclose(file); // Fecha o arquivo.
    return 0; // Retorna 0 para indicar falha no login.
}

int main() {
    int opcao = 0; // Variável para armazenar a opção selecionada pelo usuário.
    int laco = 1; // Variável de controle para o loop principal.

    setlocale(LC_ALL, "Portuguese"); // Configura o local para exibição de caracteres acentuados.

    printf("\t\t ----- CÁRTORIO EBAC -----\n\n"); // Exibe o cabeçalho do programa.

    while (laco == 1) { // Loop principal que será executado enquanto 'laco' for igual a 1.
        if (login()) { // Verifica se o login foi bem-sucedido.
            for (laco = 1; laco == 1;) { // Loop interno para exibir o menu e processar as opções.
                setlocale(LC_ALL, "Portuguese"); // Configura novamente o local para exibição de caracteres acentuados.

                printf("\t\t ----- CÁRTORIO EBAC -----\n\n"); // Exibe o cabeçalho do programa.
                printf("\t *Escolha abaixo a opção desejada:*\n\n"); // Exibe o menu de opções.
                printf(" 1 - Registrar usuários\n");
                printf(" 2 - Consultar usuários\n");
                printf(" 3 - Deletar usuários\n");
                printf(" 4 - Sair do sistema\n\n");
                printf(" Opção: ");

                scanf("%d", &opcao); // Lê a opção selecionada pelo usuário.

                system("cls"); // Limpa a tela do console.

                switch (opcao) { // Realiza a ação correspondente à opção selecionada.
                    case 1:
                        registro(); // Chama a função para registrar usuários.
                        break;
                    case 2:
                        consulta(); // Chama a função para consultar usuários.
                        break;
                    case 3:
                        deletar(); // Chama a função para deletar usuários.
                        break;
                    case 4:
                        printf("Obrigado por utilizar o sistema.\n"); // Exibe uma mensagem de despedida.
                        return 0; // Encerra o programa.
                    default:
                        printf("Essa opção não está disponível. Escolha uma opção entre 1 e 4!\n\n"); // Exibe uma mensagem de erro para opções inválidas.
                        system("pause"); // Aguarda o pressionamento de uma tecla antes de continuar a execução do programa (dependendo do sistema operacional).
                        break;
                }
            }
        } else {
            system("cls"); // Limpa a tela do console.
            printf("Usuário ou senha incorretos!\n"); // Exibe uma mensagem de erro para login incorreto.
            printf("Por favor, crie uma conta de administrador.\n\n"); // Solicita a criação de uma conta de administrador.
            criarUsuario(); // Chama a função para criar um novo usuário.
        }
    }
}
