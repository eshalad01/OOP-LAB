#include <iostream>
#include <string>
#include<cstdio>
using namespace std;

int main(int argc, char* argv[]) {

   string movie_name=argv[1];
   float adult_tckt=stof(argv[2]);
   float child_tckt=stof(argv[3]);
   int a_tckt_sold=stoi(argv[4]);
   int c_tckt_sold=stoi(argv[5]);
   float percentage=stof(argv[6]);
   
   if(argc!=7){
   	cout<<"Invalid Inputs"<<endl;
   	return 1;
   }
   float gross=(adult_tckt*a_tckt_sold)+(child_tckt*c_tckt_sold);
   float donated=(percentage/100)*gross;
    float net_sale=gross-donated;
   printf("\n%-40s %s", "Movie Name:", movie_name.c_str());
    printf("\n%-40s %d", "Number of Tickets Sold:", a_tckt_sold + c_tckt_sold);
    printf("\n%-40s $%8.2f", "Gross Amount:", gross);
    printf("\n%-40s %7.2f%%", "Percentage of Gross Amount Donated:", percentage);
    printf("\n%-40s $%8.2f", "Amount Donated:", donated);
    printf("\n%-40s $%8.2f\n", "Net Sale:", net_sale);

   
    return 0;
}
