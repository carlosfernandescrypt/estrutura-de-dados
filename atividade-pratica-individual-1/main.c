#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a estrutura Artista
typedef struct {
    char nome[100];
    char genero[50];
    char local[100];
    char albums[100][100];
    int numAlbums;
} Artista;

// Função para ler um artista de um arquivo
Artista lerArtista(FILE *arquivo) {
    Artista artista;
    fscanf(arquivo, "%s", artista.nome); // Lê o nome do artista
    fscanf(arquivo, "%s", artista.genero); // Lê o gênero do artista
    fscanf(arquivo, "%s", artista.local); // Lê o local do artista
    artista.numAlbums = 0; // Inicializa o número de álbuns
    char linha[100];
    // Lê os álbuns do artista até encontrar "=========="
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strcmp(linha, "==========\n") == 0) {
            break;
        }
        strcpy(artista.albums[artista.numAlbums], linha); // Copia o nome do álbum
        artista.numAlbums++; // Incrementa o número de álbuns
    }
    return artista; // Retorna o artista lido
}

// Função para inserir um novo artista no array de artistas
void inserirArtista(Artista artistas[], int *numArtistas, Artista novoArtista) {
    int posicao = *numArtistas;
    // Encontra a posição correta para inserir o novo artista (ordem alfabética)
    while (posicao > 0 && strcmp(novoArtista.nome, artistas[posicao - 1].nome) < 0) {
        artistas[posicao] = artistas[posicao - 1];
        posicao--;
    }
    artistas[posicao] = novoArtista; // Insere o novo artista na posição correta
    (*numArtistas)++; // Incrementa o número de artistas

    // Abre o arquivo para escrita (modo "a" para adicionar ao final do arquivo)
    FILE *arquivo = fopen("arquivo.txt", "a");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve os dados do novo artista no arquivo
    fprintf(arquivo, "%s\n", novoArtista.nome);
    fprintf(arquivo, "%s\n", novoArtista.genero);
    fprintf(arquivo, "%s\n", novoArtista.local);
    for (int i = 0; i < novoArtista.numAlbums; i++) {
        fprintf(arquivo, "%s\n", novoArtista.albums[i]);
    }
    fprintf(arquivo, "===========\n"); // Marca o fim do registro

    fclose(arquivo); // Fecha o arquivo

    printf("Artista inserido com sucesso!\n"); // Imprime uma mensagem de sucesso
}

// Função para remover um artista do array de artistas
void removerArtista(Artista artistas[], int *numArtistas, char nome[]) {
    int i, j;
    // Procura o artista pelo nome
    for (i = 0; i < *numArtistas; i++) {
        if (strcmp(artistas[i].nome, nome) == 0) {
            // Remove o artista deslocando todos os artistas seguintes uma posição para trás
            for (j = i; j < *numArtistas - 1; j++) {
                artistas[j] = artistas[j + 1];
            }
            (*numArtistas)--; // Decrementa o número de artistas
            break;
        }
    }

    // Abre o arquivo para escrita (modo "w" para sobrescrever o arquivo)
    FILE *arquivo = fopen("arquivo.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    // Escreve todos os artistas no arquivo
    for (i = 0; i < *numArtistas; i++) {
        fprintf(arquivo, "%s\n%s\n%s\n", artistas[i].nome, artistas[i].genero, artistas[i].local);
        for (j = 0; j < artistas[i].numAlbums; j++) {
            fprintf(arquivo, "%s\n", artistas[i].albums[j]);
        }
    }
    fclose(arquivo); // Fecha o arquivo
}

void editarArtista(Artista artistas[], int *numArtistas, char nome[]) { //OBS: não foi possivel implementar essa função para editar o .txt pois não é possível editar textos no meio do arquivo, pesquisei em tudo quanto é forum uma forma de fazer isso, e a única que encontrei foi excluindo o arquivo e criando outro, o que é muito difícil para ser implementado. Mesma coisa para o removerArtista, remover texto no meio do arquivo é muito complicado.
    Artista novoArtista;
 int i;
    // Procura o artista pelo nome
    for (i = 0; i < numArtistas; i++) {
        if (strcmp(artistas[i].nome, nome) == 0) {
            // Solicita ao usuário os novos dados do artista
            printf("Digite o novo nome do artista: ");
            scanf("%99[^\n]", artistas[i].nome);
            printf("Digite o novo gênero musical: ");
            scanf("%49[^\n]", artistas[i].genero);
            printf("Digite o novo local de criação/nascimento: ");
            scanf("%99[^\n]", artistas[i].local);
            printf("Digite os novos álbuns (digite '==========' para encerrar):\n");
            artistas[i].numAlbums = 0;
            // Lê os novos álbuns do artista
            while (1) {
                scanf("%99[^\n]", artistas[i].albums[artistas[i].numAlbums]);
                if (strcmp(artistas[i].albums[artistas[i].numAlbums], "==========") == 0) {
                    break;
                }
                artistas[i].numAlbums++;
            }

          FILE *arquivo = fopen("artistas.txt", "w");
          if (!arquivo) {
              printf("Erro ao abrir o arquivo.\n");
              return;
          }
          // Escreve todos os artistas no arquivo
          for (int i = 0; i < numArtistas; i++) {
              fprintf(arquivo, "%s\n%s\n%s\n", artistas[i].nome, artistas[i].genero, artistas[i].local);
              for (int j = 0; j < artistas[i].numAlbums; j++) {
                  fprintf(arquivo, "%s\n", artistas[i].albums[j]);
              }
              fprintf(arquivo, "==========\n"); // Marca o fim do registro
          }
          fclose(arquivo); // Fecha o arquivo
          }
            break;
        }
    }

// Função para buscar um artista pelo nome (busca sequencial)
int buscarArtistaSequencial(Artista artistas[], int numArtistas, char nome[]) {
    int i;
    // Procura o artista pelo nome
    for (i = 0; i < numArtistas; i++) {
        if (strcmp(artistas[i].nome, nome) == 0) {
            return i; // Retorna o índice do artista encontrado
        }
    }
    return -1; // Retorna -1 se o artista não foi encontrado
}

// Função para buscar um artista pelo nome (busca binária)
int buscarArtistaBinario(Artista artistas[], int numArtistas, char nome[]) {
    int inicio = 0;
    int fim = numArtistas - 1;
    // Procura o artista pelo nome
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int comparacao = strcmp(artistas[meio].nome, nome);
        if (comparacao == 0) {
            return meio; // Retorna o índice do artista encontrado
        }
    }
    return -1; // Retorna -1 se o artista não foi encontrado
}

// Função para exibir um artista
void exibirArtista(Artista artista) {
    // Imprime as informações do artista
    printf("Nome: %s\n", artista.nome);
    printf("Gênero: %s\n", artista.genero);
    printf("Local: %s\n", artista.local);
    printf("Álbuns:\n");
    // Imprime todos os álbuns do artista
    for (int i = 0; i < artista.numAlbums; i++) {
        printf("  - %s\n", artista.albums[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    // Abre o arquivo de artistas para leitura
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (!arquivo) {
        // Se houve um erro ao abrir o arquivo, imprime uma mensagem de erro e encerra o programa
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    // Cria um array para armazenar os artistas
    Artista artistas[100];
    int numArtistas = 0;
    // Lê todos os artistas do arquivo
    while (!feof(arquivo)) {
        artistas[numArtistas] = lerArtista(arquivo);
        numArtistas++;
    }
    // Fecha o arquivo
    fclose(arquivo);

    // Cria uma variável para armazenar um novo artista
    Artista novoArtista;
    int opcao;
    // Exibe um menu de opções até que o usuário escolha sair
    do {
        // Imprime o menu
        printf("\nMenu:\n");
        printf("1. Inserir novo artista\n");
        printf("2. Remover artista\n");
        printf("3. Editar artista\n");
        printf("4. Buscar artista (busca binária)\n");
        printf("5. Buscar álbum (busca sequencial)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        // Lê a opção escolhida pelo usuário
        scanf("%d", &opcao);

        // Executa a ação correspondente à opção escolhida
        switch (opcao) {
          case 1:
          {
              // Opção para inserir um novo artista
              printf("Digite o nome do novo artista: ");
              scanf(" %[^\n]", novoArtista.nome);
              printf("Digite o gênero musical: ");
              scanf(" %[^\n]", novoArtista.genero);
              printf("Digite o local de criação/nascimento: ");
              scanf(" %[^\n]", novoArtista.local);
              printf("Digite os álbuns (digite '==========' para encerrar):\n");
              novoArtista.numAlbums = 0;
              // Lê os álbuns do novo artista
              while (1) {
                  scanf(" %[^\n]", novoArtista.albums[novoArtista.numAlbums]);
                  if (strcmp(novoArtista.albums[novoArtista.numAlbums], "==========") == 0) {
                      break;
                  }
                  novoArtista.numAlbums++;
              }
              // Insere o novo artista no array de artistas
              inserirArtista(artistas, &numArtistas, novoArtista);
              printf("Artista inserido com sucesso!\n");
              break;
          }
          case 2:
            {
              // Opção para remover um artista
              char nomeRemover[100];
              printf("Digite o nome do artista a ser removido: ");
              scanf("%s", nomeRemover);
              // Remove o artista do array de artistas
              removerArtista(artistas, &numArtistas, nomeRemover);
              printf("Artista removido com sucesso!\n");
              break;
            }
          case 3:
          {
              // Opção para editar um artista
              char nomeEditar[100];
              printf("Digite o nome do artista a ser editado: ");
              scanf(" %[^\n]", nomeEditar);
              int i;
              // Procura o artista pelo nome
              for (i = 0; i < numArtistas; i++) {
                  if (strcmp(artistas[i].nome, nomeEditar) == 0) {
                      // Solicita ao usuário os novos dados do artista
                      printf("Digite o novo nome do artista: ");
                      scanf(" %[^\n]", artistas[i].nome);
                      printf("Digite o novo gênero musical: ");
                      scanf(" %[^\n]", artistas[i].genero);
                      printf("Digite o novo local de criação/nascimento: ");
                      scanf(" %[^\n]", artistas[i].local);
                      printf("Digite os novos álbuns (digite '==========' para encerrar):\n");
                      artistas[i].numAlbums = 0;
                      // Lê os novos álbuns do artista
                      while (1) {
                          scanf(" %[^\n]", artistas[i].albums[artistas[i].numAlbums]);
                          if (strcmp(artistas[i].albums[artistas[i].numAlbums], "==========") == 0) {
                              break;
                          }
                          artistas[i].numAlbums++;
                      }
                      break;
                  }
              }
              printf("Artista editado com sucesso!\n");
              break;
          }

          case 4:
            {
              // Opção para buscar um artista (busca binária)
              char nomeBuscarBinario[100];  
              printf("Digite o nome do artista a ser buscado (busca binária): "); 
              scanf("%s", nomeBuscarBinario);
              int indiceBinario = buscarArtistaBinario(artistas, numArtistas, nomeBuscarBinario);
              if (indiceBinario != -1) {
                  printf("Artista encontrado:\n");
                  exibirArtista(artistas[indiceBinario]);
              }
              break;
              }
          case 5:
            {
              // Opção para buscar um artista (busca sequencial)
              char nomeBuscarSequencial[100];
              printf("Digite o nome do artista a ser buscado (busca sequencial): ");
              scanf("%s", nomeBuscarSequencial);
              int indiceSequencial = buscarArtistaSequencial(artistas, numArtistas, nomeBuscarSequencial);
              if (indiceSequencial != -1) {
                  printf("Artista encontrado:\n");
                  exibirArtista(artistas[indiceSequencial]);
              }
              break;
            }
            case 0:
                // Opção para sair do programa
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                // Opção inválida
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);


    return 0;
}
