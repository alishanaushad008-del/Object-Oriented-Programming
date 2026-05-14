//Question no#4
#include<iostream>
using namespace std;
//Iam using void function with argument
void addMatrix(int A[3][3], int B[3][3], int sum[3][3]){
       for (int i=0;i<3;i++){
           
      for( int j=0;j<3;j++){
          
          sum[i][j]=A[i][j] +B[i][j];
    
    }
       }
}

void multiplyMatrix(int A[3][3], int B[3][3], int product[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            product[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
         }
   }


int main (){
     int A[3][3];
     int B[3][3];
     int sum[3][3];
     int product[3][3];
 cout<<"\nEnter element of 1st matrix:\n";
 for (int i=0;i<3;i++){
     for( int j=0;j<3;j++){
         cin>>A[i][j];
           }
          }
     
      cout<<"\nEnter element of 2nd matrix:\n";
 for (int i=0;i<3;i++){
     for( int j=0;j<3;j++){
         cin>>B[i][j];
           }
         }
     
     
     addMatrix(A,B,sum);
     cout<<"\nsum of matrices:\n";
     for (int i=0;i<3;i++){
     for( int j=0;j<3;j++){
         cout<<sum[i][j]<<" ";
    }
    cout<< endl;
     }
      multiplyMatrix(A,B,product);
     cout<<"\nproduct of matrices:\n";
     for (int i=0;i<3;i++){
     for( int j=0;j<3;j++){
         cout << product[i][j] <<" ";
     }
    cout<< endl;
     }
     return 0;
}

