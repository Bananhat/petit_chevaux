int search_player(joueur liste_joueur[4], char couleur) {
  for(int i = 0; i < 4; i++) {
    if (liste_joueur[i].couleur == couleur) {
      return i;
    }
  }
  return 0;
}

char search_number(joueur liste_joueur[4], int player, int pos_x, int pos_y) {
  for(int i = 0; i < 4; i++) {
    if (liste_joueur[player].liste_chevaux[i].case_x == pos_x && liste_joueur[player].liste_chevaux[i].case_y == pos_y) {
      return liste_joueur[player].liste_chevaux[i].nom;
    }
  }
  return 0;
}
