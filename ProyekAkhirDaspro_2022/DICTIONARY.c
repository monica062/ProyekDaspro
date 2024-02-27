/*
DICTIONARY BATAK - ENGLISH
Monica Silaban    -  11322062
*/


#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{

   FILE *its;

   char msg[1000][15];
   char ind[15];

   int a,b;

   if((its = fopen("KAMUS.txt", "r"))==NULL)
   {
      printf("ERROR!!! file KAMUS.txt corrupt");
      getch();
      exit(1);
   }

   while(1){
   
   puts("Tentukan arah translate");
   puts("1. Batak-English");
   puts("2. English-Batak");
   puts("3. Masukkan kamus baru");
   puts("Tekan 'q' untuk keluar dari program");
   b=getch();

   switch(b){
      case '1' : {
         for(a=1;a<=1000;a++)
         fgets(msg[a], sizeof(msg),its);
         printf("Batak   : ");
         gets(ind);

         strcat(ind,"\n");
         printf("English : ");
         for(a=1;a<=1000;a++)

         if(strcmp(ind,msg[a])==0)
         printf("%s", msg[a+1]);
         fclose(its);
         getch();
         break;
      }
      case '2' : {
         for(a=1;a<=1000;a++)
         fgets(msg[a], sizeof(msg),its);
         printf("English     : ");
         gets(ind);
         strcat(ind,"\n");
         printf("Batak       : ");
         for(a=1;a<=1000;a++)
         if(strcmp(ind,msg[a])==0)
         printf("%s", msg[a-1]);
         fclose(its);
         getch();
         break;
      }

      case '3' : {
         char batak[100];
         char inggris[100];
         
         printf("\n Masukkan bahasa batak                : ");
         scanf("%s", &batak);
         printf("\n Masukkan arti dalam bahasa inggris   : ");
         scanf("%s", &inggris);


         FILE *kamus;

         kamus = fopen("KAMUS.txt", "r+");

         fseek(kamus, 0L, SEEK_END);
         fprintf(kamus, "\n%s\n%s\n", batak, inggris);
      }

      case 'q' :

         exit(0);
         break;
   }
   }

   return 0;
}
