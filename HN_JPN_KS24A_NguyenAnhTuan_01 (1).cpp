#include<stdio.h>
int main(){
	int arr[50];
	int choice, length, primeNumber, deleteIndex, sum, min, max;
	int findIndex = -1;
	do{
		printf("\tMENU\n");
		printf("1. Nhap so phan tu va gia tri cua mang\n");
		printf("2. In ra gia tri cac phan tu trong mang\n");
		printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
		printf("4. In ra tong cua tat ca cac phan tu\n");
		printf("5. Them mot phan tu vao cuoi mang (nguoi dung nhap)\n");
		printf("6. Xoa phan tu tai vi tri cu the (nguoi dung nhap)\n");
		printf("7. Sap xep mang theo thu tu giam dan\n");
		printf("8. Tim kiem phan tu trong mang\n");
		printf("9. In ra toan bo so nguyen to trong mang\n");
		printf("10. Sap xep mang theo thu tu tang dan\n");
		printf("11. Thoat menu\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: // Nhap so phan tu va gia tri cua mang
				printf("Moi ban nhap so luong phan tu trong mang: ");
				scanf("%d", &length);
				for(int i = 0; i < length; i++){
					printf("Nhap arr[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				printf("\n");
				break;
			case 2: // In ra gia tri cac phan tu trong mang
				for(int i = 0; i < length; i++){
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			case 3: // Tim gia tri nho nhat va lon nhat trong mang
				min = arr[0];
				max = arr[0];
				for(int i = 0; i < length; i++){
					if(max < arr[i]){
						max = arr[i];
					}
					if(min > arr[i]){
						min = arr[i];
					}
				}
				printf("Gia tri lon nhat trong mang la %d\n", max);
				printf("Gia tri nho nhat trong mang la %d\n", min);
				break;
			case 4: // In ra tong cua tat ca cac phan tu
				for(int i = 0; i < length; i++){
					sum += arr[i];
				}
				printf("Tong tat ca cac phan tu trong mang la %d\n", sum);
				break;
			case 5: // Them mot phan tu vao cuoi mang (nguoi dung nhap)
				
			case 6: // Xoa phan tu tai vi tri cu the
				printf("Moi ban nhap vi tri phan tu muon xoa: ");
				scanf("%d", &deleteIndex);
				if(deleteIndex < 0 and deleteIndex >= length){
					printf("Vi tri da nhap khong hop li\n");
				}else{
					for(int i = deleteIndex; i < length - 1; i++){
						arr[i] = arr[i + 1];
					}
					length--;
				}
				break;
			case 7: // Sap xep mang theo thu tu giam dan 
				for(int i = 0; i < length - 1; i++){
					for(int j = 0; j < length - 1 - i; j++){
						if(arr[j] < arr[j + 1]){
							int temp = arr[j + 1];
							arr[j + 1] = arr[j];
							arr[j] = temp;
						}
					}
				}
				for(int i = 0; i < length; i++){
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			case 8: // Tim kiem phan tu trong mang
				printf("Nhap phan tu ban muon tim: ");
				scanf("%d", &findIndex);
				for(int i = 0; i < length; i++){
					if(arr[i] == findIndex){
						findIndex = i;
						break;
					}
				}
				printf("Phan tu ton tai trong mang tai arr[%d]\n", findIndex);
				break;
			case 9: // In ra toan bo so nguyen to trong mang
				for(int i = 0; i < length; i++){
					if(arr[i] == 2){
						printf("2 ");
					}else if(arr[i] > 2){
						for(int j = 2; j < arr[i]; j++){
							if(arr[i] % j != 0){
								printf("%d ", arr[i]);
							}
							break;
						}
					}
				}
				printf("\n");
				break;
			case 10: // Sap xep mang theo thu tu tang dan
				for(int i = 0; i < length - 1; i++){
					for(int j = 0; j < length - 1 - i; j++){
						if(arr[j] > arr[j + 1]){
							int temp = arr[j + 1];
							arr[j + 1] = arr[j];
							arr[j] = temp;
						}
					}
				}
				for(int i = 0; i < length; i++){
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
				default:
					printf("Thao tac khong hop le\n");
		}
	}while(choice != 11);
	return 0;
}

