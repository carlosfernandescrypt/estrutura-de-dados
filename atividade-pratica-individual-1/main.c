#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char genero[50];
    char local[100];
    char albums[100][100];
    int numAlbums;
} Artista;

Artista lerArtista(FILE *arquivo) {
    Artista artista;
    fscanf(arquivo, "%s", artista.nome);
    fscanf(arquivo, "%s", artista.genero);
    fscanf(arquivo, "%s", artista.local);
    artista.numAlbums = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strcmp(linha, "==========\n") == 0) {
            break;
        }
        strcpy(artista.albums[artista.numAlbums], linha);
        artista.numAlbums++;
      
    }
    return artista;
}

void inserirArtista(Artista artistas[], int *numArtistas, Artista novoArtista) {
    int posicao = *numArtistas;
    while (posicao > 0 && strcmp(novoArtista.nome, artistas[posicao - 1].nome) < 0) {
        artistas[posicao] = artistas[posicao - 1];
        posicao--;
    }
    artistas[posicao] = novoArtista;
    (*numArtistas)++;

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

    // Fecha o arquivo
    fclose(arquivo);

    printf("Artista inserido com sucesso!\n");
}

void removerArtista(Artista artistas[], int *numArtistas, char nome[]) {
    int i, j;
    for (i = 0; i < *numArtistas; i++) {
        if (strcmp(artistas[i].nome, nome) == 0) {
            for (j = i; j < *numArtistas - 1; j++) {
                artistas[j] = artistas[j + 1];
            }
            (*numArtistas)--;
            break; // Encontrou o artista, pode sair do loop
          
        }
    }

    // Abrir o arquivo no modo de escrita
    FILE *arquivo = fopen("arquivo.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escrever a lista atualizada no arquivo
    for (i = 0; i < *numArtistas; i++) {
        fprintf(arquivo, "%s\n%s\n%s\n", artistas[i].nome, artistas[i].genero, artistas[i].local);
        for (j = 0; j < artistas[i].numAlbums; j++) {
            fprintf(arquivo, "%s\n", artistas[i].albums[j]);
        }
        fprintf(arquivo, "==========\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void editarArtista(Artista artistas[], int numArtistas, char nome[]) {
    int i;
    for (i = 0; i < numArtistas; i++) {
        if (strcmp(artistas[i].nome, nome) == 0) {
            printf("Digite o novo nome do artista: ");
            scanf("%99[^\n]", artistas[i].nome);
            printf("Digite o novo gênero musical: ");
            scanf("%49[^\n]", artistas[i].genero);
            printf("Digite o novo local de criação/nascimento: ");
            scanf("%99[^\n]", artistas[i].local);
            printf("Digite os novos álbuns (digite '==========' para encerrar):\n");
            artistas[i].numAlbums = 0;
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
          for (int i = 0; i < numArtistas; i++) {
              fprintf(arquivo, "%s\n%s\n%s\n", artistas[i].nome, artistas[i].genero, artistas[i].local);
              for (int j = 0; j < artistas[i].numAlbums; j++) {
                  fprintf(arquivo, "%s\n", artistas[i].albums[j]);
              }
              fprintf(arquivo, "==========\n");
          }
          fclose(arquivo);
          }
            break;
        }
    }

int buscarArtistaSequencial(Artista artistas[], int numArtistas, char nome[]) {
    int i;
    for (i = 0; i < numArtistas; i++) {
        if (strcmp(artistas[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

int buscarArtistaBinario(Artista artistas[], int numArtistas, char nome[]) {
    int inicio = 0;
    int fim = numArtistas - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int comparacao = strcmp(artistas[meio].nome, nome);
        if (comparacao == 0) {
            return meio;
        }
    }
    return -1;
}

void imprimirArtistas(Artista artistas[], int numArtistas) {
    int i;
    for (i = 0; i < numArtistas; i++) {
        printf("Nome: %s\n", artistas[i].nome);
        printf("Gênero: %s\n", artistas[i].genero);
        printf("Local de criação/nascimento: %s\n", artistas[i].local);
        printf("Álbuns:\n");
        int j;
        for (j = 0; j < artistas[i].numAlbums; j++) {
            printf("- %s\n", artistas[i].albums[j]);
        }
        printf("\n");
    }
}

void exibirArtista(Artista artista) {
    printf("Nome: %s\n", artista.nome);
    printf("Gênero: %s\n", artista.genero);
    printf("Local: %s\n", artista.local);
    printf("Álbuns:\n");
    for (int i = 0; i < artista.numAlbums; i++) {
        printf("  - %s\n", artista.albums[i]);
    }
    printf("\n");
}

int main() {
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    Artista artistas[100];
    int numArtistas = 0;
    while (!feof(arquivo)) {
        artistas[numArtistas] = lerArtista(arquivo);
        numArtistas++;
    }
    fclose(arquivo);

    Artista novoArtista;
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir novo artista\n");
        printf("2. Remover artista\n");
        printf("3. Editar artista\n");
        printf("4. Buscar artista (busca binária)\n");
        printf("5. Buscar álbum (busca sequencial)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
          case 1:
          {
              printf("Digite o nome do novo artista: ");
              scanf(" %[^\n]", novoArtista.nome);
              printf("Digite o gênero musical: ");
              scanf(" %[^\n]", novoArtista.genero);
              printf("Digite o local de criação/nascimento: ");
              scanf(" %[^\n]", novoArtista.local);
              printf("Digite os álbuns (digite '==========' para encerrar):\n");
              novoArtista.numAlbums = 0;
              while (1) {
                  scanf(" %[^\n]", novoArtista.albums[novoArtista.numAlbums]);
                  if (strcmp(novoArtista.albums[novoArtista.numAlbums], "==========") == 0) {
                      break;
                  }
                  novoArtista.numAlbums++;
              }
              inserirArtista(artistas, &numArtistas, novoArtista);
              printf("Artista inserido com sucesso!\n");
              break;
          }
          case 2:
            {
              char nomeRemover[100];
              printf("Digite o nome do artista a ser removido: ");
              scanf("%s", nomeRemover);
              removerArtista(artistas, &numArtistas, nomeRemover);
              printf("Artista removido com sucesso!\n");
              break;
            }
          case 3:
            {
              char nomeEditar[100];
              printf("Digite o nome do artista a ser editado: ");
              scanf("%s", nomeEditar);
              editarArtista(artistas, numArtistas, nomeEditar);
              printf("Artista editado com sucesso!\n");
              break;
            }
          case 4:
            {
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
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
  

    return 0;
}