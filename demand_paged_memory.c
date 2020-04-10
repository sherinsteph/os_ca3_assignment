//Q4) DEMAND PAGED MEMORY---------11807129-----SHERINSTEPHEN------ROLLNO:43----

#include <stdio.h>
#include <stdlib.h>
double page_fault_rate();
void userInput(void);

double spfe;//service_page_fault_empty
double spfm;//service_page_fault_modified
double mat;//mem_access_time
double tpm;//times_page_modified
double eat;//effective_access_time
double pfr;//pageFaultRate
double spfen;//service_page_fault_empty_ns
double spfmn;//service_page_fault_modified_ns
double tpmp;//times_page_modified_per
	

void main(){
	int va1;
	
	do{
	
	
	printf("choice to be selected\n");
	printf("1.Find PageFault Rate\n");
	printf("2.Exit");
	scanf("%d",&va1);
  	if(va1==1){
  		process();
  	}
  	else if(va1==2){
  		exit(0);
  	}
  
	printf("\n\n");

	}while(val<3);
}
void process(){
	
	
	printf("\nEnter service Page Fault");
	scanf("%lf",&spfe);
	printf("Enter Service Page Fault ");
	scanf("%lf",&spfm);
	printf("Enter Memory Access Time");
	scanf("%lf",&mat);
	printf("Enter Percentage of time the page to be replaced is modified");
	scanf("%lf",&tpm);
	printf("Enter Effective Access time[in nanoseconds]");
	scanf("%lf",&eat);

	spfen = (spfe*1000000);
	spfmn = (spfm*1000000);
	tpmp = (tpm/100);   
	printf("\nPage Fault rate calculated For:\n");
	printf("Service Page Fault[Empty|Page Not Modified]=%lf \n",spfen);
	printf("Service Page Fault [Modified Page][in nanoseconds] %lf \n",spfmn);
	printf("Memory Access Time[in nanoseconds]%lf\n",mat);
	printf("Effective Access Time %lf\n",eat);
    	pfr =  page_fault_rate(spfen,spfmn,mat,tpmp,eat);
	printf("\nMaximum Acceptable Page Fault rate = %.2e[exponential notation]",pfr);


}
//calculation of page fault by a function page_fault_rate
double page_fault_rate(double servicePageFaultEmpty,double servicePageFaultMod,double memAccess,double timesPages,double effAccess){
	double assume,serve;
	double numerator,denominator;
	double pageFault;
	 assume = (1- timesPages)*servicePageFaultEmpty;
	 serve = timesPages*servicePageFaultMod;
	 numerator = effAccess - memAccess;
     denominator = (assume+serve);

	pageFault = numerator/denominator;
	return pageFault;


}
