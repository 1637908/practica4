#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//int ignorar(){
//	if (pointer in){ escriure les 4 condicions
	
	
//}

void read(int row, int col, char *filename){
	FILE *fitxer;
	fitxer = open("CAVideos.csv", 0666)
	
char *getField( int fn, char line[], char field[] ){
	int i;
	char *p, aux[256];
	
	strcpy(aux, line );
	p = strtok( aux, "," );
	for ( i = 0; i < fn; i++ ) p = strtok( NULL, "," );
	return strcpy(field,p);
}

//int read(int fitxer, void *buffer, int 5){
	//while(fitxer != EOF){
		//printf(

int main(int argc, char** argv){
	int fitxer;
	//FILE *fitxer 
	fitxer = open ("CAvideos.csv", 0666 );
	
}
