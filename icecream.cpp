#include<iostream>
#include<string>
using namespace std;
struct node
{
    int prn;
    node *next;

    node(int p)
    {
      prn=p;
      next=NULL;
    }
};
class icecream
{
    public:
    node* head;
   
    icecream()
    {
        head=NULL;
    }

    void addmember(int prn)
{
    node* newnode=new node(prn);

   if(head==NULL)
   {
    head=newnode;
   }
   else
   {
    node* temp=head;
    while(temp->next!=NULL && temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->next=NULL;
    temp->next=newnode;
   }

}

 void likeBoth(icecream &other) {
        node* list1 = head;

        cout << "\nPRNs who like both Vanilla and Butterscotch:" << endl;

        // Traverse the first list
        while (list1 != NULL) {
            node* temp2 = other.head; // Reset temp2 to head of other list

            // Traverse the second list
            while (temp2 != NULL) {
                if (temp2->prn == list1->prn) {
                    cout << "PRN = " << temp2->prn << endl;
                    break; // Stop checking once a match is found
                }
                temp2 = temp2->next;
            }
            list1 = list1->next; // Move to the next node in the first list
        }
    }

void likeone(icecream &other) {
    node* list1 = head;
   node* list2 = other.head;

    cout << "\nPRNs who like either Vanilla or Butterscotch (not both):" << endl;

    // Print PRNs from Vanilla list that are NOT in Butterscotch list
    while (list1 != NULL) {
        node* temp = other.head;
        bool found = false;

        while (temp != NULL) {
            if (temp->prn == list1->prn) {
                found = true; // PRN is in both lists
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "PRN = " << list1->prn << endl;
        }
        list1 = list1->next;
    }

    // Print PRNs from Butterscotch list that are NOT in Vanilla list
    while (list2 != NULL) {
        node* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->prn == list2->prn) {
                found = true; // PRN is in both lists
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "PRN = " << list2->prn << endl;
        }
        list2 = list2->next;
    }
}

 void notBoth(icecream &t, icecream &other) {
    node* total = t.head; // Total list of PRNs
    cout << "\nPRNs who don't like both Vanilla and Butterscotch:" << endl;

    // Traverse the total list
    while (total != NULL) {
        node* vanilla = head;         // Start of Vanilla list
        node* butterscotch = other.head; // Start of Butterscotch list
        bool found = false;

        // Check if PRN exists in Vanilla list
        while (vanilla != NULL) {
            if (vanilla->prn == total->prn) {
                found = true;
                break;
            }
            vanilla = vanilla->next;
        }

        // Check if PRN exists in Butterscotch list
        while (!found && butterscotch != NULL) {
            if (butterscotch->prn == total->prn) {
                found = true;
                break;
            }
            butterscotch = butterscotch->next;
        }

        // If not found in either list, print the PRN
        if (!found) {
            cout << "PRN = " << total->prn << endl;
        }

        total = total->next; // Move to the next PRN in total list
    }
}


void display()
{
    if(head==NULL)
    {
        cout<<"No members";
    }

    node* temp=head;
    cout<<"Club members:"<<endl;

    while(temp!=NULL)
    {
        cout<<"PRN="<<temp->prn<<endl;
        temp=temp->next;
    }
}
};

int main()
{
    icecream total;
    icecream vanila,butterscotch;

    total.addmember(2);
    total.addmember(3);
    total.addmember(4);
    total.addmember(7);
    total.addmember(8);
    total.addmember(88);
    total.addmember(21);
    total.addmember(55);

    vanila.addmember(2);
    vanila.addmember(3);
    vanila.addmember(4);
    vanila.addmember(7);

    vanila.display();

    butterscotch.addmember(8);
    butterscotch.addmember(2);
    butterscotch.addmember(3);
    butterscotch.addmember(88);

    butterscotch.display();

    vanila.likeBoth(butterscotch);
    vanila.likeone(butterscotch);
    vanila.notBoth(total,butterscotch);
    return 0;
}