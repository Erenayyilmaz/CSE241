#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	struct n {

	char *val;
	struct n * next; 

    };
	typedef struct n Node; 
	 
	Node *curr;
	void ekle(char *deger)
	{

		curr->val = deger;
		Node *tmp = (Node*)malloc(sizeof(Node));
		curr->next = tmp; 
		//printf("%s\n",curr->val);
		curr = curr->next;
	}	


		void satiriAyir(char *satir)  {
		 
		char *kelime; 
		kelime = strtok (satir,"");
		while (kelime != NULL) {
		
			ekle(kelime);
			kelime = strtok (NULL, " ");
									 }
                                    }

			int main() {

			curr = (Node *)malloc(sizeof(Node));

			FILE *dosya1;
  			char dosya[1000];
  			printf("Dosyanin adini giriniz: ");
  			scanf("%s",dosya);
			if((dosya1=fopen(dosya,"r"))==NULL) {
		
				printf("Dosya acilamadi.\n");
				return 1;   }
		
			char satir[50];
			while (fgets( satir, sizeof(satir), dosya1 )!=NULL) //Verilen dosya akýþýndan en fazla count parametre deðerinin 1 eksiði kadar karakter okur ve okuduðu karakterleri str parametresi ile gösterilen karakter dizisine atar. Dosya sonuna eriþildiðinde veya bir yeni satýr karakteri ile karþýlaþýldýðýnda belirtilen sayýda karakter okumadan iþlem sona erer.
			satiriAyir(satir);
			fclose(dosya1);
			return 0;       }

