#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define h      0.05
#define time   10.0
 

int main()
{
   
   int l,t,N;
   
   double y,yn,yn_1,T;
      
   double f1,f2,f3,f4;
   
   double Y1,Y2,Y3,Y4;
   
   double X1,X2;
   
   double k1,k2,k3,k4;   
   
   FILE *fpm,*fpm2;
   
   N=time/h;
  
   fpm=fopen("integracao_2mrk_dt005.txt","w");
   if(!fpm) exit(0);   
   
   fpm2=fopen("integracao_4mrk_dt005.txt","w");
   if(!fpm2) exit(0);
   
   fprintf(fpm,"#tempo\t\t\t\t\t\t#2ºordem\t\t\t\t#erro\n");
   fprintf(fpm2,"#tempo\t\t\t\t\t\t#4ºordem\t\t\t\t#erro\n"); 
//-----------------------2º ordem--------------------------------------------------------------- 
   l=1;
   T=0.0;
   yn=1.0;
   fprintf(fpm,"%lf\t\t\t\t\t%.12f\t\t\t\t0\n",T,yn);
   for(t=0;t<N;t++){   
      T=t*h; //valores de cada loop para o eixo x

     
      y=exp((t+1)*h)+exp((t+1)*h/2)*sin(5*(t+1)*h); //solução analitica
      
      
      Y1=yn;
      f1=Y1-exp(T/2.0)*sin(5*T)/2.0 + 5*exp(T/2.0)*cos(5*T) ; //f(Xn,Yn)
      k1=h*f1;//K1=hf(Xn,Yn)
      
      X1=T+h/2.0;//Xn de k2
      Y2=yn+k1/2.0;//Yn de k2
      f2=Y2-exp(X1/2.0)*sin(5*X1)/2.0 + 5*exp(X1/2.0)*cos(5*X1) ; //f(Xn+h/2,Yn+K1/2)
      k2=h*f2;//k2=hf(Xn+h/2,Yn+K1/2)
      
      yn_1=yn+k2;
      
      if((t+1)*h==0.1*l){
        fprintf(fpm,"%lf\t\t\t\t\t%.12f\t\t\t\t%.12f\n",(t+1)*h,yn_1,fabs(fabs(y)-fabs(yn_1)));
        l++;
      }
      
      yn=yn_1;
   }   
      
//-----------------------4º ordem---------------------------------------------------------------
   l=1;
   T=0.0;
   yn=1.0;
   fprintf(fpm2,"%lf\t\t\t\t\t%.12f\t\t\t\t0\n",T,yn);
   for(t=0;t<N;t++){             
      T=t*h; //valores de cada loop para o eixo x
      
      
      y=exp((t+1)*h)+exp((t+1)*h/2)*sin(5*(t+1)*h); //solução analitica
      
      X1=T+h/2.00;
      
      Y1=yn;
      f1=Y1-exp(T/2.0)*sin(5*T)/2.00 + 5*exp(T/2.0)*cos(5*T) ; //f(Xn,Yn)
      k1=h*f1;//K1=hf(Xn,Yn)
       
       
      
      Y2=yn+k1/2.0;
      f2=Y2-exp(X1/2.0)*sin(5*X1)/2.00+ 5*exp(X1/2.0)*cos(5*X1) ; //f(Xn+h/2,Yn+K1/2)
      k2=h*f2;//k2=hf(Xn+h/2,Yn+K1/2)
      
      
      X2=T+h;
      
      Y3=yn+k2/2.0;
      f3=Y3-exp(X1/2.0)*sin(5*X1)/2.00 + 5*exp(X1/2.0)*cos(5*X1) ; //f(Xn+h/2,Yn+K2/2)
      k3=h*f3;//k3=hf(Xn+h/2,Yn+K1/2)
      
      Y4=yn+k3;
      f4=Y4-exp(X2/2.0)*sin(5*X2)/2.00 + 5*exp(X2/2.0)*cos(5*X2) ; //f(Xn+h,Yn+K3)
      k4=h*f4;//k3=hf(Xn+h,Yn+K3)
      
      
      yn_1=yn+k1/6.00+k2/3.00+k3/3.00+k4/6.00;      
      
      if((t+1)*h==0.1*l){
        fprintf(fpm2,"%lf\t\t\t\t\t%.12f\t\t\t\t%.12f\n",(t+1)*h,yn_1,fabs(fabs(y)-fabs(yn_1)));
        l++;
      }

      yn=yn_1;
   }
//---------------------------------------------------------------------------------------------------      
 
   fclose(fpm);
   fclose(fpm2);
   
}   

