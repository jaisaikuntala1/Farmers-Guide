#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
using namespace std;
struct node
{
char* data1;
char* data2;
char* location;
char* soil;
char* area;
int n,m;
char query[300];
char answer[300];
struct node *next;
};

class login
{
public:
node *head;
login(){head=NULL;}
void add_begin(char* x,char* y);
void display();
bool isexist(char* x);
bool iscorrect(char* x,char* y);
void details(char* m,char* n);
void read_query(char* x,char* y);
bool is_query_asked(char* x,char* y);
bool is_query_answered(char* x,char* y);
void query_clearance();
void unanswered_query();
void assign_query(char* x,char* y);
};
void login::assign_query(char* x,char* y)
{
node *p;
p=head;
while(p!=NULL)
{
if(strcmp(x,p->data1)==0)
{
strcpy(p->query,y);
p->n=1;
p->m=1;
}
p=p->next;
}
}
void login::unanswered_query()
{
fstream file("uns_query.txt",ios::in|ios::out|ios::trunc);
if(!file.is_open())
{
file.open("uns_query.txt");
}
node *p;
p=head;
while(p!=NULL)
{
if(p->n==1&&p->m!=0)
{
file<<p->data1<<endl;
file<<p->query<<endl;
}
p=p->next;
}
file.close();
}
void login::query_clearance()
{
node *p;
p=head;
while(p!=NULL)
{
if(p->n==1&&p->m!=0)
{
cout<<endl<<p->data1<<":"<<endl<<p->query<<endl<<endl<<endl;
}
p=p->next;
}
cout<<"Do you want to answer any of the queries?"<<endl;
cout<<"If yes...enter 1"<<endl;
cout<<"If no....enter 0"<<endl;
int s1;
cin>>s1;
if(s1==1)
{
cout<<endl<<"Enter the username of the query which you want to answer:";
char user[40];char s2[400];
cin>>user;
p=head;
while(p!=NULL)
{
if(strcmp(user,p->data1)==0)
{
cout<<endl<<"Enter the solution of the query:"<<endl;
cout<<p->query<<endl;

int f=0;
char h;
  for(f=0;;)
    {
        h=getch();
        if((h>=' '&&h<='~'))
            {
            s2[f]=h;
            ++f;
            cout<<h;
        }
        if(h=='\b'&&f>=1)
           
        {
            cout<<"\b \b";
            --f;
        }
        if(h=='\r')
        {
            s2[f]='\0';
            break;
        }
    }
    strcpy(p->answer,s2);
p->m=0;
break;
}
p=p->next;
}
fstream file5("query.txt",ios::in|ios::out|ios::app);
                if(!file5.is_open())
                {
                file5.open("query.txt");
}
file5<<user<<endl<<p->query<<endl<<s2<<endl;
file5.close();
}
}

bool login::is_query_answered(char* x,char* y)
{
node *p;
p=head;
while(p!=NULL)
{
if(strcmp(p->data1,x)==0)
{
if(p->m==0&&p->n==1)
{
return true;
}
else
{
return false;
}

}
p=p->next;
}


}
bool login::is_query_asked(char* x,char* y)
{
node *p;
p=head;
while(p!=NULL)
{
if(strcmp(p->data1,x)==0)
{
if(p->n==1)
{
return true;
}
else
{
return false;
}
}
p=p->next;
}
}
void login::read_query(char* x,char* y)
{
cout<<endl<<endl<<"Enter your query:"<<endl;
char str[300];
int f=0;
char h;
   for(f=0;;)
    {
        h=getch();
        if((h>=' '&&h<='~'))
           
        {
            str[f]=h;
            ++f;
            cout<<h;
        }
        if(h=='\b'&&f>=1)
           
        {
            cout<<"\b \b";
            --f;
        }
        if(h=='\r')
        {
            str[f]='\0';
            break;
        }
    }
    cout<<endl<<endl<<endl;
cout<<endl<<"query read"<<endl;
node *p;
p=head;
while(p!=NULL)
{  
cout<<endl<<"while loop entered"<<endl;
if(strcmp(p->data1,x)==0)
{
strcpy(p->query,str);
p->m=1;
p->n=1;
break;
}
p=p->next;
}
}
void login::details(char* m,char* n)
{
char l[50],s[50],t[50];
int z=0,f=0;
node *p;
p=head;
while(p!=NULL)
{
if(strcmp(p->data1,m)==0 && strcmp(p->data2,n)==0)
{
cout<<endl<<endl<<endl<<"Login successful"<<endl<<endl<<endl;
cout<<endl<<endl<<endl<<"Enter the following details:-"<<endl<<endl<<endl;
cout<<endl<<"If you belong to any of these districts, select an option."<<endl<<"If not type your district or state manually:"<<endl;
cout<<"Select the location:"<<endl;
cout<<"1.Karimnagar"<<endl<<"2.Warangal"<<endl<<"3.Khammam"<<endl<<"4.Adilabad"<<endl;
cout<<"5.Nizamabad"<<endl<<"6.Ranga Reddy"<<endl<<"7.Rajendranagar"<<endl;
cout<<"8.Medak"<<endl<<"9.Mahabubnagar"<<endl<<"10.Nalgonda"<<endl;
cout<<"Enter your choice:";
cin>>f;
switch(f)
{
case 1:
p->location=new char[strlen("Karimnagar")+1];
strcpy(p->location,"Karimnagar");
break;
case 2:
p->location=new char[strlen("Warangal")+1];
strcpy(p->location,"Warangal");
break;
case 3:
p->location=new char[strlen("Khammam")+1];
strcpy(p->location,"Khammam");
break;
case 4:
p->location=new char[strlen("Adilabad")+1];
strcpy(p->location,"Adilabad");
break;
case 5:
p->location=new char[strlen("Nizamabad")+1];
strcpy(p->location,"Nizamabad");
break;
case 6:
p->location=new char[strlen("Rangareddy")+1];
strcpy(p->location,"Rangareddy");
break;
case 7:
p->location=new char[strlen("Rajendranagar")+1];
strcpy(p->location,"Rajendranagar");
break;
case 8:
p->location=new char[strlen("Medak")+1];
strcpy(p->location,"Medak");
break;
case 9:
p->location=new char[strlen("Mehabubnagar")+1];
strcpy(p->location,"Mehabubnagar");
break;
case 10:
p->location=new char[strlen("Nalgonda")+1];
strcpy(p->location,"Nalgonda");
break;
default:
cout<<"Invalid choice."<<endl<<endl;
}
cout<<endl<<endl<<endl<<endl<<"Select the type of soil:"<<endl<<"1.red soil"<<endl<<"2.black soil"<<endl<<"3.loamy soil"<<endl<<"4.clayey soil"<<endl<<"5.sandy soil"<<endl;
cin>>z;
switch(z)
{
case 1: p->soil=new char[strlen("red soil")+1];
            strcpy(p->soil,"red soil");
break;
case 2: p->soil=new char[strlen("black soil")+1];
strcpy(p->soil,"black soil");
break;
case 3:p->soil=new char[strlen("loamy soil")+1];
strcpy(p->soil,"loamy soil");
break;
case 4:p->soil=new char[strlen("clayey soil")+1];
strcpy(p->soil,"clayey soil");
break;
case 5:p->soil=new char[strlen("sandy soil")+1];
strcpy(p->soil,"sandy soil");
break;
}

cout<<endl<<endl<<endl<<"Enter the area of the farmfield in meter square:";
cin>>t;
p->area=new char[strlen(t)+1];
strcpy(p->area,t);
cout<<endl<<endl;
cout<<"Based on the type of climate in your location,the type of your soil and the area of your farm field"<<endl;
cout<<"Suggested crops are:"<<endl<<endl<<endl;
if(z==1)
{
cout<<endl<<endl<<"1.cotton"<<endl<<"2.groundnut"<<endl<<"3.millets"<<endl<<"4.pulses"<<endl<<"5.tobacco"<<endl<<endl<<endl;
}
if(z==2)
{
cout<<endl<<endl<<"1.Sugarcane"<<endl<<"2.Wheat"<<endl<<"3.oilseeds"<<endl<<"4.cotton"<<endl<<"5.tobacco"<<endl<<"6.millets"<<endl<<endl<<endl;
}
if(z==3)
{
cout<<endl<<endl<<"1.Wheat"<<endl<<"2.jute"<<endl<<"3.vegetables"<<endl<<"4.cotton"<<endl<<"5.sugarcane"<<endl<<"6.pulses"<<endl<<"7.oilseeds"<<endl<<endl<<endl;
 }
if(z==4)
{
cout<<endl<<endl<<"1.paddy"<<endl<<endl<<endl;
}
if(z==5)
{
cout<<endl<<endl<<"1.melon"<<endl<<"2.coconut"<<endl<<"3.maize"<<endl<<"4.millets"<<endl<<"5.barley"<<endl<<endl<<endl;
}
break;
}
p=p->next;
}
}

void login::add_begin(char* x,char* y)
{
node *temp=new node;
temp->data1=new char[strlen(x)+1];
strcpy(temp->data1,x);
temp->data2=new char[strlen(y)+1];
strcpy(temp->data2,y);
temp->next=NULL;
temp->m=0;
temp->n=0;
if(head==NULL)
{
head=temp;
}
else
{
temp->next=head;
head=temp;
}
}void login:: display()
{
node *p;
p=head->next;
while(p!=NULL)
{
cout<<"Username:"<<p->data1<<"\t"<<"Password:"<<p->data2<<endl;
p=p->next;
}
cout<<endl;
}
bool login::isexist(char* x)
{
node *p;
p=head;
while(p!=NULL)
{
if(strcmp(p->data1,x)==0)
{
return true;
}
p=p->next;
}
return false;
}bool login::iscorrect(char* x,char* y)
{
node *p;
p=head;
while(p!=NULL)
{
if(strcmp(p->data1,x)==0 && strcmp(p->data2,y)==0)
{
return true;
}
p=p->next;
}
return false;
}
int main()
{
cout<<"          -----------------------FARMER'S GUIDE-----------------------------"<<endl<<endl<<endl;
login t;
int a;
char b[50];
char c[50];
char d[50];
char quer[300];
fstream file("details3.txt",ios::in|ios::out);
                if(!file.is_open())
                {
                file.open("details3.txt");
}
while(!file.eof())
{
file.getline(b,50);
file.getline(c,50);
t.add_begin(b,c);
}
file.close();

fstream file2("uns_query.txt",ios::in|ios::out);
if(!file2.is_open())
{

file2.open("uns_query.txt");
}
while(!file2.eof())
{
file2.getline(b,50);
file2.getline(quer,200);
t.assign_query(b,quer);

}
file2.close();


while(1)
{
cout<<endl<<endl<<endl<<"1.Create username and password"<<endl<<"2.login"<<endl<<"3.Admin login"<<endl;
cout<<"4.Query Clearance."<<endl<<"5.exit"<<endl;
cout<<"Enter your choice:";
cin>>a; switch(a)
{
case 1:
{
        cout<<"Create your username:";
        cin>>b;
        cout<<"Create your password:";
        int f=0;
        char h;
   for(f=0;;)
    {
        h=getch();
        if((h>=' '&&h<='~'))
           
        {
            c[f]=h;
            ++f;
            cout<<"*";
        }
        if(h=='\b'&&f>=1)
           
        {
            cout<<"\b \b";
            --f;
        }
        if(h=='\r')
        {
            c[f]='\0';
            break;
        }
    }

        if(!t.isexist(b))
        {
                t.add_begin(b,c);
                fstream file("details3.txt",ios::in|ios::out|ios::app);
                if(!file.is_open())
                {
                file.open("details3.txt");
}
file<<b<<endl<<c<<endl;
file.close();
        }
        else
        {
                cout<<"Username already exists"<<endl;
        }
        break;
    }
case 2:
{
        cout<<"Enter your username:";
        cin>>b;
        cout<<"Enter your password:";
        int f=0;
char h;
   for(f=0;;)
    {
        h=getch();
        if((h>=' '&&h<='~'))
           
        {
            c[f]=h;
            ++f;
            cout<<"*";
        }
        if(h=='\b'&&f>=1)
           
        {
            cout<<"\b \b";
            --f;
        }
        if(h=='\r')
        {
            c[f]='\0';
            break;
        }
    }
        if(t.iscorrect(b,c))
        {
        while(1)
        {
       
        int o;
        cout<<endl<<endl<<endl<<"1.Enter details for crop suggestions.";
        cout<<endl<<"2.Display query solutions.";
        cout<<endl<<"3.Ask a query.";
        cout<<endl<<"4.Crop Production.";
        cout<<endl<<"5.Post Harvest Technologies.";
        cout<<endl<<"6.Market information.";
        cout<<endl<<"7.Best Practices.";
        cout<<endl<<"8.Policies and schemes.";
        cout<<endl<<"9.State-specific schemes for farmers.";
        cout<<endl<<"10.ICT applications in Agriculture.";
        cout<<endl<<"11.Previous years analysis of crops.";
cout<<endl<<"12.Logout."<<endl<<endl<<endl;
        cout<<"Select your choice:";
        cin>>o;
        switch(o)
        {  
           case 1:
                t.details(b,c);
                break;
                case 2:
                {
                char user[50],que[200],ans[200];
                fstream file8("query.txt",ios::in|ios::out);
                if(!file8.is_open())
                {
                file8.open("query.txt");
}
while(!file8.eof())
{
file8.getline(user,50);
file8.getline(que,200);
file8.getline(ans,200);
if(strcmp(b,user)==0)
{
cout<<"query asked is:"<<endl<<que<<endl<<"Solution is:"<<endl<<ans<<endl;
}
}
file8.close();
break;
}
               
case 3:
{
if(!t.is_query_asked(b,c))
                {
                cout<<endl<<"Do you want to ask a query?"<<endl<<endl;
cout<<"If yes...enter 1"<<endl;
cout<<"If no....enter 0"<<endl;
int h1;
cin>>h1;
if(h1==1)
{
cout<<endl<<"You can ask your query here and if it is answered it will be shown here in your next login"<<endl;
t.read_query(b,c);
                }
        }
        if(t.is_query_answered(b,c))
        {
        cout<<"entered into is query answered function"<<endl;
  cout<<endl<<endl<<"Do you want to ask another query?"<<endl;
cout<<endl<<"If yes...enter 1"<<endl;
cout<<endl<<"If no....enter 0"<<endl;
int q2;
cin>>q2;
if(q2==1)
{
t.read_query(b,c);
}
}
 
else
{
cout<<"You can ask another query once the previous one is answered"<<endl<<endl;
}
break;
}
case 4:
{
cout<<endl<<"Critical factors to be considered for selection of crops:"<<endl<<endl;
cout<<endl<<"Key requirements for improving productivity:"<<endl<<endl;
cout<<endl<<"Increase in productivity and profitability can be achieved through:"<<endl<<endl;
cout<<"~Blending practical knowledge with scientific technologies."<<endl;
cout<<"~Efficient use of natural resources."<<endl;
cout<<"~Adopting time specific management practices."<<endl;
cout<<"~Giving priority for quality driven production."<<endl;
cout<<"~Adopting suitable farming systems."<<endl;
cout<<"~Adoption of location specific technology."<<endl;
cout<<"~Market demand driven production."<<endl;
cout<<"~Adopting low cost and no cost technologies."<<endl<<endl<<endl;
cout<<endl<<"Factors influencing decisions on the selection of crops & cropping system:"<<endl<<endl<<endl;
cout<<endl<<"Farmers need to answer all the below questions while making decisions for choosing a crop/ cropping pattern. During this decision making process, farmers cross check the suitability of proposed crop/cropping systems with their existing resources and other conditions. Thereby, they justify choosing or rejecting a crop/cropping systems. This process enables the farmers to undertake a SWOT analysis internally which in turn guides them to take an appropriate decision."<<endl;
   cout<<endl<<"1.Climatic factors - Is the crop/cropping system suitable for local weather parameters such as temperature, rainfall, sun shine hours, relative humidity, wind velocity, wind direction, seasons and agro-ecological situations?"<<endl;
   cout<<endl<<"2.Soil conditions - Is the crop/cropping system suitable for local soil type, pH and soil fertility?"<<endl;
   cout<<endl<<"3.Water:"<<endl<<"~Do you have adequate water source like a tanks, wells, dams, etc.?"<<endl<<"~Do you receive adequate rainfall?"<<"~Is the distribution of rainfall suitable to grow identified crops?"<<endl<<"~Is the water quality suitable?"<<endl<<"~Is electricity available for lifting the water?"<<endl<<"~Do you have pump sets, micro irrigation systems?"<<endl;
   cout<<endl<<"4.Cropping system options:"<<endl<<"~Do you have the opportunity to go for inter-cropping, mixed cropping, multi-storeyed cropping, relay cropping, crop rotation, etc.?"<<endl<<"~Do you have the knowledge on cropping systems management?"<<endl;
   cout<<endl<<"5.Past and present experiences of farmers:"<<endl<<
"~What were your previous experiences with regard to the crop/cropping systems that you are planning to choose?"<<endl<<
"~What is the opinion of your friends, relatives and neighbours on proposed crop/cropping systems?"<<endl;
cout<<endl<<endl<<"6.Expected profit and risk:"<<endl<<
"~How much profit are you expecting from the proposed crop/cropping system?"<<endl<<
"~Whether this profit is better than the existing crop/cropping system?"<<endl<<
"~What are the risks you are anticipating in the proposed crop/cropping system?"<<endl<<
"~Do you have the solution?"<<endl<<
"~Can you manage the risks?"<<endl<<
"~Is it worth to take the risks for anticipated profits?"<<endl<<endl<<endl;
cout<<endl<<"7.Economic conditions of farmers including land holding:"<<endl<<
"~Are the proposed crop/cropping systems suitable for your size of land holding?"<<endl<<
"~Are your financial resources adequate to manage the proposed crop/cropping system?"<<endl<<
"~If not, can you mobilize financial resources through alternative routes?"<<endl<<endl<<endl<<
"8.Labour availability and mechanization potential:"<<endl<<
"~Can you manage the proposed crop/cropping system through your family labour?"<<endl<<
"~If not, do you have adequate labours to manage the same?"<<endl<<
"~Is family/hired labour equipped to handle the proposed crop/cropping system?"<<endl<<
"~Are there any mechanization options to substitute the labour?"<<endl<<
"~Is machinery available? Affordable? Cost effective?"<<endl<<
"~Is family/hired labour equipped to handle the machinery?"<<endl<<endl<<endl<<
"9.Technology availability and suitability:"<<endl<<
"~Is the proposed crop/cropping system suitable?"<<endl<<
"~Do you have technologies for the proposed crop/cropping system?"<<endl<<
"~Do you have extension access to get the technologies?"<<endl<<
"~Are technologies economically feasible and technically viable?"<<endl<<
"~Are technologies complex or user-friendly?"<<endl<<endl<<endl<<
"10.Market demand and availability of market infrastructure:"<<endl<<
"~Are the crops proposed in market demand?"<<endl<<
"~Do you have market infrastructure to sell your produce?"<<endl<<
"~Do you have organized marketing system to reduce the intermediaries?"<<endl<<
"~Do you have answers for questions such as where to sell? When to sell? Whom to sell to? What form to sell in? What price to sell for?"<<endl<<
"~Do you get real time market information and market intelligence on proposed crops?"<<endl<<endl<<endl<<
"11.Policies and schemes:"<<endl<<
"~Do Government policies favour your crops?"<<endl<<
"~Is there any existing scheme which incentivises your crop?"<<endl<<
"~Are you eligible to avail those benefits?"<<endl<<endl<<endl<<
"12.Public and private extension influence:"<<endl<<
"~Do you have access to Agricultural Technology Management Agency (ATMA)/ Departmental extension functionaries to get advisory?"<<endl<<
"~Do you know Kissan Call Center?"<<endl<<
"~Do you have access to KVKs, Agricultural Universities and ICAR organizations?"<<endl<<
"~Do you subscribe agricultural magazines?"<<endl<<
"~Do you read agricultural articles in newspapers?"<<endl<<
"~Do you get any support from input dealers, Agribusiness Companies, NGOs, Agriclinics and Agribusiness Centers?"<<endl<<endl<<endl<<
"13.Availability of required agricultural inputs including agricultural credit:"<<endl<<
"~Do you get adequate agricultural inputs such as seeds, fertilizers, pesticides, and implements in time?"<<endl<<
"~Do you have access to institutional credit?"<<endl<<endl<<endl<<
"14.Post harvest storage and processing technologies:"<<endl<<
"~Do you have your own storage facility?"<<endl<<
"~If not, do you have access to such facility?"<<endl<<
"~Do you have access to primary processing facility?"<<endl<<
"~Do you know technologies for value addition of your crop?"<<endl<<
"~Do you have market linkage for value added products?"<<endl<<
"~Are you aware about required quality standards of value added products of proposed crops?"<<endl;
break;
}
case 5:
{
cout<<"Rice milling : process description"<<endl<<endl<<endl<<endl<<
"1.Paddy Cleaning - Essential for removal of undesired foreign matter, paddy cleaning is given utmost importance to ensure proper functioning of the Rice Milling machinery. Rough rice is passed through a series of sieves and closed circuit aspiration system is provided to remove dust and light impurities through positive air suction.Undesired material, heavier than rough rice (but of similar size) is removed through a de-stoner/gravity separator. This machine works on the principle of specific gravity. Stones and other heavy impurities, being heavier, stay on the screen surface whereas rough rice, being lighter, fluidizes into the positive air gradient created by an external source."<<endl;
cout<<endl<<endl<<"2.Paddy De-husking - A streamlined paddy flow is directed into a pair of rubber rolls, rotating at different speeds, in opposite directions. A horizontal inward pressure is applied on the rubble rollers, pneumatically. Due to the difference in the seed of rotation, a shear force is generated on the surface of hull (with two sides being rubber by tow rubber rolls) that breaks apart of the surface/hull."<<endl;
cout<<"Husk, being of lower specific gravity, is then separated form brown rice by a closed circuit aspiration system."<<endl;
cout<<"This process leads to breakage of brown rice. Although a proper horizontal inward pressure is mot important factor for breakage or rice, de-husking efficiency is equally important and should be maintained between 75 to 85%."<<endl<<endl<<endl;
cout<<"3.Paddy Separation - Rice surface is smooth as compared to rough paddy surface. This difference in surface texture is utilized to separate brown rice from paddy through paddy separator."<<endl<<endl<<endl;
cout<<"Grain surface with smooth texture, being of higher width, is removed off along with red grains by precision sizes."<<endl<<endl<<endl;
cout<<"4.Rice Whitening - Brown rice is rubbed with a rough surface, created using emery stones of specific grid size. The rough emery removes off the brown bran layer. The radial velocity of the stone wheels, grid size of the stones, clearance between stone surface & the other screen and the external pressure on the outlet chamber of the whitening machines determine the extent of whiteness.The bran layer removed from the surface if pneumatically conveyed to a separate room for further processing /storage."<<endl<<endl<<endl;
cout<<"5.Rice Polishing - The surface of whitened rice is still rough and is smoothened by a humidified rice polisher. The process involves rubbing of rice surface against another rice surface with mystified air acting as lubricant between the two surfaces. Usually a modified version of this process is used to produce superfine silky finish on rice surface.The bran layer removed from the surface if pneumatically conveyed to a separate room for further processing/storage."<<endl<<endl<<endl;
cout<<"6.Rice Grading - Broken rice is removed from whole rice by passing the lot through a cylindrical indented screen rotating at a particular speed. The broken/small grains, fit into the indents of the rotating cylinder, are lifted by centrifugal force and gravitational pull falls the grains into a trough. Adjusting the rotational speed and angle of trough can vary the average length of grains."<<endl<<endl<<endl;
cout<<"7.Rice Colour Sorting - Discoloured rice grains are removed off from the like coloured grains by Rice colour sorting machines. Photo sensors/CCD (Charged Coupled Device) sensors generate voltage signal on viewing discoloured grains, which are then removed off by air jet generated through solenoid valves."<<endl;
break;
}
case 6:
{
cout<<" Determination of MSP:"<<endl;
cout<<"In formulating the recommendations in respect of the level of minimum support prices and other non-price measures,"<<endl<<" the Commission takes into account, apart from a comprehensive view of the entire structure of the economy of a particular"<<endl<<" commodity or group of commodities, the following factors:-"<<endl;

cout<<"Cost of production"<<endl;
cout<<"Changes in input prices"<<endl;
cout<<"Input-output price parity"<<endl;
cout<<"Trends in market prices"<<endl;
cout<<"Demand and supply"<<endl;
cout<<"Inter-crop price parity"<<endl;
cout<<"Effect on industrial cost structure"<<endl;
cout<<"Effect on cost of living"<<endl;
cout<<"Effect on general price level"<<endl;
cout<<"International price situation"<<endl;
cout<<"Parity between prices paid and prices received by the farmers."<<endl;
cout<<"Effect on issue prices and implications for subsidy"<<endl;
cout<<endl<<"The Commission makes use of both micro-level data and aggregates at the level of district, state and the country. "<<endl<<"The information/data used by the Commission, inter-alia include the following :-"<<endl;

cout<<"Cost of cultivation per hectare and structure of costs in various regions of the country and changes there in;"<<endl;
cout<<"Cost of production per quintal in various regions of the country and changes therein;"<<endl;
cout<<"Prices of various inputs and changes therein;"<<endl;
cout<<"Market prices of products and changes therein;"<<endl;
cout<<"Prices of commodities sold by the farmers and of those purchased by them and changes therein;"<<endl;
cout<<"Supply related information - area, yield and production, imports, exports and domestic availability and stocks with the Government/public agencies or industry;"<<endl;
cout<<"Demand related information - total and per capita consumption, trends and capacity of the processing industry;"<<endl;
cout<<"Prices in the international market and changes therein, demand and supply situation in the world market;"<<endl;
cout<<"Prices of the derivatives of the farm products such as sugar, jaggery, jute goods, edible/non-edible oils and cotton yarn and changes therein;"<<endl;
cout<<"Cost of processing of agricultural products and changes therein;"<<endl;
cout<<"Cost of marketing - storage, transportation, processing, marketing services, taxes/fees and margins retained by market functionaries;"<<endl;
cout<<"Macro-economic variables such as general level of prices, consumer price indices and those reflecting monetary and fiscal factors."<<endl;
cout<<"Government has announced its historic decision to fix MSP at a level of at least 150 per cent of the cost of production for kharif crops 2018-19."<<endl;
cout<<endl<<endl<<"\t"<<"Commodity"<<"\t"<<"\t"<<"MSP for 2018-19"<<"\t\t"<<"MSP for 2019-20 "<<"\t"<<"Increase over previous year"<<endl;
cout<<"\t\t\t\t"<<" (Rs per quintal)"<<"\t"<<" (Rs per quintal)"<<"\t"<<" (Rs per quintal)"<<endl;
cout<<"\t"<<"Paddy"<<"\t\t\t\t"<<"1750"<<"\t\t\t"<<"1815"<<"\t\t\t"<<"65"<<endl;
cout<<"\t"<<"Jowar"<<"\t\t\t\t"<<"2430"<<"\t\t\t"<<"2550"<<"\t\t\t"<<"120"<<endl;
cout<<"\t"<<"Bajra"<<"\t\t\t\t"<<"1950"<<"\t\t\t"<<"2000"<<"\t\t\t"<<"50"<<endl;
cout<<"\t"<<"Maize"<<"\t\t\t\t"<<"1700"<<"\t\t\t"<<"1760"<<"\t\t\t"<<"60"<<endl;
cout<<"\t"<<"Ragi"<<"\t\t\t\t"<<"2897"<<"\t\t\t"<<"3150"<<"\t\t\t"<<"253"<<endl;
cout<<"\t"<<"Arhar"<<"\t\t\t\t"<<"1750"<<"\t\t\t"<<"1815"<<"\t\t\t"<<"65"<<endl;
cout<<"\t"<<"Moong"<<"\t\t\t\t"<<"6975"<<"\t\t\t"<<"7050"<<"\t\t\t"<<"75"<<endl;
cout<<"\t"<<"Urad"<<"\t\t\t\t"<<"5600"<<"\t\t\t"<<"5700"<<"\t\t\t"<<"100"<<endl;
cout<<"\t"<<"Cotton"<<"\t\t\t\t"<<"5150"<<"\t\t\t"<<"5255"<<"\t\t\t"<<"105"<<endl;
cout<<"\t"<<"Wheat"<<"\t\t\t\t"<<"1840"<<"\t\t\t"<<"1925"<<"\t\t\t"<<"85"<<endl;
cout<<"\t"<<"Barley"<<"\t\t\t\t"<<"1440"<<"\t\t\t"<<"1525"<<"\t\t\t"<<"85"<<endl;
cout<<"\t"<<"Gram"<<"\t\t\t\t"<<"4620"<<"\t\t\t"<<"4875"<<"\t\t\t"<<"255"<<endl;
cout<<"\t"<<"Masur"<<"\t\t\t\t"<<"4475"<<"\t\t\t"<<"4800"<<"\t\t\t"<<"325"<<endl;
cout<<"\t"<<"Sugarcane"<<"\t\t\t"<<"-"<<"\t\t\t"<<"275"<<"\t\t\t"<<"-"<<endl;

break;
}
case 7:
{
string x;;
fstream file("best.txt",ios::in|ios::out);
                if(!file.is_open())
                {
                file.open("best.txt");
                }
 while (getline(file,x)) {
cout << x << endl ;
}
break;
}
case 8:
{
string x;;
fstream file5("poli.txt",ios::in|ios::out);
                if(!file5.is_open())
                {
                file5.open("poli.txt");
                }
 while (getline(file5,x)) {
cout << x << endl ;
}

file5.close();
break;
}
case 9:
{
string x;;
fstream file5("state.txt",ios::in|ios::out);
                if(!file5.is_open())
                {
                file5.open("state.txt");
                }
 while (getline(file5,x)) {
cout << x << endl ;
}

file5.close();
break;
}
case 10:
{
string x;;
fstream file5("ict.txt",ios::in|ios::out);
                if(!file5.is_open())
                {
                file5.open("ict.txt");
                }
 while (getline(file5,x)) {
cout << x << endl ;
}

file5.close();
break;
}

case 11:
{
cout<<endl<<endl<<endl<<"PADDY:"<<endl<<"last year the cost was 1528/- per quintal.Note:Abundant sunshine is essential during its four months of growth.Paddy requires more water than any other crop."<<endl<<" As a result, paddy cultivation is done only in those areas where minimum rainfall is 115 cm."<<endl<<"Paddy requires three essential plant nutrients: nitrogen, phosphorus and potassium.It can grow in any type of soil."<<endl<<"HIGH CAPITAL";  
cout<<endl<<endl<<endl<<"WHEAT:"<<endl<<"Previous 2 year's average  cost was 1120/-per quintal.The amount of rainfall required for wheat cultivation varies between 30 cm and 100 cm.Red soil,Black soil."<<endl<<"CAPITAL INTENSIVE";
cout<<endl<<endl<<endl<<"MAIZE:"<<endl<<" Previous 2 year's average  cost was 1325/-per quintal.Maize is grown mostly in regions having annual rainfall between 60 cm to 110 cm.NITROGEN is crucial for maize.Alluvial soil,Red Soil."<<endl<<"SMALL CAPITAL";
cout<<endl<<endl<<endl<<"COTTON:"<<endl<<"Previous 2 year's average cost was 3901/-per quintal.The amount of rainfall required for cotton cultivation varies between 50 cm and 100 cm.High nutrient contents is required.";
cout<<endl<<endl<<endl<<"ARHAR:"<<endl<<"Previous 2 year's average  cost was 3967/-per quintal.The amount of rainfall required for arhar cultivation varies between 60 cm and 140 cm.Zinc is required in high amount";
cout<<endl<<endl<<endl<<"GROUNDNUT:"<<endl<<"Previous 2 year's average  cost was 5675/-per quintal.The amount of rainfall required for groundnut cultivation varies between 60 cm and 150 cm.Sandy clay soil";
cout<<endl<<endl<<endl<<"GREEN GRAM:"<<endl<<"Previous 2 year's average  cost was 4122/-per quintal.The amount of rainfall required for green gram cultivation varies between 60 cm and 90 cm.Phophorous,Nitrogen should be high.";
cout<<endl<<endl<<endl<<"BENGAL GRAM:"<<endl<<"Previous 2 year's average cost was 3850/-per quintal.The amount of rainfall required for bengal gram cultivation varies between 60 cm and 90 cm.Nitrogen conent should be high";
cout<<endl<<endl<<endl<<"BLACK GRAM:"<<endl<<"Previous 2 year's average  cost was 4150/-per quintal.The amount of rainfall required for wheat cultivation varies between 60 cm and 75 cm.Black soil";
break;
}


case 12:
goto k;


    }
    }
    k:
    break;
}
        else
        {
                cout<<endl<<endl<<endl<<"Username or password is invalid"<<endl;
        }
        break;
}
case 3:
{
cout<<"Enter admin password:";
int f=0;
char h;
   for(f=0;;)
    {
        h=getch();
        if((h>=' '&&h<='~'))
           
        {
            d[f]=h;
            ++f;
            cout<<"*";
        }
        if(h=='\b'&&f>=1)
           
        {
            cout<<"\b \b";
            --f;
        }
        if(h=='\r')
        {
            d[f]='\0';
            break;
        }
    }
    cout<<endl<<endl<<endl;
if(strcmp(d,"admin2627")==0)
{
        t.display();
    }
    else
    {
    cout<<endl<<endl<<"Wrong password entered for admin."<<endl<<endl<<endl;
}
        break;
}
case 4:
t.query_clearance();
break;
case 5:
t.unanswered_query();
return 0;
default:
cout<<"Invalid choice"<<endl;
}
}
return 0;
} 
