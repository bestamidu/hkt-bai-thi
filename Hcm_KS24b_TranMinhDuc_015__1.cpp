#include <stdio.h>
#include <limits.h> /

int main() {
    int choice, n = 0, arr[100]; 

    do {
      	printf (" \n MEnu\n");
	printf(",1nhap so phan tu va gia tri cua mang\n");
	printf("2.in ra cac gia tri phan tu theo mang arr[0]=1 arr[1]=2\n");
	printf("3,dem so luong cac so so nguyenn to co trong mang\n");
	printf ("4,in ra so nho thu 2 o trong mang\n");
	printf("5.them mot phan tu vao vi tri ngau nhien trong mang , phan tu them moi va gia tri moi do nguoi dung nhap vao\n");
	printf("6.xoa phan tu tai mot vi tri cu the\n");
	printf("7,sap xep mang theo thu tu giam dan insert sort\n ");
	printf("8 cho nguoi dung nhap vao xem phan tu do co ton tai hay khong binary search\n");
	printf("9xoa toan bo phan tu trung lap va hien thi toan bo phan tu doc nhat co o trong mang\n");
	printf("10.dao nguoc thu tu co o trong mang\n ");
	printf(" lua chon cua ban la\n ");
	scanf("%d",&choice); 

        switch (choice) {
            case 1: {
                printf("nhap so phan tu cau mang ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("nhap gia tri cho  arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("cac phan tu trong mang la  ");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            }
            
            	case 3: {
                int count = 0;
                int isPrime(int num) {
                    if (num < 2) return 0;
                    for (int i = 2; i * i <= num; i++) {
                        if (num % i == 0) return 0;
                    }
                    return 1;
                }
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        count++;
                    }
                }
                printf("So luong so nguyen to trong mang: %d\n", count);
                break;
            }

            case 4: {
                if (n < 2) {
                    printf("khong du n de chay");
                } else {
                    int smallest = INT_MAX, second_smallest = INT_MAX;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] < smallest) {
                            second_smallest = smallest;
                            smallest = arr[i];
                        } else if (arr[i] > smallest && arr[i] < second_smallest) {
                            second_smallest = arr[i];
                        }
                    }
                    if (second_smallest == INT_MAX) {
                        printf("khong ton tai vi tri thu 2.\n");
                    } else {
                        printf("gia tri nho thu 2 la  %d\n", second_smallest);
                    }
                }
                break;
            }
            case 5: {
                int value, addIndex;
                printf("nhap vi tri muon them : ");
                scanf("%d", &addIndex);
                if (addIndex < 0 || addIndex > n) {
                    printf("vi tri khong hop le");
                    break;
                }
                printf("nhap vi tri muon them ");
                scanf("%d", &value);
                for (int i = n; i > addIndex; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[addIndex] = value;
                n++;
                printf("mang duoc them la ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 6: {
                int deleteIndex;
                printf("nhap vi tri muon xoa ");
                scanf("%d", &deleteIndex);
                if (deleteIndex < 0 || deleteIndex >= n) {
                    printf("vi tri khong hop le\n");
                    break;
                }
                for (int i = deleteIndex; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("magn sau khi duoc xoa la ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 7: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("mangg duoc sap xep giam dan la: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            
            default: {
                printf("thu lai , khong hop le \n");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}
