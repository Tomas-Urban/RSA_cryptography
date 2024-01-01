#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> //používátí funkcí printf() a scanf()
#include <stdlib.h>
#include <string.h>
#include <math.h> //používátí matematických funkce
#include  <iostream >
#include  <fstream >

#include <bits/stdc++.h> 
using namespace std; 

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
	int  b=0, c=0, m=0, i=0, j=0, k=0, q=0, zbytek=0; 
	const int delka_zpravy=255; 
	// pøevodní tabulka znakù na èísla
	char tabulka []= {
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
 	printf("Sifrator\n"
		   "========\n");
	// zadání veøejného klíèe, kterým se zpráva zašifruje.
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
					//printf("e= %i\n", b);
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
					//printf("m= %i\n", m);
				}
			
	} while (ostatni_znaky_2 != 0);
	
	
	int neplatny_znak;
	do
	{	neplatny_znak = 0;
		char zprava[delka_zpravy];  //Pole, do kterého se nahraje zpráva o délce hodnoty intu: delka_zpravy.
	printf("Zprava smi obsahovat pouze znaky:\n"
			"        '1','2','3','4','5','6','7','8',\n"
		 	"'9','0','a','b','c','d','e','f','g','h',\n"
		 	"'i','j','k','l','m','n','o','p','q','r',\n"
		 	"'s','t','u','v','w','x','y','z','A','B',\n"
		 	"'C','D','E','F','G','H','I','J','K','L',\n"
		 	"'M','N','O','P','Q','R','S','T','U','V',\n"
		 	"'W','X','Y','Z',',','.','?','!','_','+',\n"
		 	"'-','*','/','$','<','>','(',')','[',']',\n"
		 	"'{','}','=','\"','\'','-',' '.\n"
			"Zadej zpravu a stiskni Enter. \n");
	scanf(" %[^\n]s",&zprava);
	
	// Smaže pøedchozí zprávu, pokud nìjaká je. Pokud není vytvoøí prázdný soubor, do kterého se nahraje zašifrovaná zpráva.
	FILE * p_soubor = fopen("zasifrovana_zprava.txt", "w");
   					if (p_soubor == NULL)
   					{
        				printf("Soubor se nepodarilo otevrit pro zapis, zkontrolujte prosim opravneni.");
        				return 1;
    				}
					fprintf(p_soubor, "verejny klic: (%i,%i) \n", b,m);
   						

    				if (fclose(p_soubor) == EOF)
    				{
       					printf("Soubor se nepodarilo uzavrit.");
       					return 1;
   					}
		//Cyklus, který projde postupnì znaky zprávy, najde je v tabulce a vypíše hodnotu jejich buòky v tabulce.
		for(i=0; zprava[i] !='\0';i++)
		{
			char *p = strchr(tabulka, zprava[i]);	
			int pozice_znaku = p - tabulka;
			if (p == 0)
			{
				printf("Znak na pozici %i neumim zasifrovat. \n", i+1);
				neplatny_znak = 1;
				break;
			}
		
		//	printf("p: %i, tabulka: %i. \n", p, tabulka);
		
		
			//Pøepoèet hodnoty z tabulky zadaným veøejným klíèem
			zbytek = pozice_znaku % m;
				//	printf("zbytek po deleni cisla %i cislem %i je %i\n", pozice_znaku, m, z);
			c=pozice_znaku;
		
			const int n = m;
			//Pole, do kterého se nahrávají zbytky po dìlení 
			int pole[n]; 
			
			//cyklus nahrávající zbytky do pole
			for(j=0; j<=m; j++) 
			{
				zbytek=c%m;
			//	printf("%i z=%i \n", j+1, z);
				pole[j]=zbytek;
				c=zbytek*pozice_znaku;
					
				//Hledání konce cyklu opakujících se zbytku
				int *l = find(pole, pole + n, zbytek);
    			int pozice = l - pole - 1;
    			if (b==j+1) //když dojde k mocninì b døíve než se zopakuje zbytek
    			{
    			//	printf("zbytek %i nalezen pred koncem prvni periody na pozici %i.\n", z, pozice+2);
				//	printf("%i ^ %i (mod %i) = %i\n", pozice_znaku, b, m, pole[j]);
					printf("Znak: %c, Prevedeny:  %i, Zasifrovany: %i\n", zprava[i], pozice_znaku, pole[j]);
						
						
					FILE * p_soubor = fopen("zasifrovana_zprava.txt", "a");
   					if (p_soubor == NULL)
   					{
        				printf("Soubor se nepodarilo otevrit pro zapis, zkontrolujte prosim opravneni.");
        				return 1;
    				}
					fprintf(p_soubor, "%i\n", pole[j]);
   						

    				if (fclose(p_soubor) == EOF)
    				{
       					printf("Soubor se nepodarilo uzavrit.");
       					return 1;
   					}
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
						//	printf("%i ^ %i (mod %i) = %i\n", pozice_znaku, b, m, pole[pozice+q]);
							printf("Znak: %c, Prevedeny:  %i, Zasifrovany: %i\n", zprava[i], pozice_znaku, pole[pozice+q]);
							
								
							FILE * p_soubor = fopen("zasifrovana_zprava.txt", "a");
   							if (p_soubor == NULL)
   							{
        						printf("Soubor se nepodarilo otevrit pro zapis, zkontrolujte prosim opravneni.");
       							return 1;
    						}
							fprintf(p_soubor, "%i\n", pole[pozice+q]);
   						

    						if (fclose(p_soubor) == EOF)
    						{
        						printf("Soubor se nepodarilo uzavrit.");
       							return 1;
   							}
						}
					else
						{
						//	printf("(b-i) (mod q) = %i, pozice = %i\n", k, pozice+1+k);
						//	printf("%i^%i (mod %i) = %i\n", pozice_znaku, b, m, pole[pozice+k]);
							printf("Znak: %c, Prevedeny:  %i, Zasifrovany: %i\n", zprava[i], pozice_znaku, pole[pozice+k]);
							
								
							FILE * p_soubor = fopen("zasifrovana_zprava.txt", "a");
   							if (p_soubor == NULL)
   							{
        						printf("Soubor se nepodarilo otevrit pro zapis, zkontrolujte prosim opravneni.");
        						return 1;
    						}
							fprintf(p_soubor, "%i\n", pole[pozice+k]);
   					

    						if (fclose(p_soubor) == EOF)
    						{
        						printf("Soubor se nepodarilo uzavrit.");
        						return 1;
    						}
						} break;
    				
				} 	
			}	
		} 
	} while (neplatny_znak == 1);
	
	
	system("pause");
    return EXIT_SUCCESS;
}
