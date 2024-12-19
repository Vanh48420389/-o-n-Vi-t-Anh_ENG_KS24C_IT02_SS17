#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	char *chuoi=NULL;  
	int choice;
	int size=0;
	int letterCount = 0;
	int specialCount = 0;
	do {
	printf("\n--MENU--\n");
	printf("1.Nhap vao chuoi \n");
	printf("2.In ra chuoi \n");
	printf("3.Dem so luong chu cai trong chuoi va in ra \n") ;
	printf("4.Dem so luong chu so trong chuoi va in ra \n");
	printf("5.Dem so luong ky tu dac biet trong chuoi va in ra \n");
	printf("6.THOAT\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("Moi ban nhap do dai chuoi :");
			scanf("%d", &size);
			chuoi = (char *)malloc(size * sizeof(int));
			if(chuoi == NULL){
				printf("Khong the cap phat bo nho ");
				exit(1);
			}else{
				printf("Nhap chuoi: "); 
				scanf(" "); 
				fgets(chuoi, size + 1, stdin); 
				chuoi[strcspn(chuoi, "\n")] = '\0';	
			} 
			
		break;
    	case 2:
    		if(chuoi==NULL){
    			printf("Chuoi chua duoc nhap");
			}else{
				printf("Chuoi vua nhap la :%s", chuoi);
			}
		break;
		case 3:
			if (chuoi == NULL) {
				printf("Chuoi chua duoc nhap\n"); 
			}else { 
			for (int i = 0; chuoi[i] != '\0'; i++) {
				if (isalpha(chuoi[i])) { 
					letterCount++; 
			} 
			} 
			printf("So luong chu cai trong chuoi: %d\n", letterCount); 
			}	
		break;
		case 4:
			if (chuoi == NULL) {
			printf("Chuoi chua duoc nhap\n");
			} else {
			int digitCount = 0;
			for (int i = 0; chuoi[i] != '\0'; i++) {
				if (isdigit(chuoi[i])) { 
					digitCount++;
			} 
			} 
			printf("So luong chu so trong chuoi: %d\n", digitCount);
			}
		break;
		case 5:
			if (chuoi == NULL) {
				printf("Chuoi chua duoc nhap\n");
			}else{
				
				for (int i = 0; chuoi[i] != '\0'; i++) {
				if (!isalpha(chuoi[i]) && !isdigit(chuoi[i])) {
				specialCount++;
				} 
				}
				printf("So luong ky tu dac biet trong chuoi: %d\n", specialCount);
			}
		break;
	}
	
	}while(choice!=6);
		printf("THOAT CHUONG TRINH");
	return 0;
}
