#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int *arr = NULL;
	int choice;
	int size=0;
	int sum =0;	
	do {
	printf("\n--MENU--\n");
	printf("1.Nhap so phan tu va tung phan tu cho mang \n");
	printf("2.Hien thi cac phan tu trong mang \n");
	printf("3.Tinh do dai mang \n") ;
	printf("4.Tinh tong cac phan tu trong mang \n");
	printf("5.Hien thi phan tu lon nhat \n");
	printf("6.THOAT\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("Nhap so phan tu: ");
			scanf("%d", &size); 
			arr = (int *)malloc(size * sizeof(int)); 
			if (arr == NULL) {
				printf("Khong the cap phat bo nho\n");  
			} 
			for (int i = 0; i < size; i++) {
				printf("arr[%d] : ", i + 1);
				scanf("%d", &arr[i]); 
			} 
		break;
    	case 2:
    		printf("cac phan tu trong mang la :");
    		for(int i=0; i < size; i++){
    			printf("%d\t", arr[i]);	
			}
		break;
		case 3:
			printf("Do dai mang la : %d", size);	
		break;
		case 4:
			if(arr == NULL){
				printf("Mang chua duoc khoi tao");
			}else{
				for(int i=0;i<size;i++){
					sum+=arr[i];
				}
			}
			printf("Tong cua mang la : %d",sum);
			
		break;
		case 5:
			int max=arr[0];
			if(arr==NULL){
				printf("Mang chua duoc khoi tao ");
			}else{
				for(int i=1;i<size;i++){
					if(arr[i]>max){
						max=arr[i];
					}
				}
			}
			printf("Gia tri lon nhat cua mang la : %d", max);
			
		break;
	}
	
	}while(choice!=6);
		printf("THOAT CHUONG TRINH");
	return 0;
}
