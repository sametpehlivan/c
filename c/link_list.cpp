//L�NK L�ST �LE DOSYADAN OKUNAN ELEMANLARI BA�LI L�STEYE SIRALI B���MDE YERLE�T�RME,ARAMA,EKLEME,S�LME

#include<stdio.h>
#include<stdlib.h>


typedef struct akademisyen{
	
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

void listele(){
	iter=root;
	while(iter!=NULL){
		switch(iter->unvanID){
			
			case 1: printf("%d Prof.Dr %s %s\n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 2:  printf("%d Doc.Dr %s %s \n",iter->sicilNo,iter->ad,iter->soyAd); break;
			case 3:  printf("%d Dr.Ogr.Uyesi %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 4:  printf("%d Ars.Gor %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
			
			
			
		}
		
		iter=iter->sonraki;
		
	}
	
	
	
	
}

int ekle(akademisyen *veri){
    	
	if(root==NULL){      //il eleman kontrolu
	  Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
   	    temp=veri;
		root=temp;
		root->sonraki=NULL;
		return 0;
	}
   if(veri->unvanID < root->unvanID){    //�nvan� ilk eleman�n �nan�ndan b�y�kse
     iter=root;
   	 Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
   	 temp=veri;
   	 temp->sonraki=iter;
   	 root=temp;
   	 return 0;
     }
    if(root->sonraki==NULL && veri->unvanID >root->unvanID){   //tek eleman varsa ve tekelmandan �nvan� k�c�kse ve sonraki s�ralamalarda listenin sonunu konrtrolunu k�saltmak i�in
     Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
   	 temp=veri;
   	 temp->sonraki=root->sonraki;
   	 root->sonraki=temp;
   	 return 0;
	}
    if(veri->unvanID==root->unvanID ){      //ilk elamana �navan� e�itse y�la g�re s�ralama
    	iter=root;
		if(veri->unvanYili >= root->unvanYili){
    	     Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
   	         temp=veri;
             temp->sonraki=root->sonraki;
             root->sonraki=temp;
             return 0;    		
    		
		}
    	else{
    		 Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
   	         temp=veri;
    		 temp->sonraki=iter;
    		 root=temp;
    		 return 0;
		}
    	
    	
    	
	}
	
	
	
	 iter=root;
    while(iter->sonraki!=NULL && veri->unvanID > iter->sonraki->unvanID ){ //araya eklemek i�in kontrol
    	iter=iter->sonraki;
	} 
    if(iter->sonraki->unvanID == veri->unvanID ){     //aradaki herhangi bir elemana unvan� e�itse yerle�tirme
    	if(iter->sonraki->unvanYili <= veri->unvanYili){
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
    
     if(iter->sonraki->unvanID > veri->unvanID){  //araya ekleme
      Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
   	  temp=veri;
      temp->sonraki=iter->sonraki;
	  iter->sonraki=temp;
	  return 0;	
	 }
 

}

void gorevlendirme(int a){         //ka� kisi g�revlendirilecekse toplam adetten ��kar�p fark kadar listeyi ilerletiyoruz daha sonra ise listenin sonunu g�rene kadar bast�r�yoruz
	iter=root;                        
	for(int i=0;i<sayac-a;i++){	   //b�ylece �nvana g�re g�rev alacaklar� s�ral�yoruz
		iter=iter->sonraki;
	
	}
	
	while(iter!=NULL){
		switch(iter->unvanID){
			
			case 1: printf("%d Prof.Dr %s %s\n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 2:  printf("%d Doc.Dr %s %s \n",iter->sicilNo,iter->ad,iter->soyAd); break;
			case 3:  printf("%d Dr.Ogr.Uyesi %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
			case 4:  printf("%d Ars.Gor %s %s \n",iter->sicilNo,iter->ad,iter->soyAd);break;
			
			
			
		}
		
		iter=iter->sonraki;
		
	}
	
	
	
	
}
	

int sil (int data){
	
	 Akademisyen *temp=(Akademisyen*)malloc(sizeof(Akademisyen));
	 iter=root;
	 if(root->sicilNo== data){            //ilk eleman kontrolu yap�yoruz b�ylece ilk eleman� kaybetmeden hafizadan siliyoruz
	 	temp=root;
		 root=root->sonraki;
	     iter=root;
	     free(temp);
	     listele();
		 return 0;
	 }
	  
	 while(iter->sonraki->sicilNo != data){
	 	iter=iter->sonraki;
	 	 if(iter->sonraki==NULL){
	    	printf("ARANAN KISI KAYITLI DEGIL \n");return 0;
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

while(!(feof(dosya))){   //elemanlar� s�ral�yarak ekliyor
	 gecici=(Akademisyen*)malloc(sizeof(Akademisyen));
	fscanf(dosya,"%d %s %s %d %d",&gecici->sicilNo,gecici->ad,gecici->soyAd,&gecici->unvanID,&gecici->unvanYili);
	ekle(gecici);
    sayac++;
  
}


		
	
	
	while(1==1){       
	printf("Secim yapiniz \n 1-Listeleme 2-Gorevlendirme 3-ekleme 4-Silme 0-Cikma\n");
	scanf("%d",&secim);
	switch(secim){
		
		case 1:
			 listele();break;
		   	 	
	         
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
