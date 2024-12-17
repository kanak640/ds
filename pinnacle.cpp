#include<iostream>
#include<string>
using namespace std;
struct node
{
    int prn;
    string name;
    node *next;

    node(int p,string n)
    {
      prn=p;
      name=n;
      next=NULL;
    }
};
class pinnacle
{
    public:
    node* head;
    node* tail;

    pinnacle()
    {
        head=NULL;
        tail=NULL;
    }
void addpresident(int prn,string name)
{
   node* newnode=new node(prn,name);

   if(head==NULL)
   {
    head=tail=newnode;
   }
   else
   {
    newnode->next=head;
    head=newnode;
   }
   cout<<"President added successfully"<<endl;
}

void addSecretory(int prn,string name)
 {
  node* newnode=new node(prn,name);

   if(head==NULL)
   {
    head=tail=newnode;
   }
   else
   {
    tail->next=newnode;
    tail=newnode;
   }
   cout<<"Secretory added successfully"<<endl;
 }

void addmember(int prn,string name)
{
    node* newnode=new node(prn,name);

   if(head==NULL)
   {
    head=tail=newnode;
   }
   else
   {
    node* temp=head;
    while(temp->next!=NULL && temp->next!=tail)
    {
        temp=temp->next;
    }
    newnode->next=tail;
    temp->next=newnode;
   }
   cout<<"new member added successfully"<<endl;
}

void deletePresident()
{
    if(head==NULL)
    {
        cout<<"List is empty";
    }
        node* temp=head;
        head=head->next;
        delete temp;
        cout<<"president deleted\n";
}

void deleteMember(int prn)
{
    //travers  list to find member to deleted
    node* current=head;
    node* prev=NULL;
    
    while(current!=NULL && current->prn!=prn)
    {
        prev=current;
        current=current->next;
    }

    if(current==NULL)
    {
        cout<<"Member with PRN not found\n";
    }
    else
    {
     prev->next=current->next;
     delete current;
     cout<<"Member Deleted";
    }
}

void deleteSecretory()
{
    node* current=head;
    node* prev=NULL;
    
    while(current!=tail)
    {
        prev=current;
        current=current->next;
    }
    if(current==tail)
    {
        tail=prev;
        tail->next=NULL;
        delete current;
        cout<<"seceretary deteled\n";
    }   

}

void toalMember()
{
    int count=1;
    node* temp=head;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
   cout<<"Total members="<<count<<endl; 
}

void display()
{
    if(head==NULL)
    {
        cout<<"No members in club";
    }

    node* temp=head;
    cout<<"Club members:"<<endl;

    while(temp!=NULL)
    {
        cout<<"PRN="<<temp->prn<<endl;
        cout<<"Name"<<temp->name<<endl;
        temp=temp->next;
    }
}

void concateList(pinnacle &other)
{
    if(head==NULL)
    {
        head=other.head;
    }
    if(other.head!=NULL)
    {
      tail->next=other.head;
      tail=other.tail;
    }
   other.head=NULL;
   other.tail=NULL;

   cout<<"list Concate successfully"<<endl;
}
};

int main()
{
 pinnacle divA,divB;
 
divA.addpresident(101,"alice");
divA.addSecretory(107,"zayn");
divA.addmember(102,"charlie");
divA.addmember(103,"David");

divA.display();
cout<<"TOtal member in DIV A:"<<endl;
divA.toalMember();

divB.addpresident(201,"Anne");
divB.addSecretory(209,"Cole");
divB.addmember(202,"Diana");
divB.addmember(203,"Gilbert");

divB.display();
cout<<"TOtal member in DIV B:"<<endl;
divB.toalMember();

divA.concateList(divB);
divA.display();
cout<<"After concatenation:"<<endl;
divA.toalMember();

divA.deletePresident();//delete presidenet
divA.deleteMember(102);//regular member
divA.deleteSecretory();//delete secretary
divA.display();


return 0;
}