//GÝRÝLEN SAYIDAN KAÇ ADET OLDUÐUNU DOSYAYA YAZDIRMA

#include<stdio.h>



int main(){
	
	int i,j,dizi[50],k,a,sayac;
	printf("Kaç tane sayi girilecek :");
	scanf("%d",&k);
    printf("\n"); 
	FILE *dosya;
	dosya=fopen("dosya.txt","w+");
	printf("%d tane sayi giriniz\n",k);
	for(i=0;i<k;i++){
        scanf("%d",&a) ; 
		fprintf(dosya,"%d\n",a);
	}
	
	fclose(dosya);
	dosya=fopen("dosya.txt","r");
	for(i=0;i<k;i++){
		fscanf(dosya,"%d",&a);
		dizi[i]=a;
	}
	fclose(dosya);
	dosya=fopen("dosya.txt","a");
	for(i=0;i<k;i++){
		sayac=1;
		if(dizi[i]>=0){
		for(j=i+1;j<k;j++){
			if(dizi[i]==dizi[j]){
				sayac++;
				dizi[j]=-1;
			}
			
	
		}
	      printf("%d sayisindan %d tane var\n",dizi[i],sayac);
	     fprintf(dosya,"%d sayisindan %d tane var\n",dizi[i],sayac);
	 }
	
	
	}
	
	
	
	fclose(dosya);
	
	
	
	
	
}
























