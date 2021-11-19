// PROYECTO FINAL
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int CalcularDias(int mes, int a);
bool Bisiesto(int a);
int zeller(int ano, int mes, int dia);

int main(){

	printf("Ano : "); // Año en formato AAAA
	int a;
	scanf("%i",&a);
	printf("Mes : "); // Mes en formato númerico (1-12)
	int b;
	scanf("%i",&b);
	char *m[]  =  {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiempre", "Octubre","Noviembre", "Diciembre"};
	int c;
	if(b<1 || b>12){
		b=1;
		c=12;
	} else{
		c=b;
	}
	for(int mes=b ; mes<=c ; mes++){
		printf("\n");
		printf("Mes : %s\n",m[mes-1]);
		printf("Dom Lun Mar Mie Jue Vie Sab \n");
		int x = zeller(a, mes, 1);
		for(int i = 0 ; i < x ; i ++){
			printf("    ");
		}

		int dias_mes_actual = CalcularDias(mes, a);
		for(int dia=1 ; dia <= dias_mes_actual ; dia++){
		   if(dia < 10) {
		   printf("%i   ", dia);
		   }
		   else {
		   	printf("%i  ",dia);
		   }
		   x++;
		   if(x % 7 == 0) {
		   	printf("\n");
		   };

		}
		printf("\n");

	}


	return 0;

}

int CalcularDias(int mes, int a) {
	if(mes == 1 || mes == 3 || mes == 5 || mes == 7|| mes == 8|| mes == 10 || mes == 12)
	   return 31;

	if(mes ==2) {

	   if( Bisiesto(a)  == true) return 29;
	   else return 28;

		}
	return 30;

}

bool Bisiesto(int a){
    if(a%4 != 0) return false;
    else if(a%100 != 0) return true;
    else if(a%400 != 0) return false;
    return true;

}

int zeller(int ano, int mes, int dia){
         //Dom 0,  Lun 1, Mart 2, Mier 3, Juev 4, Vier 5, Sab 6

    int a = (14-mes)/12;
    int y = ano - a;
    int m = mes + 12*a - 2;

    int d = (dia + y+ y/4 - y/100 + y/400 + (31*m)/12)%7;
    return d;
}
