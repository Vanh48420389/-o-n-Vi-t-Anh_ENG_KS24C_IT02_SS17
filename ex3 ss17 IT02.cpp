#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str = NULL;
    char *str2 = NULL;
    int choice;
    int size;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Nhap do dai chuoi: ");
                scanf("%d", &size);
                str = (char *)malloc((size + 1) * sizeof(char));
                if (str == NULL) {
                    printf("Khong the cap phat bo nho\n");
                    exit(1);
                }

                printf("Nhap chuoi: ");
                scanf(" ");
                fgets(str, size + 1, stdin);
                str[strcspn(str, "\n")] = '\0'; 
                break;

            case 2:
                
                if (str == NULL) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    int len = strlen(str);
                    for (int i = 0; i < len / 2; i++) {
                        char temp = str[i];
                        str[i] = str[len - i - 1];
                        str[len - i - 1] = temp;
                    }
                    printf("Chuoi dao nguoc: %s\n", str);
                }
                break;

            case 3:
                
                if (str == NULL) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    int count = 0;
                    int inWord = 0;
                    for (int i = 0; str[i] != '\0'; i++) {
						if (isspace(str[i])) {
							inWord = 0; 
						} else {
							inWord = 1; 
							count++; 
							} 
						}
                    printf("So luong tu trong chuoi: %d\n", count);
                }
                break;

            case 4:
                
                if (str == NULL) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    printf("Nhap do dai chuoi khac: ");
                    scanf("%d", &size);

                    
                    str2 = (char *)malloc((size + 1) * sizeof(char));
                    if (str2 == NULL) {
                        printf("Khong the cap phat bo nho\n");
                        exit(1);
                    }

                    printf("Nhap chuoi khac: ");
                    scanf(" ");
                    fgets(str2, size + 1, stdin);
                    str2[strcspn(str2, "\n")] = '\0'; 

                    if (strlen(str) > strlen(str2)) {
                        printf("Chuoi khac ngan hon chuoi ban dau\n");
                    } else if (strlen(str) < strlen(str2)) {
                        printf("Chuoi khac dai hon chuoi ban dau\n");
                    } else {
                        printf("Chuoi khac co do dai bang chuoi ban dau\n");
                    }
                    free(str2);
                }
                break;

            case 5:
                if (str == NULL) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    char *ptr = str;
                    while (*ptr) {
                        *ptr = toupper(*ptr);
                        ptr++;
                    }
                    printf("Chuoi sau khi in hoa: %s\n", str);
                }
                break;

            case 6:
                if (str == NULL) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    printf("Nhap do dai chuoi khac: ");
                    scanf("%d", &size);
                    str2 = (char *)malloc((size + 1) * sizeof(char));
                    if (str2 == NULL) {
                        printf("Khong the cap phat bo nho\n");
                        exit(1);
                    }

                    printf("Nhap chuoi khac: ");
                    scanf(" ");
                    fgets(str2, size + 1, stdin);
                    str2[strcspn(str2, "\n")] = '\0'; 
                    str = (char *)realloc(str, (strlen(str) + strlen(str2) + 1) * sizeof(char));
                    if (str == NULL) {
                        printf("Khong the cap phat bo nho\n");
                        exit(1);
                    }

                    strcat(str, str2);
                    printf("Chuoi sau khi them: %s\n", str);
                    free(str2);
                }
                break;

            case 7:
                printf("Thoat chuong trinh\n");
                free(str); 
                exit(0);

            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while (choice!=7);

    return 0;
}

