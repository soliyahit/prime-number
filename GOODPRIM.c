#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef enum Bool{false,true}Bool;

Bool primeCheck(int num){
	int sqRoot,i;
	if(num==0 || num ==1)
		return false;
	if(num==2)
		return true;
	if(num%2==0)
		return false;
	sqRoot=sqrt(num);
	for(i=3; i<sqRoot; i++){
		if(num%i==0){
			return false;
		}
	}

	return true;
}

Bool goodPrime(int primeSq,int primeMul){
	if(primeSq>=primeMul)
		return true;
	else
		return false;
}

Bool circularPrime(int num,short len){
	int i;
	if(primeCheck(num)==true){
		for(i=1; i<len; i++){
			num=swap(num,len);
			if(primeCheck(num)==false){
				return false;
			}
		}
	}
	else
		return false;

	return true;
}

int swap(int num,short len){
    int temp;
    if(len==1){
        return num;
    }
    temp = num%10;
    num /= 10;
    temp*=pow(10,len-1);

	return temp+num;
}

short digitLength(int num){
	int len=0;
	while(num>0){
		num/=10;
		len++;
	}

	return len;
}

void fileStore(int prime,char fileName[20]){
	FILE* file;
	file = fopen(fileName,"a");
	fprintf(file,"%5d",prime);
	fclose(file);
}

void main(){
	int i,primeSize=-1,goodPrimeNum[101],primeNum[183],goodPrimeSize=-1;
	short len;
	clrscr();

	//Store all Prime Numbers in array
	for(i=2; i<1000; i++){
		if(primeCheck(i)==true){
			primeSize++;
			//*primeNum = malloc((primeSize + 1) * sizeof(int));
			primeNum[primeSize]=i;
		}
	}

	printf("Good Prime Numbers\n");
	for(i=2; i<=primeSize; i++){
		if(goodPrime(primeNum[i]*primeNum[i],primeNum[i-1]*primeNum[i+1])==true){
			goodPrimeSize++;
			printf("%5d",primeNum[i]);
			goodPrimeNum[goodPrimeSize]=primeNum[i];
			fileStore(primeNum[i],"Gprime.txt");
		}
	}

	printf("\n\nGood Circular Prime Numbers\n");
	for(i=0; i<goodPrimeSize; i++){
		len=digitLength(goodPrimeNum[i]);
		if(circularPrime(goodPrimeNum[i],len)==true){
			printf("%5d",goodPrimeNum[i]);
			fileStore(goodPrimeNum[i],"Cprime.txt");
		}
	}
	//free(primeNum);
	getch();
}