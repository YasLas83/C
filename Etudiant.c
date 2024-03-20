#include<stdio.h>
#include<stdlib.h>
#define MAXNOTES 4
typedef struct date {
	int jour;
	int mois;
	int annee;
}date;

//lire une date
date scan_date() {
date d;
printf("date (jj/mm/aaaa): ");
scanf("%d/%d/%d", &d.jour, &d.mois, &d.annee);
return d;
}
//Imprimer une date
void print_date(date d) {
printf("%d/%d/%d\n", d.jour, d.mois, d.annee);
}


typedef struct etudiant{
	int matricule;
    char nom[65];
	char prenom [65];
    date date_naissance;
    float notes[MAXNOTES];
}etudiant;

//Lire un etudiant
etudiant scan_etudiant() {
int i;
char c;
etudiant e;
printf("Matricule: ");
scanf("%d", &e.matricule);
scanf("%c",&c);//bach mathrebch liya entrer w douz nichan l prenom 9bel mandir saisie l matricule
printf("Nom : ");
fgets(e.nom,sizeof(e.nom),stdin);// avant c'etait gets(nom) mais on l'a changé a cause du recherche par nom 
strtok(e.nom,"\n");// pour controler les espaces apres la saisie du nom 
printf("Prenom : ");
fgets(e.prenom,sizeof(e.prenom),stdin);// du mm que pour nom
strtok(e.prenom,"\n");
printf("Date de naissance:\n");
e.date_naissance = scan_date();
for (i=0; i<MAXNOTES; i++) {
printf("Note %d: ", i+1);
scanf("%f", &e.notes[i]);
}
return e;
}

//Imprimer les infos d'un etudiant
void print_etudiant(etudiant e) {
int i;
printf("Matricule : %d\n", e.matricule);
printf("Nom : %s\n", e.nom);
printf("Prenom : %s\n",e.prenom);
printf("Date de naissance: ");
print_date(e.date_naissance);
printf("notes: ");
for (i=0; i<MAXNOTES; i++) {
printf("%.2f ", e.notes[i]); }
printf("\n");
}


typedef struct registre {
etudiant* etudiants;
int nb_etudiants;
} registre;


//Ajouter un étudiant à la fin 

void addfin_etudiant(etudiant* e, registre* r) {
if (r->nb_etudiants==0) {
r->etudiants = (etudiant*) malloc(sizeof(etudiant));
r->etudiants[r->nb_etudiants] = *e;
r->nb_etudiants++;
return;// soit faire return; soit enlever return et faire un else après
}
r->etudiants = (etudiant*) realloc( r->etudiants, (r->nb_etudiants+1)*sizeof(etudiant) );
//remplir les etudiants
r->etudiants[r->nb_etudiants] = *e;
r->nb_etudiants++;
}


//Afficher tous les etudiants
void print_registre(registre* r) {
int i;
for (i=0; i<r->nb_etudiants; i++)
{ print_etudiant(r->etudiants[i]);
  printf("\n");
}
}


//moyenne
float moyenne(etudiant e) {
int i;
float S = 0.0;
for (i=0; i<MAXNOTES; i++) {
S += e.notes[i];
}
return S/MAXNOTES;
}



//etudiants admis 
void print_admis(registre *r) {
	int i; 
	for (i=0;i<r->nb_etudiants;i++) {
		if (moyenne(r->etudiants[i])>=10) {
			print_etudiant(r->etudiants[i]);
			printf("\n");
		}
	}
}

//recherche par matricule
etudiant cherch_matricule(int mat ,registre *r) {
	int i;
	for (i=0;i<r->nb_etudiants;i++) {
		if (r->etudiants[i].matricule==mat) {
			return r->etudiants[i];
		}
		printf("etudiant non trouve \n");
		return;	
	}
}


//recherche par nom
etudiant cherch_nom(char Nom[65],registre *r){
	int i;
	for (i=0;i<r->nb_etudiants;i++){
		if (strcmp(r->etudiants[i].nom,Nom)==0)  {
		return r->etudiants[i];
		//print_etudiant(cherch_nom(Nom, &r)); pour afficher tt les etudiants qui ont le nom qu'on cherche
		}
		
	
	printf("etudiant non trouve\n");
	return;}
}

//Afficher les majorants
void  print_majorants(registre *r){
	int i;
	float max ; 
	max = -1.0;

for(i=0 ; i< r->nb_etudiants ; i++){
	if (moyenne(r->etudiants[i])>max)
	{ max=moyenne(r->etudiants[i]);
	}
}
	
for(i=0 ; i< r->nb_etudiants ; i++){
	if (moyenne(r->etudiants[i])==max){
		print_etudiant(r->etudiants[i]);
	}
}

}


int main() {
int ch;
int mat;
char c;
etudiant e;
char Nom[65];
registre r ;
r.nb_etudiants=0;
do {
puts("\n");
puts("1: Ajouter un nouvel etudiant a la fin : ");
puts("2: Afficher tous les etudiants");
puts("3: Afficher les etudiants admis");
puts("4: Rechercher par matricule");
puts("5: Rechercher par nom");
puts("6: Afficher les majorants");
puts("0: Quitter");
scanf("%d",&ch);
switch (ch){
case 1:
e=scan_etudiant();
addfin_etudiant(&e, &r);
break;
case 2:
print_registre(&r);
break;
case 3:
print_admis(&r);
break;
case 4:
printf("Donner le matricule a chercher :");
scanf("%d",&mat);
e=cherch_matricule(mat,&r);
print_etudiant(e); //on peut aussi ecrire ces 2 lignes sous forme de print_etudiant(cherch_matricule(mat,&r));
break;
case 5:
printf("Donner le nom a chercher :");
fgets(Nom,sizeof(Nom),stdin);
strtok(Nom,"\n");
print_etudiant(cherch_nom(Nom, &r));
break;
case 6:
print_majorants(&r);
} 
}while (ch!=0);
return 0;
}
