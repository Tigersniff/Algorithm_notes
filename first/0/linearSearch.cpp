#include<iostream>
#include<cstdlib>
#include<ctime>

#define N 1000000
#define WORD_LENGTH sizeof(int) * 8

using namespace std;

unsigned int bits[N/WORD_LENGTH+1];
void setbit(unsigned int*, unsigned int);
int testbit(unsigned int*, unsigned int);
int min_free(unsigned int* , int);
unsigned int* randomNumber(unsigned int* ,int)

int main(int argc, char* argv[])
{
	const int num = 100000;
	unsigned int id[num];
	int minID, inNumber;
	cout << "Please input ID(<100000) :" ;
	cin >> inNumber;
	for (int i=0; i<num; i++)
		if (i==inNumber)
			continue;
		else
			id[i] = i+1;
	minID = min_free(id, num);
	cout << "Ths minimun number is " << minID << endl;
		
}
/*
// 采用位排序，返回最小 ID
// 形式参数：数组,数组大小
int min_free(unsigned int* xs, int n) {
	int i, len = N/WORD_LENGTH+1;
	for (i=0; i<len; i++)
		bits[i] = 0;
	for (i=0; i<n; ++i) {
		if (xs[i] < n)
			setbit(bits, xs[i]);
	}

	for (i = 0; i <= n; i++) {
		if (!testbit(bits, i))
			return i;
	}
}
*/

// 采用分治法，返回最小 ID
int min_free(unsigned int* xs, int n) {
	int l = 0, mid;
	int u = n - 1;
	int right, left;
	while( n ) {
		mid = l + (u-l)/2;
		cout << l << '\t' << mid << '\t' << u <<  endl;
		left = 0, right = 0;
		for (right=0; right<n; right++)
			if (xs[right] <= mid) {
				int temp = xs[left];
				xs[left] = xs[right];
				xs[right] = temp;
				left++;
			}
		if (left == mid-l+1) {
			xs = xs + left;
			n = n - left;
			l = mid + 1;
		} else {
			n = left;
			u = mid;
		}
	}
	return mid;
}

unsigned int* randomNumber(int randList[], int numOf) {
	srand(unsigned(time(NULL)));
	int i = 0;
	while (i< numOf){
		int temp = rand()%numOf;
		for (int j=0; j<i; j++) {
			if (temp == randList[j])
				continue;
		}
		randList[i] = temp;
		i ++;
	}
}

void setbit(unsigned int* bits, unsigned int i) {
	bits[i/WORD_LENGTH] |= (1<<(i%WORD_LENGTH));
}

int testbit(unsigned int* bits, unsigned int i) {
	return bits[i/WORD_LENGTH] & (1<<(i%WORD_LENGTH));
}

