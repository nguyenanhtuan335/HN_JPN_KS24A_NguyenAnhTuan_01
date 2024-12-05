#include <stdio.h>
#include <stdbool.h>

// Ham kem tra so nguyen to
    bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int arr[100], n = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In tong cac phan tu trong mang\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan \n");
        printf("8. Tim kiem phan tu \n");
        printf("9. In ra toan bo so nguyen to trong mang\n");
        printf("10. Sap xep mang theo thu tu tang dan \n");
        printf("11. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }

            case 2: 
                printf("Cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            

            case 3: {
                if (n > 0) {
                    int min = arr[0], max = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] < min) min = arr[i];
                        if (arr[i] > max) max = arr[i];
                    }
                    printf("Gia tri nho nhat: %d\n", min);
                    printf("Gia tri lon nhat: %d\n", max);
                } else {
                    printf("Mang rong!\n");
                }
                break;
            }

            case 4: {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Tong cac phan tu trong mang: %d\n", sum);
                break;
            }

            case 5: {
                int newElement;
                printf("Nhap phan tu moi: ");
                scanf("%d", &newElement);
                arr[n++] = newElement;
                printf("Them phan tu thanh cong.\n");
                break;
		      }

            case 6: {
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Xoa phan tu thanh cong.\n");
                }
                break;
            }

            case 7: 
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - 1 - i; j++) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep giam dan:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            

            case 8: {
                int x, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == x) {
                        printf("Phan tu %d xuat hien tai vi tri arr[%d]\n", x, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong mang.\n", x);
                }
                break;
            }

            case 9: {
                int hasPrime = 0;
                printf("Cac so nguyen to trong mang:\n");
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        hasPrime = 1;
                    }
                }
                if (!hasPrime) {
                    printf("Khong co so nguyen to nao trong mang.\n");
                }
                printf("\n");
                break;
            }

            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    int minIdx = i;
                    for (int j = i + 1; j < n; j++) {
                        if (arr[j] < arr[minIdx]) {
                            minIdx = j;
                        }
                    }
                    int temp = arr[i];
                    arr[i] = arr[minIdx];
                    arr[minIdx] = temp;
                }
                printf("Mang sau khi sap xep tang dan:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 11: 
                printf("Thoat chuong trinh.\n");
                break;
            

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 11);

    return 0;
}

