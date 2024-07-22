// https://www.naukri.com/code360/problems/number-of-digits_9173?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM


int countDigits(int n){
    int count=0;
		while(n>0){
	    count++;
	    n=n/10;
	}
	return count;
}


//  T.C. = O(log10 (N))





int countDigits(int n){
	int digit = (int)(log10(n) +1);
	return digit;
}


// T.C. = O(1)
