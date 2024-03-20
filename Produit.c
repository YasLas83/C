#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct produit{
	int code;
	char nom[64];
	char prenom[64];
	float stock;
}produit;
 
 
 typedef struct produits{
 	produit *produits;
 	int nb_produit;
 }produits;
 
 	void ajouter_pro(produits* ps){
 			produit p;
 			char c;
 		printf("Entrez le code:\n");
 		scanf("%d",&p.code);
 		
 		printf("Entrez le nom:\n");
 			scanf("%*c");	//fflush(stdin);
 		gets(p.nom);//&p.nom deja un pointeur ()
 		
 		printf("Entrez le prenom:\n");
 			scanf("%*c");	//fflush(stdin);
 		gets(p.prenom);
 		
 		printf("Entrez le stock:\n");
 		scanf("%f",&p.stock);
 	
 	if(ps->nb_produit==0) {
	 ps->produits = (produit*)malloc (sizeof(produit));
	 
	 
	 }
	 else{
	 ps->produits=(produit*)realloc(ps->produits,(ps->nb_produit+1)*sizeof(produit));}
	 ps->produits[ps->nb_produit]=p;
	 
 	ps->nb_produit++;
 	
 	 }
 	 
	 
	void afficher_pro(produits ps){//si *ps alors ps-> {main avec &}
		int i;
		
		for(i=0;i<ps.nb_produit;i++){
			printf("Nom %s : le code %d quantite %.2f\n",ps.produits[i].nom,ps.produits[i].code,ps.produits[i].stock);
			//print_pro(ps->produits[i]);
			
		}}
	void nbr_pro(produits* ps){
		int cpt=0;
		int i;
		for(i=0;i<ps->nb_produit;i++){
			cpt++;			
		}
		printf("%d \n",cpt);
	}
	
	void som_stock(produits* ps){
		float som=0;
		int i;
		for(i=0;i<ps->nb_produit;i++){
			som = som + ps->produits[i].stock;			
		}
		printf("la somme total des stock est %.2f \n" , som );
	}
	
	void aff_max(produits* ps){
		int i;
		float max;
			max = ps->produits[0].stock;
		for(i=1;i<ps->nb_produit;i++){
			if(max<ps->produits[i].stock)	
				{max=ps->produits[i].stock;}
								
		}
		printf("le maximum de stock est %.2f\n",max);
	
		for(i=0;i<ps->nb_produit;i++){
			if(max==ps->produits[i].stock)
	printf("Nom %s : le code %d quantite %.2f\n",ps->produits[i].nom,ps->produits[i].code,ps->produits[i].stock);
		
	}
	}
	
	void rech_code(produits* ps,int code){
		int i,j=0;
		for(i=0;i<ps->nb_produit;i++){
			if(ps->produits[i].code == code){		
	printf("Nom %s : le code %d quantite %.2f\n",ps->produits[i].nom,ps->produits[i].code,ps->produits[i].stock);
				j++;
			}}
		if(j== 0) printf("Le code n existe pas\n");		
	}
	
	void rech_nom(produits* ps,char *nom){
		int i,j=0;
		for(i=0;i<ps->nb_produit;i++){
			if(strcmp(ps->produits[i].nom,nom)==0){
					j++;
	printf("Nom %s : le code %d quantite %.2f\n",ps->produits[i].nom,ps->produits[i].code,ps->produits[i].stock);
		}}
		if(j== 0) printf("Le nom saisie n existe pas\n");	
		}
		
		void echange(produit *a,produit *b){
			produit T;
			T = *a;
			*a =* b;
			*b = T;
		}		
	
	produits tri_code(produits*ps){
			int i,j;
			
		for(i=0;i<ps->nb_produit-1;i++){
			for(j=i+1;j<ps->nb_produit;j++){
				if( ps->produits[i].code > ps->produits[j].code)
				echange(&ps->produits[i],&ps->produits[j]);
			}
		}
		 return *ps;
	}
	
	produits tri_nom(produits*ps){
			int i,j;
			int n=0;			
		for(i=0;i<ps->nb_produit-1;i++){
			for(j=i+1;j<ps->nb_produit;j++){
			n =	strcmp (ps->produits[i].nom,ps->produits[j].nom);
				if(n>0)
				echange(&ps->produits[i],&ps->produits[j]);
			}
		}
		 return *ps;
	}
	
	void tri_stock(produits*ps){
			int i,j;
			
		for(i=0;i<ps->nb_produit-1;i++){
			for(j=i+1;j<ps->nb_produit;j++){
				if( ps->produits[i].stock > ps->produits[j].stock)
				echange(&ps->produits[i],&ps->produits[j]);
			}
		}
		
	}
	void supprime_code(produits*ps,int code){
		int i,j;
	for(i=0;i<ps->nb_produit;i++){
			if(ps->produits[i].code == code){
				for(j=i+1;j<ps->nb_produit;j++){	
			ps->produits[i]=ps->produits[j];
			}
			}
			}	
			ps->nb_produit--;
	}
	
	//Pile:
	typedef struct pile{
		int sommet;
		char nom[64];
	}pile;
	
	pile pile_vide(pile* p){
		p->sommet = -1;
		return *p;
	}
/*	pile int_pile(pile *p){
		for(int i=p->sommet;i<-1;i--){
			p->nom="";
		}
		return *p;
	}
	
	
	void empiler(pile *p,char n){
		p->sommet++;
		p->nom = n ;
	}
	
	void depiler(pile*p){
		if(p->sommet <= -1)
			printf("la pile est vide");break;
		p->sommet--;
	}
	
	pile charge_pile(pile *p, produits *ps){
		
		
	}
	*/
	
	main(){
		produits ps;
		ps.nb_produit=0;
		int n;
		int code;
		char nom[25];
	
		
	do{
	printf("Veuillez choisir :\n");
		//printf("1.Ajouter un Produit\n 2.Afficher les produits\n 0.Quitter\n");
		printf("1.Ajouter un Produit\n");
		printf("2.Afficher les produits\n");
		printf("3.Nombre de produits\n");
		printf("4.Somme Totale des stock\n");
		printf("5.Maximum des stock et produits\n");
		printf("6.Recherche par code \n");
		printf("7.Recherche par nom \n");
		printf("8.Tri par code \n");
		printf("9.Tri par nom \n");
		printf("10.Tri par stock \n");
		printf("11.Supprime \n");
		printf("0.Quitter\n");
		scanf("%d",&n);
	
		switch(n){
		//case 0 : break|| exit(0),break;
		case 1 : ajouter_pro(&ps); break;
		case 2 : afficher_pro(ps); break;
		case 3 : nbr_pro(&ps);break;
		case 4 : som_stock(&ps);break;
		case 5 : aff_max(&ps);break;
		case 6 :  printf("Veuillez entrez le code que vous voulez chercher : ");
				scanf("%d",&code);
				rech_code(&ps,code);break;
		case 7 : printf("Veuillez entrez le nom que vous voulez chercher : ");
				scanf("%s",&nom); 
				rech_nom(&ps,&nom);break;
		case 8 : ps = tri_code(&ps);
				afficher_pro(ps);break;
		case 9 : ps = tri_nom(&ps);
					afficher_pro(ps);break;
		case 10 :  tri_stock(&ps);
				afficher_pro(ps);break;
		case 11 : printf("Veuillez entrez le code que vous voulez chercher : ");
				scanf("%d",&code);
					supprime_code(&ps,code);
					afficher_pro(ps);break;
		//default : printf("Choix incorrect/n");	}
		}
		}while(n!=0);
	}
	
