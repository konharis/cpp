#include <iostream>
#include <string>
#include <limits>

#define NN   5

struct STUD
{
    int AM;
    std::string Name;
    int Semester;
};

using namespace std;

void max2(float A[],int N);
float& doubleMin(float A[],int N);


int main (int argc, char **argv)
{
    float *A = new float[NN];
    system("chcp 1253");
    
    for (int i=0; i<NN;i++) {	
    	cout << "Δώστε αριθμό no "<<(i+1)<<":";
    	cin  >> A[i];
    }
    cout << "Πίνακας:";
    for (int i=0; i<NN;i++)
    	cout<<A[i]<<" ";
    cout<<endl;
    max2(A,NN);
    
    return 0;
}

void max2(float A[],int N) {
	if (N<3)
		return ;
	
	float max1=A[0],max2=A[1];
	if (A[0]<A[1]) {
		max1 = A[1];
		max2 = A[0];
	}
	else if (A[0]>A[1]) {
		max1 = A[0];
		max2 = A[1];

	}
	else {
		max1 = A[0];
		max2 = numeric_limits<float>::min();
	}
	
	for (int i=2; i<N; i++) {	
		if (A[i]>max1) {
			max2 = max1;
			max1 = A[i];
		}
		else if (A[i]>max2 && A[i]!= max1) 
			max2 = A[i];			
	}
	if (max2!=numeric_limits<float>::min())
		cout<<"Max1 ="<<max1<<", Max2 ="<<max2<<endl;
	else
		cout<<" All values are equal to "<<max1<<endl;
		
}

float& doubleMin(float A[],int N) {
	int i,pos=0;
	float min=A[0];
	
	for (int i=1; i<N; i++) 
		if (min > A[i]) {
			min = A[i];
			pos = i;
		}
	A[pos] *= 2;
	return A[pos];
}
    

