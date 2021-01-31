//
//  calculatrice.c
//  Projet3
//
//  Created by Saïd H on 15/04/2020.
//

#include "calculatrice.h"
#include <gtk/gtk.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

extern GtkWidget *pointeurEntree1; //Pointeur de la première entrée de Nombre 1
extern GtkWidget *pointeurEntree2; //Pointeur de la seconde entrée de Nombre 2
extern GtkWidget *pointeurLabel3; //Pointeur du Troisème label "Qui donnera la réponse"


GtkWidget *creer_fenetre(const char *nom){
    assert(nom != NULL);
    
    GtkWidget *pointeurFenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        
    //Nom de la fenêtre
    gtk_window_set_title(GTK_WINDOW(pointeurFenetre), nom);
    
    //Taille de la fenêtre
    gtk_window_set_default_size(GTK_WINDOW(pointeurFenetre), 100, 200);

    //Action de fermeture de la fenêtre
    g_signal_connect(G_OBJECT(pointeurFenetre), //La source du signal
                     "destroy", //Doit-on écrire en anglais ?
                     G_CALLBACK(gtk_main_quit), //La fonction qu'on appelle
                     NULL); //Données supplémentaires
    
    return pointeurFenetre;
}

/*le pragma permet de rendre silencieux le warning "-Wunused-parameter" pour la procédure : void detruire_popup(GtkWidget *popup, gpointer donnees)
 *son utilisation est déconseillée, mais utile
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void detruire_popup(GtkWidget *popup, gpointer donnees){
    
    //Afin de faire taire le warning
    //popup = popup;
    
    gtk_grab_remove(GTK_WIDGET(donnees)); //Enlève ce qu'il y'a dans le popup
    
    gtk_widget_destroy(GTK_WIDGET(donnees)); //Detruit le popup
}
#pragma GCC diagnostic pop

void erreur_popup(const char *nomErreur, const char *DialogueErr){
    assert(nomErreur != NULL && DialogueErr != NULL);
    
    GtkWidget *pBtn;
    GtkWidget *pErreur;
    GtkWidget *pLabelErr;
    
    /* -- Fenêtre popup -- */
    
    pErreur = gtk_dialog_new(); //Crée le popup
    
    //Action de fermeture de la fenêtre
    gtk_signal_connect(GTK_OBJECT(pErreur),
                       "destroy",
                       GTK_SIGNAL_FUNC(gtk_widget_destroyed), //MACRO equivalent à gtk_object_destroy()
                       &pErreur);
    
    gtk_window_set_title(GTK_WINDOW(pErreur), nomErreur); //Donne un titre au popup
    
    
    //Insertion de l'erreur dans un label
    pLabelErr = gtk_label_new(DialogueErr);
    
    //Met le label dans le popup
    gtk_box_pack_start(GTK_BOX (GTK_DIALOG (pErreur)->vbox),
                       pLabelErr,
                       TRUE,
                       TRUE,
                       0);
    
    gtk_widget_show(pLabelErr); //Affiche le label

    /* -- Bouton OK -- */
    
    pBtn = gtk_button_new_with_label("OK"); // Création du Bouton OK
    
    //Utilité du bouton OK
    g_signal_connect(G_OBJECT(pBtn),
                     "clicked",
                     GTK_SIGNAL_FUNC(detruire_popup),
                     pErreur);
    
    //Met le bouton dans le popup
    gtk_box_pack_start(GTK_BOX (GTK_DIALOG (pErreur)->action_area),
                       pBtn,
                       TRUE,
                       TRUE,
                       0);
    
    
    //Affichage
    gtk_widget_grab_default(pBtn);
    gtk_widget_show(pBtn);
    gtk_widget_show(pErreur);
    gtk_grab_add(pErreur);
    
}

double verification_entier(const char *Nombre){
    assert(Nombre != NULL);
    
    unsigned double x = 0;
    
    if(Nombre[0] == '-'){
        x++;
    }
    
    for(; x < strlen(Nombre); x++){
        if(!isdigit(Nombre[x])){
            return -1;
        }
    }
    
    return 0;
}

void resultat_addition(GtkWidget *pointeurLabel3, double Nombre1, double Nombre2){
    assert(pointeurLabel3 != NULL);
    
    char reponse[100];
    sprintf(reponse, "La somme vaut : %d", Nombre1 + Nombre2);
    gtk_label_set_text(GTK_LABEL(pointeurLabel3), reponse);
}

void resultat_soustraction(GtkWidget *pointeurLabel3, double Nombre1, double Nombre2){
    assert(pointeurLabel3 != NULL);
    
    char reponse[100];
    sprintf(reponse, "La somme vaut : %d", Nombre1 - Nombre2);
    gtk_label_set_text(GTK_LABEL(pointeurLabel3), reponse);
}

void resultat_multiplication(GtkWidget *pointeurLabel3, double Nombre1, double Nombre2){
    assert(pointeurLabel3 != NULL);
    
    char reponse[100];
    sprintf(reponse, "La somme vaut : %d", Nombre1 * Nombre2);
    gtk_label_set_text(GTK_LABEL(pointeurLabel3), reponse);
}

void resultat_division(GtkWidget *pointeurLabel3, double Nombre1, double Nombre2){
    assert(pointeurLabel3 != NULL);
    
    char reponse[100];
    sprintf(reponse, "La somme vaut : %d", Nombre1 / Nombre2);
    gtk_label_set_text(GTK_LABEL(pointeurLabel3), reponse);
}

void verification_champs(string operationDemandee){
    
    const char *Nombre1 = gtk_entry_get_text(GTK_ENTRY(pointeurEntree1));
    const char *Nombre2 = gtk_entry_get_text(GTK_ENTRY(pointeurEntree2));
    
    if(Nombre1[0] == '\0' || Nombre2[0] == '\0'){
        //printf("Un des 2 champs est vide\n");
        erreur_popup("ERREUR", "Un des deux champs est vide !");
    }

    //Variables qui prendront la valeur de verication entier
    int testNombre1 = verification_entier(Nombre1);
    int testNombre2 = verification_entier(Nombre2);
        
    if(testNombre1 == -1 && testNombre2 == -1){
        erreur_popup("ERREUR", "Les deux champs possèdent autre chose qu'un nombre !");
    }
    else if(testNombre1 == -1 && testNombre2 == 0){
        erreur_popup("ERREUR", "Le champ Nombre 1 possède autre chose qu'un nombre !");
    }
    else if(testNombre1 == 0 && testNombre2 == -1){
        erreur_popup("ERREUR", "Le champ Nombre 2 possède autre chose qu'un nombre!");
    }
    else{
        //Conversion de la chaine de caractère en int
        int nombre1Convert = atoi(Nombre1);
        int nombre2Convert = atoi(Nombre2);
        
        switch(operationDemandee) {
                case "Addition": resultat_addition(pointeurLabel3, nombre1Convert, nombre2Convert);
                case "Soustraction": resultat_soustraction(pointeurLabel3, nombre1Convert, nombre2Convert);
                case "Multiplication": resultat_multiplication(pointeurLabel3, nombre1Convert, nombre2Convert);
                case "Division": resultat_soustraction(pointeurLabel3, nombre1Convert, nombre2Convert);
        }
    }
}

GtkWidget *bouton_addition(void){
    
    GtkWidget *pointeurBouton = gtk_button_new_with_label("Additionner");
    
    g_signal_connect(G_OBJECT(pointeurBouton), //La source du signal
                     "clicked", // ???
                     G_CALLBACK(verification_champs("Addition")), //La fonction qu'on appelle
                     NULL);
    
    return pointeurBouton;
}

GtkWidget *bouton_soustraction(void){
    
    GtkWidget *pointeurBouton = gtk_button_new_with_label("Soustraire");
    
    g_signal_connect(G_OBJECT(pointeurBouton), //La source du signal
                     "clicked", // ???
                     G_CALLBACK(verification_champs("Soustraction")), //La fonction qu'on appelle
                     NULL);
    
    return pointeurBouton;
}

GtkWidget *bouton_multiplication(void){
    
    GtkWidget *pointeurBouton = gtk_button_new_with_label("Multiplier");
    
    g_signal_connect(G_OBJECT(pointeurBouton), //La source du signal
                     "clicked", // ???
                     G_CALLBACK(verification_champs("Multiplication")), //La fonction qu'on appelle
                     NULL);
    
    return pointeurBouton;
}

GtkWidget *bouton_division(void){
    
    GtkWidget *pointeurBouton = gtk_button_new_with_label("Diviser");
    
    g_signal_connect(G_OBJECT(pointeurBouton), //La source du signal
                     "clicked", // ???
                     G_CALLBACK(verification_champs("Division")), //La fonction qu'on appelle
                     NULL);
    
    return pointeurBouton;
}
