#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bbtd(int* thing,int to){
	int val = 0;
	int base = 1;
	for (int i = 0; i < to; i++){
		val = val + thing[i] * base;
		base = base*2;
	}
	return val;
}

int btd(int num){
	int val = 0;
	int base = 1;
	while (num>0){
		val = val + num%10 * base;
		base = base*2;
		num = num/10;
	}
	return val;
}

void dtb(int num){
	int val = 0;
	int base = num;
	while (base !=0){
	val+=1;
	base = base/2;
	}
	val = val-1;
	while (val >= 0 ){
	int n = 0;
	n = (num & 1<<val)>>val;
	printf("%d",n);
	val = val-1;
	}
	printf("\n");
	return;
}

int math(char** argv,int *start){
	
	int t1 = 0;
	char c = 'a'; 
	argv[1] = argv[1]+1;
	sscanf(argv[1],"%c",&c);
	argv[1] = argv[1]+1;
	*start+=2;
	
	
	if (c == '0'){sscanf(argv[1],"%4d",&t1);}
	if (c == 'h'){sscanf(argv[1],"%4o",&t1);}
	if (c == 'x'){sscanf(argv[1],"%4x",&t1);}
	if (c == 'b'){sscanf(argv[1],"%4d",&t1);t1 = btd(t1);}
	argv[1] = argv[1]+4;	
	*start+=4;	
	argv[1] = argv[1]+1;
	sscanf(argv[1],"%c",&c);
	argv[1] = argv[1]+1;
	*start+=2;
	char * num;
	//printf("%d",t1);
	num = malloc(sizeof(int)*t1);
		for (int i = 0; i < t1; i++){
			char t2 = '0';
			sscanf(argv[1],"%1c",&t2);
			argv[1] = argv[1]+1;
			*start+=1;
				
			num[i] = t2;
		}
	if (c == '0'){t1 = strtol(num,NULL,10);}
	if (c == 'h'){t1 = strtol(num,NULL,8);}
	if (c == 'x'){t1 = strtol(num,NULL,16);}
	if (c == 'b'){t1 = strtol(num,NULL,2);}
	//printf("%d",t1);
	free(num);
	return t1;
}

int sub(char** argv,int *start){
	printf("\\S");
	int p = 0;
	sscanf(argv[1],"%4d",&p);
	argv[1] = argv[1]+4;
	*start+=4;
	
	
	int n1 = 0;
	int n2 = 0;
	int op = 0;
	
	while (p!=1001){
	if (p == 1010){n2 = sub(argv,*&start);if (op == 0){
					n1 = n1+n2;
					n2 = 0;
				}
				if (op == 1){
					n1 = n1-n2;
					n2 = 0;
				}
				if (op == 10){
					n1 = n1*n2;
					n2 = 0;
				}}
	if (p == 100){sscanf(argv[1],"%2d",&op); argv[1] = argv[1]+2;*start+=2;
			if (op==0){printf("/1");}
			if (op==1){printf("\\1");}
			if (op==10){printf("//1");}
		
	
	}
	else if (p==10){
			
			int bruh[10] = {0,0,0,0,0,0,0,0,0,0};
			int rev[100];
			int revc = 0;
			n1 = math(argv,*&start);
			while (n1!=0){		
				int g = n1%10;
				n1=n1/10;
				bruh[g] = bruh[g]+1;
				while (n1%10 == g){
					g = n1%10;
					n1=n1/10;
					bruh[g] = bruh[g]+1;
				}
				rev[revc] = g;
				rev[revc+1]= bruh[g];
				revc=revc+2;
				//printf("%d%d",bruh[g],g);
				bruh[g]=0;
			}
			
			for (int i = revc-1;i>=0;i--){
				printf("%d",rev[i]);
			}

			if (n1 != 0 && n2 !=0){
				if (op == 0){
					n1 = n1+n2;
					n2 = 0;
				}
				if (op == 1){
					n1 = n1-n2;
					n2 = 0;
				}
				if (op == 10){
					n1 = n1*n2;
					n2 = 0;
				}
			}
		}
	sscanf(argv[1],"%4d",&p);
	argv[1] = argv[1]+4;
	*start+=4;
	}
	printf("/S");
	return n1;
	
	
}


int main(int argc,  char * argv[argc + 1]){

	int stop = strlen(argv[1]);
	int start = 0;
	int p=0;
	int a = 0;
	char base = 'b';
	int n1= 0;
	int n2 = 0;
	int op = 0;
	
	printf("S");

	while (start<stop){
		
		sscanf(argv[1],"%4d",&p);
		argv[1] = argv[1]+4;
		start+=4;
	
		if (p == 1){
			
			argv[1] = argv[1]+1;
			sscanf(argv[1],"%1c",&base);
			argv[1] = argv[1]+1;
			start+=2;
			//if (base == '0'){printf("00%d\n",a);}
			//if (base == 'h'){printf("0h%o\n",a);}
			//if (base == 'x'){printf("0x%X\n",a);}
			//if (base == 'b'){printf("0b");dtb(a);} // fix this to make sure it prints in binary
			if (start !=4){printf("E");if (start<stop){printf("S");}}
			
			a = 0;
			n1 = 0;
			n2 = 0;
		}
		
		else if (p==10){
			int rev[100];
			int revc = 0;
			int bruh[10] = {0,0,0,0,0,0,0,0,0,0};
			n1 = math(argv,&start);
			while (n1!=0){		
				int g = n1%10;
				n1=n1/10;
				bruh[g] = bruh[g]+1;
				while (n1%10 == g){
					g = n1%10;
					n1=n1/10;
					bruh[g] = bruh[g]+1;
				}
				rev[revc] = g;
				rev[revc+1]= bruh[g];
				revc=revc+2;
				//printf("%d%d",bruh[g],g);
				bruh[g]=0;
			}
			for (int i = revc-1;i>=0;i--){
				printf("%d",rev[i]);
			}
			
			if (a<0){printf("NaN\n");a = 0; n1 = 0; n2 = 0;}
		}
		else if (p == 100){sscanf(argv[1],"%2d",&op); argv[1] = argv[1]+2;start+=2;
			if (op==0){printf("/1");}
			if (op==1){printf("\\1");}
			if (op==10){printf("//1");}
		
		}
		else if (p == 1000){printf("NaN\n");a = 0; n1 = 0; n2 = 0;argv[1] = argv[1]+4;start+=4;}
		else if (p == 1010){
			n2 = sub(argv,&start);
			if (op == 0){
					a = n1+n2;
					n1 = a;
					n2 = 0;
				}
				if (op == 1){
					a = n1-n2;
					n1 = a;
					n2 = 0;
				}
				if (op == 10){
					a = n1*n2;
					n1 = a;
					n2 = 0;
				}
		}
	//printf("%d %d %d\n",a,n1,n2);
	}

   return EXIT_SUCCESS;
}
