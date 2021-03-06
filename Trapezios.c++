#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct poli{
   float coenf;
   float expoe;
   int tam;
}poli;

typedef struct inter{
    float a;
    float b;
}inter;

typedef struct func{
    float fx;
    
}func;
void alocaPoli(poli **nomio, int grau);
void alocaInter(inter **valo);
void alocaFunc(func **ao,int n);
float calculo(float pulo,poli *nomio);
float calculoITR(func *ao, float h,int n);

int main(){
    float aux,h, printas;
    int op=1,op2=1,grau,i,j,n;

    poli *nomio;
    inter *valo;
    func *ao; 

    while (op!=0){   

        printf("Digite o Grau do Polinomio\n");
        scanf("%d",&grau);
		
		alocaPoli(&nomio,grau);
        alocaInter(&valo);

        for(i=grau;i>=0;i--){

            printf("Digite o valor do coeficiente com valor do expoente %i:  \n",i);
            scanf("%f",&(nomio+i)->coenf);
            (nomio+i)->expoe=i;
            (nomio+i)->tam=grau;

        }

        printf("Digite o intervalo (valores entre virgula por favor): \n");
        scanf("%f,%f",&valo->a,&valo->b);

        //Faz a troca caso A seja maior que B

        if(valo->a>valo->b){

            aux=valo->b;
            valo->b=valo->a;
            valo->a=aux;

        }

		op2 = 1;
        while (op2!=0){
    
            printf("Digite a quantidade de trapezios: \n");
            scanf("%i",&n);

			alocaFunc(&ao,n);
          
           
            //Calcula o valor de H

            h=((valo->b-valo->a)/n);
        
             printf(" Valor X | Valor de F(X)\n");

            for(j=0;j<=n;j++){

                (ao+j)->fx=calculo(h*j+valo->a,nomio);

                printf(" %.1f | %.4f\n",h*j+valo->a,(ao+j)->fx);

            }

            printas=calculoITR(ao,h,n);

            printf("ITR = %.4f\n",printas);

            printf("Deseja alterar as divisoes do trapezio? 1 = SIM | 0 = NAO\n");

            scanf("%i",&op2);
        }
    
        printf("Deseja Calcular outro trapezio? 1 = SIM | 0 = NAO\n");

        scanf("%i",&op);

    }

}


//Calcula os valores de F(X)

float calculo(float pulo,poli *nomio){

    int i;

    float resultado=0;
    float helper;
    
    helper = resultado;

    for(i=nomio->tam;i>=0;i--){

        resultado+=(nomio+i)->coenf*(pow(pulo,(nomio+i)->expoe));

    }
    
    return (resultado);
}

//Calcula o valor de ITR

float calculoITR(func *ao, float h,int n){
    int i;

    float resul,cont;

    for (i=1;i<n;i++){

        cont=cont+(ao+i)->fx;
    }

    resul=((ao+0)->fx+(ao+n)->fx+(2*cont))*(h/2);
    
return resul;

}


void alocaPoli(poli **nomio, int grau)
{
	if((*nomio = (poli *)malloc( grau*sizeof(poli)))==NULL){
        printf("\nErro na alocacao. O programa sera encerrado!\n");
        exit(1);
	}
	
}

void alocaInter(inter **valo)
{
	if((*valo = (inter *)malloc(sizeof(inter)))==NULL){
        printf("\nErro na alocacao. O programa sera encerrado!\n");
        exit(1);
	}
	
}

void alocaFunc(func **ao,int n)
{
	if((*ao = (func *)malloc(n*sizeof(func)))==NULL){
        printf("\nErro na alocacao. O programa sera encerrado!\n");
        exit(1);
	}
	
}
