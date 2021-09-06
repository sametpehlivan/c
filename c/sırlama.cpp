//BUBBLE,MERGE VE QUÝCK SORT 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void b_sort(int dizi[],int n){
	clock_t start;
	float fark;
	int bayrak=0,temp;

	while(bayrak==0){   /// bayrak ile eðer sýralýysa dizi n durumda anlamasýiçin
		
		bayrak=1;
		for( int i=0;i<n-1;i++){
		
			if(dizi[i]>dizi[i+1]){
				bayrak=0;
				temp=dizi[i];
				dizi[i]=dizi[i+1];
				dizi[i+1]=temp;
				
			}
			
			n--; ///son sýralanan eleman en büyük olduðu için dizi konrolu küçültürülerek gidilmesi için
			
		}
		
	
	}
    
   	fark=clock()-start;
	
//	printf("%.2lf\n",(float)fark);
}

//////////*************************************************************************///////////////////////////////////
void merge(int dizi[],int ilk,int orta,int son);

void m_sort(int dizi[],int ilk,int son){
	
	if (ilk<son){ //dizi iki elamnlý küçük dizilere bölünüyor
		int orta=(ilk+son)/2;
		m_sort(dizi,ilk,orta); 
		m_sort(dizi,orta+1,son);
		merge(dizi,ilk,orta,son);
		
	}
	
	
	           
}


void merge(int dizi[],int ilk,int orta,int son){
	int tempArray[1000];
	int ilk1=ilk; int ilk2=orta+1; // bölünen küçük 2 elamanlý diziler tekrar 2'ye bölünüyor
	int son1=orta; int son2=son;
	int index=ilk1;
	
	while(ilk1<=son1 && ilk2<=son2){
		
		if(dizi[ilk1]<dizi[ilk2]){      
			tempArray[index]=dizi[ilk1]; 
			ilk1++;
		}
		else{
			tempArray[index]=dizi[ilk2];
			ilk2++;
			
		}
	 index++;	
   	}///eger ikli grupdaki dizilerden en büyük elamn  birinci dizideyese o eleman yukardaki döngüde yerleþtirilmediði için burada yerleþtirilor veya ayný olay 2. diziedeyse 
	   //2. ,döngüde yerleþtiriliyor
	while(ilk1<=son1  ){
		tempArray[index]=dizi[ilk1];
		ilk1++;
		index++;
	}
	while(ilk2<=son2 ){
		tempArray[index]=dizi[ilk2];
	   ilk2++;
	   index++;
	}
	for(index=ilk;index<=son;index++){    //kopya diziye yerleþtiriliyor
		dizi[index]=tempArray[index];
	}
  

}

////////////////////////////**************************************************************////////////////////////////////
int Dayanak(int dizi[],int alt,int ust);

void q_sort(int dizi[],int alt,int ust){
	int dayanak;
	if (alt<ust){
		dayanak = Dayanak(dizi,alt,ust);
		q_sort(dizi,alt,dayanak-1);
		q_sort(dizi,dayanak+1,ust);
		
	}
	
	
	
	
	
}



int Dayanak(int dizi[],int alt_indis,int ust_indis) { 
    int i,j,pivot_degeri,pivot_indisi,gecici;  

     pivot_degeri=dizi[alt_indis];  
     j=alt_indis; 

     for(i=alt_indis+1;i<=ust_indis;i++) {   

        if (dizi[i]>pivot_degeri)  {  
          j++;                        /// pivot degerinden sonraki elaman ,pivattan büyük elaman gelene kadar yeri deðiþmeyek büyük elaman geldiðinde sadece i deðeþecek ve   
		  gecici=dizi[i];               ///  büyük elamandan sonra pivottan küçük elaman gelirse j büyük elamanýn hemen arkasýnda olduðundan j büyük elemaný gösterecek
          dizi[i]=dizi[j];              /// küçük elamn ile pivottan büyük elaman yer deðiþirecek pivotun yeri sabit !!!!!!
          dizi[j]=gecici; 
         }
     }
     pivot_indisi=j;        ////burada ise j pivottan küçük grubun en sagýndaki elamý göterdiðinden dolayý pivot ile j nin gösterdiði elaman yer deðiþirerek    
     gecici=dizi[alt_indis];  //// pivot ortaya alýnýr 
     dizi[alt_indis]=dizi[pivot_indisi]; 
     dizi[pivot_indisi]=gecici; 
     return pivot_indisi;  
 } 


int main(){

	int dizi[100];
	
	srand(time(NULL));
	for(int i=0;i<100;i++){
		dizi[i]=rand()%1000;
	}
        
   	//b_sort(dizi,100);

     // m_sort(dizi,0,99)  ;
	dizi[0]=2;
	dizi[1]=3;
	q_sort(dizi,0,99);
    printf("\n\n\n");
	for(int i=0;i<100;i++){
		printf("%d   %d\n",dizi[i],i+1);
	}
  
	
	
}


