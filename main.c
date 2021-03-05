#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10

/*Contient les toutes les informations utiles pour un joueur.*/
/*coordsBateau[x][0] est la ligne [x][1] est la colonne*/
typedef struct statusBateaux{
  /*Porte Avion*/
  char porteAvion[5];
  char coordsPorteAvion[5][2];
  int statusPorteAvion;
  /*Croiseur*/
  char croiseur[4];
  char coordsCroiseur[4][2];
  int statusCroiseur;
  /*Contre Torpilleur*/
  char contreTorp1[3];
  char coordsContreTorp1[3][2];
  int statusContreTorp1;
  /*Contre Torpilleur*/
  char contreTorp2[3];
  char coordsContreTorp2[3][2];
  int statusContreTorp2;
  /*Torpilleur*/
  char torp[2];
  char coordsTorp[2][2];
  int statusTorp;
}statusBateaux;

/*
  case vide : ' '
  case pleine : 'o'
  case visee : '.'
  case touchee : '?'
  case coulee : '!'
*/

/*Affiche le terrain de l'ordinateur pendant la partie (ne révèle pas la position des cases non touchées)*/
void affTerrainPartie(char terrain[TAILLE][TAILLE]){
  int i = 0, j = 0;
  printf("   | A | B | C | D | E | F | G | H | I | J |\n");
  printf("---+---+---+---+---+---+---+---+---+---+---+\n %d ", i+1);
  for(i = 0; i < TAILLE; i++){
    for(j = 0; j < TAILLE; j++){
      if(terrain[i][j] != 'o'){
        printf("| %c ", terrain[i][j]);
      }else{
        printf("|   ");
      }
    }
    printf("|\n---+---+---+---+---+---+---+---+---+---+---+\n");
    if(i < 8){
      printf(" %d ", i+2);
    }else{
      if(i < 9) printf("10 ");
    }
  }
  printf("\n\n");
}

/*Affiche le terrain du joueur donne*/
void affTerrainJoueur(char terrain[TAILLE][TAILLE]){
  int i = 0, j = 0;
  printf("   | A | B | C | D | E | F | G | H | I | J |\n");
  printf("---+---+---+---+---+---+---+---+---+---+---+\n %d ", i+1);
  for(i = 0; i < TAILLE; i++){
    for(j = 0; j < TAILLE; j++){
      printf("| %c ", terrain[i][j]);
    }
    printf("|\n---+---+---+---+---+---+---+---+---+---+---+\n");
    if(i < 8){
      printf(" %d ", i+2);
    }else{
      if(i < 9) printf("10 ");
    }
  }
  printf("\n\n");
}

/*Affiche les resultats de la partie*/
void affResultats(statusBateaux bateauxJ, statusBateaux bateauxO, char platJ[TAILLE][TAILLE], char platO[TAILLE][TAILLE]){
  int j1Perdant = 1;
  for(int i = 0; i < 5; i++){
    switch(i){
      case 0:
        if(bateauxJ.statusPorteAvion) j1Perdant = 0;
        break;
      case 1:
        if(bateauxJ.statusCroiseur) j1Perdant = 0;
        break;
      case 2:
        if(bateauxJ.statusContreTorp1) j1Perdant = 0;
        break;
      case 3:
        if(bateauxJ.statusContreTorp2) j1Perdant = 0;
        break;
      case 4:
        if(bateauxJ.statusTorp) j1Perdant = 0;
        break;
    }
  }
  if(j1Perdant){
    printf("Le joueur a perdu. La victoire revient a l'ordinateur.\n");
  }else{
    printf("L'ordinateur a perdu. La victoire revient au joueur.\n");
  }
  printf("Votre plateau : \n\n");
  affTerrainJoueur(platJ);
  printf("Plateau de l'ordinateur :\n\n");
  affTerrainJoueur(platO);
  system("PAUSE");
}

/*Unsure*/
void affStatusBateaux(statusBateaux bateaux){
  int taillesBateaux[5] = {5,4,3,3,2};
  for(int j = 0; j < 5;j++){
    for(int i = 0; i <taillesBateaux[j];i++){
      switch (j) {
        case 0:
          printf("%c", bateaux.porteAvion[i]);
          break;
        case 1:
          printf("%c", bateaux.croiseur[i]);
          break;
        case 2:
          printf("%c", bateaux.contreTorp1[i]);
          break;
        case 3:
          printf("%c", bateaux.contreTorp2[i]);
          break;
        case 4:
          printf("%c", bateaux.torp[i]);
          break;
      }
    }
    switch (j) {
      case 0:
        printf(" %d\n",bateaux.statusPorteAvion);
        break;
      case 1:
        printf(" %d\n",bateaux.statusCroiseur);
        break;
      case 2:
        printf(" %d\n",bateaux.statusContreTorp1);
        break;
      case 3:
        printf(" %d\n",bateaux.statusContreTorp2);
        break;
      case 4:
        printf(" %d\n",bateaux.statusTorp);
        break;
    }
  }
}

/*Affiche les coordonnees des bateaux du joueur founi*/
void affCoordsBateaux(statusBateaux bateaux, int nbBateaux){
  int taillesBateaux[5] = {5,4,3,3,2};
  char * nomsBateaux[5]={"Porte-avions","Croiseur","Contre-torpilleur","Contre-torpilleur","Torpilleur"};
  for(int j = 0; j < nbBateaux+1;j++){
    printf("%s\n", nomsBateaux[j]);
    for(int i = 0; i <taillesBateaux[j];i++){
      switch (j) {
        case 0:
          printf("%c%d\n", 'A'+bateaux.coordsPorteAvion[i][1],1+bateaux.coordsPorteAvion[i][0]);
          break;
        case 1:
          printf("%c%d\n", 'A'+bateaux.coordsCroiseur[i][1],1+bateaux.coordsCroiseur[i][0]);
          break;
        case 2:
          printf("%c%d\n", 'A'+bateaux.coordsContreTorp1[i][1],1+bateaux.coordsContreTorp1[i][0]);
          break;
        case 3:
          printf("%c%d\n", 'A'+bateaux.coordsContreTorp2[i][1],1+bateaux.coordsContreTorp2[i][0]);
          break;
        case 4:
          printf("%c%d\n", 'A'+bateaux.coordsTorp[i][1],1+bateaux.coordsTorp[i][0]);
          break;
      }
    }
    printf("\n");
  }
}

/*Remplis le plateau par des cases vides*/
void initTerrain(char plat[TAILLE][TAILLE]){
  for(int i = 0; i < TAILLE;i++){
     for(int j = 0; j < TAILLE;j++){
       plat[i][j] = ' ';
     }
  }
}

/*Place le bateau aux coordonnees voulues et remplit les structures*/
int placerBateau(char plat[TAILLE][TAILLE], int bateau, char orientation, int ligne, int colonne, statusBateaux * coords){
  /*system("Clear");*/
  int taillesBateaux[5] = {5,4,3,3,2};
  int t;
  switch (orientation) {
    case 'h':
      for(t = colonne ; t < taillesBateaux[bateau] + colonne; t++){
        plat[ligne][t] = 'o';
        switch (bateau) {
          case 0:
            coords->coordsPorteAvion[t - colonne][0] = ligne;
            coords->coordsPorteAvion[t - colonne][1] = t;
            break;
          case 1:
            coords->coordsCroiseur[t - colonne][0] = ligne;
            coords->coordsCroiseur[t - colonne][1] = t;
            break;
          case 2:
            coords->coordsContreTorp1[t - colonne][0] = ligne;
            coords->coordsContreTorp1[t - colonne][1] = t;
            break;
          case 3:
            coords->coordsContreTorp2[t - colonne][0] = ligne;
            coords->coordsContreTorp2[t - colonne][1] = t;
            break;
          case 4:
            coords->coordsTorp[t - colonne][0] = ligne;
            coords->coordsTorp[t - colonne][1] = t;
            break;
        }
      }
      break;
    case 'v':
      for(t = ligne ; t < taillesBateaux[bateau] + ligne ; t++){
        plat[t][colonne] = 'o';
        switch (bateau) {
          case 0:
            coords->coordsPorteAvion[t - ligne][0] = t;
            coords->coordsPorteAvion[t - ligne][1] = colonne;
            break;
          case 1:
            coords->coordsCroiseur[t - ligne][0] = t;
            coords->coordsCroiseur[t - ligne][1] = colonne;
            break;
          case 2:
            coords->coordsContreTorp1[t - ligne][0] = t;
            coords->coordsContreTorp1[t - ligne][1] = colonne;
            break;
          case 3:
            coords->coordsContreTorp2[t - ligne][0] = t;
            coords->coordsContreTorp2[t - ligne][1] = colonne;
            break;
          case 4:
            coords->coordsTorp[t - ligne][0] = t;
            coords->coordsTorp[t - ligne][1] = colonne;
            break;
        }
      }
      break;
    default:
      printf("Une erreur est survenue, arret du programme.");
      system("PAUSE");
      return 0;
      break;
  }
  /*affTerrainJoueur(plat);
  affCoordsBateaux(*coords, bateau);*/
  return 1;
}

/*Verifie que le bateau peut etre place a cet endroit*/
int caseValide(char plat[TAILLE][TAILLE], int bateau, char orientation, int ligne, int colonne){
  int caseValide = 0;
  int taillesBateaux[5] = {5,4,3,3,2};
  int t = 0;
  switch (orientation) {
    case 'h':
      if(colonne + taillesBateaux[bateau] <= 10){
        for(t = colonne-1 ; t < taillesBateaux[bateau] + colonne; t++){
          if(plat[ligne][t] != ' '){
            return 0;
          }
        }
        caseValide = 1;
      }
      break;
    case 'v':
      if(ligne + taillesBateaux[bateau] <= 10){
        for(t = ligne-1 ; t < taillesBateaux[bateau] + ligne; t++){
          if(plat[t][colonne] != ' '){
            return 0;
          }
        }
        caseValide = 1;
      }
      break;
    default:
      printf("Une erreur est survenue, arret du programme.");
      system("PAUSE");
      return 0;
      break;
  }
  return caseValide;
}

/*Remplissage aleatoire des coordonnees des bateaux*/
int saisieBateauRandom(char plat[TAILLE][TAILLE], statusBateaux * coords){
  /*system("Clear");*/
  int nbBateaux = 5;
  for(int i = 0; i < nbBateaux; i++){
    int piece = rand()%2;
    char orientation = 'h';
    if(piece) orientation = 'v';
    int ligne = rand()%10 + 1;
    int colonne = rand()%10 + 1;
    while(!caseValide(plat, i, orientation, ligne, colonne)){
      ligne = rand()%10 + 1;
      colonne = rand()%10 + 1;
    }
    ligne--;
    colonne--;
    placerBateau(plat, i, orientation, ligne, colonne,coords);
  }
}

/*Saisie des coordonnees des bateaux du joueur*/
int saisieBateauxJoueur(char plat[TAILLE][TAILLE], statusBateaux * coords){
  /*system("Clear");*/
  printf("La coordonnee saisie pour chaque bateau correspond a sa partie la plus haute a gauche.\n\n");
  /*DECLARATIONS DE VARIABLES*/
  char * bateaux[5][2]={"Porte-avions","5","Croiseur","4","premier Contre-torpilleur","3","second Contre-torpilleur","3","Torpilleur","2"};
  int ligne = -1;
  int colonneInt = 0;
  char colonne = 'Z';
  char orientation = 'Z';
  for(int i = 0; i < 5; i++){
    /*system("Clear");*/
    affTerrainJoueur(plat);
    /*ORIENTATION DU BATEAU*/
    printf("Choisissez si votre %s (%s cases) doit etre oriente verticalement (V) ou horizontalement (H) : ", bateaux[i][0], bateaux[i][1]);
    scanf("%c", &orientation);
    getchar();
    while(orientation != 'V' && orientation != 'H' && orientation != 'v' && orientation != 'h'){
      printf("Orientation incorrecte, elle doit etre V ou H : ");
      scanf("%c", &orientation);
      getchar();
    }
    if(orientation == 'H' || orientation == 'V'){
      orientation -= ('A' - 'a');
    }
    /*POSITION DU BATEAU*/
    printf("Saisissez les coordonnees (ex: B7) ou vous souhaitez placer votre %s (%s cases)", bateaux[i][0], bateaux[i][1]);
    printf("\nCoordonnees : ");
    scanf("%c%d", &colonne, &ligne);
    getchar();
    /*uniformisation des donnees*/
    if(colonne >= 'A' && colonne <= 'A' + TAILLE){
        colonneInt = colonne - 'A';
      }else{
        colonneInt = colonne - 'a';
      }
    ligne--;
    while((ligne < 0 || ligne > 9) || (colonneInt < 0 && colonneInt > 9)){
      printf("Saisie incorrecte, la case doit etre dans le plateau.\nCoordonnees : ");
      scanf("%c%d", &colonne, &ligne);
      getchar();
      /*uniformisation des donnees*/
      if(colonne >= 'A' && colonne <= 'A' + TAILLE){
          colonneInt = colonne - 'A';
        }else{
          colonneInt = colonne - 'a';
        }
        printf("%d",colonneInt);
      ligne--;
    }
    if(!caseValide(plat,i,orientation,ligne,colonneInt)){
      while(!caseValide(plat,i,orientation,ligne,colonneInt)){
        int caseValide = 0;
        printf("votre %s (%s cases) ", bateaux[i][0], bateaux[i][1]);
        printf("ne va pas rentrer ici, veuillez resaisir des coordonnees (ex: B7) : ");
        scanf("%c%d", &colonne, &ligne);
        getchar();
        /*uniformisation des donnees*/
        if(colonne >= 'A' && colonne <= 'J'){
          colonneInt = colonne - 'A';
        }else{
          colonneInt = colonne - 'a';
        }
        ligne--;
      }
    }
    if(!placerBateau(plat,i,orientation,ligne,colonneInt,coords)) return 0;
  }
  return 1;
}

int estFini(char plat[TAILLE][TAILLE]){
  int estFini = 1;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10 ; j++){
      if(plat[i][j] == 'o') estFini = 0;
    }
  }
  return estFini;
}

/*
  Application du tir
  met le ? ou le !
  change la structure
  change le status si besoin
*/
int touche(char plat[TAILLE][TAILLE], int ligne, int colonne, statusBateaux * coords){
  int taillesBateaux[5]={5,4,4,3,2};
  int bateau = 0;
  for(int j = 0 ; j < 5 ; j++){
    for(int i = 0 ; i <taillesBateaux[j] ; i++){
      switch (j) {
        case 0:
          if(coords->coordsPorteAvion[i][0] == ligne && coords->coordsPorteAvion[i][1] == colonne){
            bateau = 0;
            coords->porteAvion[i] = '?';
            plat[ligne][colonne] = '?';
          }
          break;
        case 1:
          if(coords->coordsCroiseur[i][0] == ligne && coords->coordsCroiseur[i][1] == colonne){
            bateau = 1;
            coords->croiseur[i] = '?';
            plat[ligne][colonne] = '?';
          }
          break;
        case 2:
          if(coords->coordsContreTorp1[i][0] == ligne && coords->coordsContreTorp1[i][1] == colonne){
            bateau = 2;
            coords->contreTorp1[i] = '?';
            plat[ligne][colonne] = '?';
          }
          break;
        case 3:
          if(coords->coordsContreTorp2[i][0] == ligne && coords->coordsContreTorp2[i][1] == colonne){
            bateau = 3;
            coords->contreTorp2[i] = '?';
            plat[ligne][colonne] = '?';
          }
          break;
        case 4:
          if(coords->coordsTorp[i][0] == ligne && coords->coordsTorp[i][1] == colonne){
            bateau = 4;
            coords->torp[i] = '?';
            plat[ligne][colonne] = '?';
          }
          break;
      }
    }
  }
  int coule = 1;
  /*passage de ? a ! si besoin*/
  for(int i = 0; i < taillesBateaux[bateau];i++){
    switch (bateau) {
      case 0:
        if(coords->porteAvion[i] == 'o') coule = 0;
      break;
      case 1:
        if(coords->croiseur[i] == 'o') coule = 0;
      break;
      case 2:
        if(coords->contreTorp1[i] == 'o') coule = 0;
      break;
      case 3:
        if(coords->contreTorp2[i] == 'o') coule = 0;
      break;
      case 4:
        if(coords->torp[i] == 'o') coule = 0;
      break;
    }
  }
  if(coule){
    printf(" Coule!");
    for(int i = 0 ; i < taillesBateaux[bateau] ; i++){
      switch (bateau) {
        case 0:
          coords->porteAvion[i] = '!';
          plat[coords->coordsPorteAvion[i][0]][coords->coordsPorteAvion[i][1]] = '!';
          coords->statusPorteAvion = 0;
        break;
        case 1:
          coords->croiseur[i] = '!';
          plat[coords->coordsCroiseur[i][0]][coords->coordsCroiseur[i][1]] = '!';
          coords->statusCroiseur = 0;
        break;
        case 2:
          coords->contreTorp1[i] = '!';
          plat[coords->coordsContreTorp1[i][0]][coords->coordsContreTorp1[i][1]] = '!';
          coords->statusContreTorp1 = 0;
        break;
        case 3:
          coords->contreTorp2[i] = '!';
          plat[coords->coordsContreTorp2[i][0]][coords->coordsContreTorp2[i][1]] = '!';
          coords->statusContreTorp2 = 0;
        break;
        case 4:
          coords->torp[i] = '!';
          plat[coords->coordsTorp[i][0]][coords->coordsTorp[i][1]] = '!';
          coords->statusTorp = 0;
        break;
      }
    }
  }
  printf("\n");
  return 1;
}

/*Verification de la case tiree*/
int tir(char plat[TAILLE][TAILLE], int ligne, int colonne, statusBateaux * coords){
  if(plat[ligne][colonne] == 'o'){
    printf("Touche");
    touche(plat, ligne, colonne, coords);
  }else{
    printf("Rate");
    plat[ligne][colonne] = '.';
  }
  printf("\n");
  return 1;
}

/*Saisie des coordonnees ou le joueur veut tirer*/
int saisieTir(char plat[TAILLE][TAILLE], statusBateaux * coords, int estOrdi){
  int colonneInt;
  char colonne;
  int ligne;
  int trouve = 0;
  switch (estOrdi) {
    case 0:
      printf("Sur quelle case souhaitez vous tirer (ex: B7) ?");
      printf("\nCoordonnees : ");
      scanf("%c%d", &colonne, &ligne);
      getchar();
      if(colonne == 'S'){
        affStatusBateaux(*coords);
      }
      /*uniformisation des donnees*/
      if(colonne >= 'A' && colonne <= 'A' + TAILLE){
          colonneInt = colonne - 'A';
        }else{
          colonneInt = colonne - 'a';
        }
      ligne--;
      while((ligne < 0 || ligne > 9) || (colonneInt < 0 && colonneInt > 9) || (plat[ligne][colonneInt] != ' ') && (plat[ligne][colonneInt] != 'o')){
        printf("Saisie incorrecte, Vous devez tirer sur une case vide du plateau.\nCoordonnees : ");
        scanf("%c%d", &colonne, &ligne);
        getchar();
        /*uniformisation des donnees*/
        if(colonne >= 'A' && colonne <= 'A' + TAILLE){
            colonneInt = colonne - 'A';
          }else{
            colonneInt = colonne - 'a';
          }
          printf("%d",colonneInt);
        ligne--;
      }
    break;
    case 1:
      for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
          if(plat[i][j]=='?'){
            /*Si il y a un point d'interrogation en dessous de la case actuelle*/
            if(i != 0){
              if(plat[i+1][j] == '?'){
                if(plat[i-1][j]== 'o' || plat[i-1][j] == ' '){
                  ligne = i-1;
                  colonneInt = j;
                  trouve = 1;
                }else{
                  ligne = i+2;
                  colonneInt = j;
                  trouve = 1;
                }
              }
            }
            /*Si il y a un point d'interrogation a droite de la case actuelle*/
            if(!trouve && i != 9){
              if(plat[i][j+1] == '?'){
                if(plat[i][j-1]== 'o' || plat[i][j-1]== ' '){
                  ligne = i;
                  colonneInt = j-1;
                  trouve = 1;
                }else{
                  ligne = i;
                  colonneInt = j+2;
                  trouve = 1;
                }
              }
            }
            /*SI IL N'Y A PAS DE LIGNE/COLONNE DE '?'*/
            if(!trouve){
              /*Haut*/
              if(!trouve && i!=0){
                if(plat[i-1][j]!= '?' && plat[i-1][j]!= '!' && plat[i-1][j]!= '.'){
                  ligne = i-1;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*Bas*/
              if(!trouve && i!=9){
                if(plat[i+1][j]!= '?' && plat[i+1][j]!= '!' && plat[i+1][j]!= '.'){
                  ligne = i+1;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*Gauche*/
              if(!trouve && j!=0){
                if(plat[i][j-1]!= '?' && plat[i][j-1]!= '!' && plat[i][j-1]!= '.'){
                  ligne = i;
                  colonneInt = j-1;
                  trouve = 1;
                }
              }
              /*Droite*/
              if(!trouve && j!=9){
                if(plat[i][j+1]!= '?' && plat[i][j+1]!= '!' && plat[i][j+1]!= '.'){
                  ligne = i;
                  colonneInt = j+1;
                  trouve = 1;
                }
              }
            }
          }
        }
      }
      /*Si il n'y a pas de '?' à tirer*/
      int nbCasesVides = 0;
      for(int i = 0 ; i < TAILLE ; i++){
        for(int j = 0; j < TAILLE ; j++){
          if(plat[i][j] == ' ' || plat[i][j] == 'o'){
            nbCasesVides++;
          }
        }
      }
      if(nbCasesVides < 70 && !trouve){
        for(int i = 0 ; i < TAILLE ; i++){
          for(int j = 0; j < TAILLE ; j++){
            if(plat[i][j] == ' ' || plat[i][j] == 'o'){
              /* premiere ligne et colonne */
              if(i < 1 && j < 1){
                if((plat[i+1][j]==' ' || plat[i+1][j] == 'o') && (plat[i][j+1]==' ' || plat[i][j+1] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*premiere ligne*/
              if(i < 1 && !trouve){
                if((plat[i+1][j]==' ' || plat[i+1][j] == 'o') && (plat[i][j+1]==' ' || plat[i][j+1] == 'o') && (plat[i][j-1]==' ' || plat[i][j-1] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*premiere colonne*/
              if( j < 1 && !trouve){
                if((plat[i+1][j]==' ' || plat[i+1][j] == 'o') && (plat[i][j+1]==' ' || plat[i][j+1] == 'o') && (plat[i-1][j]==' ' || plat[i-1][j] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*Pas dans l'une des premieres ni dernieres lignes ou colonnes*/
              if(i < 9 && j < 9 && !trouve){
                if((plat[i+1][j]==' ' || plat[i+1][j] == 'o') && (plat[i][j+1]==' ' || plat[i][j+1] == 'o') && (plat[i-1][j]==' ' || plat[i-1][j] == 'o') && (plat[i-1][j]==' ' || plat[i-1][j] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*derniere ligne et colonne*/
              if(i > 8 && j > 8 && !trouve){
                if((plat[i-1][j]==' ' || plat[i-1][j] == 'o') && (plat[i][j-1]==' ' || plat[i][j-1] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*premiere ligne*/
              if(i > 8 && !trouve){
                if((plat[i-1][j]==' ' || plat[i-1][j] == 'o') && (plat[i][j+1]==' ' || plat[i][j+1] == 'o') && (plat[i][j-1]==' ' || plat[i][j-1] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
              /*derniere colonne*/
              if( j > 8 && !trouve){
                if((plat[i+1][j]==' ' || plat[i+1][j] == 'o') && (plat[i][j-1]==' ' || plat[i][j-1] == 'o') && (plat[i-1][j]==' ' || plat[i-1][j] == 'o')){
                  ligne = i;
                  colonneInt = j;
                  trouve = 1;
                }
              }
            }
          }
        }
      }
      if(!trouve){
        ligne = rand()%10;
        colonneInt = rand()%10;
      }
      while(plat[ligne][colonneInt] != ' ' && plat[ligne][colonneInt] != 'o'){
        ligne = rand()%10;
        colonneInt = rand()%10;
      }
    break;
  }
  printf("Tir precedent : %c%d\n",'A'+colonneInt,ligne+1);
  return tir(plat,ligne,colonneInt,coords);
}

int main(){
  srand(time(NULL));
  int tour = 0;
  char platJ[TAILLE][TAILLE];
  char platO[TAILLE][TAILLE];
  int taillesBateaux[5] = {5,4,3,3,2};
  statusBateaux bateauxJ;
  statusBateaux bateauxO;
  statusBateaux * ptrBateauxJ = &bateauxJ;
  statusBateaux * ptrBateauxO = &bateauxO;
  int continuer = 1;
  /*Pour les declarations des bateaux :
    status de la case 'o' '?' ou '!'
    ligne de la case
    colonne de la case
    et enfin le status du bateau "OK" ou "KO"
  */
  while(continuer){
    printf("Debut de la partie.\n\n");
    int done = 0;
    int tour = 0;
    /*AFFECTATION DES VALEURS DES STRUCTURES DES BATEAUX*/
    {
      for(int j = 0; j < 5;j++){
        for(int i = 0; i < taillesBateaux[j] ; i++){
          switch (j) {
            case 0:
              bateauxJ.porteAvion[i] = 'o';
              bateauxO.porteAvion[i] = 'o';
              break;
            case 1:
              bateauxJ.croiseur[i] = 'o';
              bateauxO.croiseur[i] = 'o';
              break;
            case 2:
              bateauxJ.contreTorp1[i] = 'o';
              bateauxO.contreTorp1[i] = 'o';
              break;
            case 3:
              bateauxJ.contreTorp2[i] = 'o';
              bateauxO.contreTorp2[i] = 'o';
              break;
            case 4:
              bateauxJ.torp[i] = 'o';
              bateauxO.torp[i] = 'o';
              break;
          }
        }
      }
      bateauxJ.statusPorteAvion = 1;
      bateauxO.statusPorteAvion = 1;
      bateauxJ.statusCroiseur = 1;
      bateauxO.statusCroiseur = 1;
      bateauxJ.statusContreTorp1 = 1;
      bateauxO.statusContreTorp1 = 1;
      bateauxJ.statusContreTorp2 = 1;
      bateauxO.statusContreTorp2 = 1;
      bateauxJ.statusTorp = 1;
      bateauxO.statusTorp = 1;
    }
    initTerrain(platJ);
    initTerrain(platO);
    /*
    printf("Votre plateau : \n\n");
    affTerrainJoueur(platJ);
    printf("Plateau de l'ordinateur : \n\n");
    affTerrainJoueur(platO);
    system("PAUSE");
    */
    char aleat = 'N';
    printf("Souhaitez vous saisir l'emplacement de vos bateaux ou les placer aleatoirement (Y/N) : ");
    scanf("%s",&aleat);
    getchar();
    if(aleat == 'Y' || aleat == 'y'){
      saisieBateauRandom(platJ, ptrBateauxJ);
    }else{
      if(!saisieBateauxJoueur(platJ, ptrBateauxJ)) return 0;
    }
    saisieBateauRandom(platO, ptrBateauxO);
    /*Partie*/
    while(!done){
      printf("Votre plateau\n");
      affTerrainJoueur(platJ);
      printf("Plateau de l'ordinateur\n");
      affTerrainPartie(platO);
      switch (tour) {
        /*Tour du joueur*/
        case 0:
          saisieTir(platO,ptrBateauxO,0);
          done = estFini(platO);
        break;
        /*Tour de l'ordi*/
        case 1:
          saisieTir(platJ,ptrBateauxJ,1);
          done = estFini(platJ);
        break;
      }
      tour = tour==1?0:1;
    }
    /*FIN DE PARTIE*/
    affResultats(bateauxJ,bateauxO,platJ,platO);
    printf("Souhaitez-vous rejouer ? (Y/N) : ");
    scanf("%s",&aleat);
    getchar();
    if(aleat != 'Y' && aleat != 'y'){
      continuer = 0;
    }
  }
  printf("Au revoir.\n");
  system("PAUSE");
  return 1;
}
