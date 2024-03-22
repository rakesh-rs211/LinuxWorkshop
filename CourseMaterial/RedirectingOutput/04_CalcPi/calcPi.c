#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv){
        int N;
	double sumPI=0,X, delX;
	if(argc==1){ // No arguments set to default values
		fprintf(stderr,"No arguments were entered defaulting to N=10000\n");
		N = 10000;	
	}
	else if(argc==2){
		N = atoi(argv[1]);	
	}
	else{
		fprintf(stderr,"More than two arguments are entered defaulting to N=10000\n");
	}
	delX = 1.0/((double)N);
	for(int i=0;i<N;i++){
		X = (i+0.5)*delX;
		sumPI += (4.0*delX)/(1.0+X*X);
	}
	fprintf(stdout,"The value of PI is: %6.4lf \n",sumPI);
	return 0;
}
