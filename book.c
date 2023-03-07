#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"



void book(struct Passenger *a[],struct seats fseats[]){
    int choice;
    int day1;
    char date_of_travel[20];
    char*chosen_from=(char*)malloc(30*sizeof(char));
    char*chosen_to=(char*)malloc(30*sizeof(char));
    char*day_of_travel=(char*)malloc(30*sizeof(char));
    while(1){
        printf("Please choose from where you wish to fly:");
        printf("Mumbai Delhi Bangalore Hyderabad");
        printf("\n");
        scanf("%s",chosen_from);
        printf("Please choose your destination:");
        printf("Mumbai Delhi Bangalore Hyderabad");
        printf("\n");
        scanf("%s",chosen_to);
            
        if(((strcmp(chosen_from,"Mumbai")!=0)&&(strcmp(chosen_from,"Delhi"))&&(strcmp(chosen_from,"Bangalore"))&&(strcmp(chosen_from,"Hyderabad"))||((strcmp(chosen_to,"Mumbai"))&&(strcmp(chosen_to,"Delhi"))&&(strcmp(chosen_to,"Bangalore"))&&(strcmp(chosen_to,"Hyderabad"))))){
                printf("Invalid flight choice");//if input  not from Mumbai Delhi Bangalore Hyderabad 
        }
        else{
            if(strcmp(chosen_from,chosen_to)==0){
                printf("Invalid flight choice\n");// both from and to are equal
            }
            else{
                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);//to find the system date
                int d=tm.tm_mday;
                int m=tm.tm_mon+1;
                int y=tm.tm_year+1900;
                char day[3];
                char month[3];
                char year[5];
                printf("Please type  your date of travel within one week from now");
                scanf("%s",day_of_travel);
                day1=diff(d,m,y,atoi(strncpy(day,day_of_travel+0,2)),atoi(strncpy(month,day_of_travel+2,2)),atoi(strncpy(year,day_of_travel+4,4)));
                fflush(stdin);
                
                if(day1==0){
                printf("Invalid date of travel\n");
                }
                
                else{          //printing the list of flights availabel
                    printf("S.no\t\t\tTIME OF DEPARTURE\t\tTIME OF ARRIVAL\t\t\tFROM\t\t\t\tTO\t\t\t\tAIRLINE COMPANY\t\t\t\tPRICE(Rs)\n");
                    printf("1)\t\t\t4:15  AM\t\t\t6:20  AM\t\t\t%s\t\t\t%s\t\t\t\tIndigo\t\t\t\t%d\n",chosen_from,chosen_to,dynamic_pricing(4000,day1));
                    printf("2)\t\t\t9:55  AM\t\t\t1:00  PM\t\t\t%s\t\t\t%s\t\t\t\tVistara\t\t\t\t%d\n",chosen_from,chosen_to,dynamic_pricing(6000,day1));
                    printf("3)\t\t\t3:05  PM\t\t\t7:00  PM\t\t\t%s\t\t\t%s\t\t\t\tAir India\t\t\t\t%d\n",chosen_from,chosen_to,dynamic_pricing(5000,day1));
                    printf("4)\t\t\t8:25  PM\t\t\t10:25  PM\t\t\t%s\t\t\t%s\t\t\t\tAir Asia\t\t\t\t%d\n",chosen_from,chosen_to,dynamic_pricing(7000,day1));
                    printf("5)\t\t\t11:35 PM\t\t\t1:45  AM\t\t\t%s\t\t\t%s\t\t\t\tGo First\t\t\t\t%d\n",chosen_from,chosen_to,dynamic_pricing(3500,day1));
                    printf("ENTER YOUR CHOICE\n");
                    scanf("%d",&choice);
                    
                    if(choice==1||choice==2||choice==3||choice==4||choice==5){//choice is from the list provided
                        int k=0;
                        int z; 
                        for (int i=0;i<420;i++){
                            if (!strcmp(fseats[i].from,chosen_from)&&!strcmp(fseats[i].to,chosen_to)&&fseats[i].flight_number==choice){//finding the flight in the array
                                k=i;//to find the flight 
                                break;
                            }
                        }                     
                        int NUMBER_OF_PEOPLE;
                        printf("NUMBER OF PEOPLE TRAVELLING?");
                        scanf("%d",&NUMBER_OF_PEOPLE);
                        if(NUMBER_OF_PEOPLE<=0){
                            printf("INVALID NUMBER OF PEOPLE TRAVELLING");
                        }
                        else if(+15-fseats[k].seats-NUMBER_OF_PEOPLE<0){//if number of people is more than   seats available in  flight(total seats available in eac flight=15)
                            printf("No Seats Available\n");
                            break;
                        }
                        else{
                            Passengerdetails(NUMBER_OF_PEOPLE,a,fseats,z,k);
                            payment_complete();
                            printf("\t\t\tTHANK YOU FOR BOOKING WITH KAATIL AIRLINES\n");//thank you message
                            printf("\t\t\tYOUR BOOKING IS CONFIRMED\n");
                            int x=1;
                            
                            while(NUMBER_OF_PEOPLE>0){
                                srand(time(NULL));
                                long long int y=rand();//generate random pnr
                                a[k][fseats[k].seats-NUMBER_OF_PEOPLE].pnr=y;
                                printf("YOUR PNR NUMBER FOR PASSENGER %d IS %lld\n",x,y);
                                NUMBER_OF_PEOPLE=NUMBER_OF_PEOPLE-1;
                                x=x+1;
                            }
                            FILE *backend=fopen("database.txt","w");//updating the databse and seats file
                            for(int i=0;i<420;i++){
                                for (int j=0;j<15;j++){
                                    fprintf(backend,"%s %s %d %d %s %s %s %s %d %lld \n",a[i][j].from,a[i][j].to,a[i][j].flight_number,a[i][j].date1,a[i][j].FirstAndLastname,a[i][j].MiddleName,a[i][j].gen,a[i][j].Email,a[i][j].age,a[i][j].pnr);
                                }
                            }
                            fclose(backend);
                            FILE *seats=fopen("seats.txt","w");
                            for (int i=0;i<420;i++){
                                fprintf(seats,"%s %s %d %d %d\n",fseats[i].from,fseats[i].to,fseats[i].flight_number,fseats[i].date1,fseats[i].seats);
                            }
                            fclose(seats);
                        }
                        break;              
                    }
                    else{
                        printf("PLEASE CHOOSE CORRECT CHOICE\n");//if choice is not from the list provided
                    }
                }
            }   
        }
    }
}
