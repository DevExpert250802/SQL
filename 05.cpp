// Armstrong Number
//   https://bit.ly/3vBfkbD





bool checkArmstrong(int n){
	int x = n;
	long armstrong = 0;
	int countdigits = (int)(log10(n)+1);
	while(x){
		int lastdigit = x%10;
		armstrong += pow(lastdigit,countdigits);
		x=x/10;
	}
	return (n==armstrong);
}


T.C. = log(n)
