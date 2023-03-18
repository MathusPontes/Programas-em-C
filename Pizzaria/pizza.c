/* Bibliotecas importadas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Struct´s */
typedef struct sabor Sabor;
struct sabor{
    int codigo;
    char sabor [31];
    char vem [501];
    float preco;
    int quant;
    long int maior;
    char status;
};

typedef struct bebida Bebida;
struct bebida{
    int codigo;
    char bebida [31];
    float preco;
    int quant;
    long int maior;
    char status;
};

typedef struct cliente Cliente;
struct cliente{
    char nome [51];
    int idade;
    char cpf [12];
    char telefone [12];
    char status;
};

typedef struct pizza Pizza;
struct pizza{
    char nome [51];
    int idade;
    char cpf [12];
    char status;
};

typedef struct avalia Avalia;
struct avalia{
    char notaC [2];
    char notaT [2];
    char notaS [2];
    char comentario [1001];
};

typedef struct pedido Pedido;
struct pedido{
    int code;
    char pedidoPizza [51];
    char pedidoBebida [51];
    char pedidoPess [51];
    char cpfPedido [12];
    float total;
    char status;
};

/* Funçoes */
int validaCPF (int *cpfV);
void menuPrinc (void);
void login (void);
int alimento (void);
int pedido (void);
void addPedido (void);
int excPedido (void);
void salvaPedido (Pedido*);
int cliente (void);
void novoClie (void);
void salvaClie (Cliente*);
int excluiClie (void);
int visualizaClie (void);
int todoClie (void);
void exibeClie(Cliente*);
int pizzaiolo (void);
void novoPizzaiolo (void);
int excluiPizzaiolo (void);
int todoPizzaiolo (void);
void exibePizzaiolo (Pizza* chapa);
void salvaPizzaiolo (Pizza* chapa);
int avalia (void);
void cadastraAvalia (void);
void salvaAvalia (Avalia*);
int listaAvalia (void);
void exibeAvalia (Avalia*);
int promo (void);
int estoque (void);
int addPizza (void);
int addBebida (void);
void cadastroSabor (void);
void salvaPizza (Sabor*);
void exibeSabor (Sabor*);
int excluiSabor (void);
int listaSabor (void);
void cadastroBebida (void);
void salvaBebida (Bebida*);
void exibeBebida (Bebida*);
int excluiBebida (void);
int listaBebida (void);
int relatorio (void);
float precoT = 0;

/* Programa Principal */
int main (void){
    login();
    menuPrinc();
    return 0;
}

void login (void){
    char login [50];
    char senha [50];
    int conf = 0;
    printf ("\n  ===================\n");
    printf ("  ===\t  Tela \t  ===\n");
    printf ("  ===\t   De  \t  ===\n");
    printf ("  ===\t Login \t  ===\n");
    printf ("  ===================\n\n\n");
    printf ("Informe o login do usuario: ");
    scanf ("%s", login);
    printf ("Informe a senha do usuario: ");
    scanf ("%s", senha);
    if (strcmp (login, "adm") == 0 && strcmp (senha, "123") == 0){
        conf = 1;
    }
    while (conf == 0){
        printf ("\nLogin: %s\nSenha: %s\n", login, senha);
        printf ("\nUsuario ou senha informada esta incorreto, por favor tente novamente\n\n");
        printf ("Informe o login do usuario: ");
        scanf ("%s", login);
        printf ("Informe a senha do usuario: ");
        scanf ("%s", senha);
        if (strcmp (login, "adm") == 0 && strcmp (senha, "123") == 0){
            conf = 1;
        }
    }
}

void menuPrinc (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ####################\n");
        printf ("\t\t ###  Bem - vindo ###\n");
        printf ("\t\t ###      ao      ###\n");
        printf ("\t\t ###   Programa   ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t\t1 - Alimentos\n");
        printf ("\t\t2 - Pedidos\n");
        printf ("\t\t3 - Clientes\n");
        printf ("\t\t4 - Pizzaiolos\n");
        printf ("\t\t5 - Avaliacoes\n");
        printf ("\t\t6 - Promocoes\n");
        printf ("\t\t7 - Estoque\n");
        printf ("\t\t8 - Relatorio\n");
        printf ("\t\t0 - Sair\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                alimento ();
                break;
            case (2):
                pedido ();
                break;
            case (3):
                cliente ();
                break;
            case (4):
                pizzaiolo ();
                break;
            case (5):
                avalia ();
                break;
            case (6):
                promo ();
                break;
            case (7):
                estoque ();
                break;
            case (8):
                relatorio ();
                break;
            case (0):
                printf ("O programa ira fechar\n");
                printf ("Pressione qualquer tecla para continuar");
                setbuf (stdin,NULL);
                getchar ();
                exit(1);
            default:
                printf ("Porfavor insira um numero valido");
                setbuf (stdin,NULL);
                getchar ();
                break;
        }
    }
    while (conf != 0);
}

int alimento (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ####################\n");
        printf ("\t\t ###      Menu    ###\n");
        printf ("\t\t ###       de     ###\n");
        printf ("\t\t ###   Alimentos  ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t\t1 - Cadastrar sabor de pizza\n");
        printf ("\t\t2 - Excluir sabores de pizza\n");
        printf ("\t\t3 - Cadastrar bebida\n");
        printf ("\t\t4 - Excluir Bebidas\n");
        printf ("\t\t0 - Voltar\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                cadastroSabor ();
                break;
            case (2):
                excluiSabor ();
                break;
            case (3):
                cadastroBebida ();
                break;
            case (4):
                excluiBebida ();
                break;
            case (0):
                return 0;
            default:
                printf ("Por favor insira um numero valido");
                setbuf (stdin,NULL);
                getchar ();
                break;
        }
    }
    while (conf != 0);
    return 0;
}

void cadastroSabor (void){
    Sabor* pizza;
    pizza = (Sabor*) malloc(sizeof(Sabor));
    system ("clear || cls");
    printf ("\n\t\t ####################\n");
    printf ("\t\t ###    Cadastro  ###\n");
    printf ("\t\t ###       de     ###\n");
    printf ("\t\t ###     Sabor    ###\n");
    printf ("\t\t ####################\n\n");
    printf ("\nSempre pressione o enter 2 vezes para confirmar\n");
    printf ("Informe o codigo do sabor (menos 0): ");
    scanf ("%d", &pizza -> codigo);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe o nome do sabor da pizza: ");
    scanf (" %[a-z A-Z0-9]30[^\n]", pizza -> sabor);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe oque vem nela separado por virgulas (ex: Queijo, molho...): ");
    scanf (" %[a-z , A-Z]500[^\n]", pizza -> vem);
    setbuf (stdin, NULL);
    getchar ();
    pizza -> status = 'A';
    printf ("Informe o preco da pizza: ");
    scanf ("%f", &pizza -> preco);
    setbuf (stdin, NULL);
    getchar ();
    pizza -> quant = 0;
    pizza -> maior = 0;
    salvaPizza (pizza);
    free (pizza);
}

void salvaPizza (Sabor* pizza){
    FILE* fp;
    fp = fopen("Pizza.dat", "ab");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Por questoes de segurança vamos encerrar o programa!\n");
        setbuf (stdin,NULL);
        getchar ();
        exit(1);
    }
  fwrite(pizza, sizeof(Sabor), 1, fp);
  fclose(fp);
}

int listaSabor (void){
    system ("clear || cls");
    printf ("\n\t\t#########################\n");
    printf ("\t\t##  Todos os Sabores  ##\n");
    printf ("\t\t#########################\n\n");
    FILE* fp;
    Sabor* pizza;
    printf ("\n = Lista de Sabores = \n");
    pizza = (Sabor*) malloc (sizeof(Sabor));
    fp = fopen("Pizza.dat" , "rb");
    if (fp == NULL){
        printf ("Ocorreu um erro na abertura do arquivo!\n");
        printf("Pressione qualquer tecla para voltar ao menu\n");
        setbuf (stdin,NULL);
        getchar ();
        return 0;
    }
    while(fread(pizza, sizeof(Sabor), 1, fp)) {
        if (pizza->status == 'A'){
            printf ("======================================\n");
            exibeSabor(pizza);
            printf ("======================================\n");
        }
    }
    printf ("Pressione qualquer tecla para continuar\n");
    setbuf (stdin, NULL);
    getchar ();
    fclose(fp);
    free(pizza);
    return 0;
}

void exibeSabor(Sabor* pizza) {
    printf("Codigo: %d\n", pizza->codigo);
    printf("Sabor: %s\n", pizza->sabor);
    printf("Oque vem: %s\n", pizza->vem);
    printf("Preco: %gR$\n", pizza->preco);
    printf ("Quantidade em estoque: %d\n", pizza->quant);
    printf ("Quantidade vendidas: %ld\n", pizza->maior);
}

int excluiSabor (void){
    system ("clear || cls");
    printf ("\n\t\t#########################\n");
    printf ("\t\t##  Excluir um Sabor  ##\n");
    printf ("\t\t#########################\n\n");
    FILE* fp;
    Sabor* pizza;
    int achou = 0;
    int confCod;
    fp = fopen("Pizza.dat", "r+b");
    if (fp == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("Pressione qualquer tecla para voltar");
        setbuf (stdin, NULL);
        getchar ();
        return 0;
    }
    printf("Informe o codigo do sabor de pizza que deseja apagar ou digite 0 para retornar ao menu: ");
    scanf("%d", &confCod);
    if (confCod == 0){
        return 0;
    }
    pizza = (Sabor*) malloc(sizeof(Sabor));
    while((!achou) && (fread(pizza, sizeof(Sabor), 1, fp))) {
        if ((pizza -> codigo == confCod) && (pizza -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou) {
        printf ("\n======================================\n");
        exibeSabor(pizza);
        printf ("======================================");
        pizza -> status = 'X';
        fseek(fp, (-1)*sizeof(Sabor), SEEK_CUR);
        fwrite(pizza, sizeof(Sabor), 1, fp);
        printf("\nSabor excluido com sucesso\n");
        setbuf (stdin, NULL);
        getchar();
    } 
    else {
        printf("O sabor não se encontra cadastrado no nosso sistema\n");
        setbuf (stdin, NULL);
        getchar();
    }
    free(pizza);
    fclose(fp);
    return 0;
}

void cadastroBebida (void){
    Bebida* tipo;
    tipo = (Bebida*) malloc(sizeof(Bebida));
    system ("clear || cls");
    printf ("\n\t\t ####################\n");
    printf ("\t\t ###    Cadastro  ###\n");
    printf ("\t\t ###       de     ###\n");
    printf ("\t\t ###    Bebidas   ###\n");
    printf ("\t\t ####################\n\n");
    printf ("\nSempre pressione 2 vezes o entem para confirmar\n");
    printf ("Informe o codigo do da bebida (menos 0): ");
    scanf ("%d", &tipo -> codigo);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe o nome da bebida: ");
    scanf (" %[a-z A-Z.,]30[^\n]", tipo -> bebida);
    setbuf (stdin, NULL);
    getchar ();
    tipo -> status = 'A';
    printf ("Informe o preco da bebida: ");
    scanf ("%f", &tipo -> preco);
    setbuf (stdin, NULL);
    getchar ();
    tipo -> quant = 0;
    tipo -> maior = 0;
    salvaBebida (tipo);
    free (tipo);
}

void salvaBebida (Bebida* tipo){
    FILE* fp;
    fp = fopen("Bebida.dat", "ab");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Por questoes de segurança vamos encerrar o programa!\n");
        setbuf (stdin,NULL);
        getchar ();
        exit(1);
    }
  fwrite(tipo, sizeof(Bebida), 1, fp);
  fclose(fp);
}

int listaBebida (void){
    system ("clear || cls");
    printf ("\n\t\t#########################\n");
    printf ("\t\t##  Todos as Bebidas  ##\n");
    printf ("\t\t#########################\n\n");
    FILE* fp;
    Bebida* tipo;
    printf ("\n = Lista de Bebidas = \n");
    tipo = (Bebida*) malloc (sizeof(Bebida));
    fp = fopen("Bebida.dat" , "rb");
    if (fp == NULL){
        printf ("Ocorreu um erro na abertura do arquivo!\n");
        printf("Pressione qualquer tecla para voltar ao menu\n");
        setbuf (stdin,NULL);
        getchar ();
        return 0;
    }
    while(fread(tipo, sizeof(Bebida), 1, fp)) {
        if (tipo->status == 'A'){
            printf ("======================================\n");
            exibeBebida(tipo);
            printf ("======================================\n");
        }
    }
    printf ("Pressione qualquer tecla para continuar\n");
    setbuf (stdin, NULL);
    getchar ();
    fclose(fp);
    free(tipo);
    return 0;
}

void exibeBebida(Bebida* tipo) {
    printf("Codigo: %d\n", tipo->codigo);
    printf("Bebida: %s\n", tipo->bebida);
    printf("Preco: %gR$\n", tipo->preco);
    printf ("Quantidade em estoque: %d\n", tipo->quant);
    printf ("Quantidade vendidas: %ld\n", tipo->maior);
}

int excluiBebida (void){
    system ("clear || cls");
    printf ("\n\t\t#########################\n");
    printf ("\t\t##  Excluir uma Bebida  ##\n");
    printf ("\t\t#########################\n\n");
    FILE* fp;
    Bebida* tipo;
    int achou = 0;
    int confCod;
    fp = fopen("Bebida.dat", "r+b");
    if (fp == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("Pressione qualquer tecla para voltar");
        setbuf (stdin, NULL);
        getchar ();
        return 0;
    }
    printf("Informe o codigo da bebida que deseja apagar ou digite 0 para retornar ao menu: ");
    scanf("%d", &confCod);
    if (confCod == 0){
        return 0;
    }
    tipo = (Bebida*) malloc(sizeof(Bebida));
    while((!achou) && (fread(tipo, sizeof(Bebida), 1, fp))) {
        if ((tipo -> codigo == confCod) && (tipo -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou) {
        printf ("\n======================================\n");
        exibeBebida(tipo);
        printf ("======================================");
        tipo -> status = 'X';
        fseek(fp, (-1)*sizeof(Bebida), SEEK_CUR);
        fwrite(tipo, sizeof(Bebida), 1, fp);
        printf("\nBebida excluida com sucesso\n");
        setbuf (stdin, NULL);
        getchar();
    } 
    else {
        printf("A bebida não se encontra cadastrado no nosso sistema\n");
        setbuf (stdin, NULL);
        getchar();
    }
    free(tipo);
    fclose(fp);
    return 0;
}

int pedido (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ####################\n");
        printf ("\t\t ###      Menu    ###\n");
        printf ("\t\t ###       de     ###\n");
        printf ("\t\t ###    Pedidos   ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t\t1 - Cadastrar um novo pedido\n");
        printf ("\t\t2 - Cancelar um pedido\n");
        printf ("\t\t0 - Voltar\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                addPedido ();
                break;
            case (2):
                excPedido ();
                break;
            case (0):
                return 0;
            default:
                printf ("Porfavor insira um numero valido");
                setbuf (stdin,NULL);
                getchar ();
                break;
        }
    }
    while (conf != 0); 
    return 0;
}

void addPedido (void){
    char confPedi [2];
    char confPess [12]; 
    char nomePess [51];
    char cpfPess [12];
    char nomePizza [31];
    char nomeBebida [31];
    float precoPizza = 0;
    float precoBebida = 0;
    int conf = 0;
    int achou = 0;
    int confCod = 0;
    int confCod2 = 0;
    int cpfV[12];
    system ("clear || cls");
    printf ("\n\t\t ###################\n");
    printf ("\t\t ###   Realizar  ###\n");
    printf ("\t\t ###    Pedido   ###\n");
    printf ("\t\t ###################\n\n");
    setbuf (stdin,NULL);
    printf ("O cliente ja e cadastrado? (S/N) ");
    scanf ("%[SsNn]1[^\n]", confPedi);
    if (strcmp (confPedi, "S") == 0 || strcmp (confPedi, "s") == 0){
        printf ("Informe o CPF: ");
        scanf (" %11[^\n]", confPess);
        setbuf (stdin,NULL);
        getchar ();
        FILE* fp;
        Cliente* pessoa;
        fp = fopen ("Cliente.dat", "r+b");
        pessoa = (Cliente*) malloc(sizeof(Cliente));
        while((!achou) && (fread(pessoa, sizeof(Cliente), 1, fp))) {
            if ((strcmp(pessoa -> cpf, confPess) == 0) && (pessoa -> status == 'A')) {
                achou = 1;
            }
        }
        if (achou){
            printf ("======================================\n");
            exibeClie(pessoa);
            printf ("======================================\n");
            setbuf (stdin, NULL);
            getchar();
            fseek (fp, (-1)*sizeof(Cliente), SEEK_CUR);
            strcpy (nomePess, pessoa->nome);
            strcpy (cpfPess, pessoa->cpf);
            free (pessoa);
            fclose (fp);
            printf ("Informe o codigo da pizza que deseja ou 0 caso ele não queira: ");
            scanf ("%d", &confCod);
            if (confCod != 0){
                FILE* fp;
                Sabor* pizza;
                pizza = (Sabor*) malloc(sizeof(Sabor));
                achou = 0;
                fp = fopen("Pizza.dat", "r+b");
                while((!achou) && (fread(pizza, sizeof(Sabor), 1, fp))) {
                    if ((pizza -> codigo == confCod) && (pizza -> status == 'A')) {
                    achou = 1;
                    }
                }
                fseek (fp, (-1)*sizeof(Sabor), SEEK_CUR);
                strcpy (nomePizza, pizza->sabor);
                pizza->quant -= 1;
                pizza->maior +=1;
                precoPizza = pizza->preco;
                fwrite(pizza, sizeof(Sabor), 1, fp);
                free (pizza);
                fclose(fp);
            }
            else{
                nomePizza[1] = 'X';
            }
            printf ("Informe o codigo da bebida que deseja ou 0 caso ele não queira: ");
            scanf ("%d", &confCod2);
            if (confCod2 !=0){
                FILE* fp;
                Bebida* tipo;
                fp = fopen("Bebida.dat", "r+b");
                tipo = (Bebida*) malloc(sizeof(Bebida));
                achou = 0;
                while((!achou) && (fread(tipo, sizeof(Bebida), 1, fp))) {
                    if ((tipo -> codigo == confCod2) && (tipo -> status == 'A')) {
                    achou = 1;
                    }
                }
                fseek (fp, (-1)*sizeof(Bebida), SEEK_CUR);
                strcpy (nomeBebida, tipo->bebida);
                precoBebida = tipo->preco;
                tipo->quant -=1;
                tipo->maior +=1;
                fwrite(tipo, sizeof(Bebida), 1, fp);
                free (tipo);
                fclose(fp);
            }
            else {
                nomeBebida[1] = 'x'; 
            }
            Pedido* codigo;
            codigo = (Pedido*) malloc(sizeof(Pedido));
            printf ("Informe o codigo que o pedido vai receber: ");
            scanf ("%d", &codigo->code);
            setbuf (stdin,NULL);
            getchar();
            strcpy(codigo->cpfPedido, cpfPess);
            strcpy(codigo->pedidoPess, nomePess);
            strcpy(codigo->pedidoBebida, nomeBebida);
            strcpy(codigo->pedidoPizza, nomePizza);
            codigo->total = precoPizza + precoBebida;
            precoT += codigo->total;
            codigo->status = 'A';
            salvaPedido (codigo);
            free (codigo);
        }
        else{
            printf ("Pessoa se encontra cadastrada no sistema\n");
            printf ("Pressione qualquer tecla para voltar ao menu anterior");
            setbuf (stdin, NULL);
            getchar();
        }
    }
    else if (strcmp (confPedi, "N") == 0 || strcmp (confPedi, "n") == 0){
        printf ("Informe o codigo da pizza que deseja ou 0 caso ele não queira: ");
        scanf ("%d", &confCod);
        if (confCod != 0){
            FILE* fp;
            Sabor* pizza;
            fp = fopen ("Pizza.dat", "r+b");
            pizza = (Sabor*) malloc(sizeof(Sabor));
            achou = 0;
            while((!achou) && (fread(pizza, sizeof(Sabor), 1, fp))) {
                if ((pizza -> codigo == confCod) && (pizza -> status == 'A')) {
                achou = 1;
                }
            }
            fseek (fp, (-1)*sizeof(Sabor), SEEK_CUR);
            strcpy (nomePizza, pizza->sabor);
            precoPizza = pizza->preco;
            pizza->quant -= 1;
            pizza->maior +=1;
            fwrite(pizza, sizeof(Sabor), 1, fp);
            free (pizza);
            fclose(fp);
        }
        else {
            nomePizza [1] = 'x';
        }
        printf ("Informe o codigo da bebida que deseja ou 0 caso ele não queira: ");
        scanf ("%d", &confCod2);
        if (confCod2 !=0){
            FILE* fp;
            Bebida* tipo;
            fp = fopen ("Bebida.dat", "r+b");
            tipo = (Bebida*) malloc(sizeof(Bebida));
            achou = 0;
            while((!achou) && (fread(tipo, sizeof(Bebida), 1, fp))) {
                if ((tipo -> codigo == confCod2) && (tipo -> status == 'A')) {
                achou = 1;
                }
            }
            fseek (fp, (-1)*sizeof(Bebida), SEEK_CUR);
            strcpy (nomeBebida, tipo->bebida);
            precoBebida = tipo->preco;
            tipo->quant -= 1;
            tipo->maior +=1;
            fwrite(tipo, sizeof(Bebida), 1, fp);
            free (tipo);
            fclose(fp);
        }
        else{
            nomeBebida[1] = 'x';
        }
        Pedido* codigo;
        codigo = (Pedido*) malloc(sizeof(Pedido));
        printf ("Informe o nome do cliente: ");
        scanf (" %[a-z A-Z]50[^\n]", codigo->pedidoPess);
        setbuf (stdin,NULL);
        getchar();
        printf ("Informe o cpf do cliente: ");
        scanf (" %[0-9]11[^\n]", codigo->cpfPedido);
        setbuf (stdin,NULL);
        getchar();
        for(int i=0;i<11;i++){  
            cpfV[i] = codigo -> cpfPedido [i] - 48;
        }
        conf = validaCPF(cpfV);
        while (conf != 0) {
            printf ("CPF invalido, Por favor informe um CPF valido: ");
            scanf (" %[0-9]11[^\n]", codigo -> cpfPedido);
            setbuf (stdin, NULL);
            getchar ();
            for(int i=0;i<11;i++){  
                cpfV[i] = codigo -> cpfPedido [i] - 48;
            }
            conf = validaCPF(cpfV);
        }
        printf ("Informe o codigo que o pedido vai receber: ");
        scanf ("%d", &codigo->code);
        setbuf (stdin,NULL);
        getchar();
        strcpy (codigo->pedidoBebida, nomeBebida);
        strcpy (codigo->pedidoPizza, nomePizza);
        codigo->total = precoBebida + precoPizza;
        precoT += codigo->total;
        codigo->status = 'A';
        printf ("Preço a se pagar: %g", codigo->total);
        setbuf (stdin, NULL);
        getchar ();
        salvaPedido (codigo);
        free (codigo);
    }
}

void salvaPedido (Pedido* codigo){
    FILE* fp;
    fp = fopen("Pedido.dat", "ab");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Por questoes de segurança vamos encerrar o programa!\n");
        setbuf (stdin,NULL);
        getchar ();
        exit(1);
    }
  fwrite(codigo, sizeof(Pedido), 1, fp);
  fclose(fp);
}

int excPedido (void){
    system ("clear || cls");
    printf ("\n\t\t########################\n");
    printf ("\t\t##  Excluir um pedido  ##\n");
    printf ("\t\t########################\n\n");
    FILE* fp;
    Pedido* codigo;
    int achou = 0;
    int confCode;
    fp = fopen("Pedido.dat", "r+b");
    if (fp == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf("O programa ira voltar ao menu anterior\n");
        printf ("Pressione qualquer tecla para continuar");
        setbuf (stdin, NULL);
        return 0;
    }
    printf("Informe o codigo do pedido que deseja apagar: ");
    scanf("%d", &confCode);
    codigo = (Pedido*) malloc(sizeof(Pedido));
    while((!achou) && (fread(codigo, sizeof(Pedido), 1, fp))) {
        if ((codigo -> code == confCode) && (codigo -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou) {
        codigo -> status = 'X';
        fseek(fp, (-1)*sizeof(Pedido), SEEK_CUR);
        fwrite(codigo, sizeof(Pedido), 1, fp);
        printf("\nPedido excluido com sucesso\n");
        setbuf (stdin, NULL);
        getchar();
    } 
    else {
        printf("O pedido nao se encontra cadastrada no nosso sistema\n");
        setbuf (stdin, NULL);
        getchar();
    }
    free(codigo);
    fclose(fp);
    return 0;
}

int cliente (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ####################\n");
        printf ("\t\t ###  Bem - vindo ###\n");
        printf ("\t\t ###      ao      ###\n");
        printf ("\t\t ### Menu Cliente ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t 1 - Adicionar um novo cliente\n");
        printf ("\t 2 - Excluir um cliente\n");
        printf ("\t 3 - Visualizar um cliente\n");
        printf ("\t 4 - Visualizar todos os clientes\n");
        printf ("\t 0 - Voltar\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                novoClie();
                break;
            case (2):
                excluiClie();
                break;
            case (3):
                visualizaClie();
                break;
            case (4):
                todoClie();
                break;
            case (0):
                return 0;
            default:
            printf ("Porfavor insira um numero valido");
            setbuf (stdin,NULL);
            getchar ();
            break;
        }
    }
    while (conf != 0);
    return 0;
}

void novoClie (void){
    int conf;
    int cpfV [12];
    Cliente* pessoa;
    pessoa = (Cliente*) malloc(sizeof(Cliente));
    system ("clear || cls");
    printf ("\n\t\t ####################\n");
    printf ("\t\t ###   Cadastro   ###\n");
    printf ("\t\t ###      de      ###\n");
    printf ("\t\t ###   Clientes   ###\n");
    printf ("\t\t ####################\n\n");
    printf ("\nSempre pressione o enter 2 vezes para confirmar\n");
    printf ("Informe o nome do cliente: ");
    scanf (" %[a-z A-Z]50[^\n]", pessoa -> nome);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe a idade do cliente: ");
    scanf ("%d", &pessoa -> idade);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe o cpf do cliente: ");
    scanf (" %[0-9]11[^\n]", pessoa -> cpf);
    setbuf (stdin, NULL);
    getchar ();
    for(int i=0;i<11;i++){  
        cpfV[i] = pessoa -> cpf [i] - 48;
    }
    conf = validaCPF(cpfV);
    while (conf != 0) {
        printf ("CPF invalido, Por favor informe um CPF valido: ");
        scanf (" %[0-9]11[^\n]", pessoa -> cpf);
        setbuf (stdin, NULL);
        getchar ();
        for(int i=0;i<11;i++){  
            cpfV[i] = pessoa -> cpf [i] - 48;
        }
        conf = validaCPF(cpfV);
    }
    printf ("Informe o telefone do cliente: ");
    scanf (" %[0-9]s[^\n]", pessoa -> telefone);
    setbuf (stdin, NULL);
    getchar ();
    pessoa->status = 'A';
    salvaClie (pessoa);
    free (pessoa);
}

int excluiClie (void){
    system ("clear || cls");
    printf ("\n\t\t#########################\n");
    printf ("\t\t##  Excluir um cliente  ##\n");
    printf ("\t\t#########################\n\n");
    FILE* fp;
    Cliente* pessoa;
    int achou = 0;
    char confPess[12];
    fp = fopen("Cliente.dat", "r+b");
    if (fp == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("Pressione qualquer tecla para voltar ao menu");
        setbuf (stdin, NULL);
        return 0;
    }
    printf("Informe o CPF da pessoa que deseja apagar ou 0 para voltar: ");
    scanf(" %11[^\n]", confPess);
    if (strcmp(confPess, "0") == 0){
        return 0;
    }
    pessoa = (Cliente*) malloc(sizeof(Cliente));
    while((!achou) && (fread(pessoa, sizeof(Cliente), 1, fp))) {
        if ((strcmp(pessoa -> cpf, confPess) == 0) && (pessoa -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou) {
        printf ("\n======================================\n");
        exibeClie(pessoa);
        printf ("======================================");
        pessoa -> status = 'X';
        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
        fwrite(pessoa, sizeof(Cliente), 1, fp);
        printf("\nPessoa excluída com sucesso\n");
        setbuf (stdin, NULL);
        getchar();
    } 
    else {
        printf("A pessoa não se encontra cadastrada no nosso sistema\n");
        setbuf (stdin, NULL);
        getchar();
    }
    free(pessoa);
    fclose(fp);
    return 0;
}

int visualizaClie (void){
    FILE* fp;
    Cliente* pessoa;
    int conf = 0;
    char confPess [12];
    fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Pressiona qualquer tecla para voltar\n");
        setbuf (stdin, NULL);
        getchar();
        return 0;
    }
    system ("clear || cls");
    printf ("\n\t\t###########################\n");
    printf ("\t\t## Visualizar um Cliente ##\n");
    printf ("\t\t###########################\n\n");
    printf ("Por favor informe o CPF do cliente que deseja verificar ou 0 para voltar: ");
    scanf ("%s", confPess);
    if (strcmp(confPess, "0") == 0){
        return 0;
    }
    pessoa = (Cliente*) malloc(sizeof(Cliente));
    while((!conf) && (fread(pessoa, sizeof(Cliente), 1, fp))) {
        if ((strcmp(pessoa->cpf, confPess) == 0) && (pessoa->status == 'A')) {
            conf = 1;
        }
    }
    if (conf) {
        printf ("======================================\n");
        exibeClie(pessoa);
        printf ("======================================\n");
        printf ("Pressione qualquer tecla para continuar\n");
        setbuf (stdin, NULL);
        getchar ();
    } 
    else {
        printf("Esta pessoa não se encontra cadastrada\n");
        setbuf (stdin, NULL);
        getchar();
    }
    fclose(fp);
    free(pessoa);
    return 0;
}

int todoClie (void){
    system ("clear || cls");
    printf ("\n\t\t##########################\n");
    printf ("\t\t##  Todos os Clientes  ##\n");
    printf ("\t\t##########################\n\n");
    FILE* fp;
    Cliente* pessoa;
    printf ("\n = Lista de Clientes = \n");
    pessoa = (Cliente*) malloc (sizeof(Cliente));
    fp = fopen("Cliente.dat" , "rb");
    if (fp == NULL){
        printf ("Ocorreu um erro na abertura do arquivo!\n");
        printf("Pressione qualquer tecla para voltar\n");
        setbuf (stdin,NULL);
        getchar ();
        return 0;
    }
    while(fread(pessoa, sizeof(Cliente), 1, fp)) {
        if (pessoa->status == 'A'){
            printf ("======================================\n");
            exibeClie(pessoa);
            printf ("======================================\n");
        }
    }
    printf ("Pressione qualquer tecla para continuar\n");
    setbuf (stdin, NULL);
    getchar ();
    fclose(fp);
    free(pessoa);
    return 0;
}

void exibeClie(Cliente* pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("CPF: %s\n", pessoa->cpf);
    printf("Idade: %d\n", pessoa->idade);
    printf ("Telefone: %s\n", pessoa->telefone);
}

void salvaClie (Cliente* pessoa){
    FILE* fp;
    fp = fopen("Cliente.dat", "ab");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Por questoes de segurança vamos encerrar o programa!\n");
        setbuf (stdin,NULL);
        getchar ();
        exit(1);
    }
    fwrite(pessoa, sizeof(Cliente), 1, fp);
    fclose(fp);
}

int pizzaiolo (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ######################\n");
        printf ("\t\t ###   Bem - vindo  ###\n");
        printf ("\t\t ###       ao       ###\n");
        printf ("\t\t ### Menu Pizzaiolo ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t 1 - Adicionar um novo pizzaiolo\n");
        printf ("\t 2 - Excluir um pizzaiolo\n");
        printf ("\t 3 - Visualizar todos os pizzaiolos\n");
        printf ("\t 0 - Voltar\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                novoPizzaiolo();
                break;
            case (2):
                excluiPizzaiolo();
                break;
            case (3):
                todoPizzaiolo();
                break;
            case (0):
                return 0;
            default:
            printf ("Porfavor insira um numero valido");
            setbuf (stdin,NULL);
            getchar ();
            break;
        }
    }
    while (conf != 0);
    return 0;
}

void novoPizzaiolo (void){
    int conf;
    int cpfV [12];
    Pizza* chapa;
    chapa = (Pizza*) malloc(sizeof(Pizza));
    system ("clear || cls");
    printf ("\n\t\t ####################\n");
    printf ("\t\t ###   Cadastro   ###\n");
    printf ("\t\t ###     de     ###\n");
    printf ("\t\t ###  Pizzaiolo  ###\n");
    printf ("\t\t ####################\n\n");
    printf ("\nSempre pressione o enter 2 vezes para confirmar\n");
    printf ("Informe o nome do pizzaiolo: ");
    scanf (" %[a-z A-Z]50[^\n]", chapa -> nome);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe a idade do pizzaiolo: ");
    scanf ("%d", &chapa -> idade);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe o cpf do pizzaiolo: ");
    scanf (" %[0-9]11[^\n]", chapa -> cpf);
    setbuf (stdin, NULL);
    getchar ();
    for(int i=0;i<11;i++){  
        cpfV[i] = chapa -> cpf [i] - 48;
    }
    conf = validaCPF(cpfV);
    while (conf != 0) {
        printf ("CPF invalido, Por favor informe um CPF valido: ");
        scanf (" %[0-9]11[^\n]", chapa -> cpf);
        setbuf (stdin, NULL);
        getchar ();
        for(int i=0;i<11;i++){  
            cpfV[i] = chapa -> cpf [i] - 48;
        }
        conf = validaCPF(cpfV);
    }
    chapa->status = 'A';
    salvaPizzaiolo (chapa);
    free (chapa);
}

int excluiPizzaiolo (void){
    system ("clear || cls");
    printf ("\n\t\t############################\n");
    printf ("\t\t##  Excluir um pizzaiolo  ##\n");
    printf ("\t\t############################\n\n");
    FILE* fp;
    Pizza* chapa;
    int achou = 0;
    char confPizza[12];
    fp = fopen("Pizzaiolo.dat", "r+b");
    if (fp == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("Pressione qualquer tecla para voltar ao menu");
        setbuf (stdin, NULL);
        return 0;
    }
    printf("Informe o CPF do pizzaiolo que deseja apagar ou 0 para voltar: ");
    scanf(" %11[^\n]", confPizza);
    if (strcmp(confPizza, "0") == 0){
        return 0;
    }
    chapa = (Pizza*) malloc(sizeof(Pizza));
    while((!achou) && (fread(chapa, sizeof(Pizza), 1, fp))) {
        if ((strcmp(chapa -> cpf, confPizza) == 0) && (chapa -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou) {
        printf ("\n======================================\n");
        exibePizzaiolo(chapa);
        printf ("======================================");
        chapa -> status = 'X';
        fseek(fp, (-1)*sizeof(Pizza), SEEK_CUR);
        fwrite(chapa, sizeof(Pizza), 1, fp);
        printf("\nPizzaiolo excluído com sucesso\n");
        setbuf (stdin, NULL);
        getchar();
    } 
    else {
        printf("O pizzaiolo não se encontra cadastrado no nosso sistema\n");
        setbuf (stdin, NULL);
        getchar();
    }
    free(chapa);
    fclose(fp);
    return 0;
}

int todoPizzaiolo (void){
    system ("clear || cls");
    printf ("\n\t\t###########################\n");
    printf ("\t\t##  Todos os Pizzaiolos  ##\n");
    printf ("\t\t###########################\n\n");
    FILE* fp;
    Pizza* chapa;
    printf ("\n = Lista de Pizzaiolos = \n");
    chapa = (Pizza*) malloc (sizeof(Pizza));
    fp = fopen("Pizzaiolo.dat" , "rb");
    if (fp == NULL){
        printf ("Ocorreu um erro na abertura do arquivo!\n");
        printf("Pressione qualquer tecla para voltar\n");
        setbuf (stdin,NULL);
        getchar ();
        return 0;
    }
    while(fread(chapa, sizeof(Pizza), 1, fp)) {
        if (chapa->status == 'A'){
            printf ("======================================\n");
            exibePizzaiolo(chapa);
            printf ("======================================\n");
        }
    }
    printf ("Pressione qualquer tecla para continuar\n");
    setbuf (stdin, NULL);
    getchar ();
    fclose(fp);
    free(chapa);
    return 0;
}

void exibePizzaiolo (Pizza* chapa) {
    printf("Nome: %s\n", chapa->nome);
    printf("CPF: %s\n", chapa->cpf);
    printf("Idade: %d\n", chapa->idade);
}

void salvaPizzaiolo (Pizza* chapa){
    FILE* fp;
    fp = fopen("Pizzaiolo.dat", "ab");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Por questoes de segurança vamos encerrar o programa!\n");
        setbuf (stdin,NULL);
        getchar ();
        exit(1);
    }
    fwrite(chapa, sizeof(Pizza), 1, fp);
    fclose(fp);
}

int avalia (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ####################\n");
        printf ("\t\t ###      Menu    ###\n");
        printf ("\t\t ###       de     ###\n");
        printf ("\t\t ###   Avaliacao  ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t\t1 - Cadastrar avaliação\n");
        printf ("\t\t2 - Mostrar avaliacoes\n");
        printf ("\t\t0 - Voltar\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                cadastraAvalia ();
                break;
            case (2):
                listaAvalia ();
                break;
            case (0):
                return 0;
            default:
                printf ("Por favor insira um numero valido");
                setbuf (stdin,NULL);
                getchar ();
                break;
        }
    }
    while (conf != 0);
    return 0;
}

void cadastraAvalia (void){
    Avalia* servico;
    servico = (Avalia*) malloc(sizeof(Avalia));
    system ("clear || cls");
    printf ("\n\t\t ########################\n");
    printf ("\t\t ###      Cadastro    ###\n");
    printf ("\t\t ###         de       ###\n");
    printf ("\t\t ###     Alimentos    ###\n");
    printf ("\t\t ########################\n\n");
    printf ("\nSempre pressione o enter 2 vezes para confirmar\n");
    printf ("Informe uma nota de 0 a 5 para a qualidade da comida: ");
    scanf (" %[0-5]1[^\n]", servico -> notaC);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe uma nota de 0 a 5 para o tempo de espera: ");
    scanf (" %[0-5]1[^\n]", servico -> notaT);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe uma nota de 0 a 5 para a qualidade do servico: ");
    scanf (" %[0-5]1[^\n]", servico -> notaS);
    setbuf (stdin, NULL);
    getchar ();
    printf ("Informe um comentario sobre: ");
    scanf (" %[a-z A-Z]s[^\n]" ,servico -> comentario);
    setbuf (stdin, NULL);
    getchar ();
    salvaAvalia (servico);
    free (servico);
    printf ("Obrigado pela preferencia e volte sempre :)");
    setbuf (stdin, NULL);
    getchar ();
}

void salvaAvalia (Avalia* servico){
    FILE* fp;
    fp = fopen("Avaliaçoes.txt", "at");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        printf("Por questoes de segurança vamos encerrar o programa!\n");
        setbuf (stdin,NULL);
        getchar ();
        exit(1);
    }
  fwrite(servico, sizeof(Avalia), 1, fp);
  fclose(fp);
}

int listaAvalia (void){
    system ("clear || cls");
    printf ("\n\t\t #####################\n");
    printf ("\t\t ###      Lista    ###\n");
    printf ("\t\t ###       de      ###\n");
    printf ("\t\t ###   Avaliacoes  ###\n");
    printf ("\t\t #####################\n\n");
    FILE* fp;
    Avalia* servico;
    servico = (Avalia*) malloc (sizeof(Avalia));
    fp = fopen("avaliaçoes.txt" , "rt");
    if (fp == NULL){
        printf ("Ocorreu um erro na abertura do arquivo!\n");
        printf("Pressione qualquer tecla para voltar ao menu\n");
        setbuf (stdin,NULL);
        getchar ();
        return 0;
    }
    while(fread(servico, sizeof(Avalia), 1, fp)) {
        printf ("======================================\n");
        exibeAvalia(servico);
        printf ("======================================\n");
    }
    printf ("Pressione qualquer tecla para continuar\n");
    setbuf (stdin, NULL);
    getchar ();
    fclose(fp);
    free(servico);
    return 0;
}

void exibeAvalia(Avalia* servico) {
    printf("Nota da comida: %s\n", servico->notaC);
    printf("Nota do servico: %s\n", servico->notaS);
    printf("Nota de espera: %s\n", servico->notaT);
    printf("Comentario: %s\n", servico->comentario);
}

int promo (void){
    system ("clear || cls");
    printf ("\n\t\t ###################\n");
    printf ("\t\t ##    Promocao   ##\n");
    printf ("\t\t ###################\n\n");
    FILE* fp;
    Sabor* pizza;
    int achou = 0;
    int confCod;
    fp = fopen("Pizza.dat", "r+b");
    if (fp == NULL){
        printf ("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("O programa ira fechar por questoes de segurança\n");
        printf ("Digite qualquer tecla");
        setbuf (stdin, NULL);
        getchar ();
        return 0;
    }
    printf ("Informe o codigo da pizza que recebera a promoacao ou 0 para voltar: ");
    scanf ("%d", &confCod);
    if (confCod == 0){
        return 0;
    }
    pizza = (Sabor*) malloc(sizeof(Sabor));
    while((!achou) && (fread(pizza, sizeof(Sabor), 1, fp))) {
        if ((pizza ->codigo == confCod) && (pizza -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou){
        printf ("======================================\n");
        exibeSabor(pizza);
        printf ("======================================\n");
        setbuf (stdin, NULL);
        getchar();
        printf ("Informe o novo preco: ");
        scanf ("%f", &pizza -> preco);
        fseek (fp, (-1)*sizeof(Sabor), SEEK_CUR);
        fwrite (pizza, sizeof(Sabor), 1, fp);
    }
    else{
        printf ("Esta pizza não esta cadastrada no sistema\n");
        setbuf (stdin, NULL);
        getchar ();
    }
    free(pizza);
    fclose(fp);
    return 0;
}

int estoque (void){
    int conf;
    do {
        system ("clear || cls");
        printf ("\n\t\t ####################\n");
        printf ("\t\t ###      Menu    ###\n");
        printf ("\t\t ###       de     ###\n");
        printf ("\t\t ###    Estoque   ###\n");
        printf ("\t\t ####################\n\n");
        printf ("=====================================================\n");
        printf ("\t\t1 - Adicionar quantidade de pizzas no estoque\n");
        printf ("\t\t2 - Adicionar quantidade de bebidas no estoque\n");
        printf ("\t\t3 - Ver todas as pizzas do estoque\n");
        printf ("\t\t4 - Ver todas as bebidas do estoque\n");
        printf ("\t\t0 - Voltar\n");
        printf ("=====================================================\n\n\n");
        printf ("Informe uma das alternativas: ");
        scanf ("%d", &conf);
        switch (conf){
            case (1):
                addPizza ();
                break;
            case (2):
                addBebida ();
                break;
            case (3):
                listaSabor();
                break;
            case (4):
                listaBebida();
                break;
            case (0):
                return 0;
            default:
                printf ("Por favor insira um numero valido");
                setbuf (stdin,NULL);
                getchar ();
                break;
        }
    }
    while (conf != 0);
    return 0;
}

int addPizza (void){
    system ("clear || cls");
    FILE* fp;
    Sabor* pizza;
    int achou = 0;
    int confCod, add;
    fp = fopen("Pizza.dat", "r+b");
    if (fp == NULL){
        printf ("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("Digite qualquer tecla");
        setbuf (stdin, NULL);
        getchar ();
        return 0;
    }
    printf ("Informe o codigo da pizza que deseja adicionar: ");
    scanf ("%d", &confCod);
    pizza = (Sabor*) malloc(sizeof(Sabor));
    while((!achou) && (fread(pizza, sizeof(Sabor), 1, fp))) {
        if ((pizza ->codigo == confCod) && (pizza -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou){
        printf ("======================================\n");
        exibeSabor(pizza);
        printf ("======================================\n");
        setbuf (stdin, NULL);
        getchar();
        printf ("Informe quantas unidades vai adicionar: ");
        scanf ("%d", &add);
        pizza->quant += add;
        fseek (fp, (-1)*sizeof(Sabor), SEEK_CUR);
        fwrite (pizza, sizeof(Sabor), 1, fp);
    }
    else{
        printf ("Esta pizza não esta cadastrada no sistema\n");
        setbuf (stdin, NULL);
        getchar ();
    }
    free(pizza);
    fclose(fp);
    return 0;
}

int addBebida (void){
    system ("clear || cls");
    FILE* fp;
    Bebida* tipo;
    int achou = 0;
    int confCod, add;
    fp = fopen("Bebida.dat", "r+b");
    if (fp == NULL){
        printf ("Ocorreu um erro ao tentar abrir o arquivo\n");
        printf ("Digite qualquer tecla");
        setbuf (stdin, NULL);
        getchar ();
        return 0;
    }
    printf ("Informe o codigo da bebida que deseja adicionar: ");
    scanf ("%d", &confCod);
    tipo = (Bebida*) malloc(sizeof(Bebida));
    while((!achou) && (fread(tipo, sizeof(Bebida), 1, fp))) {
        if ((tipo ->codigo == confCod) && (tipo -> status == 'A')) {
            achou = 1;
        }
    }
    if (achou){
        printf ("======================================\n");
        exibeBebida(tipo);
        printf ("======================================\n");
        setbuf (stdin, NULL);
        getchar();
        printf ("Informe quantas unidades vai adicionar: ");
        scanf ("%d", &add);
        tipo->quant += add;
        fseek (fp, (-1)*sizeof(Bebida), SEEK_CUR);
        fwrite (tipo, sizeof(Bebida), 1, fp);
    }
    else{
        printf ("Esta bebida não esta cadastrada no sistema\n");
        setbuf (stdin, NULL);
        getchar ();
    }
    free(tipo);
    fclose(fp);
    return 0;
}

int relatorio (void){
    system ("clear || cls");
    int codP, codB;
    int conf = 0;
    long int maioriaP = 0;
    long int maioriaB = 0;
    FILE* fa;
    FILE* fb;
    FILE* fc;
    FILE* fd;
    Sabor* pizza;

    pizza =(Sabor*) malloc(sizeof(Sabor));
    fa = fopen ("Pizza.dat", "rb");
    fb = fopen ("Pizza.dat", "rb");
    while ((fread(pizza, sizeof(Sabor), 1, fa))){
        if (maioriaP < pizza->maior){
            maioriaP = pizza->maior;
            codP = pizza->codigo;
        }
    }
    
    while((!conf) && (fread(pizza, sizeof(Sabor), 1, fb))) {
        if ((pizza->codigo == codP) && (pizza->status == 'A')) {
            conf = 1;
        }
    }
    if (conf) {
        printf ("\nPizza mais vendida: \n");
        printf ("======================================\n");
        exibeSabor(pizza);
        printf ("======================================");
    }
    free (pizza);
    fclose(fa);
    fclose(fb);

    Bebida* tipo;
    tipo =(Bebida*) malloc(sizeof(Bebida));
    fc = fopen ("Bebida.dat", "rb");
    fd = fopen ("Bebida.dat", "rb");
    while ((fread(tipo, sizeof(Bebida), 1, fc))){
        if (maioriaB < tipo->maior){
            maioriaB = tipo->maior;
            codB = tipo->codigo;
        }
    }
    conf = 0;
    while((!conf) && (fread(tipo, sizeof(Bebida), 1, fd))) {
        if ((tipo->codigo == codB) && (tipo->status == 'A')) {
            conf = 1;
        }
    }
    if (conf) {
        printf ("\n\nBebida mais vendida: \n");
        printf ("======================================\n");
        exibeBebida(tipo);
        printf ("======================================");
    }
    free (tipo);
    fclose(fc);
    fclose (fd);
    printf ("\n\nTotal faturado hoje: %g R$", precoT);
    printf ("\n\nPressione qualquer tecla para voltar");
    setbuf (stdin, NULL);
    getchar ();
    return 0;
}

int validaCPF (int *cpfV){
    int soma = 0, resul1, resul2;
    for(int i=0;i<9;i++){
        soma+=cpfV[i]*(10-i);
    }
    resul1=(soma*10)%11;
    if(resul1 >= 10){
        resul1=0;
    }

    soma=0;
    for(int i=0;i<10;i++){
        soma += cpfV[i]*(11-i);
    }
    resul2= (soma*10)%11;
    if(resul2 >= 10){
        resul2=0;
    } 
    if((resul1 == cpfV[9]) && (resul2 == cpfV[10])){
        return 0;
    }  
    else{
        return 1;
    }  
}
