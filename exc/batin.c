#include <stdio.h>  
#include <stdlib.h>
    

    /*  KANKA LINKEDKISTLERI EN BASTA GLOBAL TANIMLADI YAPMAN GEREKEN ADD FONKSIYONUNUN FALAN PROTOIPINI DEGISTIRIP UYARLAMAK KODLARI GECEN SENEKI
     LAB KODLARIMDAN ALDIGIM ICIN BOYLE YAPMAK ZORUNDA KALDIM    LL_SORTED DIYE TANIMLADIGIM SEY YENI BI LINKEDLISTI TEMSIL EDECEK BU DA ORJINAL LINKEDLISTIN YENI BI 
     KOPYASI OLACCAK SONRA BUNU DA SORT FONKSIYONUNA GONDERECKSIN ARDINDAN SORTLANMIS HALINI TEK TEK BASRTIRABILIRSIN */

            

    /*  DOSYADAN OKUMAYI SATIR SATIR YAPTIM AMA SON SATIR IKI KERE OKUAYBILIR ONA DIKKAT ETMEK GEREK GECEN SENE OYLE SEYLERE RASTLAMISTIM   */



struct node{  
    int data;
    int note;
    struct node *next;  
};      
    
struct node *head, *tail = NULL;  

    
void addNode(int data, int note) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;
    newNode->note = note;
    newNode->next = NULL;  
        
    if(head == NULL) {  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        tail->next = newNode;  
        tail = newNode;  
    }  
}  
    
void sortList() {  
    struct node *current = head, *index = NULL;  
    int temp;  
        
    if(head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
            index = current->next;  
                
            while(index != NULL) {  
                if(current->data > index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }  
}  
    
void display() {  
    struct node *current = head;  
    if(head == NULL) {  
        printf("liste bos \n");  
        return;  
    }  
    while(current != NULL) {  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
        
int getCount(struct Node* head)
{
    int count = 0; 
    struct Node* current = head; 
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


int main()  
{  
    char tmp[200];

    FILE *fp;
    char dosya[1000];
    printf("Dosyanin adini giriniz: ");
    scanf("%s",dosya);
    if((fp=fopen(dosya,"r+"))==NULL) 
    {

        printf("Dosya acilamadi.\n");
        return 1;
    }
		
    while(fgets(tmp, sizeof(tmp), fp) != NULL)
    {
        int index = 0;
        int tot = 0;
        int sum = 0;
        while (tmp[index] != ' ')
        {
            tot *= 10;
            tot += ((tmp[index]) - '0');
            index++;
        }
        index++;
        while (tmp[index] != '\n' && tmp[index] != EOF)
        {
            sum *= 10;
            sum += ((tmp[index]) - '0');
            index++;
        }
        addNode(tot, sum);
    }

    struct node *ll_sorted;


    ll_sorted = (node)malloc(sizeof(node) * (getCount(head)));
    
    //kodu devam ettir knk burdan 

    return 0;  
}  