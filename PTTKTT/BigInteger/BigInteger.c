// Bai toan nhan hai so nguyen lon
// Du lieu cho trong file D://CT174/thuc hanh/BigInteger.INP
// Giai bang phuong phap CHIA DE TRI
// Dung chuoi ky tu bieu dien cho mot so nguyen 
// moi so nguyen co n chu so, n co dang n = 2^k

// Noi dung file BigInteger.INP nhu sau
// Co 2 dong, moi dong bieu dien cho mot so nguyen, 
// ket thuc bang ky hieu xuong dong


#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef char * BigInteger;
// Ham doc du lieu tu file BigInteger.INP 
// vao 2 tham so x va y

int min(int a, int b){
	if (a < b) return a;
	return b;
}

int max(int a, int b){
	if (a < b) return b;
	return a;
}

void ReadFromFile(BigInteger x, BigInteger y){
	freopen("input.txt", "r", stdin);
	gets(x); gets(y);
}

BigInteger newBigInteger(){
	BigInteger s;
	s = (BigInteger)malloc(sizeof(char)*256);
	memset(s, 0, 256);
	return s;
}

BigInteger RemoveLeadingZero(BigInteger s){
	BigInteger res = newBigInteger();
	int idx = 0, pos = 0;
	if (s[0] == '-') {
		idx = 1;
		res[pos++] = '-';
	}
	while (s[idx] == '0') ++idx;
	if (idx == strlen(s)) {
		res[0] = '0';
		return res;
	}
	int i;
	for (i = idx; i < strlen(s); ++i){
		res[pos++] = s[i];
	}
	return res;
}

void Swap(BigInteger *x, BigInteger *y){
	BigInteger tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
// Ham xac dinh dau cua so nguyen lon x
int Sign(BigInteger x){
	if (x[0] == '-') return -1;
	if (x[0] == '0') return 0;
	return 1;
}

// DAO NGUOC MOT CHUOI
BigInteger Reverse(BigInteger x){
	BigInteger s = newBigInteger();
	int i, len = strlen(x);
	for (i = len-1; i >= 0; --i) s[len-i-1] = x[i];
	return s;
} 

// Ham Right lay ben phai so nguyen lon x, n chu so
BigInteger Right(BigInteger x, int n){
	BigInteger s = newBigInteger();
	BigInteger rx = newBigInteger();
	rx = Reverse(x);
	memcpy(s, rx, n);
	s = Reverse(s);
	return s;
}

// Ham Left lay ben trai so nguyen lon x, n chu so
BigInteger Left(BigInteger x, int n){
	BigInteger s;
	s = (BigInteger)malloc(sizeof(char)*256);
	memset(s, 0, 256);
	memcpy(s, x, n);
	return s;
}

// Lay tri tuyet doi cua so nguyen lon x
BigInteger ABS(BigInteger x){
	if (Sign(x) < 0) return Right(x, strlen(x)-1);
	return x;
}

// Nhan so nguyen lon x voi 10 mu n
BigInteger Nhan10_mu_n (BigInteger x, int n){
	BigInteger s = newBigInteger();
	int i, len = strlen(x);
	s = Left(x, len);
	for (i = len; i < len+n; ++i) s[i] = '0';
	return s;
}            

// Kiem tra xem co phai so duong hay khong
int Positive(BigInteger x){
    return Sign(x) > 0;
}    

// Kiem tra xem co phai so am hay khong
int Negative(BigInteger x){
	return Sign(x) < 0;
}    

// Kiem tra xem co phai so KHONG am hay khong
int Not_Negative(BigInteger x){
	return !Negative(x);
}    

//  Kiem tra xem co phai so KHONG duong hay khong
int Not_Positive(BigInteger x){
	return !Positive(x);
}    

// Ham xet xem 2 so co bang nhau hay kh
int Equal(BigInteger x, BigInteger y){
    return strcmp(x, y) == 0;
}

int Less_Than(BigInteger x, BigInteger y){
	int i, lenX = strlen(x), lenY = strlen(y);
	if (Equal(x, y)) return 0;
	if (Not_Positive(x) && Positive(y)) return 1;
	if (Positive(x) && Not_Positive(y)) return 0;
	
	if (Sign(x) > 0){
		if (lenX > lenY) return 0;
		if (lenX < lenY) return 1;
		int i = 0;
		while (x[i] == y[i]) ++i;
		return x[i] < y[i];
	} else {
		if (lenX > lenY) return 1;
		if (lenX < lenY) return 0;
		for (i = 1; i < lenX; ++i){
			if (x[i] < y[i]) return 0;
		}
		return 1;
	}
}   

BigInteger Add(BigInteger x, BigInteger y);

// nhan mot so nguyen voi so 1 hoac -1
BigInteger MultS(BigInteger x, int sign){
	BigInteger s = newBigInteger();
	int i, len = strlen(x);
	if (sign < 0){
		int pos = 0;
		if (Sign(x) > 0) s[pos++] = '-';
		for (i = Sign(x) < 0 ? 1 : 0; i < len; ++i) s[pos++] = x[i];
		return s;
	}
	return x;
}

BigInteger Subtract(BigInteger x, BigInteger y){
	if (Sign(x) == 0){
		if (Sign(y) > 0) return MultS(y, -1);
		return ABS(y);
	}
	if (Sign(y) == 0) return x;
	if (Sign(x) > 0 && Sign(y) < 0) return Add(x, ABS(y));
	if (Sign(x) < 0 && Sign(y) > 0) return MultS(Add(ABS(x), y), -1);
	if (Sign(x) < 0 && Sign(y) < 0) return Subtract(ABS(y), ABS(x));
	int sign = 1;
	BigInteger a = newBigInteger();
	BigInteger b = newBigInteger();
	BigInteger s = newBigInteger();
	int i, lenX = strlen(x), lenY = strlen(y), len = max(lenX, lenY), tmp = 0;
	if (Less_Than(x, y)) {
		sign = -1;
		Swap(&x, &y);
	}
	a = Reverse(x);
	b = Reverse(y);
	
	a = Nhan10_mu_n(a, len-strlen(a));
	b = Nhan10_mu_n(b, len-strlen(b));
	
	for (i = 0; i < max(lenX, lenY); ++i){
		int sub = a[i]-'0' - (b[i]-'0' + tmp);
		s[i] = (sub + (sub < 0 ? 10: 0))%10 + '0';
		tmp = sub < 0 ? 1: 0;
	}
	if (tmp) s[len++] = tmp+'0';
	if (sign < 0) s[len] = '-';
	return RemoveLeadingZero(Reverse(s));
} 

// cong 2 so nguyen bat ki
BigInteger Add(BigInteger x, BigInteger y){
	if (Sign(x) > 0 && Sign(y) < 0) return Subtract(x, ABS(y));
	if (Sign(x) < 0 && Sign(y) > 0) return Subtract(y, ABS(x));
	if (Sign(x) < 0 && Sign(y) < 0) return MultS(Add(ABS(x), ABS(y)), -1);
	BigInteger a = newBigInteger();
	BigInteger b = newBigInteger();
	BigInteger s = newBigInteger();
	int i, lenX = strlen(x), lenY = strlen(y), len = max(lenX, lenY), tmp = 0;
	a = Reverse(x);
	b = Reverse(y);
	a = Nhan10_mu_n(a, len-lenX);
	b = Nhan10_mu_n(b, len-lenY);
	for (i = 0; i < max(lenX, lenY); ++i){
		s[i] = (a[i]-'0' + b[i]-'0' + tmp)%10 + '0';
		tmp = (a[i]-'0' + b[i]-'0' + tmp)/10;
	}
	if (tmp) s[len] = tmp+'0';
	return Reverse(s);
} 

BigInteger ConvertIntToBigInteger(int x){
	BigInteger res = newBigInteger();
	if (x == 0) {
		res[0] = '0';
		return res;
	}
	int i = 0;
	while (x > 0){
		res[i++] = x%10 + '0';
		x /= 10;
		
	}
	return Reverse(res);
}
// Nhan 2 so nguyen co mot chu so 
BigInteger Mult1(BigInteger x, BigInteger y){
	int i = 0, j = 0;
	if (Sign(x) < 0) i = 1;
	if (Sign(y) < 0) j = 1;
	if (Sign(x)*Sign(y) == 0) return ConvertIntToBigInteger(0);
	return MultS(ConvertIntToBigInteger((x[i]-'0')*(y[j]-'0')), Sign(x)*Sign(y));
} 


BigInteger Mult(BigInteger X, BigInteger Y, int n){
   BigInteger m1,m2,m3,A,B,C,D;
   
   int s; // Luu tru dau cua tich XY 
   s = Sign(X)*Sign(Y); 
   X = ABS(X); //Lay tri tuyet doi cua X 
   Y = ABS(Y);
   if (n == 1)  return MultS(Mult1(X,Y),s);
   
   A = Left(X, n/2);
   B = Right(X, n/2);
   C = Left(Y, n/2);
   D = Right(Y, n/2);
   m1 = Mult(A,C, n/2);
   m2 = Mult(Subtract(A,B),Subtract(D,C), n/2);
   m3 = Mult(B,D, n/2);
   
   return MultS(Add(Nhan10_mu_n(m1,n), Add(Nhan10_mu_n(Add(m1, Add(m2,m3)),n/2),  m3)),s);
}

BigInteger FillLeadingZero(BigInteger x, int maxLen){
	x = Reverse(x);
	x = Nhan10_mu_n(x, maxLen-strlen(x));
	x = Reverse(x);
	return x;
}

int main(){
    BigInteger x, y;
	x = (BigInteger)malloc(sizeof(char)*256);
	y = (BigInteger)malloc(sizeof(char)*256);

	ReadFromFile(x,y);
	printf("\nSo nguyen X= %s\n\n",x);
	printf("So nguyen Y= %s\n\n",y);
	int maxLen = max(strlen(x), strlen(y));
	x = FillLeadingZero(x, maxLen);
	y = FillLeadingZero(y, maxLen);
	
	printf("%s", RemoveLeadingZero(Mult(x, y, strlen(x))));
	return 0;
}
