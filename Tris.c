#include <stdio.h>
#include <stdlib.h>

//TP1
    // Fonction de copie
    void copie(int *tab1, int *tab2) {
    int i = 0;
    for (i = 0 ; i < 10 ; i++)
        tab2[i] = tab1[i] ;
    }

    // Affiche les tableaux
    void affiche(int tab[], int j){
    int i ;
    for (i = 0 ; i < 10 ; i++){
        printf("%d ", tab[i]) ;
    }
    printf("\n") ;

    // Si l'argument = 10, affichage de la fin du tri
    if (j == 10){
        puts("--Fin du tri--\n") ;
        printf("Affichage du tableau apres tri : ",138) ;
        affiche(tab,0) ;
    }
}

    // Trouve la valeur minimum et parse le tableau et retourne 'min'
    int valmin(int tab[], int index){
    int i ;
    int min = tab[index] ;
    for (i = index ; i < 10 ; i++){
        if (min >= tab[i]){
            min = tab[i] ;
        }
    }
    return min ;
}

    // Trouve l'index du minimum et parse le tableau et retourne 'indexMin'
    int indexmin(int tab[], int index){
    int i ;
    int min = tab[index] ;
    int indexMin ;
    for (i = index ; i < 10 ; i++){
        if (min >= tab[i]){
            min = tab[i] ;
            indexMin = i ;
        }
    }
    return indexMin ;
}

    // Tri par séléction
    // Parse le tableau, index par index pour trouver à l'aide de la fonction 'indexMin' la valeur minimal dans le tableau
    void selects(int *tab){
    int i ;
    int j = 0 ;
    int valeurMin ;
    int indexMin ;
    for (i = 0 ; i < 10 ; i++){
        j++ ;
        indexMin = indexmin(tab,i) ;
        valeurMin = tab[indexMin] ;
        tab[indexMin] = tab[i] ;
        tab[i] = valeurMin ;
        affiche(tab, j) ;
    }

}

    // Tri à bulles
    // Pour une première boucle qui s'arrête sur la valeur de la taille du tableau puis, dans la seconde allant jusqu'à la taille du tableau -1, vérifie si la valeur de l'index est supérieur à l'index suivant
    void bulle(int *tab) {
    int i,j ;
    int h = 0 ;
    int tri = 0 ;
    for (i = 0 ; i < 10 ; i++){
        h++ ;
        for (j = 0 ; j < 10-1 ; j++) {
            if(tab[j] > tab[j+1]) {
                tri = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = tri;
            }
        }
        affiche(tab,h) ;
    }
}

//TP2
    //Tri par insertion
    // Fonction swap pour insertion
    void swap(int tab[],int i) {
    int valeur ;
    if (tab[i] < tab[i-1]) {
        if(i != 0){
            valeur = tab[i] ;
            tab[i] = tab[i-1] ;
            tab[i-1] = valeur ;
            swap(tab,i-1) ;
        }
    }
}

    // Recherche à l'aide de la fonction swap, si la valeur de i-1 et supérieur à i, si oui alors la valeur de i-1 est échanger avec i
    void insertion(int tab[]){
    int i ;
    int j = 0 ;
    for (i = 0 ; i < 10 ; i++) {
        swap(tab,i) ;
        j++ ;
        affiche(tab,j) ;
    }
}

    // Recherche séquentielle
    // Parcours le tableau de 1 en 1 pour la recherche
    void sequentielle(int *tab, int val) {

    printf("Recherche sequentielle\n", 130) ;
    printf("La valeur a rechercher est %d\n", 133, val);

    int i ;
    int index ;
    for (i = 0 ; i < 10 ; i++){
        if(tab[i] == val){index = i ; break ;}
    }
    if(tab[index] == val){
        printf("La valeur %d est positionnee apres le tri a l'index %d.\n\n", val, 130, 138, 133, index) ;
    }
    else {
        printf("La valeur %d n'est pas dans la liste.\n\n", val);
    }
}

    // Recherche dichotomique
    // Boucle tant que la variable "trouve" est fausse, boucle en divisant le total du tableau par 2, pour ensuite vérifier si la valeur à rechercher est égal au pivot, si oui alors trouve prend 1 et
    // s'arrêtera à la prochaine boucle. Continue pour vérifier si la valeur à rechercher est supérieur au pivot, si oui alors la variables "fin" prend la valeur du pivot, sinon c'est le début qui prend la valeur du pivot.
    void dichotomique(int *tab,int val,int debut,int fin){
    int trouve = 0 ;
    int ipiv ;

    printf("Recherche dichotomique\n") ;
    printf("La valeur a rechercher est %d\n", 133, val);

    while(!trouve && ((fin - debut) > 1)) {
        ipiv = (debut+fin)/2 ;
        trouve = (tab[ipiv] == val) ;

        if(tab[ipiv] > val){ fin = ipiv ; }
        else { debut = ipiv ; }
    }
    if(tab[ipiv] == val) {
        printf("La valeur %d est positionnee apres le tri a l'index %d.\n", val, 130, 138, 133, ipiv) ;
    }
    else {
        printf("La valeur %d n'est pas dans la liste.\n", val) ;
    }
}

   //Tri rapide (QuickSort)
   //Fonction Pivot
   int replace( int tab[], int debut, int fin) {
   int pivot, gauche, droite, swap ;
   pivot = tab[debut] ;
   gauche = debut; droite = fin+1 ;

   //Parcours du tableau de gauche à droite puis droite à gauche, permutation des éléments
   while(1){
    affiche(tab, 0) ;
    do ++gauche; while( tab[gauche] <= pivot && gauche <= fin ) ;
    do --droite; while( tab[droite] > pivot ) ;
    if( gauche >= droite ) break ;
    swap = tab[gauche] ;
    tab[gauche] = tab[droite] ;
    tab[droite] = swap ;
    }
    swap = tab[debut] ;
    tab[debut] = tab[droite] ;
    tab[droite] = swap ;
    return droite ;
    }

    //Fonction 'quickSort'
    void quickSort( int tab[], int debut, int fin){
    int i ;
    if(debut < fin){
       i = replace( tab, debut, fin) ;
       quickSort( tab, debut, i-1) ;
       quickSort( tab, i+1, fin) ;
   }
}

//Déclaration des variables et printf
    int main()
    {

    int tab1[10]={37,10,8,29,97,4,11,76,55,34} ;
    int tab2[10] ;
    int tab3[10] ;
    int tab4[10] ;
    int tab5[10] ;
    int val1 = 8, val2 = 34 ;

    copie(tab1,tab2) ;
    copie(tab1,tab3) ;
    copie(tab1,tab4) ;
    copie(tab1,tab5) ;

    printf("\n(!) Exercices sur le tri par selection, tri a bulles, tri par insertion, algorithme de recherche dans un tableau, le tri rapide et le palindrome ! (!)") ;
    printf("\n\nAffichage du tableau : ") ;
    affiche(tab1,0) ;
    printf("Fonction min : %d\n", valmin(tab1,1)) ;
    printf("Fonction indicemin : %d\n", indexmin(tab1,1)) ;
    printf("\n--Debut du tri selection--\n",130,130) ;
    affiche(tab1,0) ;
    selects(tab1) ;

    printf("\nAffichage du tableau : ") ;
    affiche(tab2,0) ;
    printf("\n--Debut du tri a bulles ASC--\n",130,133) ;
    affiche(tab2,0) ;
    bulle(tab2) ;

    printf("\nAffichage du tableau : ") ;
    affiche(tab3,0) ;
    printf("\n--Debut du tri par insertion--\n",130) ;
    insertion(tab3) ;
    puts("") ;

    sequentielle(tab1, val1) ;
    dichotomique(tab2, val2, 0, 10) ;

    printf("\nAffichage du tableau : ") ;
    affiche(tab4,0) ;
    printf("\n--Debut du tri rapide--\n",130) ;
    quickSort(tab4, 0, 9) ;
    affiche(tab4,10) ;
    printf("\n(!) Fin des exercices (!)\n\n") ;

    return 0 ;
    }
