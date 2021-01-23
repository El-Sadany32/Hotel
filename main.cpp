#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
	
	void Insert();
	void Read();
	void Search();
    void Update();
    void Delete();

 
	int mainChoice=1 ;
	while(mainChoice==1)
	{
    int choice;
    cout<<"Enter Your Choice 1 to Wite 2 to Read 3 to Search 4 to Update 5 to Delete \n";
    cin>>choice;
    cin.ignore();
    
	if(choice==1)
      Insert();
      
    else if(choice==2)
      Read();
	
	else if(choice==3
	)
      Search();
      
    else if(choice==4)
      Update();
      
	else if(choice==5)
      Delete();
    

cout<<"Enter 1 to Continue  2 to Close ";
cin>>mainChoice;

} 
	return 0;
	
} 

 
void Insert(){
	
	fstream file;
 	file.open("hotel.txt", ios::in | ios::out | ios::app );
    char name[50];
    char age[10];
    char birthDate[15];
    char roomNum[15];
    
	if(file)
	file<<endl;
	cout<<"Enter name \n";
	cin.getline(name,50); 
	cout<<"Enter Age \n";
	cin.getline(age,10);
	cout<<"Enter Birthdate \n";
	cin.getline(birthDate,15);
	cout<<"Enter room  Num  \n";
	cin.getline(roomNum,15);
	file<<name<<"$"<<age<<"$"<<birthDate<<"$"<<roomNum ;
	
} 
 

void Read(){
	fstream file;
	file.open("hotel.txt", ios::in | ios::out | ios::app );
    char name[50];
    char age[10];
    char birthDate[15];
    char roomNum[15];
    
	while(!file.eof())
		{	
        file.getline(name,50,'$');
        file.getline(age,10,'$');
        file.getline(birthDate,15,'$');
        file.getline(roomNum,15,'\n');
    
        cout<<"Name : "<<name << " \Age : "<<age <<" \Birthdate : "<<birthDate<<"\room  Num : "<<roomNum <<" \\******************* \n";
        
       } 
file.close();

}


 


void Search(){
	char searchKey[50];
	int found=0;
	cout<<"Enter name to Search On \n";
	cin.getline(searchKey,50);
	fstream file;
	file.open("hotel.txt", ios::in );
    char name[50];
    char age[10];
    char birthDate[15];
    char roomNum[15];
	while(!file.eof())
		{	
        file.getline(name,50,'$');
        file.getline(age,10,'$');
        file.getline(birthDate,15,'$'); 
        file.getline(roomNum,15);
    
    if(strcmp(name,searchKey)==0)
    {cout<<"Found !! \n";
    cout<<"Name : "<<name << " Age : "<<age <<" Birthdate : "<<birthDate<<"room  Num : "<<roomNum << endl;
    found=1;
    } 
    
    } 
if(found==0)
cout<<"Not Found !! \n";	
} 


 
void Update(){
	char searchKey[50];
	int found=0;
	cout<<"Enter name of Record to Update \n";
	cin.getline(searchKey,50);
	fstream file;
	fstream newFile;
	file.open("hotel.txt", ios::in );
	newFile.open("newHotel.txt",ios::in |ios::out | ios::app);
    char name[50];
    char age[10];
    char birthDate[15];
    char roomNum[15];
	while(!file.eof())
		{	
        file.getline(name,50,'$');
        file.getline(age,10,'$');
        file.getline(birthDate,15,'$');
          file.getline(roomNum,15);
    
    if(strcmp(name,searchKey)==0)
    {
	found=1;
	cout<<"Found !! .. Enter New Record Data ! \n";
	cout<<"Enter name \n";
	cin.getline(name,50); 
	cout<<"Enter Age \n";
	cin.getline(age,10);
	cout<<"Enter Birthdate \n";
	cin.getline(birthDate,15);
		cout<<"Enter room  Num \n";
	cin.getline(roomNum,15); 
	newFile<<name<<"$"<<age<<"$"<<birthDate<<"$"<<roomNum<< endl;
    } 
    
else
	newFile<<name<<"$"<<age<<"$"<<birthDate<<"$"<<roomNum<< endl;
	
    }
if(found==0)
cout<<"Not Found !! \n";
file.close();
newFile.close();
remove("hotel.txt");
rename("newHotel.txt","hotel.txt");
}  


 

void Delete(){
	char searchKey[50];
	int found=0;
	cout<<"Enter name of Record to Delete \n";
	cin.getline(searchKey,50);
	fstream file;
	fstream newFile;
	file.open("hotel.txt", ios::in );
	newFile.open("newHotel.txt",ios::out | ios::app);
    char name[50];
    char age[10];
    char birthDate[15];
    char roomNum[15];
    
	while(!file.eof())
		{	
        file.getline(name,50,'$');
        file.getline(age,10,'$');
        file.getline(birthDate,15);
        file.getline(roomNum,15);

    
    if(strcmp(name,searchKey)==0)
    {
	found=1;
	cout<<"Found !! .. Record Data is Deleted ! \n";
    } 
else
	newFile<<name<<"$"<<age<<"$"<<birthDate<<"$"<<roomNum<< endl;

    } 
if(found==0)
cout<<"Not Found !! \n";
file.close();
newFile.close();
remove("hotel.txt");
rename("newHotel.txt","hotel.txt");

}
