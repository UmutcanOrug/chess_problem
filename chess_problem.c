#include<stdio.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#define SIZE 8
#define SIZE2 64

int showNotationandBoard(int board[SIZE][SIZE] , char[] , int numbers[], int );
int main(){
	
	srand(time(NULL));
	
	//tanimalamalar
	int xpos,ypos,ytemp,xtemp,i,j,k,z,randommove,counter;
	int movecounter=1,tmpcount,numbers[SIZE2],newxpos,newypos,canmove[SIZE],board[SIZE][SIZE],themoves[SIZE2],AHnumbers[SIZE];
	double iteration;
	char xpos1,AH[SIZE2];
	printf("This program solves the knights tour problem ! Press enter to continue!");
	getch();
	//taking starting positions!
	do{
		printf("\nPlease enter the starting position A-H = ");
		scanf("%c",&xpos1);
		xpos=xpos1-64;
		system("CLS");
	}while((xpos1>72)||(xpos1<65));
	system("CLS");
	do{
		printf("Please enter the starting position 1-8 = ");
		scanf("%d",&ypos);
		system("CLS");
	}while((ypos>8)||(ypos<1));
	system("CLS");
	printf("PLease wait...");
	for(i=0; i<SIZE ; i++){
		for(j=0; j<SIZE ; j++){
			board[i][j]=0;
			
		}
	}
	
	
	//The movement matrix of the knight
		int moves[8][2]=
	{
			{-2,-1},
			{-1,-2},
			{1,-2},
			{2,-1},
			{2,1},
			{1,2},
			{-1,2},
			{-2,1}			
	};
	
	do{
		newxpos=xpos-1;
		newypos=ypos-1;
	
		board[newypos][newxpos]=1;
		counter=1;
		z=0;
		// iki dizi sifirlaniyor
		for(i=0; i<SIZE2 ; i++){
			AH[i]=0;
			numbers[i]=0;
			AHnumbers[i]=0;  /*burda AH dizisini sonradan board indisinde kullanmak icin integer halini tutan yeni bir dizi actým*/
			
		}
		do {
			
			for(i=0; i<SIZE ; i++){
				canmove[i]=-1;
			}
			k=0;
			for(i=0; i <SIZE ; i++){
				xtemp=moves[i][0];
				ytemp=moves[i][1];
				if((newxpos+xtemp>=0)&&(newxpos+xtemp<SIZE)&&(newypos+ytemp>=0)&&(newypos+ytemp<SIZE)){
					if(board[newypos+ytemp][newxpos+xtemp]==0){
						canmove[k]=i;
						k++;
					}
				}
				
			}
			if(canmove[0]!=-1){
				randommove=rand() % k;
				newxpos=newxpos + moves[canmove[randommove]][0];
				newypos=newypos + moves[canmove[randommove]][1];
				board[newypos][newxpos]=1;
				AH[z]='A'+ newxpos ;
				AHnumbers[z]=newxpos; //AH'in sadece integer hali tutuluyor
				numbers[z]=  newypos;
				
				z++;
				counter++;
			}
			
			}while(canmove[0]!=-1);
			
		iteration++;
		
	
		if(counter==64){
		system("CLS");
		printf("\nIteration #  %.0f  (%d moves):      ",iteration,counter);
		for(i=0; i<z ; i++){
			printf("%c%d    ",AH[i],numbers[i]+1);
		}
			
		}
		
		for(i=0 ; i<SIZE ; i++){
			for(j=0 ; j<SIZE ; j++){
				board[i][j]=0;
			}
		}
		if (counter==64){
			Sleep(5000);
			board[ypos-1][xpos-1]=1;
			for(i=0; i<(SIZE2-1) ; i++){
				
					board[numbers[i]][AHnumbers[i]]=i+2;	//burda ise yapilan her hamleyi sirasiyla gostermek icin olan algoritma var.
				
				tmpcount=showNotationandBoard(board,AH,numbers,movecounter); //her hamle yapildiginda tahta gosteriliyor
				movecounter=tmpcount;
				movecounter++;
			}
			printf("\n\nPlease wait little bit for a new knights tour!\n\n");	
		}
		//getch();
		movecounter=1;
		

		}while(counter<65);
	return 0 ;
}
int showNotationandBoard(int board[SIZE][SIZE] , char AH[] , int numbers[] , int movecounter){
	
	int l, b , s  ;
	char AHboard;
	system("CLS");
	printf("\n\n\n");
	for(l=0; l<SIZE; l++){
		printf("%5d|",l+1);
		for(b=0; b<SIZE; b++){
			printf("%5d", board[l][b]);
		}
		printf("\n\n");
	}
	printf("\n");
	printf("      ");
	for(s=0 ; s<8 ; s++){
			AHboard='A'+ s ;
			 
			printf("%5c",AHboard);
		}
	printf("\n\n\n\n");
	for(l=0 ; l<movecounter ; l++){
		printf("%d) %c%d ",l+2,AH[l],numbers[l]+1);
	}
	Sleep(2000);
	
	return movecounter;
	
}


































