#include <iostream>
#include <string>
#include<cstdio>
using namespace std;

int main(int argc, char* argv[]) {

   int cust_id=stoi(argv[1]);
   string cust_name=argv[2];
   int units=stoi(argv[3]);
   
   if(argc!=4){
   	cout<<"Invalid Inputs"<<endl;
   	return 1;
   }
   cout<<"Customer ID:"<<cust_id<<endl;
   cout<<"Customer Name:"<<cust_name<<endl;
   cout<<"Units Consumed:"<<units<<endl;
   float amount_charges=35.90*units;
   printf("Amount Charges @Rs. 35.90 per unit:%.2f\n",amount_charges);
   float surcharge=0;
   if(amount_charges>18000){
   	surcharge=0.15*amount_charges;
   }
   cout<<"Surcharge Amount:"<<surcharge<<endl;
   float net=amount_charges+surcharge;
   printf("Net Amount Paid by the Customer:%.2f",net);

    return 0;
}
