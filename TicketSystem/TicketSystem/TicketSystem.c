#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int main()
{

	struct alldata
	{
		int MovieBooking_Number;
		char Name_of_Customer[30];
		char Name_of_Movie[30];
		char Movie_Schedule[30];
		char time[30];
		int Number_of_Guests;
		int House_Number;
		char Ticket_Type[30];
		float Total_Fee;
	};
	int option;
	char choice;
	int i;
	struct alldata psdata[SIZE];
	int modify;
	int gn;
	float nf;
	char r;
	int j;
	int l;
	float sum;
	FILE* fp;


	struct fuction6
	{
		char problem[50];
		long phno;
		char email[30];
	};
	struct fuction6 support[SIZE];
	FILE* sp;
	char spc;
	char spch;
	int k;


	do
	{
		choice = 'Y';
		printf("*** Welcome to HK Grand SPACE Movie Ticketing Management System 2017 ***\n");
		printf("*** This system is developed by CCIT4020 Class No.NL-03 Group No.03 ***\n");

		printf("--<Basic functions>--\n");

		printf("1.Add New Movie Ticketing Record(s):\n");
		printf("2.Display All Movie Ticketing Records:\n");
		printf("3.Modify Movie Ticketing Record(s):\n");
		printf("4.Search Movie Ticketing Record(s):\n");
		printf("5.Delete Movie Ticketing Record(s):\n");
		printf("______________extra function_____________\n");
		printf("6.Help:\n");
		printf("7. Change number of Guests:\n");
		printf("8. Movie introduction:\n");
		printf("9.The total fee\n");
		printf("What is your option(1-9)\n");
		scanf("%d", &option);
		fflush(stdin);
		switch (option)
		{
		case 1:

			for (i = 0; i < SIZE; i++)
			{
				while (choice == 'Y')
				{
					printf("Please enter 1)Movie Booking Number, 2)Name of Customer, 3)Name of Movie, 4)Movie Schedule,");
					printf("5)Time, 6)Number of Guests, 7)House Number, 8)Ticket Type & 9)Total Fee:\n");
					scanf("%d", &psdata[i].MovieBooking_Number);
					fflush(stdin);
					gets(psdata[i].Name_of_Customer);
					fflush(stdin);
					gets(psdata[i].Name_of_Movie);
					fflush(stdin);
					gets(psdata[i].Movie_Schedule);
					fflush(stdin);
					scanf("%d", &psdata[i].time);
					fflush(stdin);
					scanf("%d", &psdata[i].Number_of_Guests);
					fflush(stdin);
					scanf("%d", &psdata[i].House_Number);
					fflush(stdin);
					gets(psdata[i].Ticket_Type);
					fflush(stdin);
					scanf("%f", &psdata[i].Total_Fee);
					fflush(stdin);
					printf("Add another record(Y/N):");
					scanf("%c", &choice);
					fp = fopen("movie.txt", "a");
					fprintf(fp, "%d\n%s\n%s\n%s\n%d\n%d\n%d\n%s\n%.1f\n\n", psdata[i].MovieBooking_Number,
						psdata[i].Name_of_Customer,
						psdata[i].Name_of_Movie,
						psdata[i].Movie_Schedule,
						psdata[i].time,
						psdata[i].Number_of_Guests,
						psdata[i].House_Number,
						psdata[i].Ticket_Type,
						psdata[i].Total_Fee);
					fclose(fp);
				}
			}
			break;

		case 2:
			fp = fopen("movie.txt", "r");
			i = 0;
			j = 0;
			while (fscanf(fp, "%d,%f", &psdata[i].MovieBooking_Number, &psdata[i].Total_Fee) != EOF)
			{
				fscanf(fp, "%d%c", &psdata[i].MovieBooking_Number, &r);
				fgets(psdata[i].Name_of_Customer, 30, fp);
				fgets(psdata[i].Name_of_Movie, 30, fp);
				fgets(psdata[i].Movie_Schedule, 30, fp);
				fgets(psdata[i].time, 30, fp);
				fscanf(fp, "%d%c", &psdata[i].Number_of_Guests, &r);
				fscanf(fp, "%d%c", &psdata[i].House_Number, &r);
				fgets(psdata[i].Ticket_Type, 30, fp);
				fscanf(fp, "%f", &psdata[i].Total_Fee);
				i++;
				j++;
			}
			fclose(fp);

			for (i = 0; i < j; i++)
			{
				printf("%d\n%s%s%s%s%d\n%d\n%s%.1f\n\n", psdata[i].MovieBooking_Number,
					psdata[i].Name_of_Customer,
					psdata[i].Name_of_Movie,
					psdata[i].Movie_Schedule,
					psdata[i].time,
					psdata[i].Number_of_Guests,
					psdata[i].House_Number,
					psdata[i].Ticket_Type,
					psdata[i].Total_Fee);
			}
			break;

		case 3:

			fp = fopen("movie.txt", "r");

			j = 0;
			i = 0;
			while (fscanf(fp, "%d,%f", &psdata[i].MovieBooking_Number, &psdata[i].Total_Fee) != EOF)
			{
				fscanf(fp, "%d%c", &psdata[i].MovieBooking_Number, &r);
				fgets(psdata[i].Name_of_Customer, 30, fp);
				fgets(psdata[i].Name_of_Movie, 30, fp);
				fgets(psdata[i].Movie_Schedule, 30, fp);
				fgets(psdata[i].time, 30, fp);
				fscanf(fp, "%d%c%d%c", &psdata[i].Number_of_Guests, &r, &psdata[i].House_Number, &r);
				fgets(psdata[i].Ticket_Type, 30, fp);
				fscanf(fp, "%f", &psdata[i].Total_Fee);
				j++;
				i++;
			}
			fclose(fp);

			while (choice == 'Y')
			{

				printf("Enter Movie Booking Number\n");
				scanf("%d", &modify);
				fflush(stdin);


				fp = fopen("movie.txt", "w");
				for (i = 0; i < j; i++)
				{
					if (psdata[i].MovieBooking_Number != modify)
						fprintf(fp, "%d\n%s%s%s%s%d\n%d\n%s%.1f\n\n", psdata[i].MovieBooking_Number, psdata[i].Name_of_Customer, psdata[i].Name_of_Movie, psdata[i].Movie_Schedule, psdata[i].time, psdata[i].Number_of_Guests, psdata[i].House_Number, psdata[i].Ticket_Type, psdata[i].Total_Fee);

					else
					{
						printf("There is no record");
					}
				}
				fclose(fp);

				printf("Please modify 1)Movie Booking Number, 2)Name of Customer, 3)Name of Movie, 4)Movie Schedule,");
				printf("5)Time, 6)Number of Guests, 7)House Number, 8)Ticket Type & 9)Total Fee:\n");
				scanf("%d", &psdata[i].MovieBooking_Number);
				fflush(stdin);
				gets(psdata[i].Name_of_Customer);
				fflush(stdin);
				gets(psdata[i].Name_of_Movie);
				fflush(stdin);
				gets(psdata[i].Movie_Schedule);
				fflush(stdin);
				gets(psdata[i].time);
				fflush(stdin);
				scanf("%d", &psdata[i].Number_of_Guests);
				fflush(stdin);
				scanf("%d", &psdata[i].House_Number);
				fflush(stdin);
				gets(psdata[i].Ticket_Type);
				fflush(stdin);
				scanf("%f", &psdata[i].Total_Fee);
				fflush(stdin);
				printf("Add another record(Y/N):");
				scanf("%c", &choice);
				fp = fopen("movie.txt", "a");


				fprintf(fp, "%d\n%s\n%s\n%s\n%s\n%d\n%d\n%s\n%.1f\n\n", psdata[i].MovieBooking_Number, psdata[i].Name_of_Customer, psdata[i].Name_of_Movie, psdata[i].Movie_Schedule, psdata[i].time, psdata[i].Number_of_Guests, psdata[i].House_Number, psdata[i].Ticket_Type, psdata[i].Total_Fee);

				fclose(fp);
			}
			break;

		case 4:

			fp = fopen("movie.txt", "r");

			j = 0;
			i = 0;
			while (fscanf(fp, "%d,%f", &psdata[i].MovieBooking_Number, &psdata[i].Total_Fee) != EOF)
			{
				fscanf(fp, "%d%c", &psdata[i].MovieBooking_Number, &r);
				fgets(psdata[i].Name_of_Customer, 30, fp);
				fgets(psdata[i].Name_of_Movie, 30, fp);
				fgets(psdata[i].Movie_Schedule, 30, fp);
				fgets(psdata[i].time, 30, fp);
				fscanf(fp, "%d%c%d%c", &psdata[i].Number_of_Guests, &r, &psdata[i].House_Number, &r);
				fgets(psdata[i].Ticket_Type, 30, fp);
				fscanf(fp, "%f", &psdata[i].Total_Fee);
				j++;
				i++;
			}

			fclose(fp);


			while (choice == 'Y')
			{
				printf("\nEnter Movie Booking Number\n");
				scanf("%d", &modify);
				fflush(stdin);
				printf("\n");
				for (i = 0; i < SIZE; i++)
				{
					if (psdata[i].MovieBooking_Number == modify)
					{
						printf("%d\n%s%s%s%s%d\n%d\n%s%.1f\n\n", psdata[i].MovieBooking_Number, psdata[i].Name_of_Customer, psdata[i].Name_of_Movie, psdata[i].Movie_Schedule, psdata[i].time, psdata[i].Number_of_Guests, psdata[i].House_Number, psdata[i].Ticket_Type, psdata[i].Total_Fee);
						printf("Search another customer's movie ticket booking record(Y/N):");
						scanf("%c", &choice);
					}

				}
			}
			break;

		case 5:

			while (choice == 'Y')
			{

				fp = fopen("movie.txt", "r");

				j = 0;
				i = 0;
				while (fscanf(fp, "%d,%f", &psdata[i].MovieBooking_Number, &psdata[i].Total_Fee) != EOF)
				{
					fscanf(fp, "%d%c", &psdata[i].MovieBooking_Number, &r);
					fgets(psdata[i].Name_of_Customer, 30, fp);
					fgets(psdata[i].Name_of_Movie, 30, fp);
					fgets(psdata[i].Movie_Schedule, 30, fp);
					fgets(psdata[i].time, 30, fp);
					fscanf(fp, "%d%c%d%c", &psdata[i].Number_of_Guests, &r, &psdata[i].House_Number, &r);
					fgets(psdata[i].Ticket_Type, 30, fp);
					fscanf(fp, "%f", &psdata[i].Total_Fee);
					j++;
					i++;
				}
				fclose(fp);


				printf("Enter Movie Booking Number\n");
				scanf("%d", &modify);
				fflush(stdin);
				fp = fopen("movie.txt", "w");
				for (i = 0; i < j; i++)
				{
					if (psdata[i].MovieBooking_Number != modify)
						fprintf(fp, "%d\n%s%s%s%s%d\n%d\n%s%.1f\n\n", psdata[i].MovieBooking_Number, psdata[i].Name_of_Customer, psdata[i].Name_of_Movie, psdata[i].Movie_Schedule, psdata[i].time, psdata[i].Number_of_Guests, psdata[i].House_Number, psdata[i].Ticket_Type, psdata[i].Total_Fee);
				}

				fclose(fp);

				printf("Delete Complete\n");
				printf("Remove another customer's movie ticket booking record(Y/N):");
				scanf("%c", &choice);

			}
			break;


		case 6:

			printf("Do you need to submit problem?(Y/N):");
			scanf("%c", &spc);
			fflush(stdin);
			if (spc == 'Y')
			{
				printf("Please enter your problem and the contact: ");
				printf("\n1.Problem:");
				gets(support[i].problem);
				fflush(stdin);
				printf("2.Phone number:");
				scanf("%d", &support[i].phno);
				fflush(stdin);
				printf("3.Email:");
				gets(support[i].email);
				fflush(stdin);

				sp = fopen("support.txt", "a");
				fprintf(sp, "%s\n%d\n%s\n\n", support[i].problem,
					support[i].phno,
					support[i].email);
				fclose(sp);

				printf("\nProblem have been submited!\nThank you for using help system and we will send back a email to you later!\n\n");
			}

			printf("\n\nDo you want to display the problem sumbit record?(Y/N):");
			scanf("%c", &spch);
			fflush(stdin);
			if (spch == 'Y')
			{
				sp = fopen("support.txt", "r");
				i = 0;
				k = 0;
				while (fscanf(sp, "%d", &support[i].phno) != EOF)
				{
					fgets(support[i].problem, 50, sp);
					fscanf(sp, "%d%c", &support[i].phno, &r);
					fgets(support[i].email, 30, sp);
					i++;
					k++;
				}

				for (i = 0; i < k; i++)
				{
					printf("%s%-8d\n%s\n\n", support[i].problem,
						support[i].phno,
						support[i].email);
					fclose(sp);
				}
			}
			break;

		case 7:

			while (choice == 'Y')
			{


				fp = fopen("movie.txt", "r");

				j = 0;
				i = 0;
				while (fscanf(fp, "%d,%f", &psdata[i].MovieBooking_Number, &psdata[i].Total_Fee) != EOF)
				{
					fscanf(fp, "%d%c", &psdata[i].MovieBooking_Number, &r);
					fgets(psdata[i].Name_of_Customer, 30, fp);
					fgets(psdata[i].Name_of_Movie, 30, fp);
					fgets(psdata[i].Movie_Schedule, 30, fp);
					fgets(psdata[i].time, 30, fp);
					fscanf(fp, "%d%c%d%c", &psdata[i].Number_of_Guests, &r, &psdata[i].House_Number, &r);
					fgets(psdata[i].Ticket_Type, 30, fp);
					fscanf(fp, "%f", &psdata[i].Total_Fee);
					j++;
					i++;
				}
				fclose(fp);



				printf("Enter Movie Booking Number\n");
				scanf("%d", &modify);
				fflush(stdin);

				for (i = 0; i < SIZE; i++)
				{

					if (psdata[i].MovieBooking_Number == modify)
					{
						k = 100;
						l = i;
					}

				}
				if (k != 100)
				{
					printf("No record of %d\n", modify);
				}

				else
				{
					printf("\nMovie Booking Number: %d\nName of Customer: %sName of Movie: %sMovie Schedule: %sTime:%sNumber of Guests: %d\nHouse Number: %d\nTicket Type: %sTotal Fee: %.1f\n\n", psdata[l].MovieBooking_Number, psdata[l].Name_of_Customer, psdata[l].Name_of_Movie, psdata[l].Movie_Schedule, psdata[l].time, psdata[l].Number_of_Guests, psdata[l].House_Number, psdata[l].Ticket_Type, psdata[l].Total_Fee);
					printf("Enter Number of Guests\n");
					scanf("%d", &gn);
					fflush(stdin);

					if (gn == 0)
						printf("Please go to option 5 to delete record.\n");

					else if (gn < 0)
						printf("Wrong number is enter\n");

					else
					{
						nf = psdata[l].Total_Fee / psdata[l].Number_of_Guests * gn;
						printf("\nNumber_of Guests change from %d to %d", psdata[l].Number_of_Guests, gn);
						printf("\nTotal Fee change from %.1f to %.1f", psdata[l].Total_Fee, nf);
						printf("\nChange Confirm(Y/N):");
						scanf("%c", &choice);
						fflush(stdin);


						if (choice == 'Y')
						{
							psdata[l].Number_of_Guests = gn;
							psdata[l].Total_Fee = nf;
						}
						else if (choice == 'N')
							break;

						fp = fopen("movie.txt", "w");
						for (i = 0; i < j; i++)
						{
							fprintf(fp, "%d\n%s%s%s%s%d\n%d\n%s%.1f\n\n", psdata[i].MovieBooking_Number, psdata[i].Name_of_Customer, psdata[i].Name_of_Movie, psdata[i].Movie_Schedule, psdata[i].time, psdata[i].Number_of_Guests, psdata[i].House_Number, psdata[i].Ticket_Type, psdata[i].Total_Fee);
						}

						fclose(fp);

						printf("OK\n");
					}
				}printf("Change another customer's movie ticket booking record(Y/N):");
				scanf("%c", &choice);

			}


			break;

		case 8:
		{
			int Answer;
			int key;
			char film[3] = { 'A','B','C' };// We could assume that cinema totally show A , B , C 3 films to customer
			printf("If you want to know more about film?\n");
			printf("Yes ? Please input 1\n");
			printf("No ? Please input 0 \n");
			scanf("%d", &Answer);

			if (Answer == 0)
			{
				printf("\nI will be honored to help you!!!");
			}

			else {
				do
				{
					printf("\n\nThere are 3 film you could wantch. They are A , B , C.");
					printf("\n\nPlease input the name of film which you would like to know more about:");


					scanf("%d", &key);
					switch (key)
					{
					case 1:
						printf("\nThis %c is mainly described.........", film[0]);
						break;
					case 2:
						printf("\nThis %c is mainly described.........", film[1]);
						break;
					case 3:
						printf("\nThis %c is mainly described.........", film[2]);
						break;
					default:
						printf("\nWrong number, please input film again, the number you input should be 1, or 2, or 3");
					}
				} while (key != 1 && key != 2 && key != 3);

			}
		}
		break;


		case 9:
			fp = fopen("movie.txt", "r");
			i = 0;
			j = 0;
			while (fscanf(fp, "%f", &psdata[i].Total_Fee) != EOF)
			{
				fscanf(fp, "%d%c", &psdata[i].MovieBooking_Number, &r);
				fgets(psdata[i].Name_of_Customer, 30, fp);
				fgets(psdata[i].Name_of_Movie, 30, fp);
				fgets(psdata[i].Movie_Schedule, 30, fp);
				fgets(psdata[i].time, 30, fp);
				fscanf(fp, "%d%c%d%c", &psdata[i].Number_of_Guests, &r, &psdata[i].House_Number, &r);
				fgets(psdata[i].Ticket_Type, 30, fp);
				fscanf(fp, "%f", &psdata[i].Total_Fee);
				j++;
				i++;
			}
			fclose(fp);

			int sum = 0;

			for (i = 0; i < j; i++)
			{
				sum = sum + psdata[i].Total_Fee;
			}

			printf("The total fee is %.1f", sum);
			break;

		default:
			printf("\nEnter a wrong number");

		}
	} while (choice == 'N');


	return 0;
}

