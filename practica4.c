#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *getField( int fn, char line[], char field[] ){
	int i;
	char *p, aux[10000];
	
	strcpy(aux, line );
	p = strtok( aux, "," );
	for ( i = 0; i < fn; i++ ) p = strtok( NULL, "," );
	return strcpy(field,p);
}


int main(int argc, char** argv){
	int fitxer,i=0, col=1,pointer;
	int total_linies=0;
	int top_l=0, top_dl=0;
	int top1=0, top2=0, top3=0, aux=0, aux1=0,aux2=0;
	float v=0,l=0,dl=0; //visualizaciones, likes, dislikes
	char c;
	char sortida1[10000],sortida2[10000],sortida3[10000],sortida4[10000]; //a la funció getField l'array sortida es guarda el camp que volem
	char views[1000], likes[1000], dislikes[1000];
	char buf[10000];//buf és un guardem la sortida
	char topl_buf[10000],topdl_buf[10000];
	char top_buf1[10000],top_buf2[10000],top_buf3[10000];
	
	fitxer = open("CAvideos.csv", 0666 );

	while ((pointer = read(fitxer, &c, 1)) > 0){

		if(c != '\n'){
			if (c == ','){
				col++;	
				if (col != 12 && col <= 15){
					buf[i] = c;
					i++;
				}
			}
			else{
				if (col != 12 && col <= 15){
					buf[i] = c;
					i++;
				}
			}
		
		}
		else{
				buf[i]='\n'; //per saber final línia, bno 0 = buit
				getField(11, buf, sortida1);
				getField(12, buf, sortida2);
				getField(13, buf, sortida3);
				getField(4, buf, sortida4);
				if ((((strcmp(sortida1, "True")==0 || strcmp(sortida1,"False")==0)) || ((strcmp(sortida2, "True"))==1) || ((strcmp(sortida3, "True"))==1)) && (strcmp(sortida4, "1")==0)){

					//printf("%s", buf);	
					
					total_linies++;
				
					getField(7, buf, views);
					v += atoi(views);
					if (atoi(views)>top1){
						aux = top2;
						top3 = aux;
						aux1 = top1;
						top2 = aux1;
						top1 = atoi(views);
						
						for (int i=0; i<sizeof(buf); i++){
							top_buf1[i] = buf[i];	
						}
						
					}
					else{
						if(top2<atoi(views)){
							aux2 = top2;
							top3= aux2;
							top2=atoi(views);
							
							for (int i=0; i<sizeof(buf); i++){
								top_buf2[i] = buf[i];	
							}
						}
						else{
							if(top3<atoi(views)){
								top3 = atoi(views);
								
								for (int i=0; i<sizeof(buf); i++){
									top_buf3[i] = buf[i];	
								}
					
							}
						}
					}
							
					getField(8, buf, likes);
					l += atoi(likes);
					if(atoi(likes)>top_l){
						top_l = atoi(likes);
						for (int i=0; i<sizeof(buf); i++){
							topl_buf[i] = buf[i];	
						}
					}
					getField(9, buf, dislikes);
					dl += atoi(dislikes);
					if(atoi(dislikes)>top_dl){
						top_dl = atoi(dislikes);
						for (int i=0; i<sizeof(buf); i++){
							topdl_buf[i] = buf[i];
						}
					}
				}
			
			memset(buf, 0, sizeof(buf)); //reinicialitzar buf
			i = 0;
			col = 1;
			//}
		}
		
	}
	const char *mit1= "La mitjana de visualitzacions és:";
	v = v/total_linies;
	char vv[100];
	gcvt(v, 13, vv);
	const char *mit2= "La mitjana de likes és:";
	l = l/total_linies;
	char ll[100];
	gcvt(l, 13, ll);
	const char *mit3= "La mitjana de dislikes és:";
	dl = dl/total_linies;
	char dldl[100];
	gcvt(dl, 13, dldl);
	
	//printf("visualitzacions: %f, likes: %f,dislikes: %f", v,l,dl);
	
	const char *mit4= "El video amb més likes és:";
	char titol[10000], publish_time[1000], num_v[100], lk[100], dlk[100];
	getField(2, topl_buf, titol);
	getField(5, topl_buf, publish_time);
	getField(7, topl_buf, num_v);
	getField(8, topl_buf, lk);
	getField(9, topl_buf, dlk);
	
	const char *mit5= "El video amb més dislikes és:";
	char titol1[10000], publish_time1[1000], num_v1[100], lk1[100], dlk1[100];
	getField(2, topdl_buf, titol1);
	getField(5, topdl_buf, publish_time1);
	getField(7, topdl_buf, num_v1);
	getField(8, topdl_buf, lk1);
	getField(9, topdl_buf, dlk1);
	
	
	//printf("Top likes: %s, %s, %s,%s,%s", titol, publish_time, num_v, lk,dlk);
	//printf("Top dislikes: %s, %s, %s, %s,%s", titol1, publish_time1, num_v1, lk1,dlk1);
	
	const char *mit6= "El vídeo amb més visualitzacions és:";
	char t1[10000], v1[5000];
	getField(2, top_buf1, t1);
	getField(7, top_buf1, v1);
	const char *mit7= "El segon vídeo amb més visualitzacions és:";
	char t2[10000], v2[5000];
	getField(2, top_buf2, t2); 
	getField(7, top_buf2, v2);
	const char *mit8= "El tercer vídeo amb més visualitzacions és:";
	char t3[10000], v3[5000];
	getField(2, top_buf3, t3); 
	getField(7, top_buf3, v3);
	
	//printf("Top 1: %s, %s", t1,v1);
	//printf("Top 2: %s, %s", t2,v2);
	//printf("Top 3: %s, %s", t3,v3);
	
	int resultat;
	resultat=creat("GlobalOutput.txt", 0666);
	const char *y = "\n";
	const char *z = " ";
	
	write(resultat,mit1,strlen(mit1));
	write(resultat,y,strlen(y));
	write(resultat,vv,strlen(vv));
	write(resultat,y,strlen(y));
	write(resultat,mit2,strlen(mit2));
	write(resultat,y,strlen(y));
	write(resultat,ll, strlen(ll));
	write(resultat,y,strlen(y));
	write(resultat,mit3,strlen(mit3));
	write(resultat,y,strlen(y));
	write(resultat,dldl,strlen(dldl));
	write(resultat,y,strlen(y));
	
	write(resultat,mit6,strlen(mit6));
	write(resultat,y,strlen(y));
	write(resultat,t1,strlen(t1));
	write(resultat,z,strlen(z));
	write(resultat,v1,strlen(v1));
	write(resultat,y,strlen(y));
	
	write(resultat,mit7,strlen(mit7));
	write(resultat,y,strlen(y));
	write(resultat,t2,strlen(t2));
	write(resultat,z,strlen(z));
	write(resultat,v2,strlen(v2));
	write(resultat,y,strlen(y));
	
	write(resultat,mit8,strlen(mit8));
	write(resultat,y,strlen(y));
	write(resultat,t3,strlen(t3));
	write(resultat,z,strlen(z));
	write(resultat,v3,strlen(v3));
	write(resultat,y,strlen(y));
	
	write(resultat,mit4,strlen(mit4));
	write(resultat,y,strlen(y));
	write(resultat, titol, strlen(titol));
	write(resultat,z,strlen(z));
	write(resultat,publish_time,strlen(publish_time));
	write(resultat,z,strlen(z));
	write(resultat,num_v,strlen(num_v));
	write(resultat,z,strlen(z));
	write(resultat,lk,strlen(lk));
	write(resultat,z,strlen(z));
	write(resultat,dlk,strlen(dlk));
	write(resultat,y,strlen(y));
	
	write(resultat,mit5,strlen(mit5));
	write(resultat,y,strlen(y));
	write(resultat, titol1, strlen(titol1));
	write(resultat,z,strlen(z));
	write(resultat,publish_time1,strlen(publish_time1));
	write(resultat,z,strlen(z));
	write(resultat,num_v1,strlen(num_v1));
	write(resultat,z,strlen(z));
	write(resultat,lk1,strlen(lk1));
	write(resultat,z,strlen(z));
	write(resultat,dlk1,strlen(dlk1));
	
	
	close(resultat);
							
}
