#include <iostream>
#include <string>
using namespace std;

class Post
{
public:
    string posterLastName; // last name of the person who posted
    int messageId;         // unique per poster
    string date;           // format: YYYYMMDD
    string time;           // format: HHMM
    string message;        // full post text (may contain hashtags)
    bool isDeleted;        // true if post is deleted
    // Constructors
// A — Add Post
// Format
// A PosterLastName, messageId, YYYYMMDD, HHMM, message text...
// Behavior
// • Create a new post with the given information (mark isDeleted = false).
// • Store it in the global posts array.
// • Add the post’s index to the poster’s outgoing list.
// • For every person who follows PosterLastName, add the post’s index to their incoming list
    Post() 
    {
        posterLastName = "";
        messageId = 0;
        date = "";
        time = "";
        message = "";
        isDeleted = false;
    };
};

class Person
{
public:
    string lastName;
    // Follow relationships
    string follows[10]; // last names this person follows
    int numFollows;
    // Post references (indices into Postings.posts)
    int outgoingPostIdx[500];
    int numOutgoing;
    int incomingPostIdx[500];
    int numIncoming;
    // Constructors
// P — Print a Person’s Posts
// Format
// P LastName, Behavior
// Print:
// 1. PERSON LastName
// 2. OUTGOING: All non-deleted outgoing posts, Sorted by date/time (earliest first)
// 3. INCOMING: All non-deleted incoming posts, Sorted by date/time (earliest first)
// Each post must be printed as: PosterLastName (messageId) [YYYYMMDD HHMM]: message text
    Person() 
    {
        lastName = "";
        numFollows = 0;
        numOutgoing = 0;
        numIncoming =0;
    };
    // Utility prototypes
    bool followsPerson(const string &lastName) const 
    {
        for (int i = 0; i < numFollows; i++) 
        {
            if (follows[i] == lastName)
            return true;
        }
        return false;
    };
};

class Postings
{
public:
    Post posts[500];
    int numPosts;
    // Constructors
    Postings() 
    {
        numPosts = 0;
    };

    // Post management
    int addPost(const Post &p) 
    {
        posts[numPosts] =p;
        numPosts++;
        return numPosts -1;
    };
    
    int findPost(const string& posterLastName, int messageId) const 
    {
        for (int i = 0; i < numPosts; i++) 
        {
            if (posts[i].posterLastName == posterLastName && posts[i].messageId == messageId) 
            {
                return i;
            }
        }
        return -1;
    }
    
    void deletePost(int postIndex) 
    {
        if (postIndex >= 0 && postIndex < numPosts) 
        {
            posts[postIndex].isDeleted = true;
        }
    };
};

class SocialMediaSystem
{
public:
    Person persons[100];
    int numPersons;
    Postings postings;

    // Constructors
    SocialMediaSystem() 
    {
        numPersons = 0;
    };
    
    // Person management
    int findPerson(const string &lastName) const 
    {
        
    };
    
    // Command handlers
    void addPost(const string &posterLastName, int messageId, const string &date, const string &time, const string &message) 
    {

    };
    
    void deletePost(const string &posterLastName, int messageId) 
    {

    };

    void printPerson(const string &lastName) const 
    {

    };
    
    void searchHashtag(const string &hashtag) const 
    {

    };
    
    void statistics(int k) const 
    {

    };
    
    
    // Helpers
    bool isEarlier(const Post &a, const Post &b) const
    {

    };
};












//Don't Touch Main
int main()
{
    SocialMediaSystem sys;
    int N;
    cin >> N;
    sys.numPersons = N;

    for (int i = 0; i < N; i++)
    {
        cin >> sys.persons[i].lastName;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
            cin >> sys.persons[i].follows[sys.persons[i].numFollows++];
    }

    int C;
    cin >> C;
    while (C--)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'A')
        {
            string ln, d, t, msg;
            int id;
            cin >> ln >> id >> d >> t;
            cin.ignore();
            getline(cin, msg);
            sys.addPost(ln, id, d, t, msg);
        }
        else if (cmd == 'D')
        {
            string ln;
            int id;
            cin >> ln >> id;
            sys.deletePost(ln, id);
        }
        else if (cmd == 'P')
        {
            string ln;
            cin >> ln;
            sys.printPerson(ln);
        }
        else if (cmd == 'S')
        {
            string tag;
            cin >> tag;
            sys.searchHashtag(tag);
        }
        else if (cmd == 'X')
        {
            int k;
            cin >> k;
            sys.statistics(k);
        }
    }
    return 0;
}