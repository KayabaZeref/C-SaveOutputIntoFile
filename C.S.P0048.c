#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int exist(char* filename)
{
	int existed = 0;
	FILE* f= fopen(filename,"r");
	if (f!=NULL)
	{
		existed=1;
		fclose(f);
	}
	return existed;
}

int main(int argc, char *argv[]) {
	char filename[31];
	char data[100];
	char content[100];
	char key,reput;
	FILE *f;
	
//	do{
	printf("Enter file name: ");
		// %s: Lay 1 chuoi ki tu (KHONG KHOANG TRANG)

	gets(filename);
	
	while(exist(filename)==0)
	{
		printf("This file doesn't exist, create this new file as %s ?\n",filename);
		printf("Y/N: ");
		scanf("%c",&reput);
		if(toupper(reput)=='Y')
		{
			break;
		}
		else 
			if(toupper(reput)=='N')
			{
				fflush(stdin);
				printf("Enter file name: ");
				gets(filename);
			}
		
	}
	fflush(stdin);
		
	// a: ghi noi tiep
	// w: ghi de
	f = fopen(filename,"a");
	
	// Write file
	do{

	printf("Content: \n");
	fflush(stdin);
	// [^ => Except
	// alternative: gets(data);
	scanf("%[^\n]",data);
//	f = fopen(filename,"w");
	
	// Day du lieu vao file
	// alternative: fputs(data,f);
	fprintf(f,"\n%s",data);
	fflush(stdin);
	printf("Press Enter to input another content in the file. Press ESC to complete your input.\n");
	key=getch();
	if(key!=27){
		fprintf(f,"\n",data);
	}
	} while(key!=27);
	
	fclose(f);
	
	f=fopen(filename,"r");
	fread(data,100,1,f);
	printf("The cotent: ");
		printf("%s",&data);
	fclose(f);
//	gets(content);	
//	fwrite(content ,1,strlen(content), f );
//	fclose(f);	
//	
//	// Read file
//	f=fopen(filename,"r");
//	fread(data,50,1,f);
//	printf("File content: %s\n",&data);
//	fclose(f);
//	
//	printf("Press Enter to do another file, ESC to exist.");
//	fflush(stdin);	
//	key=getch();
//	}
//	while(key!=27);
	return 0;
	
}
