#include <stdio.h>
#include <math.h>

void IQA();
double OD();//oxigenio
double CF();//coliformes
double pH();//pot.hidrogenionico
double DBO();//dbos
double NIT();//nitrogenio
double FOS();//fosforo
double TUR();//turbidez
double RT();//residuos

int main(void) {
	double a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, t=0;

	
    printf("Digite os valores respectivamente de: \nOxigênio mg/L\nColiformes termotolerantes NMP/100 mL\nPotencial hidrogeniônico \nDemanda bioquímica de oxigênio DBO5,20 (mg/L)\nTemperatura da água(oC)\nNitrogênio total (mg/L)\nFósforo total (mg/L)\nTurbidez (NTU)\nResíduo total (mg/L)");

    
    
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	scanf("%lf", &d);
	scanf("%lf", &t);
	scanf("%lf", &e);
	scanf("%lf", &f);
	scanf("%lf", &g);
	scanf("%lf", &h);
	
	IQA(OD(a, t),CF(b),pH(c),DBO(d), t ,NIT(e),FOS(f),TUR(g),RT(h));

    return 0;
}
void IQA(double a,double b,double c,double d,double t,double e,double f,double g,double h){
    
    double iqa;
    int iqa2;

    iqa=pow(a,0.17)*pow(b,0.15)*pow(c,0.12)*pow(d,0.10)*pow(e,0.10)*pow(93,0.10)*pow(f,0.10)*pow(g,0.08)*pow(h,0.08);
    iqa2=iqa;
    printf("IQA = %d\n", iqa2);
    
   if(iqa>90 && iqa<=100){
		printf("O índice de qualidade da água é excelente.");
	}else if(iqa<=90 && iqa>70){
		printf("O índice de qualidade da água é bom.");		
	}else if(iqa<=70 && iqa>50 ){
		printf("O índice de qualidade da água é médio.");		
	}else if(iqa<=50 && iqa>25){
		printf("O índice de qualidade da água é ruim.");		
	}else if(iqa>=0 && iqa<=25){
		printf("O índice de qualidade da água é muito ruim.");		
	}
	printf("\n");
}
double OD(double o, double t){
	
    double q, pi, e, c, ccl, h, od;

    
    pi=3.14159265;
    e=2.71828183;
    h=852;
    ccl=9.09;
    c=(14.2*pow(e,-0.0212*t) - (0.0016*ccl*pow(e,-0.0264*t)))*(0.994 - (0.0001042*h));
    od=o/c*100;
    if(od<=100){
        double y1,y2,y3,y4,y5;
        y1=0.01396*od+ 0.0873;
        y2=(pi/56)*(od- 27);
        y3=(pi/85)-(od- 15);
        y4=(od- 65)/10;
        y5=(65-od)/10;
        q=(100*pow(sin(y1),2) -((2.5*sin(y2)- 0.018*od + 6.86)*sin(y3)) + 12/(pow(e,y4)+pow(e,y5)));
    }else if(od<=140){
        q=- 0.00777142857142832*pow(od,2) + 1.27854285714278*od + 49.8817148572;
    }else{
        q=47.0;
    }
    
    return q;
}


double CF(double coliformes){

    double qs;

	if (coliformes <= pow(10,5)){
    	qs = 98.24034 - 34.7145 * log10(coliformes) + 2.614267 * pow(log10(coliformes),2) + 0.107821 * pow(log10(coliformes),3);
	} else {
		qs=3;
	}
	return (qs);
}

double pH(double ph) {

	double qs=0;

	if(ph <= 2.0){
    	qs = 2;
	} else if (ph > 2.0 && ph <= 6.9){
    	qs = -37.1085 + 41.91277 * ph  - 15.7043 * (ph*ph) + 2.417486 * (ph*ph*ph) - 0.091252 * (ph*ph*ph*ph);
	} else if(ph > 6.9 && ph <= 7.1 ){
		qs = -4.69365 - 21.4593 * ph - 68.4561 * (ph*ph) + 21.638886 * (ph*ph*ph) - 1.59165 * (ph*ph*ph*ph);
    } else if(ph > 7.1 && ph <= 12){
    	qs = -7698.19 + 3262.031 *  ph - 499.494 * (ph*ph) + 33.1551 * (ph*ph*ph) - 0.810613 * (ph*ph*ph*ph); 
	} else if(ph >= 12.0){
    	qs = 3.0;
	}

	return qs;
}

double DBO(double calculo){
	double qs;
	
	if (calculo <=30.0){
		qs = 100.9571 - (10.7121 * (calculo)) + (0.49544 * pow(calculo,2)) - (0.011167 * pow(calculo,3)) + (0.0001 * pow(calculo,4));
	} else {
    	qs=2;
	}

	return (qs);
}

double NIT(double no3) {

	double qs=0;

	if (no3 <= 10){
	    qs = -5.1 * no3 + 100.17;
	}else if(no3 > 10 && no3 <=60 ){
	    qs = -22.853 * log(no3) + 101.18;
	}else if(no3 > 60 && no3 <=90){
		qs = 10000000000 * pow(no3, -5.1161);
	}else if(no3 > 90){
	    qs=1.0;
	}
	
	return qs;
}

double FOS(double po4) {

	double qs=0;

	if(po4 <= 10){
    	qs = 79.7 * pow((po4+0.821), -1.15);
	} else {
    	qs = 5.0;
	}

	return qs;
}

double TUR(double turb){
	
	double rtu;
	
	if(turb<=100){
		rtu= 97.34* pow(2.71828183, (-0.01139*turb+-0.04917*sqrt(turb)));
	}else if(turb>100){
		rtu=5.0;
	}
	return rtu;
	
}

double RT(double r){
    double p;
    double e = 2.71828183;
    
    if(r<=500){
        p=133.17*pow(e,(-0.0027*r)) - 53.17*pow(e,(-0.0141*r))+((-6.2*pow(e,(-0.00462*r)))*sin((0.0146*r)));
    }else{
        p=30.0;
    }
    return p;
}
