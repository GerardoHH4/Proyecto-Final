// PROYECTO FINAL
#include <iostream>
using namespace std;

int CalcularDias(int mes, int a);
bool Bisiesto(int a);
int zeller(int ano, int mes, int dia);

int main(){
	
	cout<<"Ano : ";
	int a;
	cin>>a;
	string m[]  =  {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiempre", "Octubre","Noviembre", "Diciembre"};	
	
	for(int mes=1 ; mes<=12 ; mes++){
		cout<<endl;
		cout<<"Mes : "<<m[mes-1]<<endl;
		cout<<"Dom Lun Mar Mie Jue Vie Sab"<<endl;
		int x = zeller(a, mes, 1);
		for(int i = 0 ; i < x ; i ++){
			cout<<"    "; 
		}
		
		int dias_mes_actual = CalcularDias(mes, a);
		for(int dia=1 ; dia <= dias_mes_actual ; dia++){
		   if(dia < 10) cout<<dia<<"   ";
		   else cout<<dia<<"  ";
		   x++;
		   if(x % 7 == 0) cout<<endl;
			
		}
		cout<<endl;
		
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
