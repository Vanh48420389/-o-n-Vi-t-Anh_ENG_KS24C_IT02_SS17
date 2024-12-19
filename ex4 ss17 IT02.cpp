#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Nhap so phan tu: ");
                scanf("%d", &size);

                arr = (int *)malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Khong the cap phat bo nho\n");
                    exit(1);
                }

                for (int i = 0; i < size; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                
                if (arr == NULL) {
                    printf("Mang chua duoc khoi tao\n");
                } else {
                    printf("Cac phan tu la so chan: ");
                    for (int i = 0; i < size; i++) {
                        if (arr[i] % 2 == 0) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                }
                break;

            case 3:
                
                if (arr == NULL) {
                    printf("Mang chua duoc khoi tao\n");
                } else {
                    printf("Cac phan tu la so nguyen to: ");
                    for (int i = 0; i < size; i++) {
                        int is_prime = 1;
                        if (arr[i] <= 1) {
                            is_prime = 0;
                        } else {
                            for (int j = 2; j <= arr[i] / 2; j++) {
                                if (arr[i] % j == 0) {
                                    is_prime = 0;
                                    break;
                                }
                            }
                        }
                        if (is_prime) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                }
                break;

            case 4:
                
                if (arr == NULL) {
                    printf("Mang chua duoc khoi tao\n");
                } else {
                    for (int i = 0; i < size / 2; i++) {
                        int temp = arr[i];
                        arr[i] = arr[size - 1 - i];
                        arr[size - 1 - i] = temp;
                    }
                    printf("Mang sau khi dao nguoc: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                
                if (arr == NULL) {
                    printf("Mang chua duoc khoi tao\n");
                } else {
                    int sub_choice;
                    printf("\n1. Tang dan\n2. Giam dan\nLua chon cua ban: ");
                    scanf("%d", &sub_choice);

                    switch (sub_choice) {
                        case 1:
                            
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = i + 1; j < size; j++) {
                                    if (arr[i] > arr[j]) {
                                        int temp = arr[i];
                                        arr[i] = arr[j];
                                        arr[j] = temp;
                                    }
                                }
                            }
                            printf("Mang sau khi sap xep tang dan: ");
                            for (int i = 0; i < size; i++) {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 2:
                            
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = i + 1; j < size; j++) {
                                    if (arr[i] < arr[j]) {
                                        int temp = arr[i];
                                        arr[i] = arr[j];
                                        arr[j] = temp;
                                    }
                                }
                            }
                            printf("Mang sau khi sap xep giam dan: ");
                            for (int i = 0; i < size; i++) {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        default:
                            printf("Lua chon khong hop le\n");
                            break;
                    }
                }
                break;

            case 6:
                
                if (arr == NULL) {
                    printf("Mang chua duoc khoi tao\n");
                } else {
                    int key;
                    int found = 0;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &key);

                    for (int i = 0; i < size; i++) {
                        if (arr[i] == key) {
                            printf("Gia tri %d duoc tim thay o vi tri %d\n", key, i);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Gia tri %d khong duoc tim thay trong mang\n", key);
                    }
                }
                break;

            case 7:
                
                printf("Thoat chuong trinh\n");
                free(arr);
                exit(0);

            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }

    return 0;
}

