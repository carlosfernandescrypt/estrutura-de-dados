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

Artista lerArtista(FILE *arquivo);
void inserirArtista(Artista artistas[], int *numArtistas, Artista novoArtista);
void removerArtista(Artista artistas[], int *numArtistas, char nome[]);
void editarArtista(Artista artistas[], int *numArtistas, char nome[]);
int buscarArtistaSequencial(Artista artistas[], int numArtistas, char nome[]);
int buscarArtistaBinario(Artista artistas[], int numArtistas, char nome[]);
void exibirArtista(Artista artista);
