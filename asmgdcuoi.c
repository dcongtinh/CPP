/**
 * Editor: Dao Cong Tinh dcongtinh@ferdon.io
 * Facebook: Tính Đào
 * **/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 9

int USCLN(int a, int b)
{
	if (b == 0)
		return a;
	return USCLN(b, a % b);
}
int main()
{
	int menu;
	printf("...........Menu Chuong Trinh..........\n");
	printf("\n 1.Kiem tra so nguyen");
	printf("\n 2.Tim UCLN va BCNN cua 2 so");
	printf("\n 3.Tinh tien quan karaoke");
	printf("\n 4.Tinh tien dien trong thang");
	printf("\n 5.Xay dung chuc nang doi tien");
	printf("\n 6.Xay dunh chuc nang tinh lai suat vay tien ngan hang vay tien tra gop");
	printf("\n 7.Xay dung chuc nang tinh lai suat vay tien mua xe");
	printf("\n 8.Sap xep thong tin sinh vien");
	printf("\n 9.Xay dunh chuong trinh game FPOLY-LOTT");
	printf("\n 10.Tinh toan phan so");
	printf("\n......................................");
	printf("\n");
	printf("\n Xin moi ban chon chuc nang trong menu: ");
	scanf("%d", &menu);
	// fflush(stdin);
	switch (menu)
	{
	case 1:
	{
		printf("Kiem tra so nguyen");
		float n;
		int i, dem = 0, m, count;
		printf("\nNhap so n bat ky: ");
		scanf("%f", &n);
		if (n == (int)n)
		{
			printf("\nSo %.0f la so nguyen", n);
			if (n < 2)
			{
				printf("\nSo %.0f khong la so nguyen to", n);
			}
			else //n>=2
			{
				for (i = 2; i <= sqrt(n); i++)
				{
					if ((int)n % i == 0)
						dem++;
				}
				if (dem == 0)
				{
					printf("\nSo %.0f la so nguyen to", n);
				}
				else
				{
					printf("\nSo %.0f khong la so nguyen to", n);
				}
			}
			count = 0;
			for (m = 0; m <= n; m++)
			{
				if (m * m == n)
				{
					count++;
				}
			}
			if (count != 0)
			{
				printf("\nSo %.0f l� so chinh phuong", n);
			}
			else
			{
				printf("\nSo %.0f khong phai la so chinh phuong", n);
			}
		}
		else
		{
			printf("\nSo %.1f khong phai la so nguyen", n);
			printf("\nKhong the kiem tra so %.1f co phai la so nguyen to khong vi %.1f khong la so nguyen", n, n);
			printf("\nKhong the kiem tra so %.1f co phai la so chinh phuong khong vi %.1f khong la so nguyen", n, n);
		}
	}
	break;
	case 2:
	{
		printf("Tim UCLN va BCNN cua 2 so");
		int a, b;
		printf("\nNhap so nguyen duong a: ");
		scanf("%d", &a);
		printf("Nhap so nguyen duong b: ");
		scanf("%d", &b);
		printf("\nUSCLN cua %d va %d la: %d", a, b, USCLN(a, b));
		printf("\nBSCNN cua %d va %d la: %d", a, b, (a * b) / USCLN(a, b));
	}
	break;
	case 3:
	{
		printf("Tinh tien quan karaoke");
		//Gia tri nhap vao
		int gioBD, gioKT;
		//neu nhap gio sai se lap lai
		do
		{
			printf("\nNhap vao gio bat dau: ");
			scanf("%d", &gioBD);

			if (gioBD < 12 || gioBD > 23)
			{
				printf("BAN DA NHAP SAI GIO BAT DAU, QUAN CHI HOAT DONG TU 12h DEN 23h, MOI BAN NHAP LAI\n");
			}

		} while (gioBD < 12 || gioBD > 23);

		do
		{ //neu nhap gio sai se lap lai
			printf("Nhap vao gio ket thuc: ");
			scanf("%d", &gioKT);

			if (gioKT < gioBD || gioKT > 23)
			{
				printf("BAN DA NHAP SAI GIO KET THUC, QUAN CHI HOAT DONG TU 12h DEN 23h, MOI BAN NHAP LAI\n");
			}

		} while (gioKT < gioBD || gioKT > 23);

		int soGioHat = gioKT - gioBD;
		float tienThanhToan;
		//Qua trinh xu li
		if (soGioHat <= 3)
		{
			tienThanhToan = soGioHat * 150000;
		}
		else
		{
			int gioThem = soGioHat - 3;
			float tienThem = gioThem * 150000 * 0.7;
			tienThanhToan = 3 * 150000 + tienThem;
		}
		if (gioBD >= 14 && gioBD <= 17)
		{
			tienThanhToan = tienThanhToan * 0.9;
		}
		//Du lieu dau ra
		printf(" So tien quy khach can thanh toan la: %.0f\n", tienThanhToan);
	}
	break;
	case 4:
	{
		printf("Tinh tien dien trong thang");
		int tiendien;
		printf("\nMoi ban nhap vao so kwh tieu trong thang: ");
		scanf("%d", &tiendien);
		if (tiendien <= 50)
		{
			printf("So tien dien ban thanh toan la: %dd", tiendien * 1678);
		}
		else if (tiendien <= 100)
		{
			printf("So tien dien ban thanh toan la: %dd", 50 * 1678 + (tiendien - 50) * 1734);
		}
		else if (tiendien <= 200)
		{
			printf("So tien dien ban thanh toan la: %dd", 50 * 1678 + (50 * 1734) + (tiendien - 100) * 2014);
		}
		else if (tiendien <= 300)
		{
			printf("So tien dien ban thanh toan la: %dd", 50 * 1678 + (50 * 1734) + (100 * 2014) + (tiendien - 200) * 2536);
		}
		else if (tiendien <= 400)
		{
			printf("So tien dien ban thanh toan la: %dd", 50 * 1678 + (50 * 1734) + (100 * 2014) + (100 * 2536) + (tiendien - 300) * 2834);
		}
		else
		{
			printf("So tien dien ban thanh toan la: %dd", 50 * 1678 + (50 * 1734) + (100 * 2014) + (100 * 2536) + (100 * 2834) + (tiendien - 400) * 2927);
		}
	}

	break;
	case 5:
	{
		printf("Xay dung chuc nag doi tien");
		int loaitien[MAX] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
		int h, sotien, soto;
		printf("\nNhap vao so tien cua ban");
		scanf("%d", &sotien);
		for (h = 0; h < MAX; h++)
		{
			soto = sotien / loaitien[h];
			printf("Co %d to tien %d dong\n", soto, loaitien[h]);
			sotien = sotien % loaitien[h];
		}
		break;
	}
	case 6:
	{
		printf("Xay dung chuc nang tinh lai suat vay tien ngan hang vay tra gop");
		int money, lai, tienGocTra, k, month = 12;
		printf("\nNhap so tien can vay: ");
		scanf("%d", &money);
		tienGocTra = money / month;
		for (k = 1; k <= month; k++)
		{
			lai = money * 0.05;
			printf("\nTien lai phai tra trong thang thu %d la: %d", k, lai);
			printf("\nTien goc phai tra trong thang thu %d la: %d", k, tienGocTra);
			printf("\n	*So tien phai tra trong thang thu %d la: %d", k, tienGocTra + lai);
			money = money - tienGocTra;
			printf("\n	*So tien con no la: %d\n\n", money);
		}
	}
	break;
	case 7:
	{
		float a = 0, b = 0, c = 0, d = 0, e = 0;
		int f = 0;
		printf("\nXay dung chuc nang tinh lai suat vay tien mua xe");
		printf("Moi ban nhap so phan tram vay toi da: ");
		scanf("%f", &a);
		while (a < 0 || a > 100)
		{
			printf("So phan tram vay toi da khong hop le, moi ban nhap lai.\n");
			printf("Moi ban nhap so phan tram vay toi da: ");
			scanf("%f", &a);
		}
		printf("\nSo tien ban can tra lan dau la: %.0f trieu", 500 * (100 - a) / 100);
		b = 500 * a / 100;
		c = b / 24;
		for (; b > 0; b -= c)
		{
			d = b;
			d *= .072;
			f++;
			printf("\nSo tien can tra cho thang %d la: %.0f trieu", f, d + c);
			e += d + c;
		}
		e += d + c + 500 * (100 - a) / 100;
		printf("\n--->Tong so tien can tra la: %.0f trieu<---", e);
	}
	break;

	case 8:
	{
		printf("\nSap xep thong tin sinh vien");
		struct sinhvien
		{
			char ten[50];
			float diem;
		};
		int sosv, d, f, l;
		printf("Nhap so sinh vien can nhap thong tin: ");
		scanf("%d", &sosv);
		fflush(stdin);
		printf("\n");
		struct sinhvien sv[sosv];
		for (d = 0; d < sosv; d++)
		{
			printf("Nhap ten sinh vien [%d] : ", d + 1);
			gets(sv[d].ten);
			printf("Nhap diem sv [%d] : ", d + 1);
			scanf("%f", &sv[d].diem);
			printf("\n");
			fflush(stdin);
		}
		for (d = 0; d < sosv - 1; d++)
		{
			for (f = d + 1; f < sosv; f++)
			{
				if (sv[d].diem < sv[f].diem)
				{
					struct sinhvien tg = sv[d];
					sv[d] = sv[f];
					sv[f] = tg;
				}
			}
		}
		printf("| %-25s | %-15s | %-25s |\n", "TEN", "DIEM", "HOC LUC");
		char hl[50];
		for (l = 0; l < sosv; l++)
		{
			if (sv[l].diem >= 9)
			{
				strcpy(hl, "XUAT SAC");
			}
			else if (sv[l].diem >= 8)
			{
				strcpy(hl, "GIOI");
			}
			else if (sv[l].diem >= 6.5)
			{
				strcpy(hl, "KHA");
			}
			else if (sv[l].diem >= 5)
			{
				strcpy(hl, "TRUNG BINH");
			}
			else
			{
				strcpy(hl, "YEU");
			}
			printf("| %-25s | %-15.1f | %-25s |\n", sv[l].ten, sv[l].diem, hl);
		}
	}
	break;

	case 9:
	{
		printf("\nXay dunh chuong trinh game FPOLY-LOTT");
		int so1, so2;
		printf("Xin moi nhap so 1:");
		scanf("%d", &so1);
		printf("Xin moi nhap so 2:");
		scanf("%d", &so2);
		int count = 0;
		int i;
		srand((int)time(0));
		//xu ly
		int ketqua[2]; // chua 2 so he thong tu quay ra
		for (i = 0; i < 2; i++)
		{
			int kq = rand() % 15 + 1; // gia tri max,min
			ketqua[i] = kq;
		}
		//so sanh ket qua
		for (i = 0; i < 2; i++)
		{
			if (so1 == ketqua[i])
			{
				count++;
			}
			if (so2 == ketqua[i])
			{
				count++;
			}
		}
		printf(" ket qua so xo hom nay la:\n");
		printf(" so1 =%d\n", ketqua[0]);
		printf(" so2 =%d\n", ketqua[1]);
		if (count == 2)
		{
			printf(" chuc mung ban da trung giai dac biet!\n");
			printf(" Gia tri gia thuong 2ti VND\n");
		}
		else if (count == 1)
		{
			printf("chuc mung ban da trung giai nhat!\n");
			printf(" giai thuong: 100 trieu VND\n");
		}
		else
		{
			printf(" chuc ban may man lan sau!");
		}
	}
	break;

	case 10:
	{
		printf("\nTinh toan phan so");
		struct phanso
		{
			int tuso;
			int mauso;
		};

		struct phanso so1, so2;
		printf(" xin moi nhap vao phan so thu nhat: ");
		scanf("%d%d", &so1.tuso, &so1.mauso);
		printf(" xin moi nhap vao phan so thu hai: ");
		scanf("%d%d", &so2.tuso, &so2.mauso);
		struct phanso tong, hieu, tich, thuong;
		tich.tuso = so1.tuso * so2.tuso;
		tich.mauso = so1.mauso * so2.mauso;
		thuong.tuso = so1.tuso * so2.mauso;
		thuong.mauso = so1.mauso * so2.tuso;
		tong.mauso = so1.mauso * so2.mauso;
		tong.tuso = so1.tuso * so2.mauso + so2.tuso * so1.mauso;
		hieu.mauso = so1.mauso * so2.mauso;
		hieu.tuso = so1.tuso * so2.mauso - so2.tuso * so1.mauso;
		printf(" tong 2 phan so : %d/%d\n", tong.tuso, tong.mauso);
		printf(" hieu 2 phan so : %d/%d\n", hieu.tuso, hieu.mauso);
		printf(" tich 2 phan so : %d/%d\n", tich.tuso, tich.mauso);
		printf(" thuong 2 phan so : %d/%d\n", thuong.tuso, thuong.mauso);
		// getch();
	}

	break;
	default:
	{
		printf("Vui long chi nhap chuc nang tu 1 toi 11: ");
		scanf("%d", &menu);
		// getch();
	}

	break;
		return 0;
	}
}