//Link List ile DOSYADAN OKUNAN ELEMANLARI  SIRALI BÝÇÝMDE YERLEÞTÝRME,ARAMA,EKLEME,SÝLME

#include<stdio.h>
#include<stdlib.h>

typedef struct akademisyen
{
	int sicilNo;
	char ad[15];
	char soyAd[15];
	int unvanID;
	int unvanYili;
	struct akademisyen *sonraki;
	
}Akademisyen;
int sayac;
Akademisyen *root;
Akademisyen *iter;
Akademisyen *gecici;

void listele()
{
	iter=root;
	while(iter!=NULL){
		switch(iter->unvanID)
		{
			case 1:  printf("%d Prof.Dr %s %s\n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 2:  printf("%d Doc.Dr %s %s \n",iter->sicilNo,iter->ad,iter->soyAd); break;
			case 3:  printf("%d Dr.Ogr.Uyesi %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 4:  printf("%d Ars.Gor %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
		}
		iter=iter->sonraki;
	}
}

int ekle(akademisyen *veri)
{
	if(root==NULL)
	{      
		//ilk eleman kontrolu
		Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
		temp=veri;
		root=temp;
		root->sonraki=NULL;
		return 0;
	}
	if(veri->unvanID < root->unvanID)
	{    
		//eklenen elemanın ünvanı ilk elemanın ünanından büyükse
		iter=root;
		Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
		temp=veri;
		temp->sonraki=iter;
		root=temp;
		return 0;
	}
	if(root->sonraki==NULL && veri->unvanID >root->unvanID)
	{   
		//linked listte tek eleman varsa ve var olan tek elmandan ünvanı kücükse ve sonraki sıralamalarda listenin sonunu konrtrolunu kısaltmak için
		Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
		temp=veri;
		temp->sonraki=root->sonraki;
		root->sonraki=temp;
		return 0;
	}
	if(veri->unvanID==root->unvanID )
	{      
		//ilk elamana ünavaný eþitse yýla göre sýralama
		iter=root;
		if(veri->unvanYili >= root->unvanYili)
		{
			Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
			temp=veri;
			temp->sonraki=root->sonraki;
			root->sonraki=temp;
			return 0;    		
		}
		else
		{
			 Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
			 temp=veri;
			 temp->sonraki=iter;
			 root=temp;
			 return 0;
		}
	}
	iter=root;
	while(iter->sonraki!=NULL && veri->unvanID > iter->sonraki->unvanID )
	{ 
		//araya eleman eklemek için kontrol
		iter=iter->sonraki;
	} 
	if(iter->sonraki->unvanID == veri->unvanID ){     
		//aradaki herhangi bir elemana unvaný eþitse yerleþtirme
		if(iter->sonraki->unvanYili <= veri->unvanYili)
		{
			Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
			temp=veri;
			temp->sonraki=iter->sonraki->sonraki;
			iter->sonraki->sonraki=temp;
			return 0;
		}
		else{ 
			Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
			temp=veri;
			temp->sonraki=iter->sonraki;
			iter->sonraki=temp;
			return 0;
		}
	}
    
	if(iter->sonraki->unvanID > veri->unvanID){  
		//araya ekleme
		Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
		temp=veri;
		temp->sonraki=iter->sonraki;
		iter->sonraki=temp;
		return 0;	
	}
}

void gorevlendirme(int a)
{         
	//kaç kisi görevlendirilecekse toplam adetten çýkarýp fark kadar listeyi ilerletiyoruz daha sonra ise listenin sonunu görene kadar bastýrýyoruz
	iter=root;                        
	for(int i=0;i<sayac-a;i++)
	{	   
		//böylece ünvana göre görev alacaklarý sýralýyoruz
		iter=iter->sonraki;
	}
	while(iter!=NULL)
	{
		switch(iter->unvanID)
		{
			case 1: printf("%d Prof.Dr %s %s\n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 2:  printf("%d Doc.Dr %s %s \n",iter->sicilNo,iter->ad,iter->soyAd); break;
			case 3:  printf("%d Dr.Ogr.Uyesi %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 4:  printf("%d Ars.Gor %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
		}
		iter=iter->sonraki;
	}
}

int sil (int data)
{	
	Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
	iter=root;
	if(root->sicilNo == data)
	{            
		//ilk eleman kontrolu yapýyoruz böylece ilk elemaný kaybetmeden hafizadan siliyoruz
		temp=root;
		root=root->sonraki;
		iter=root;
		free(temp);
		listele();
		return 0;
	}	  
	while(iter->sonraki->sicilNo != data)
	{
		iter=iter->sonraki;
		if(iter->sonraki==NULL)
		{
			printf("ARANAN KISI KAYITLI DEGIL \n");
			return 0;
		}
	}
	temp=iter->sonraki;
	iter->sonraki=iter->sonraki->sonraki;
	free(temp);
	listele();
	return 0;
}

int main(){
	int secim,a;
    	FILE *dosya=fopen("akademisyenler.txt","r");
	iter=(Akademisyen*)malloc(sizeof(Akademisyen));
	root=NULL;
	iter=root;
	while(!(feof(dosya)))
	{   
		//elemanlarý sýralýyarak ekliyor
		gecici=(Akademisyen*)malloc(sizeof(Akademisyen));
		fscanf(dosya,"%d %s %s %d %d",&gecici->sicilNo,gecici->ad,gecici->soyAd,&gecici->unvanID,&gecici->unvanYili);
		ekle(gecici);
		sayac++;
	}
	while(1==1){       
		printf("Secim yapiniz \n 1-Listeleme 2-Gorevlendirme 3-ekleme 4-Silme 0-Cikma\n");
		scanf("%d",&secim);
		switch(secim)
		{

			case 1:
				listele();
				break;	 
			case 2:
				printf("Kac kisi gorevlendirilecek ?");
				scanf("%d",&a);
				gorevlendirme(a);
				break;
			case 3:
				gecici=(Akademisyen*)malloc(sizeof(Akademisyen));
				printf("Eklenecekek kisilerin bilgilerini su sekilde giriniz\n ");
				printf("Sicil Numarasi,Isim,Soyisim,Uvan id ,Goreve basalama yili\n Unvan id ise bu bilgilere gore giriniz  : 1 :Prof.Dr , 2: Doc.Dr  , 3: Dr.Ogr.Uyesi,4: Ars Gor\n");
				scanf("%d %s %s %d %d",&gecici->sicilNo,gecici->ad,gecici->soyAd,&gecici->unvanID,&gecici->unvanYili);
				ekle(gecici);
				break; 
			case 4 :

				gecici=(Akademisyen*)malloc(sizeof(Akademisyen));
				printf("Silincek kisinin sicil numarasi\n");
				scanf("%d",&a);
				sil(a);
				break;   
			default:
				exit(1);  	
		}   
	}
	fclose(dosya);
}
