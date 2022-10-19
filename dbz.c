#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
void loading();
class user
{
	char usernm[20], pass[20],status[30];
	public:
	char date[30];
	void in();
	void up();
	char *retpw()
	{
		return pass;
	}
	char *retnm()
	{
		return usernm;
	}
	char *retstatus()
	{
		return status;
	}
	char *retdate()
	{
		return date;
	}
	void modstatus(char str[30])
	{
		strcpy(status,str);
	}
	void setpw(char* p)
	{
		strcpy(pass,p);
	}
	void setnm(char* u)
	{
		strcpy(usernm,u);
	}

};

 void user::up()
 {
	cout<<"The user name is:"<<usernm<<"\n The status is:"<<status<<"\nThe date is:"<<date;
 }


  void user::in()
  {
	int z,i,b=8;
	clrscr();
	gotoxy(22,7);
	for(i=0;i<35;i++)
		cout<<"<";
	gotoxy(21,8);
	for(i=0;i<9;i++,b++)
	{
		cout<<"^";
		gotoxy(21,b);
	}
	gotoxy(22,16);
	for(i=0;i<35;i++)
		cout<<">";
	gotoxy(57,15);
	for(i=0,z=15;i<9;i++,z--)
	{
		cout<<"^";
		gotoxy(57,z);
	}
	gotoxy(36,9);
	cout<<"LOGIN";
	gotoxy(28,11);
	cout<<"PLAYER NAME :";
	gotoxy(28,13);
	cout<<"PASSWORD  :";
	gotoxy(28,15);
	cout<<"DATE (dd/mm/yy) :";
	gotoxy(41,11);
	gets(usernm);
	gotoxy(39,13);
	gets(pass);
	gotoxy(45,15);
	gets(date);
	clrscr();
}

class character
{
	char um[20],sm[30];
	int hp,mp,ump;
	char name[30];
	public:
	character()
	{
		hp=200;
		mp=150;
		ump=2;
		strcpy(um,"SPIRIT BOMB");
	}
	void nment(char nm[30])
	{
		strcpy(name,nm);
	}
	void updatehp(int rhp)
	{
		hp-=rhp;
	}
	void updatemp(int rmp)
	{
		mp-=rmp;
	}
	void updateump()
	{
		ump--;
	}
	void updatesm(char sign[30])
	{
		strcpy(sm,sign);
	}
	char*retsm()
	{
		return sm;
	}
	char*retum()
	{
		return um;
	}
	char*retname()
	{
		return name;
	}
	int rethp()
	{
		return hp;
	}
	int retmp()
	{
		return mp;
	}
	int retump()
	{
		return ump;
	}
};

void game(user &ob3);

void loading()
{
	clrscr();
	int b=0;
	char ch1[]="DRAGON BALL XENOVERSE";
	_setcursortype(_NOCURSOR);
	gotoxy(26,10);
	while(b<strlen(ch1))
	{
		cout<<ch1[b++];
		delay(100);
	}
clrscr();
	int i,a=0;
	char ch[]="LOADING";
	_setcursortype(_NOCURSOR);
	gotoxy(32,10);
	while(a<strlen(ch))
	{
		cout<<ch[a++];
		delay(300);
	}
	gotoxy(18,13);
	for(i=0;i<45;i++)
	{
		delay(30);
		cout<<"_";
}
	_setcursortype(_NORMALCURSOR);
}

void signup(user &ob3)
{
     ofstream fout;
     fout.open("pwd.dat",ios::app|ios::binary);
     ob3.in();
     fout.write((char*)&ob3,sizeof(ob3));
     fout.close();
     cout<<"You have successfully signed up\n";
     getch();
     clrscr();
}

int signin(user &s)
{
	char u[20], p[20];
	int z,i,b=8;
	ifstream fin;
	fin.open("pwd.dat",ios::in|ios::binary);
	clrscr();
	gotoxy(22,7);
	for(i=0;i<35;i++)
	cout<<"<";
	gotoxy(21,8);
	for(i=0;i<9;i++,b++)
	{
		cout<<"^";
		gotoxy(21,b);
	}
	gotoxy(22,16);
	for(i=0;i<35;i++)
		cout<<">";
	gotoxy(57,15);
	for(i=0,z=15;i<9;i++,z--)
	{
		cout<<"^";
		gotoxy(57,z);
	}
	gotoxy(36,9);
	cout<<"LOGIN";
	gotoxy(28,11);
	cout<<"PLAYER NAME :";
	gotoxy(28,13);
	cout<<"PASSWORD  :";
	gotoxy(41,11);
	cin>>u;
	gotoxy(39,13);
	cin>>p;
	int play=0,f=0,w=0;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if((strcmp(u,s.retnm())==0)&&(strcmp(p,s.retpw())==0))
		{
			f=1;
			play++;
			if(strcmp(s.retstatus(),"WIN")==0)
			w++;


		}
	}loading();
if(f==0)
	{
gotoxy(45,17);
		cout<<"\nIncorrect data entered ";
		getch();
		clrscr();
		return(0);
	}
	else
       	{
		clrscr();
		cout<<u<< " Has fought for us: "<<play;
		cout<<"\nHas won: "<<w;
		fin.close();
		ofstream fout("pwd.dat",ios::app|ios::binary);
		s.setpw(p);
		s.setnm(u);
		cout<<"\nEnter the date:(dd/mm/yy)";
		cin>>s.date;
		fout.write((char*)&s,sizeof(s));
		fout.close();
		getch();
		clrscr();
		return(1);
       	}
}

void FAtt(character &ob1,char fa[30])
{
	int f=random(2);
	if(f==0)
	{
		strcpy(fa,"DEATH GRIP");
		cout<<"\nFrieza used: "<<fa;
		ob1.updatehp(30);
	}
	else if(f==1)
	{
		strcpy(fa,"KI DRAIN");
		cout<<"\nFrieza used: "<<fa;
		ob1.updatehp(40);
	}
	else if(f==2)
	{
		strcpy(fa,"DEATH BALL");
		cout<<"\nFrieza used: "<<fa;
		ob1.updatehp(50);
	}
}

void main()
{
	user ob3;
	int h;
	clrscr();
	randomize();
	do
	{
		clrscr();
		cout<<"Do you want to\n (1)SIGNIN\n (2)SIGNUP \n (3)EXIT";
		cin>>h;
		if(h==1)
		{
			int x=signin(ob3);
			if(x==1)
			game(ob3);
		}
		else if(h==2)
		{
			signup(ob3);
			game(ob3);
		}
			getch();
	}while(h!=3);
}

void game(user &ob3)
{
	int a=400,x,h;
	char sign[30],fa[30];
	character ob1;
	char c;
	cout<<"TRUNKS:\nFreiza \nThe ruler of chaos has been reborn with the help of the shadow          
                              dragon balls back on Earth... \nYou are our only hope... our gleam of victory... \nI,           
                             Trunks will be your mentor and guide you to your       
                              VICTORY...DESTINY...PEACE"<<endl;
	getch();
	clrscr();
	cout<<"TRUNKS:\nDo you remember anything...\nI've got a good feeling about 
                              you..."<<endl;
	getch();
	clrscr();
	ob1.nment(ob3.retnm());
	clrscr();
	cout<<"TRUNKS:\nYou have to train... "<<ob1.retname()<<" But for now...here are your 
                              power levels"<<endl;
	cout<<"UMP="<<ob1.retump()<<"\nMP="<<ob1.retmp()<<"\nHP="<<ob1.rethp()<<endl;
	getch();
	clrscr();
	cout<<"TRUNKS:\nDo you wish to train?";
	cout<<"Choose 'Y' for yes...\nYou can't go back if you choose anything else we're not Whis 
                              anyway...\nChoose wisely";
	cin>>c;
	if(c=='Y'||c=='y')
	{
		cout<<"Wise choice savior...I'll take you to the Supreme Kai...\nHe will train 
                                            you!"<<endl;
		if(random(4)==0)
		{
			cout<<"After all your hardwork in the hyperbolick time chamber...\nYou 
                                                           learnt GALLICK GUN";
			strcpy(sign,"GALLICK GUN");
			ob1.updatesm(sign);
			getch();
			clrscr();
		}
		else if(random(4)==1)
		{
			cout<<"After all your hardwork in the hyperbolick time chamber...\nYou 
                                                          have learnt FINAL FLASH";
			strcpy(sign,"FINAL FLASH");
			ob1.updatesm(sign);
			getch();
			clrscr();
		}
		else if(random(4)==2)
		{
			cout<<"After all your hardwork in the hyperbolick time chamber...\nYou 
                                                           have learnt KAMEHAMEHA";
			strcpy(sign,"KAMEHAMEHA");
			ob1.updatesm(sign);
			getch();
			clrscr();
		}
		else if(random(4)==3)
		{
			cout<<"After all your hardwork in the hyperbolick time chamber...\nYou 
                                                           have learnt DRAGON FIST";
			strcpy(sign,"DRAGON FIST");
			ob1.updatesm(sign);
			getch();
			clrscr();
		}

	}
	cout<<"\nI hope your ready...IKUZO!!!"<<endl;
	cout<<"**Trunks and I use instant transmission to get to the battle field...\nIt's the Cell 
                             Games Arena.\nI hope I'm ready, I hope I'm all that Trunks hopes for...\nI 
                             hope...No...I KNOW I'll beat him!!!**"<<endl;
	getch();
	clrscr();
	cout<<"FREIZA:\nI was waiting for you Human...\nI could sense your Power level from 
                              here...\nIt's been a long time since I've had fun..."<<endl;
	cout<<"TRUNKS:\nStead fast, It's time...Gambane!"<<endl;

 do
 {
	cout<<"\nChoose your Move - \n1 for melee attack \n2 for Ki attack, \n3 for your signature 
                             move \n4 for your ultimate move"<<endl;
	cin>>x;
	switch(x)
	 {
		 case 1:
			 cout<<"You used METEOR MASH";
			 a-=50;
			 if(a<0)
			 a=0;
			 FAtt(ob1,fa);
			 if(ob1.rethp()<0)
			 cout<<"\nDon't worry...you have "<<ob1.rethp()<<" life left...\nBut I think 
                                                            it's working...He has "<<a<<" life left"<<endl;
			 break;

		case 2:
			if(ob1.retmp()>=20)
			{
				cout<<"You used KI BLAST";
				a-=70;
				if(a<0)
				a=0;
				ob1.updatemp(20);
				FAtt(ob1,fa);
				cout<<"\nDon't worry...you have "<<ob1.rethp()<<" life left...\nBut I 
                                                                        think it's working...He has "<<a<<" life left"<<endl;
				break;
			}
			else
			{
				cout<<"You don't have that much Ki left in your body...";
				break;
			}

		case 3:
			if(ob1.retmp()>=30&&(c=='y'||c=='Y'))
			{
				ob1.retmp();
				cout<<"You used "<<ob1.retsm();
				a-=80;
				if(a<0)
				a=0;
				ob1.updatemp(30);
				FAtt(ob1,fa);
				cout<<"\nDon't worry...you have "<<ob1.rethp()<<" life left...\nBut I 
                                                                       think it's working...He has "<<a<<" life left"<<endl;
				break;
			}
			else if(ob1.retmp()>=30)
			{
				cout<<"You don't have that much Ki left in your body...";
				break;
			}

		case 4:
			if(ob1.retump()>0)
			{
				cout<<"You used "<<ob1.retum();
				a-=100;
				ob1.updateump();
				if(a<0)
				a=0;
				ob1.updatemp(50);
				FAtt(ob1,fa);
				cout<<"\nDon't worry...you have "<<ob1.rethp()<<" life left...\nBut I 
                                                                          think it's working...He has "<<a<<" life left"<<endl;
				break;
			}
			else
			{
				cout<<"You don't have that much Ki left in your body...";
				break;
			}

		default:
			 cout<<"Don't be so reckless...Choose your move wisely";
			 break;
	}
  }while((a>0)&&(ob1.rethp()>0));

  if(a==0)
  {
	clrscr();
	cout<<"Your health:"<<ob1.rethp()<<"\nFreiza's health:"<<a;
	cout<<"\nTRUNKS:\nI cannot sense his power level...\nI think you have done it...\nI think 
                             its finally over...\nNow peace will reign over the xenoverse for a long,long 
                             time.\nBut you can never be too sure...";
	user ob4;
	fstream f;
	f.open("pwd.dat",ios::in|ios::out|ios::binary);
	while(f.read((char*)&ob4,sizeof(ob4)))
	{
		if((strcmp(ob4.retnm(),ob3.retnm())==0)&&(strcmp(ob4.retdate(),ob3.retdate())==0))
		{
			ob4.modstatus("WIN");
			f.seekp(f.tellg()-sizeof(ob4),ios::beg);
			f.write((char*)&ob4,sizeof(ob4));
			f.close();
			break;
		}
	}

  }
 if(ob1.rethp()<=0)
 {
	clrscr();
	cout<<"Your health:0"<<"\nFreiza's health:"<<a;
	cout<<" \nTRUNKS:\nYou put in a valiant effort...\nBut he was too strong...\nBut dont 
                              worry,there is still hope...we still have the dragon balls...";
	user ob4;
	fstream f;
	f.open("pwd.dat",ios::in|ios::out|ios::binary);
	while(f.read((char*)&ob4,sizeof(ob4)))
	{
		if((strcmp(ob4.retnm(),ob3.retnm())==0)&&(strcmp(ob4.retdate(),ob3.retdate())==0))
		   {
			ob4.modstatus("LOSE");
			f.seekp(f.tellg()-sizeof(ob4),ios::beg);
			f.write((char*)&ob4,sizeof(ob4));
			f.close();
			break;
		   }
	}
 }

}
