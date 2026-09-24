#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    int a[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nMang vua nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    int tongduong_3 = 0, dem_3 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] % 3 == 0) {
            tongduong_3 += a[i];
            dem_3++;
        }
    }

    if (dem_3 > 0) {
        float tbc_3 = (float)tongduong_3 / dem_3;
        printf("TBC cac so duong va chia het cho 3: %.2f\n", tbc_3);
    } else {
        printf("Khong co so duong nao chia het cho 3 trong mang.\n");
    }
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }

    printf("Phan tu nho nhat (Min) = %d\n", min);

    int tong_le = 0, dem_le = 0;
    int tong_chan = 0, dem_chan = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            tong_le += a[i];
            dem_le++;
        } else {
            tong_chan += a[i];
            dem_chan++;
        }
    }
   
    if (dem_le > 0) {
        printf("TBC cac so le: %.2f\n", (float)tong_le / dem_le);
    } else {
        printf("Khong co so le trong mang.\n");
    }

    if (dem_chan > 0) {
        printf("TBC cac so chan: %.2f\n", (float)tong_chan / dem_chan);
    } else {
        printf("Khong co so chan trong mang.\n");
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int tong_am = 0, tong_duong = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            tong_duong += a[i];
        } else if (a[i] < 0) {
            tong_am += a[i];
        }
    }

    printf("Tong cac so duong = %d\n", tong_duong);
    printf("Tong cac so am = %d\n", tong_am);

    return 0;
}
