#include <stdio.h>

// Fonction pour afficher un tableau
void afficherTableau(int arr[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. Tri à bulles (Bubble Sort)
// Complexité : O(n^2)
void triABulles(int arr[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 2. Tri par sélection (Selection Sort)
// Complexité : O(n^2)
void triParSelection(int arr[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < taille; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// 3. Tri à fusion (Merge Sort)
// Complexité : O(n log n)
void fusionner(int arr[], int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;
    int G[n1], D[n2];
    
    for (int i = 0; i < n1; i++) {
        G[i] = arr[gauche + i];
    }
    for (int j = 0; j < n2; j++) {
        D[j] = arr[milieu + 1 + j];
    }

    int i = 0, j = 0, k = gauche;
    while (i < n1 && j < n2) {
        if (G[i] <= D[j]) {
            arr[k] = G[i];
            i++;
        } else {
            arr[k] = D[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = G[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = D[j];
        j++;
        k++;
    }
}

void triAFusion(int arr[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;
        triAFusion(arr, gauche, milieu);
        triAFusion(arr, milieu + 1, droite);
        fusionner(arr, gauche, milieu, droite);
    }
}

// 4. Tri rapide (Quick Sort)
// Complexité : O(n log n) dans le meilleur et moyen cas, O(n^2) dans le pire cas
int partition(int arr[], int bas, int haut) {
    int pivot = arr[haut];
    int i = (bas - 1);
    for (int j = bas; j <= haut - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[haut];
    arr[haut] = temp;
    return (i + 1);
}

void triRapide(int arr[], int bas, int haut) {
    if (bas < haut) {
        int pi = partition(arr, bas, haut);
        triRapide(arr, bas, pi - 1);
        triRapide(arr, pi + 1, haut);
    }
}

int main() {
    int arr[] = {66, 33, 11, 22, 44};
    int taille = sizeof(arr) / sizeof(arr[0]);

    printf("Tableau original :\n");
    afficherTableau(arr, taille);

    // Tri à bulles
    int arr1[] = {66, 33, 11, 22, 44};
    triABulles(arr1, taille);
    printf("\nTableau trié avec tri à bulles :\n");
    afficherTableau(arr1, taille);

    // Tri par sélection
    int arr2[] = {66, 33, 11, 22, 44};
    triParSelection(arr2, taille);
    printf("\nTableau trié avec tri par sélection :\n");
    afficherTableau(arr2, taille);

    // Tri à fusion
    int arr3[] = {66, 33, 11, 22, 44};
    triAFusion(arr3, 0, taille - 1);
    printf("\nTableau trié avec tri à fusion :\n");
    afficherTableau(arr3, taille);

    // Tri rapide
    int arr4[] = {66, 33, 11, 22, 44};
    triRapide(arr4, 0, taille - 1);
    printf("\nTableau trié avec tri rapide :\n");
    afficherTableau(arr4, taille);

    return 0;
}
