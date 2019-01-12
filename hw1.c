/*********************************
*     Mahdi Saeedi-Velashani     *
*     CSCI 230 SP19              *
*********************************/
#include <stdio.h>
#include <stdlib.h>
/***********************************************************
*   This Function calculates the interest on a loan, using *
*   payment amount user has entred                         *
***********************************************************/
void rate_calculation(float p, float r, float b){
   float *i = malloc(12 * sizeof(float));
   int month = 1;
   float amount_toward_loan = 0;
   float total_interest = 0;
   int j = 0;
   while( b > 0){
        if(j == 0){ //calculating first month.
          i[j] = (r/12)*b;
          total_interest = total_interest + i[j];
          printf("%d %.2f %.2f\n", month, i[j], b);
          amount_toward_loan = p - i[j];
        }
        if(j > 0){ //calculating months after the first one
          i[j] = (r/12)*(b-p+i[j-1]);
          b = b - amount_toward_loan;
          printf("%d %.2f %.2f\n", month, i[j], b);
          amount_toward_loan = p - i[j];
          if(i[j] > 0) //making sure positive interests gets added only
            total_interest = total_interest + i[j];
        }
        month++;
        j++;
   }
   printf("Total interest paid: %.2f\n", total_interest);
}
/*************************************************
*                 Main Function                  *
**************************************************/
int main(){
  float p = 0; //monthly payment by user
  float r = 0.25; //anual interest
  float b = 2000.0; //amount of loan
  //user input
  printf("Enter your monthly payment: \n");
  scanf( "%f", &p);
  printf("\n");
  printf("r = %.2f\n", r);
  printf("B = %.1f\n", b);
  printf("P = %.1f\n\n", p);
  rate_calculation(p, r, b);
}
