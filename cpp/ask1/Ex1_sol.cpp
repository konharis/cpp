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

STUD * InitStuds ();
void swap (int &, int &);
void swap (STUD &, STUD &);
void ShowStuds (const STUD *, const int);
void SortStuds (STUD *, int);
STUD& GetStudBySemester (STUD[], const int, const int);
int Cube (int len, int=2, int=1);

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
    cout << "Περιεχόμενα Πίνακα:";
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
    
int main0 (int argc, char **argv)
{
    int a = 20;
    int b = 30;
    
    system("chcp 1253");
    swap (a, b);
    cout << "a = " << a << ", b = " << b << endl <<endl;
    
    STUD *st = InitStuds ();
    ShowStuds (st, 3);
    SortStuds (st, 3);
    ShowStuds (st, 3);
    STUD &R = GetStudBySemester (st, 3, 5);
    R.Name = "Changed";
    ShowStuds (st, 3);
    delete[] st;
    
    cout << Cube (2, 3, 4) << endl;
    cout << Cube (2, 3) << endl;
    cout << Cube (2) << endl;
}

//Η γνωστή συνάρτηση swap σε cpp έκδοση με references.
void swap (int &i1, int &i2)
{
    int tmp;
    tmp = i1;
    i1 = i2;
    i2 =tmp;
}

//Η συνάρτηση swap υπερφορτωμένη για struct STUD
void swap (STUD &i1, STUD &i2)
{
    STUD tmp;
    tmp = i1;
    i1 = i2;
    i2 =tmp;
}

//Δημιουργεί έναν δυναμικό πίνακα 3 θέσεων τύπου STUD και τον αρχικοποιεί "καρφωτά"
STUD * InitStuds ()
{
    STUD *tmp = new STUD [3];
    tmp[0].AM = 456;
    tmp[0].Name = "Αντωνίου";
    tmp[0].Semester = 2;
    tmp[1].AM = 123;
    tmp[1].Name = "Βασιλείου";
    tmp[1].Semester = 1;
    tmp[2].AM = 789;
    tmp[2].Name = "Γεωργίου";
    tmp[2].Semester = 5;
    return tmp;
}

//Τυπώνει τα στοιχεία του πίνακα τύπου STUD
void ShowStuds (const STUD *S, const int N)
{
    //N++;
    for (int i = 0; i < N; i++)
        cout << S[i].AM << "   " << S[i].Name << "   " << S[i].Semester << endl;
    cout << endl;
}

//Ταξινομεί τον πίνακα τύπου STUD
void SortStuds (STUD *S, int N)
{
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++) 
            if (S[i].AM > S[j].AM)
                swap (S[i], S[j]);
}
    
//Παράδειγμα συνάρτησης που επιστρέφει αναφορά
STUD& GetStudBySemester (STUD D[], const int S, const int Semester)
{
    int i;
    for (i = 0; i < S; i++)
        if (D[i].Semester == Semester)
            return D[i];
    return D[0];
}

int Cube (int len, int wid, int hei)
{
    return len * wid * hei;
}

