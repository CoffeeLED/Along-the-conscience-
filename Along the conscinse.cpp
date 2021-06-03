#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
//====================================functions declaration======================================
int MainMenu(int* choise);
void Conductor(int* choise, int* money, bool* ticket);
void Ticket(int* choise, int* money);
void Title();
void Train(int* choise);
void NeedCheckThis(int* choise, int* trust);
void Jack(int* choise, int* trust);
void Restaurant(int* choise, int* money, int* trust);
void СashBack(int* choise, int* money, int* trust);
void OpenLocker(int* choise);
void Info();
void TheEnds(int* choise);
//==========================Clear the window and insert the title===============================
void Title() {
	system("cls");
	cout << "_______________________________________________________________________________\n";
	cout << "|                          Along the Conscience                               |\n";
	cout << "|                      The autor: Aliaksei Yunevich                           |\n";
	cout << "_______________________________________________________________________________\n";
	cout << endl;
}
void Transmission() {
	cout << endl;
	system("PAUSE");
	Title();
}


//===================================Main menu function=========================================
int MainMenu(int* choise) {
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;
	switch (*choise) {

	case 1:
		cout << endl;
		Title();
		break;
	case 2:
		cout << "let's exit";
		Title();
		break;
	default:
		cout << "Please, write the correct number" << endl;
		cin.clear();
		cin.ignore();
		MainMenu(choise);

		break;

	}
	return *choise;
}
//==============================You buy a ticket (save info in txt file)================================
void Ticket(int* choise, int* money) {
	string name;
	string city;
	bool ticket = false;
	Title();
	cout << "Finally, after waiting for your turn, you come to the ticket machine." << endl;
	cout << endl;
	cout << "	You: Good afternoon, one ticket please." << endl;
	cout << "	Ticketter: Hello, your name, sir." << endl;
	cout << endl;
	cout << "Write your name: ";
	cin >> name;
	cout << endl;
	cout << "	Ticketter: What is your destination?" << endl;
	do {
		cout << endl;
		cout << "Write the city you are going to (Prompt: it's London): ";
		cin >> city;
		cout << endl;
		if (city == "London") {
			cout << "	Ticket-taker: 50 pounds please." << endl;
			cout << "	You: Please. " << endl;
			*money -= 50;
			cout << endl;
			cout << "( " << *money << "$ left in your wallet)" << endl;
			cout << endl;
			cout << "	Ticker: Here you go, your navel is 2-3, don't mix it up." << endl;
			cout << "	You: Thank you so much. " << endl;
			ofstream fileTicket("Ticket.txt");
			fileTicket << "____________________________________________________" << endl;
			fileTicket << "=                  ENGLISH RAILWAY:                 =" << endl;
			fileTicket << "=                       TICKET                      =" << endl;
			fileTicket << "=  Name of passenger: "<< name <<"                   " << endl;
			fileTicket << "=  Destination: "<< city <<"                         " << endl;
			fileTicket << "=  Compartment number: 2-3                          =" << endl;
			fileTicket << "=  Price: 50 pounds                                 =" << endl;
			fileTicket << "=                    Thank you!!!                   =" << endl;
			fileTicket << "=___________________________________________________=" << endl;
			fileTicket.close();
			ticket = true;
			cout << endl;
			system("PAUSE");
			Conductor(choise, money, &ticket);
		}
		else {
			cout << "	Ticketter: There is no such city on the route, are you sure?" << endl;
			cout << "	You: Oh sorry, I wanted to say " << endl;
		}
	} while (city != "London");
}
//==============================Conductor check the ticket================================
void Conductor(int* choise, int* money, bool* ticket) {
	cout << endl;
	Title();
	cout << "Walking to the train entrance, near, you notice a middle-aged woman, as soon as you came closer to the train entrance, she looked down at you." << endl;
	cout << endl;
	cout << "	Conductor: Your ticket, please." << endl;

	if (*ticket == true) {
		cout << "	You: Please." << endl;
		cout << "	Conductor: Thank you, you can take your place in the car." << endl;
		cout << endl;
		system("PAUSE");
	}
	else {
		cout << "	You: Sorry, but I haven't bought it yet." << endl;
		cout << "	Conductor: In that case, you simply have to buy it from the ticket collector over there." << endl;
		cout << "	You: Okay, so I will." << endl;
		cout << endl;
		cout << "In order to board the train, you need a ticket, so at the prompting of the controller you went to the ticket collector to buy a ticket. Approaching the cash register, you see a line of several people. Having decided that there is nowhere to go, you are waiting for your turn." << endl;
		Ticket(choise, money);
	}
}
//==============================read the ticket information from txt file================================
void readticket() {
	char ticketText[55];
	ifstream readFile("Ticket.txt");
	if (readFile.is_open())
	{
		while (readFile.getline(ticketText, 55))
		{
			cout << ticketText << endl;
		}
	}
	else
	{
		cout << "	You: Damn, I can't find a ticket ... ";
	}
	readFile.close();
}
//=========================start location================================
void Peron(int* choise, int* money) {
	bool ticket;
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;

	switch (*choise) {

	case 1:
		Ticket(choise, money);
		break;
	case 2:
		Conductor(choise, money, &ticket);
		break;
	case 3:
		cout << "You open your wallet and you count there " << *money << " pounds." << endl;
		cin.clear();
		cin.ignore();
		Peron(choise, money);

		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		Peron(choise, money);
		break;

	}
}
//===========================You should to find the compartment=============================
void Train(int* choise) {
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;
	int train[2][5] = { { 1, 2, 3}, { 1, 2, 3, 4 } };
	int NumCar;
	int NumCom;
	
	switch (*choise) {

	case 1:
		
			cout << endl;
			Title();
			cout << "Write the correct carriage number: ";
			cin >> NumCar;
			cout << endl;
			cout << "Entering an empty warm carriage, you begin to examine the room for landmarks that will tell you where your room is." << endl;
			cout << "You: Okay, where is my room?" << endl;
			cout << endl;
			
			cout << "Write the correct compartment number: ";
			cin >> NumCom;
			Transmission();
			if (train[NumCar][NumCom] == train[2][3]) {
				cout << "Finally, you have found the right room and now you can rest" << endl;
				cout << endl;
				cout << "	You: Finally, I can rest on the trip home.";
				Transmission();
				cout << "Opening a small bag, cooked in panty in the morning, you satisfy your appetite. You open a slightly shabby novel by Charals Dickens and yourself do not notice how, after a couple of moments, you fall asleep after the journey to the train." << endl;
				cout << endl;
				system("PAUSE");
			}
			else {
				cout << "	Passenger: What do you allow yourself, this is not your compartment, please leave here." << endl;
				cout << endl;
				cout << "	You: Oh, I'm sorry, I was wrong." << endl;
				cout << "	You: Maybe I should take another look at the ticket." << endl;
				cout << endl;
				cout << "	1. No, I remember my compartment number." << endl;
				cout << "	2. View ticket" << endl;
				Train(choise);
			}
		break;
	case 2:
		cout << "You take your ticket from the portomone." << endl;
		cout << endl;
			cout << "You: Let's see ... " << endl;
			readticket();
		cin.clear();
		cin.ignore();
		Train(choise);
		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		Train(choise);
		break;		
	}
}
//===========================You want to check this=============================
void NeedCheckThis(int* choise, int* trust) {
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;

	switch (*choise) {

	case 1:
		cout << "Deciding to visit the neighbors, you get up with the beds, you will notice that they are visible small drops of red. This accident brings you memories of fast fleeing steps, which makes you conclude that the door leading to the compartment is not closed, not closed." << endl;
		cout << endl;
		cout << "	You: What happened there? Answer somebody?" << endl;
		Transmission();
		cout << "Thinking about the fact that something was wrong, you decide to open the door. With a slightly trembling hand, you push the handle down and push the door forward. The picture you see makes your heart pound harder than the steam pistons of a locomotive taking you to where you want to be even more. On the floor, in a pose resembling a proud bird, lay a man with a knife thrust into his right lung." << endl;
		Transmission();
		cout << endl;
		cout << "From the state of shock, you are brought out by a hand that slaps you on the shoulder, looking back at your right side. ";
		cout << "You see a 45-year-old man with a red beard, rather short and a star on the left side of his chest. The sheriff is no different, who else would wear the sheriff's star on his chest." << endl;
		cout << endl;
		cout << "	Sheriff: Hey son, what's going on here?" << endl;
		cout << "	You: I, I don't know, heard a loud bang on the wall and rapidly receding steps." << endl;
		cout << "	Sheriff: Wow, let me blow." << endl;
		*trust = *trust + 3;
		Transmission();
		break;
	case 2:
		cout << "Citing something not alarming, you fall asleep again. But after a while, knock on your door and go to the door. A man with a red beard was knocking, rather short and a sheriff's star on the left side of his chest." << endl;
		cout << endl;
		cout << "	Sheriff: Hey, son, you haven't heard that hour, haven't you seen anyone suspicious?" << endl;
		cout << "	You: No, what happened?" << endl;
		cout << "	Sheriff: The murder happened, and not long ago." << endl;
		cout << "	You: In what sense?" << endl;
		cout << "	Sheriff: In the most direct, in the next compartment, it happened." << endl;
		cout << "After a short questioning of the sheriff, he went to inspect the neighboring compartment for evidence, in the meantime you followed him.";
		*trust = *trust + 1;
		Transmission();
		cout << endl;	
		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		NeedCheckThis(choise, trust);
		break;
	}
}
//===========================You will talk with Jack yourself or sheriff=============================
void Jack(int* choise, int* trust) {
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;
	switch (*choise) {
	case 1:
		cout << "You decide to consult with the Sheriff." << endl;
		Transmission();
		cout << "You are standing in your carriage, waiting for the sheriff, when suddenly a man with a mechanical prosthesis on his leg passes by. You looked at him, which the man did too. With a limp he hid behind the door of another carriage." << endl;
		cout << "Looking back you see a well-known figure, it was the sheriff." << endl;
		cout << endl;
		cout << "	Sheriff: Well, son, did you find anything useful?" << endl;
		cout << "	You: Yes, in the toilet, where the traces of small drops of blood took me, I found a discount ticket to London." << endl;
		cout << "	Sheriff: let me see." << endl;
		Transmission();
		cout << endl;
		cout << "(You give him the ticket.)" << endl;
		cout << endl;
		cout << "	Sheriff: Interesting reading, albeit short. But this country must take care of the disabled." << endl;
		cout << endl;
		cout << "As if the lightning of the almighty Zeus entered your mind, giving a tip to a man who passed by a couple of moments earlier." << endl;
		cout << endl;
		cout << "	You: Sheriff, I think I know what to do .." << endl;
		Transmission();
		cout << "You, together with the sheriff, go to compartment 3-5, knock and the door is opened by the very figure that previously crossed your gaze." << endl;
		cout << endl;
		cout << "	You: Mr. Liam, I suppose ..." << endl;
		cout << "	Liam: Right, young man." << endl;
		cout << "	Liam: And actually, why the question?" << endl;
		cout << "	Sheriff: You are suspected of the murder of the man in compartment 2-4." << endl;
		*trust = *trust + 1;
		cout << "(Index of trust with Sheriff - " << *trust << ")" << endl;
		Transmission();	
		break;
	case 2:
		cout << "You have made a decision to ask Mr. Liam." << endl;
		Transmission();
		cout << "Approaching the door of Jack Liam's compartment, you started knocking on him, but no one opened you." << endl;
		cout << endl;
		cout << "	You: Apparently he is not there now ..." << endl;
		Transmission();
		cout << "After a couple of minutes of waiting, you hear a wheezing speech from behind, it was a man with a mechanical prosthesis on his leg." << endl;
		cout << endl;
		cout << "	Stranger: Do you need something?" << endl;
		cout << "	You: Good evening, are you Jack Liam?" << endl;
		cout << "	Liam: Jack Liam for 60 years, and who are you and what do you want?" << endl;
		cout << "	You: I wanted to know what you know about the murdered man from compartment 2-4?" << endl;
		Transmission();
		cout << "Before Liam could answer, the Sheriff entered the carriage and asked ..." << endl;
		cout << endl;
		cout << "	Sheriff: What's going on here?" << endl;
		cout << "	You: Interviewing a suspect in this case." << endl;
		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		Jack(choise, trust);	
		break;
	}
}
//===========================Restaurant location=============================
void Restaurant(int* choise, int* money, int* trust) {
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;
	switch (*choise) {
	case 1:
		cout << "Communication with the people who were there in the restaurant people, although it was useful, did not bring great results, no one saw anything, however ..." << endl;
		Transmission();
		cout << "a man in a white shirt called you quietly and you decided to approach him." << endl;
		cout << "	Stranger: You're looking for someone who can commit murder, right?" << endl;
		cout << "	You: yes, as I understand it, you have the necessary knowledge?" << endl;
		cout << "	Stranger: It depends on you." << endl;
		cout << endl;
		cout << "It was not hard to guess that this guy was asking for money for information. Is it worth giving him money or can the matter be solved differently?" << endl;
		cout << endl;
		cout << "	1. Give money" << endl;
		cout << "	2. Convince his" << endl;
		СashBack(choise, money, trust);
		cout << endl;
		cout << "This stranger told that when he was in the toilet, in your carriage, he heard someone almost bursting, right from there he heard his fear and excitement." << endl;
		cout << endl;
		cout << "(You find the new information)" << endl;
		cout << endl;
		cout << "	You: Thanks for the information." << endl;
		cout << "	You: It turns out that the killer was not interested in his actions." << endl;
		Transmission();
		cout << "After talking with the man, you noticed a young waiter, he does not have white mittens. This makes you suspicious, because this is the strictest violation of the rules of service. After serving coffee, the young waiter leaves for the staff room. Realizing that something is wrong here. You decide to follow him." << endl;
		break;
	case 2:
		Transmission();
		cout << "You decided to sit down and watch, ordering a cup of coffee along the way, a young guy brought it to you, as soon as the young man held out a cup, you notice that he has no mittens. This makes you suspicious, because this is the strictest violation of the rules of service. After serving coffee, the young waiter leaves for the staff room. Realizing that something is wrong here. You decide to follow him." << endl;
		Transmission();
		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		Restaurant(choise, money, trust);
		break;
	}
}
//===========================Usefull information=============================
void СashBack(int* choise, int* money, int* trust) {

	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;
	switch (*choise) {
	case 1:
		cout << endl;
		cout << "You decide to give him money." << endl;
		*money -= 10;
		cout << endl;
		cout << "( " << *money << " pounds left in your wallet)" << endl;
		cout << endl;
		cout << "	Stranger: Thanks for contributing to my retirement fund." << endl;
		cout << "	You: So what? Does your memory wake up?" << endl;
		Transmission();
		break;
	case 2:
		cout << endl;
		if (*trust > 3)
			cout << "By referring to the sheriff, you still teach the necessary information." << endl;
		else {
			cout << endl;
			cout << "	Stranger: Hah, made fun." << endl;
			cout << endl;
			cout << "	1. Give money" << endl;
			cout << "	2. Convince his" << endl;
			СashBack(choise, money, trust);
		}
		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		СashBack(choise, money, trust);
		break;

	}
}
//===========================lockers=============================
void OpenLocker(int* choise) {
	int locker[2][10];
	cout << endl;
	cout << "Your choise: ";
	cin >> *choise;
	switch (*choise) {
	case 1:
		for (int o = 1; o < 2; o++) {
			for (int l = 1; l < 10; l++) {
				if (locker[o][l] != locker[2][5]) {
					if (o == 1) {
					Transmission();
					cout << "(You open the locker №" << l << " from sector №1)" << endl;
					cout << endl;
					cout << "	You: Nothing ... " << endl;
					} 
					else if (o == 2) {
						Transmission();
						cout << "(You open the locker №" << l << " from sector №2)" << endl;
						cout << endl;
						cout << "	You: Nothing ... " << endl;
						
					}
				}
				else {	
					cout << "You: Bingo ..." << endl;
					
				}
			}
		}
		break;
	case 2:
		
			Transmission();
			int section;
			int ambry;
			cout << "	You: Section №1 or №2" << endl;
			cout << endl;
			cout << "Write the section number:";
			cin >> section;
			cout << "	You: What is the number of the locker I need?" << endl;
			cout << endl;
			cout << "Write the section number: ";
			cin >> ambry;
			if (section == 2 && ambry == 5) {
				cout << "You: Bingo ..." << endl;
				Transmission();
			}
			else {
				Transmission();
				cout << "	You: Nothing ..." << endl;
				cout <<  endl;
				cout << "	1. Open in order." << endl;
				cout << "	2. open any locker." << endl;
				OpenLocker(choise);
			}
		
		break;
	default:
		cout << "Please, write the correct number" << endl;
		cin.clear();
		cin.ignore();
		OpenLocker(choise);
		break;
	}
}
//===========================Information=============================
void Info() {
	cout << "	You: Victim of the noble family." << endl;
	cout << "	You: Killing was not part of the criminal's plans." << endl;
	cout << "	You: Mr. Liam's ticket in the 'bloody toilet.'" << endl;
	cout << "	You: Liam Freddie drank whiskey with the victim in the last hours of his life." << endl;
	cout << "	You: Waiter's soiled gloves." << endl;
	cout << "	You: The killer was shocked by the creation, which suggests that killing was not part of his plans." << endl;
	Transmission();
}
//===========================TheEnds of the game=============================
void TheEnds(int* choise) {
	cout << "Sheriff: Who's the killer after all?" << endl;
	cout << endl;
	cout << "	1. Jack Liam" << endl;
	cout << "	2. Waiter" << endl;
	cout << "	3. Leon Freddy" << endl;
	cout << "	4. Summarize again" << endl;
	cout << endl;
	cout << "Your choise:";
	cin >> *choise;
	switch (*choise) {
	case 1:
		cout << "	You: I think it's Jack Liam." << endl;
		cout << "	Sheriff: I think so too." << endl;
		Transmission();
		cout << "Jack Liam was arrested by the police upon the train's arrival in London.";
		Transmission();
		cout << "Soon the court proved Jack Liam's innocence in this case and he was released.";
		Transmission();
		cout << "The sheriff never saw you again. Your paths parted forever.";
		break;
	case 2:
		cout << "	You: I think this is the Waiter" << endl;
		cout << "	Sheriff: I think so too." << endl;
		Transmission();
		cout << "Upon the arrival of the train in London, the police arrested the Waiter suspected of the case.";
		Transmission();
		cout << "The police identified him, this waiter was Frederick Darby.";
		Transmission();
		cout << "Soon the court proved the guilt of Jack Liam and sentenced him to 7 years in prison.";
		Transmission();
		cout << "The sheriff noted your deduction skills and offered to work with him as a detective, you agreed. Yours worked together for a long time.";
		cout << endl;
		break;
	case 3:
		cout << "	You: I think it's Jack Liam" << endl;
		cout << "	Sheriff: I think so too." << endl;
		Transmission();
		cout << "Jack Liam was arrested by the police upon the train's arrival in London.";
		Transmission();
		cout << "Soon the court proved Jack Liam's innocence in this case and he was released.";
		Transmission();
		cout << "The sheriff never saw you again. Your paths parted forever.";
		break;
	case 4:
		Info();
		TheEnds(choise);
		break;
	default:
		cout << "Please, write the correct number." << endl;
		cin.clear();
		cin.ignore();
		TheEnds(choise);
		break;
	}
}
//=======================================main function=========================================
int main()
{
	int money = 75;
	int choise;
	int trust = 0;
	cout << "_______________________________________________________________________________\n";
	cout << "|                          Along the Conscience                               |\n";
	cout << "|                      The autor: Aliaksei Yunevich                           |\n";
	cout << "_______________________________________________________________________________\n";
	cout << endl;
	cout << "	1. start the story" << endl;
	cout << "	2. exit" << endl;
	cout << endl;
	MainMenu(&choise);
	cin.clear();
	cin.ignore();
	cout << endl;
	cout << "Once you were about to take the train home from Newcastle to London after meeting an old childhood friend, and when you take a taxi to the station, you find a train." << endl;
	cout << endl;
	cout << "	You: Yeah, here's the train. all that remains is to buy a ticket and sit down." << endl;
	cout << endl;
	cout << "	1. Go to the ticketter" << endl;
	cout << "	2. Take the train" << endl;
	cout << "	3. Count money in the wallet" << endl;
	Peron(&choise, &money);
	Title();
	cout << endl;
	cout << "Having entered the vestibule of the train, you looked around and thought: what is your compartment number. Looking up, above the door you saw the number of the carriage in which you are located (№1)" << endl;
	cout << endl;
	cout << "	You: I seem to remember which number of my compartment, but in which case I can look at the ticket." << endl;
	cout << endl;
	cout << "	1. Enter the desired carriage" << endl;
	cout << "	2. View ticket" << endl;
	Train(&choise);
	Title();
	cout << "After a while, you wake up from a sharp blow against the wall, a choking sound and quick fleeing steps from the next compartment. You were seized by bewilderment and slight fright." << endl;
	cout << "	You: Damn, what was that? Can I go check it out?" << endl;
	cout << endl;
	cout << "	1. Go check the neighbors" << endl;
	cout << "	2. Stay in compartment" << endl;
	NeedCheckThis(&choise, &trust);
	Title();
	cout << endl;
	cout << "The sheriff looked at this picture, looking over every detail in the compartment, you notice his decisive attitude, on every vein of his face you can see the whole life experience accumulated over the years of serving the country. After some time, he began to examine the deceased." << endl;
	Transmission();
	cout << "	You: Have you learned anything, mister sheriff?" << endl;
	cout << "	Sheriff: Just a little, look at his jacket, you see the brand, 'Green Vine', I give my golden teeth that he is a man of noble family, I don't think that a man working in a factory will pull such a" << endl;
	cout << endl;
	cout << "(You find the new information)" << endl;
	cout << endl;
	cout << "	Sheriff: besides, he has a mini mechsafe under his bed, besides ..." << endl;
	cout << "	You: besides what?" << endl;
	cout << "	Sheriff: There are signs of a break-in on it, but no robbery, I think killing was not part of his plans." << endl;
	cout << endl;
	cout << "(You find the new information)" << endl;
	cout << endl;
	Transmission();
	cout << "	You: It makes sense." << endl;
	cout << "	You: It turns out that the killer still lives among us among the passengers of the train, I don't think that at a speed of 80 km / h he will want to jump from it." << endl;
	cout << "	You: Moreover, we still have about an hour." << endl;
	cout << "	Sheriff: Why did you decide that?" << endl;
	cout << "	You: Because the next stop is the final one, since the murder took place after that stop, I can say for sure that he can only get off in London." << endl;
	cout << "	Sheriff: And you are smart. I would not want to drag you into this, but I really need your help." << endl;
	cout << "	You: We don't even know each other, but you already trust me?" << endl;
	cout << endl;
	cout << "(Index of trust with Sheriff - " << trust << ")" << endl;
	cout << endl;
	Transmission();
	cout << "	Sheriff: Alone, it will be difficult to unravel this case with so little time. Moreover, I do not think that the killer will stand over his victim for so long." << endl;
	cout << endl;
	cout << "Although the answer was clear, the question was still spinning in my head, 'is it worth trusting?'"  << endl;
	cout << endl;
	cout << "(You find the new information)" << endl;
	cout << endl;
	cout << "	You: It makes sense. Any idea where to start?" << endl;
	cout << "	Sheriff: We should look around, maybe we can find more leads." << endl;
	cout << "	You: I think it makes sense." << endl;
	cout <<	"	Sheriff: In that case, let's go on opposite sides of the train. We'll meet here in a few minutes." << endl;
	Transmission();
	cout << "	Walking along the next car, you notice barely visible red footprints leading to the toilet, without hesitation you go there. In the ajar, you notice footprints on the sink." << endl;
	cout << "	You: Hmm ... there are traces on the sink, apparently he was trying to rinse the blood off his hands." << endl;
	cout << "	You: So stop is that behind the trash can?" << endl;
	cout << endl;
	cout << "You find a ticket behind the trash can." << endl;
	Transmission();
	cout << "Weeeell, it's interesting..." << endl;
	cout << " ___________________________________________________ " << endl;
	cout << "=                  ENGLISH RAILWAY:                 =" << endl;
	cout << "=                       TICKET                      =" << endl;
	cout << "=  Name of passenger: Jack Liam                     =" << endl;
	cout << "=  Destination: London                              =" << endl;
	cout << "=  Compartment number: 3-5                          =" << endl;
	cout << "=  Price: 25 pounds (Discount 50%)                  =" << endl;
	cout << "=                    Thank you!!!                   =" << endl;
	cout << "=___________________________________________________=" << endl;
	cout << endl;
	cout << "(You find the new information)" << endl;
	Transmission();
	cout << "You: Looks like this ticket belongs to someone named Jack Liam. Could it be the killer? Should I tell the sheriff about it?" << endl;
	cout << endl;
	cout << "	1. Go tell the sheriff and make a decision together." << endl;
	cout << "	2. Ask Jack Liam." << endl;
	cout << endl;
	Jack(&choise, &trust);
	cout << "	Liam: Am I a suspect? Why such sudden conclusions?" << endl;
	cout << "	You: we found your ticket in the toilet next to the traces of blood in the sink." << endl;
	cout << "	Liam: Impossible ... my ticket is always in my pocket with a napkin." << endl;
	Transmission();
	cout << endl;
	cout << "	Liam pulls his hand to his pocket in bewilderment, not finding a ticket there, he begins to search for it in other pockets, without any result, he looks with even greater bewilderment at the ticket you handed out that you found in the toilet." << endl;
	cout << endl;
	cout << "	Sheriff: Now I think it's time for you to answer our questions." << endl;
	cout << "	Liam: Nothing against it." << endl;
	cout << endl;
	cout << "In the process of questioning, you learn that he is a veteran of the Egyptian war, traveling to visit his late sister, who lived in York. And he apparently dropped the ticket by accident when he wiped his hands, because it was in one pocket. When he wiped his hands, there was no trace of blood. Behind him in the compartment you see lying napkins and hand gel, apparently he has hygiene first of all." << endl;
	cout << endl;
	cout << "(You find the new information)" << endl;
	cout << endl;
	cout << "	You: Thank you for your attention ..." << endl;
	Transmission();
	cout << endl;
	cout << "	You: What do you think of him?" << endl;
	cout << "	Sheriff: He is very muddy, I smell something he is hiding." << endl;
	cout << "	You: Anything is possible, but don't jump to conclusions." << endl;
	cout << endl;
	cout << "(Index of trust with Sheriff - " << trust << ")" << endl;
	cout << endl;
	cout << "	You: What to do now?" << endl;
	cout << "	Sheriff: It would be reasonable to split up again to learn something useful." << endl;
	cout << "	You: makes sense." << endl;
	cout << endl;
	cout << "You decide to go to the restaurant car and ask someone there ..." << endl;
	Transmission();
	cout << "There was nothing surprising about the restaurant car." << endl;
	cout << endl;
	cout << "	1. Ask those present." << endl;
	cout << "	2. Sit and watch." << endl;
	Restaurant(&choise, &money, &trust);
	cout << "Peeping, you see that he put something in the locker, however, due to the risk of impersonating yourself, you did not see what kind of locker it was." << endl;
	cout << endl;
	cout << "	You: Great, he's gone, now let's see what you're hiding there, just how can I figure out what kind of locker it is." << endl;
	cout << endl;
	cout << "	1. open in order." << endl;
	cout << "	2. open any." << endl;
	OpenLocker(&choise);
	Transmission();
	cout << "	You found a cabinet with the initials 'F.D.', and there were gloves stained with something red, you suspect that this is not wine, although you cannot identify the substance by smell, since the gloves are soaked in detergent." << endl;
	cout << endl;
	cout << "	You: Interestingly, events are developing. It's hard to say if it's blood or some kind of red wine, suddenly he accidentally spilled it." << endl;
	Transmission();
	cout << "There was nothing surprising about the restaurant car." << endl;
	cout << endl;
	cout << "	After you took the evidence, you decided it would be better to leave. In your carriage, you met with the sheriff at the appointed time." << endl;
	cout << "	Sheriff: We're running out of time." << endl;
	cout << "	You: Indeed..." << endl;
	Transmission();
	cout << "	You: Have you learned anything new?" << endl;
	cout << "	Sheriff: I can tell we have another suspect." << endl;
	cout << "	Sheriff: Blond in a brown jacket, I found out they were old friends." << endl;
	cout << "	You: Why did you decide that he is a murderer?" << endl;
	cout << "	Sheriff: But because he was sitting with him at the time of the murder in the compartment and drank a bottle of whiskey, then they quarreled for personal reasons and he went into his compartment, accordingly taking whiskey with him, he still has it on his table." << endl;
	cout << "	You: how is it, and what is his name?" << endl;
	cout << "	Sheriff: Leon Freddy ..." << endl;
	cout << endl;
	cout << "(You find the new information)" << endl;
	cout << endl;
	Transmission();
	cout << "	Sheriff: What did you find out?" << endl;
	cout << "	You: admire ..." << endl;
	cout << endl;
	cout << "(You take out the waiter's gloves)" << endl;
	cout << endl;
	cout << "	You: I noticed the waiter was walking around without the gloves intended for him, that's what they are." << endl;
	cout << "	Sheriff: I wonder what prevented him from throwing them away?" << endl;
	cout << "	You: I don't think it would be smart to throw away the part of the uniform with your initials?" << endl;
	cout << "	Sheriff: Are the employee's initials stitched there?" << endl;
	cout << "	Sheriff: Well done son, I won't go into details of how you got them, but I think we have enough of this knowledge, and there is no time to look for others." << endl;
	cout << "	You: I think it's time to take stock of what we know." << endl;
	cout << "	Sheriff: Agree ..." << endl;
	Transmission();
	Info();
	TheEnds(&choise);
}