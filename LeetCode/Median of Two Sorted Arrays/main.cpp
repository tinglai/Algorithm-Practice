#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n){
		int mid = (m + n) / 2;
		if((m + n) % 2 == 0)
			return ((double)kthSmallest(A, m, B, n, mid) + (double)kthSmallest(A, m, B, n, mid + 1)) / 2.0;
		else
			return (double)kthSmallest(A, m, B, n, mid + 1);
	}
	int kthSmallest(int A[], int m, int B[], int n, int k){
		if(k > (m + n)) exit(1);
		if(m == 0){
			if(k > n) exit(1);
			else return B[k - 1];
		}
		if(n == 0){
			if(k > m) exit(1);
			else return A[k - 1];
		}
		if(m == 1 && n == 1){
			return (k == 1 ? min(A[0], B[0]): max(A[0], B[0]));
		}
//this is a help function used to find the kth smallest number among
//two sorted arrays, A and B, with length m and n, respectively.
		if(m > n) return kthSmallest(B, n, A, m, k);//make sure that i and j won't go beyond bounds

		int i = min(k / 2, m / 2);
		int j = k - 1 - i;
//here the main trick is to keep i + j + 1 == k
//This is because when B[j - 1] < A[i] < B[j] (or A[i - 1] < B[j] < A[i]), 
//A[i] (or B[j]) is the i + j + 1 th smallest number among A and B, since 
//A[0] ~ A[i - 1] and B[0] ~ B[j - 1] are smaller than A[i] (or B[j]) and others are
//all bigger than A[i]. The idea in our algorithm is to check those possible
//pairs of i and j s.t i + j = k - 1
		int Ai = A[i];
		int Bj = B[j];
		int Ai_1 = (i == 0? INT_MIN: A[i - 1]);
		int Bj_1 = (j == 0? INT_MIN: B[j - 1]);
		if(Ai <= Bj){
			if(Ai >= Bj_1){
				return Ai;
			}
			else return kthSmallest(A + i + 1, m - i - 1, B, j, k - i - 1);
		}
		//when Ai < Bj_1 <= Bj, no need search Bj and upper portion of B starting from Bj,
		//since Bj is larger than A[0] ~ A[i] (i + 1 numbers) and B[0] ~ B[j - 1]
		//(j numbers) ,and i + j + 1 = k, meaning Bj is larger than at least k numbers
		//it cannot be the kth smallest number, which is exactly larger than k - 1 numbers
		//for the similar reason, there is no need to search Ai and the lower portion of 
		//A starting from Ai, since Ai in this case is smaller than Bj_1(otherwise it will
		//be return in the first if statement), and thus Ai is bigger than A[0] ~ A[i - 1]
		//(i numbers) and at most bigger than B[0] ~ B[j - 2] (j - 1 numbers), i.e, Ai is
		//at most larger than i + j - 1 = k - 2 numbers, it cannot be larger than k - 1
		//numbers, thus it cannot be the kth smallest number
		else{
			if(Bj >= Ai_1) return Bj;
			else return kthSmallest(A, i, B + j + 1, n - j - 1, k - j - 1);
		}
	}	
};

int main(){
	int A[] = {1,2,3};
	//int A[] = {1,24,35,54,65,234};
	int B[] = {4,5,6};
	//int B[] = {3,4,45,64,124,534};
	int k = 1;
	int k2 = 2;
	
	Solution soln;
	int kth = soln.kthSmallest(A, 1, B, 1, k);
	int k2th = soln.kthSmallest(A, 1, B, 1, k2);
	double result = soln.findMedianSortedArrays(A, 3, B, 3);
	cout << "kth = " << kth << endl;
	cout << "k2th = " << k2th << endl;
	cout << "median = " << result << endl;
}
