#include<bits/stdc++.h>
#include<fstream>
using namespace std;

//The program assumes the words in the dictionary are not case sensitive as the first testcase in the question signifies so.

int getind(char c) //Function to convert lowercase chars to indexes, i.e :a-0, b-1 and so on. Takes a char as input and gives the required index as output
{
  if(c==39)
    return 26;
  else if(97<=c && c<=122)
    return c-97; //converts ' to index 26
  else {
    return 0;
  }
}


typedef struct trie //trie node
{
	trie* child[27]; // array of trie node pointers so each can point to a different char node
	int val; // value of the word that ends on this node, is -1 if no words end at this node	
};

trie *newn(void) //new node with all nulls 
{ 
    trie *n =  new trie;   
    for (int i = 0; i < 27; i++) 
        n->child[i] = NULL;
	n->val=-1; 
  
    return n; 
}

trie* r= newn(); //First node of trie

void insert(string s, int v) //inserting words in trie, takes word and value assigned to it, inserts it into the trie.
{ 
    trie *start = r; 
    for (int i = 0; i < s.size(); i++) 
    { 
        int index = getind(s[i]); 
        if (!start->child[index]) 
            start->child[index] = newn(); 
  
        start = start->child[index]; 
    }
    start->val = v; //final value of the node
} 



int search(string s) //searches the string in the trie, if present, returns the value assosiated with the string, else returns -1
{
	trie *start = r;
	for (int i = 0; i < s.size(); i++) 
    { 
        int index = getind(s[i]);
        if (!start->child[index]) 
            return -1;
  
        start = start->child[index]; 
    }
    return start->val; 
}


void readdict(string s) //read dictionary and convert it into trie, takes the path of the dictionary
{ 
    fstream f; 
    f.open(s, ios::in); 
    string w;
    vector<string> v; 
    for(string line; getline( f, line ); )//runs till f points to endoffile
	{
		v.clear();
		stringstream s(line);//converts line to stream so input can be taken from it
		while(getline(s,w,','))//input from stream s to w till it encounters ,
		{
			v.push_back(w);
		}
		transform(v[0].begin(), v[0].end(), v[0].begin(), ::tolower);//convert the word to lower case
		insert(v[0],stoi(v[1]));//insert to trie
	} 
} 

//Driver Funtion
int main()
{
	string s;
	cout<<"Please enter path of the Dictionary: ";
	cin>>s;
	readdict(s); 
	cout<<"Please enter the word you want to search: ";
	cin>>s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	int ans= search(s);
	if(ans==-1)
		cout<<"No";
	else
		cout<<"YES ,"<<ans;
}
