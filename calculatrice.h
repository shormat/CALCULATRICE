//
//  calculatrice.h
//  Projet3
//
//  Created by Saïd H on 15/04/2020.
//

#ifndef __CALCULATRICE__
#define __CALCULATRICE__

#include <stdio.h>
#include <gtk/gtk.h>


/**
 @fn GtkWidget *creer_fenetre(const char *nom);
 
 @brief Crée une fenêtre
 
 @param nom le nom de la fenêtre
 
 @pre nom != NULL
 
 @post retourne un pointeur sur GtkWidget
 
 */
GtkWidget *creer_fenetre(const char *nom);

/**
 @fn void detruire_popup(GtkWidget *popup, gpointer donnees);
 
 @brief Détruit le popup d'erreur
 
 @param popup pointeur sur GtkWidget la fenêtre
 @param donnees données supplémentaires
 
 @pre popup != NULL
 
 @post Détruit la page d'erreur
 
 */
void detruire_popup(GtkWidget *popup, gpointer donnees);

/**
 @fn void erreur_popup(const char *nomErreur, const char *DialogueErr);
 
 @brief fait apparaitre un popup déterminant l'erreur
 
 @param nomErreur le nom de l'erreur
 @param DialogueErr le dialogue de l'erreur
 
 @pre nomErreur != NULL && DialogueErr != NULL
 
 @post produit une page d'erreur
 
 */
void erreur_popup(const char *nomErreur, const char *DialogueErr);

/**
 @fn int verification_entier(const char *Nombre);
 
 @brief vérifie la chaine de caractère si elle possède autre chose que des valeurs entières
 
 @param Nombre chaine de caractère contenant (ou non) des valeurs entières
 
 @pre Nombre != NULL
 
 @post Verifie si la chaine est composée d'entier ou non
 
 @return -1 si la chaine de caractère possède autre chose que des valeurs entières\n
        0 si la chaine de caractères contient uniquement des valeurs entières
 */
double verification_entier(const char *Nombre);

/**
 @fn void resultat_addition(GtkWidget *pointeurLabel3, double Nombre1, double Nombre2);
 
 @brief affiche le résultat de l'addition
 
 @param pointeurLabel3 pointeur sur GtkWidget qui est le label qui affichera le resultat
 @param Nombre1 le premier opérande
 @param Nombre2 le second opérande
 
 @pre pointeurLabel3 != NULL
 @post affiche le résultat de l'addition de Nombre1 et Nombre 2 sous forme de label
 */
void resultat_addition(GtkWidget *pointeurLabel3, double Nombre1, double Nombre2);

/**
 @fn void verification_champs(string operationDemandee);

 @brief vérifie les champs des EntryBox
 
 @pre /
 
 @post /
 */
void verification_champs(string operationDemandee);

/**
 @fn GtkWidget *bouton_addition(void);
 
 @brief affiche le bouton d'addition
 
 @pre /
 
 @post retourne pointeurBouton qui est un pointeur sur GtkWidget
 */
GtkWidget *bouton_addition(void);

/**
 @fn GtkWidget *bouton_soustraction(void);
 
 @brief affiche le bouton de soustraction
 
 @pre /
 
 @post retourne pointeurBouton qui est un pointeur sur GtkWidget
 */
GtkWidget *bouton_soustraction(void);

/**
 @fn GtkWidget *bouton_multiplication(void);
 
 @brief affiche le bouton de multiplication
 
 @pre /
 
 @post retourne pointeurBouton qui est un pointeur sur GtkWidget
 */
GtkWidget *bouton_multiplication(void);

/**
 @fn GtkWidget *bouton_division(void);
 
 @brief affiche le bouton de division
 
 @pre /
 
 @post retourne pointeurBouton qui est un pointeur sur GtkWidget
 */
GtkWidget *bouton_division(void);

#endif //__CALCULATRICE__
