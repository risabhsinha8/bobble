#include<bits/stdc++.h>
#include<fstream>
using namespace std;

//The program assumes the words in the dictionary are not case sensitive 
//The number given to every word is in the order in which they appear in the dictionary with 0 indexing.
//The first word has been given the number 0, second has been given the word 1 and so on.

string answer="";

int getind(char c)  //Function to convert lowercase chars to indexes, i.e :a-0, b-1 and so on. Takes a char as input and gives the required index as output
{
  if(c==39)
    return 26; //converts ' to index 26
  else if(97<=c && c<=122)
    return c-97;
  else {
    return 0;
  }
}

typedef struct trie //trie node
{
	char c; //the char to which this node represents
	trie* child[27]; // array of trie node pointers so each can point to a different char node
	int val; //value of the highest number below this node
	int o;	// number of the word that ends on this node, is -1 if no words end at this node
};

trie *newn(char ch) //new node, take the character which this node signifies 
{ 
    trie *n =  new trie;   
    for (int i = 0; i < 27; i++) 
        n->child[i] = NULL;
	n->val=-1; 
  	n->c=ch;
  	n->o=-1;
    return n; 
}

trie* r= newn(' '); //First node of trie

void insert(string s, int v) //inserting words in trie, takes word and number assigned to it, inserts it into the trie.
{ 
    trie *start = r; 
    for (int i = 0; i < s.size(); i++) 
    { 
        int index = getind(s[i]); 
        if (!start->child[index]) 
            start->child[index] = newn(s[i]); 
  
        start = start->child[index];
        start->val=v;//path, will be overwritten if another word follows the same path
    }
    start->o=v;//final number assigned to the word ending on the node
} 



void search(int v)//searches the number in the trie
{
	trie *start = r,*temp;
	while(1)
	{
		for(int i=0;i<27;i++)
		{
			if(!start->child[i])
				continue;
			temp=start->child[i];
			if(temp->val>=v)
			{
				start=temp;
				answer+=start->c;//adds char to the answer if the right path is found
				break;
			}
		}
		if(start->o==v)
		{
			return;
		}
	}
}


void readdict(string s) //read dictionary and convert it into trie, takes the path of the dictionary
{ 
    fstream f; 
    f.open(s, ios::in); 
    string w;
    vector<string> v; 
    int i=0;//keep track of what number the word is
    for(string line; getline( f, line ); )//runs till f points to endoffile
	{
		v.clear();
		stringstream s(line);//converts line to stream so input can be taken from it
		while(getline(s,w,','))//input from stream s to w till it encounters ,
		{
			v.push_back(w);
		}
		transform(v[0].begin(), v[0].end(), v[0].begin(), ::tolower);//convert the word to lower case
		insert(v[0],i);//insert to trie
		i++;
	} 
} 
//Driver Function
int main()
{
	string s;
	int n;
	cout<<"Please enter path of the Dictionary: ";
	cin>>s;
	readdict(s); 
	cout<<"Please enter the number: ";
	cin>>n;
	search(n);
	cout<<answer;
}
