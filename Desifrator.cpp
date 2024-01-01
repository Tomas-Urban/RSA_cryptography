#define _CRT_SECURE_NO_WARNINGS

#define NAZEV "modulo_2.txt"

#include <stdio.h> //používátí funkcí printf() a scanf()
#include <stdlib.h>
#include <string.h>
#include <math.h> //používátí matematických funkcí
#include  <iostream >
#include  <fstream >

#include <stdlib.h> /* required for atoi */

#include <bits/stdc++.h> 
using namespace std; 

//#include <stdio.h>

int obsahuje_znak(char znak,char pole[])
{
    int i;
    for (i = 0; pole[i] != '\0'; i++)
    if (pole[i] == znak)
        return 1;
    return 0;
}

int main(int argc, char** argv)
{
	char text[255];
	int b=0, c=0, m=0, i=0, j=0, k=0, q=0, zbytek=0, znak=0; 
	const int delka_zpravy=10; 
	
	char tabulka []= { // pøevodní tabulka znakù na èísla
		 '¤','¤','1','2','3','4','5','6','7','8',
		 '9','0','a','b','c','d','e','f','g','h',
		 'i','j','k','l','m','n','o','p','q','r',
		 's','t','u','v','w','x','y','z','A','B',
		 'C','D','E','F','G','H','I','J','K','L',
		 'M','N','O','P','Q','R','S','T','U','V',
		 'W','X','Y','Z',',','.','?','!','_','+',
		 '-','*','/','$','<','>','(',')','[',']',
		 '{','}','=','"','\'','-',' ',
		};
     	// 
 	printf("Desifrator\n"
		   "==========\n");
	//cout<<"De"<<(char)231<<"ifr"<<(char)160<<"tor"<<endl;
	int ostatni_znaky_1;
	do
	{	
		int pocet_cisel_1 = 0;
		char klic_1[111];
			
		printf("Zadej mensi clen verejneho klice \n"
				"(max. ctyrciferny) a stiskni Enter: ");
			scanf(" %10[^\n]s", &klic_1);
			// definice typu znaku
   		 	char cisla[] = "0123456789";

    		// indexy
    		int index = 0;

    		// hlavni cyklus pokracuje, dokud nenarazi na znak konce retezce
    		for (index = 0; klic_1[index] != '\0'; index++)
    		{
        		if (obsahuje_znak(klic_1[index], cisla) == 1)
            	pocet_cisel_1++;
            	
            	if (index >= 5)
            		{
            			break;
					}	
    		}
    	//	printf("Pocet cisel: %i \n", pocet_cisel_1);
            ostatni_znaky_1 = strlen(klic_1) - pocet_cisel_1;
        //  printf("Ostatni znaky_1: %i \n", ostatni_znaky_1);
            
			if (ostatni_znaky_1 != 0)
				{
					printf("Zadany symbol neni cislo. \n");	
				} 
			else if (index >= 5)
        		{
        			printf("Zadane cislo ma vice nez ctiri cifry. \n");
        			ostatni_znaky_1 = 1;
				}
			else if (ostatni_znaky_1 == 0) 
				{	
					b=atoi(klic_1);
					//printf("d= %i\n", b);
				}
	} while (ostatni_znaky_1 != 0);
	
	int ostatni_znaky_2;		
	do
	{
		int pocet_cisel_2 = 0;
		char klic_2[111];
			
		printf("Zadej vetsi clen verejneho klice \n"
				"(max. ctyrciferny) a stiskni Enter: ");
			scanf(" %10[^\n]s", &klic_2);
			// definice typu znaku
   		 	char cisla[] = "0123456789";

    		// indexy
    		int index = 0;

    		// hlavni cyklus pokracuje, dokud nenarazi na znak konce retezce
    		for (index = 0; klic_2[index] != '\0'; index++)
    		{
        		if (obsahuje_znak(klic_2[index], cisla) == 1)
            	pocet_cisel_2++;
            	
            	if (index >= 5)
            		{
            			break;
					}	
    		}
    	//	printf("Pocet cisel: %i \n", pocet_cisel_2);
            ostatni_znaky_2 = strlen(klic_2) - pocet_cisel_2;
        //  printf("Ostatni znaky_2: %i \n", ostatni_znaky_2);
            
			if (ostatni_znaky_2 != 0)
				{
					printf("Zadany symbol neni cislo. \n");	
				} 
			else if (index >= 5)
        		{
        			printf("Zadane cislo ma vice nez ctyri cifry. \n");
        			ostatni_znaky_2 = 1;
				}
			else if (ostatni_znaky_2 == 0) 
				{	
					m=atoi(klic_2);
					//printf("m= %i\n", b);
				}
	} while (ostatni_znaky_2 != 0);
	
	printf("\nDesifrovana zprava:\n\n");		
  	int pocet_radku; // Sem naèteme "poèet øádkù" souboru
	int zprava[255];
  	char line[255];  // Sem naèteme jednotlivé øádky souboru (nahrají se jako string).
  
	FILE *file; //ukazatel na soubor
	file = fopen("zasifrovana_zprava.txt", "r");  //otevøení souboru pro ètení
	if (file == NULL)
   		{
        	printf("Soubor se nepodarilo otevrit, zkontrolujte umisteni souboru.");
        	return 1;
    	}
    	
	while(fgets(line, sizeof line, file)!=NULL) { //ètení souboru po øádcích, dokud nedojde na konec souboru        
    		zprava[i]=atoi(line);  //pøevedení strigu na èíslo
    		i++;
    	}
    pocet_radku = i;

    for(i = 1 ; i < pocet_radku ; i ++){
	//	char *p = strchr(tabulka, zprava[i]);	
	//	int pozice_znaku = p - tabulka;
	//	printf("Znak: %c, Prevedeny:  %i \n", zprava[i], pozice_znaku);
		
		
		//Pøepoèet hodnoty z tabulky zadaným veøejným klíèem
		int prepocet = zprava[i];
			
    	zbytek = prepocet % m;
	//	printf("zbytek po deleni cisla %i cislem %i je %i\n", prepocet, m, zbytek);
		c=prepocet;
			
		const int n = m;
		int pole[n]; //Pole, do kterého se nahrávají mezivýsledky pøepoèítávání veøejným klíèem.
		for(j=0; j<=m; j++)
			{
				zbytek=c%m;
			//	printf("%i z=%i \n", j+1, zbytek);
				pole[j]=zbytek;
				c=zbytek*prepocet;
					
				//Hledání konce cyklu opakujících se zbytku
				int *l = find(pole, pole + n, zbytek);
    			int pozice = l - pole - 1;
    			if (b==j+1)
    			{
    			//	printf("zbytek %i nalezen pred koncem prvni periody na pozici %i.\n", zbytek, pozice+2);
				//	printf("%i ^ %i (mod %i) = %i\n", zprava[i], b, m, pole[j]);
				//	printf("Prip.: 1, Zasifrovany:  %i, desifrovany: %i, Znak: %c\n", zprava[i], pole[j], tabulka[pole[j]]);
					printf("%c", tabulka[pole[j]]);
					break;
				}
				if (pozice+1 < j)
    			{
    				q=j-pozice-1;
    			//	printf("pocet zbytku q = %i, pocet zbytku i = %i\n", q, j-q);
    			
    				k=(b-(j-q))%q;
    				if(k==0)
    					{
    					//	printf("(b-i) (mod q) = %i,  pozice = %i\n", k, pozice+1+q);
						//	printf("%i ^ %i (mod %i) = %i\n", prepocet, b, m, pole[pozice+q]);
						//	printf("Prip.: 2, Zasifrovany:  %i, desifrovany: %i, Znak: %c\n", zprava[i], pole[pozice+q],tabulka[pole[pozice+q]]);
							printf("%c", tabulka[pole[pozice+q]]);
						}
					else
						{
						//	printf("(b-i) (mod q) = %i, pozice = %i\n", k, pozice+1+k);
						//	printf("%i^%i (mod %i) = %i\n", prepocet, b, m, pole[pozice+k]);
						//	printf("Prip.: 3, Zasifrovany:  %i, desifrovany: %i, Znak: %c\n", zprava[i], pole[pozice+k], tabulka[pole[pozice+k]]);
							printf("%c", tabulka[pole[pozice+k]]);	
						}	
    				break;
    			}	
			}
	}
    		printf("\n");
			system("pause");
	return 0;
}


