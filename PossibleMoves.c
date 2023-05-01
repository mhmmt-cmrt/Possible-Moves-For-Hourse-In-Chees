/* this project was created by muhammet cömert*/

/* satrançtaki atýn (sovalyenin) olasý hareketlerini
   bulan bir PossibleMoves.c kodu */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void sovalye(int,int); //sovalye fonk prototipi

void kontrol(int , int, int, int); //kontrol fonk prototipi

void hamleYaz(int, int);  //gecerli fonk prototipi

void tahtayiCizdir(int [][8]);  //tahtayiCizdir fonk prototipi

void degerAl(); //degerAl fonksiyonunun prototipi

    
int satir, sutun;
int tahta[8][8]={0};   // bu degerler global
    
    
int main()  // ana fonksiyon
{  
    
    printf("> satranc tahtasi \n");
    
    tahtayiCizdir(tahta);
   
    degerAl(); 
    
    sovalye(satir, sutun); 
    
    tahtayiCizdir(tahta);
    
    printf("At'in baslangic konumu (1) ile, ");
    
	printf("Gidecebilecegi konumlar (2) ile temsil edilmistir.  ");
	    
    return 0;
}
  void degerAl()  // satir sutun degerlerini alan fonksiyon
{ 
    
    printf("> baslangic konumu girin([satir](1-8)): "); // konum al
    scanf("%d",&satir);
    
    printf("> baslangic konumu girin([sutun](1-8)): "); // konum al
    scanf("%d",&sutun);
    
    
    system("CLS"); 
    satir--;   //dizilerde konum 0 dan basladýðý için 1 azaltýyoruz
    sutun--;
    tahta[satir][sutun]=1; // seçilen konuma 1 ata
}
  void sovalye(int n, int m)  //atýn hareketini bulan fonksiyon
{
    int ilk,son,z;
    
    int bord[8][2]={{-2,-1},{-2,1},{2,-1},{2,1},   // atýn gidecegi
	                {1,-2},{1,2},{-1,-2},{-1,2}};  // yerler.
    
    for(z=0;z<8;z++)   // max 8 hamle yapabildigi icin ust sýnýr 8
	{ 
        ilk = bord[z][0]; 
        
        son = bord[z][1];
        
        kontrol(n,m,ilk,son); 
    }
}   
void kontrol(int a, int b, int z, int t) //konumlarý bul 
{                                         //l hareketini kontrol et
    int x,y;
    
    system("cls");
    a += z; 
    b += t;
    
    for(x= 0,y = 0;x < 8, y < 8; x++,y++) // tahta alanýnda islem yap
	{
       if(a > x || b > y || a < 0 || b < 0) { }
       
       else
	       { 
             hamleYaz(a, b); 
           } 
    }
    
}
  void hamleYaz(int x, int y) // bulunan konuma 2 degerini ata
{                             //sadce tahtadaki hamleleri isler. 
   tahta[x][y]=2;
}

  void tahtayiCizdir(int dizi[][8])  // tahtayi çizdiren fonksiyon
{
    int k,l;
    printf("\n");
    printf("    [1][2][3][4][5][6][7][8]\n\n");
    
    for(k=0;k<8;k++)
	{
        for(l=0;l<8;l++)
		{
         	if(l==0)
         	   printf("[%d]",k+1);
         	   
               printf("  %d",dizi[k][l]); 
             
	    }
        printf("\n\n"); 
    }
}
  

