#include<stdio.h>
#include<stdlib.h>

#include<string.h>


#define TF 1000
#define TC 1000
#define T_BUFER 1000

//Declaracion de matrices

float M_1 [TF][TC];
float M_2 [TF][TC];
float M_3 [TF][TC];

void read_m(char*, float [T_BUFER][T_BUFER],int*,int*);
int operacion(char* );
void suma( float [TF][TC], float [TF][TC],float [TF][TC], int , int );
void resta( float [TF][TC], float [TF][TC],float [TF][TC], int , int );
void transp(float matri_R[TF][TC],int fil, int col);
void Muestra_Matriz (float [TF][TC], int , int );
//void Guardar(char dir[T_BUFER], float m[T_BUFER][T_BUFER], int f, int c);

int main (int argc, char* argv[])//Funcion principal
{
	int f=0,c=0,f1=0,c1=0, in, nop;
	char  *arg2, *arg3,*argop, *argw, *argdir;
	printf("\n tienes %d argumentos\n", argc);
	printf("\n la matriz 1 esta en %s\n",argv[1] );
	printf("\n la matriz 2 esta en %s\n",argv[2] );
	arg2=argv[1]; //Si las matrices son ingesadas por archivo csv
	arg3=argv[2];
	read_m(arg2,M_1,&f,&c);
	read_m(arg3,M_2,&f1,&c1);
				
			    
	argop=argv[3];
	nop=operacion(argop);
		    	
	//argw=argv[4];
	//argdir=argv[5];
	switch(nop){
		case 1:	suma(M_1,M_2,M_3,f,c);  //Si se elige la operacion suma
				Muestra_Matriz(M_3,f,c);
				
		    	break;
		case 2:	resta(M_1,M_2,M_3,f,c); //Si se elige la operacio resta 
				Muestra_Matriz(M_3,f,c);
				
			    break;
		case 3: Muestra_Matriz(M_3,f,c); //trasnpuesta
				transp(M_1,f,c);
				transp(M_2,f,c);
			    break;
		case 4:printf("\nVersion 1.0\n Creada por Juan Pablo Valencia y Jose Leon\n"); //bversion 
				break;
		case 5: printf("bienvenido ingrese los sigientes caracteres dependiendo lo que quiera que realice el programa\ningrese (-v) si decea ver la versión y los autores del programa\ningrese (-t) muestra la matriz transpuesta\ningrese (-a) para sumar dos matrices \ningrese (-r) para restar las dos matrices\ningrese (-w) para guardar el resultado de la operación en un archivo CSV\n");
				break;
		case 6: printf("La opcion %s no existe \n",argop);
                break; 
		
		}
//if(strcmp(argw,"-w")==0){
	//printf("\nse guarda\n");
//Guardar(argdir,M_3,f,c);}

	
	
}
void read_m(char* dir, float m2[T_BUFER][T_BUFER], int* nf,int* nc){
	
   char buffer[T_BUFER], b[T_BUFER];
   FILE  *fp;
   char m1[T_BUFER][T_BUFER];
   //float m2[T_BUFER][T_BUFER];
   int l,c,c1,cf=0,cc=0,cf1=0,cc1=0, c2=0;
 
  fp= fopen(dir, "r"); // Abrir en modo read
  // Si es NULL, entonces no existe, o no se pudo abrir
  if (!fp) {
    printf("¡No se pudo abrir el archivo %s!", dir);
    //return EXIT_FAILURE;
	}
 
  l = fread(buffer, sizeof(char), sizeof(buffer), fp);
  printf("Nunero de bytes leidos: %d",l);
  buffer[l]='\0';
  printf("\n%s \n", buffer);

  

  
  
  for(c=0;c<l;c++){
	  /**if (buffer[c] != ';')
	  {
		  m1[cf][cc]=buffer[c];
		  cf++;
		 
	
		  if (buffer[c] == '\r'){
		  cf++;
		  *nc=(*nc)+1;
		  cc = 0;
		}
	  
	  }
	  else if (buffer[c]==';')
	  {	
		if(buffer[c] != '\r'){
		  cc++;
		  m1[cf][cc]=buffer[c];
			*nf=(*nf+1);}
	  }
	for(c1=0;c1<cf;c1++){
  	
  	if(m1[c1][0]!='\r'){
  		m2[cf1][cc1]=atof(m1[c2]);	
  		cc1++;
  		
	  } else{
  	    cf1++;
  	    cc1=0;
  	    
		}
	c2++;
	
	}
  } 
	printf("filas %d", cf);
	  printf("columna %d", cc);  
	  */
  	if(buffer[c]!=';'){
  		m1[cf][cc]=buffer[c];
		 cf++;  
		 if(buffer[c]=='/'){
			 m1[cf][cc]='/';
			 *nc=(*nc)-1;
		 }
 	} else if(buffer[c]==';'){
    	m1[cf][cc]='\0';
    	cc++;
    	cc=0;
    	*nc=(*nc)+1;
		}
	
	}
char* pend;
for(c1=0;c1<cf;c1++){
  	
  	if(m1[c1][0]!='/'){
  		m2[cf1][cc1]=atof(m1[c2]);	
  		cc1++;
  		
	  } else{
  	    cf1++;
  	    cc1=0;
  	    *nf=(*nf)+1;
		}
	c2++;
	
	}
	
  *nf=(*nf)+1;
  *nc=(*nc)/(*nf);

}
int operacion(char* op){
	int r;
	if(strcmp(op,"-a")==0)
			r=1;
		else if(strcmp(op,"-r")==0)
			r=2;
		else
			if (strcmp(op,"-t")==0) 
				r=3;
			else if (strcmp(op,"-v")==0)
				
				r=4;
			if (strcmp(op,"--help")==0)
				
				r=5;
	return r;

}
//---------------------------------------------------------------------------------Funcion suma

void suma( float m1[TF][TC], float m2[TF][TC],float m3[TF][TC], int fil, int col){
	int cf, cc;
	
		for(cf=0;cf<fil;cf++)
			for(cc=0;cc<col;cc++)
				m3[cf][cc]=m2[cf][cc]+m1[cf][cc];
				
				
	
}

//----------------------------------------------------------------------------------Función resta
void resta( float m1[TF][TC], float m2[TF][TC],float m3[TF][TC], int fil, int col){
	int cf, cc;
	
		for(cf=0;cf<fil;cf++)
			for(cc=0;cc<col;cc++)
				m3[cf][cc]=m2[cf][cc]-m1[cf][cc];
				
				
	
}
//-------------------------------------------------------------------------------------------------------


void Muestra_Matriz (float Mat_R[TF][TC], int fil, int col) //Función que muestra una matriz.
{ 
	int cont1, cont2; 
	printf("\n\n");
    for (cont1 = 0; cont1 < fil; cont1++)
	{
    	for (cont2 = 0; cont2 < col; cont2++)
		{
    		printf("%.4f ",Mat_R[cont1][cont2]);	
			}
   		printf("\n\n\t\r");
	}
}

/**void Guardar(char dir[T_BUFER], float m[T_BUFER][T_BUFER], int f, int c){
	// FILE* fp;
	 // int ct=c*f, ct1,ct2,ct3;
	  //float g;
	  //char Ms[100]; 	 
	 
	 
//	int n=4;
	 
	//for(ct3=0;ct3<f;ct3++){
		//for(ct2=0;ct2<c;ct2++){
			//for(ct1=0;ct1<ct;ct1++){
				
				g=m[ct3][ct2];
			     atol(m[ct3][ct2], Ms[ct+1],n );
				
				
			}
	//	}
    //}
     
 
	//fp=fopen(dir,"w");			
	//fwrite(Ms,T_BUFER,1,fp);
	//fclose(fp);
//}*/

void transp(float matri_R[TF][TC],int fil, int col) //coge la matriz y la convierte en la transpuesta
{
 int cont1, cont2;
 printf("\n\t");
 
 for (cont2 = 0; cont2 < fil; cont2++)
  {
   for (cont1 = 0; cont1 < col; cont1++)
    {
     printf("%.4f ",matri_R[cont1][cont2]);  
    }
    printf("\n\t");
  }
 printf("\n\t");
}