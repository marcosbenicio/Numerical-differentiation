#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define dF  -4.0896256947402482534862622467891
#define x   3.0
#define N    8   

int main()
{
   int n;
   double Fx,Fx1,dFn,dx,erro;
   
   FILE *fpm;

   fpm=fopen("derivada_metodo_euler.txt","w");
   if(!fpm) exit(0);
   
   fprintf(fpm,"#dx\t\t\t\t\t#x\t\t\t\t\t\t#dF\t\t\t\t\t\t\t#dFn-dF\t\t\t\t\t\t\t#erroporc\t\t\t\t\t\t\t\t#erro\n");   
   
   for(n=0;n<=N;n++){
     dx=pow(10,-(8-n)); 
     
     Fx=(sin(pow(x,2))*exp((x)/3))/sqrt((pow(x,2))+4);
     
     Fx1=(sin(pow(x+dx,2))*exp((x+dx)/3))/sqrt(pow(x+dx,2)+4);
      
     dFn=(Fx1-Fx)/dx;
     
     erro=fabs(fabs(dF)-fabs(dFn))*100.0/fabs(dF);
     
     fprintf(fpm,"%.8f\t\t\t%lf\t\t\t\t%.12f\t\t\t%.12e\t\t\t\t\t%.12f\t\t\t\t%.12e\n",dx,x,dFn,fabs(fabs(dFn)-fabs(dF)),erro,erro/100.00);

   }
   fclose(fpm);
   
}   





