// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - buffchat driver

#include "Buffchat.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

int main(){
    //Default constructor
    Buffchat b = Buffchat();
    assert(b.getNumPosts() == 0);
    assert(b.getNumUsers() == 0);

    //readPosts
    assert(b.readPosts("posts.txt") == 50); //posts.txt test file
    assert(b.readPosts("posts.txt") == -2); //array is full
    assert(b.readPosts("nofile") == -1); //cant open file
    assert(b.readPosts("empty_file.txt") == -2);//empty file

    //readLikes
    assert(b.readLikes("nofile") == -1); //cant open file
    assert(b.readLikes("users.txt") == 50); //users.txt test file
    assert(b.readLikes("users.txt") == -2); //array is full
    assert(b.readLikes("empty_file.txt") == -2);//empty file

    //printPostsByYear
    b.printPostsByYear("22");
    /*Expected output:
    Here is a list of posts for year 22
    It's National Live Creative Day! What better way to celebrate than showcasing our creative talented and passionate Buffs!
    We had so much fun yesterday at the Be Involved Fair!
    Yesterday was such a beautiful start to the new school year
    Ready for the weekend
    Welcome to the Buffs fam to all our new students
    It's been so toasty in Boulder recently! Are you missing the snow tipped Flatirons?
    John Bally professor emeritus of astrophysical and planetary sciences at CU Boulder comes to @fiskeplanet to take a look at first glimpses of the universe.
    In honor of tomorrow being #NationalTrailsDay we want to know where your favorite hike is around campus Buffs.
    It’s 70° and sunny in April… we hope to catch you outside Buffs
    What better way to celebrate #NationalPuppyDay than with some pics of an excellently dressed @rudytheocfrenchie
    */
   b.printPostsByYear("01");
   //Expected output No posts stored for year 01
Buffchat b2 = Buffchat();
   //getLikes
   assert(b.getLikes("goldenbuff3", "chipthebuffalo") == 10); //random username and author
   assert(b.getLikes("susanfrances", "csmaster") == 6); //random username and author
   assert(b.getLikes("susanf", "seethingaardvark") == -3); //username/author do no exist
   assert(b2.getLikes("goldenbuff3", "chipthebuffalo") == -2); //no posts stored

   //findTagUser
   b.findTagUser("am");
   /*Expected output:
   Here are all the usernames that contain am
    campusfoodreview
    csgradprogram
    pacifiedIcecream7
    amazedOtter4
   */
   b.findTagUser("magdsfgr");
   /*Expected output:
   No matching user found
   */
   b.findTagUser("ar");
    /*Expected output:
   Here are all the usernames that contain ar
    lovesickSardines
    MarcusCU
    jaguarsareawesome
   */

//addPost
Buffchat b3 = Buffchat();
b3.readPosts("posts2.txt");
b3.readLikes("users2.txt");
assert(b.addPost("Hello","jake","01/22/22") == 1); //post added succesfully
assert(b3.addPost("Hello","jake","01/22/22") == 0); //post not added succesfully

//printPopularPosts
Buffchat b4 = Buffchat();
b4.readPosts("empty_file.txt");
b4.readLikes("empty_file.txt");

b4.printPopularPosts(5, "22"); //Expected output: No posts are stored

b4.readPosts("posts.txt");
b4.readLikes("users.txt");
b4.printPopularPosts(5, "22");
/* Expected output:
Top 5 posts for year 22
239 likes: It's National Live Creative Day! What better way to celebrate than showcasing our creative talented and passionate Buffs!
227 likes: Yesterday was such a beautiful start to the new school year
224 likes: Ready for the weekend
1041 likes: In honor of tomorrow being #NationalTrailsDay we want to know where your favorite hike is around campus Buffs.
224 likes: What better way to celebrate #NationalPuppyDay than with some pics of an excellently dressed @rudytheocfrenchie
*/
b4.readPosts("posts2.txt");
b4.readLikes("users2.txt");
b4.printPopularPosts(5, "10");
//Expected output: No posts stored for year 10

Buffchat b5 = Buffchat();
b5.readPosts("posts3.txt");
b5.readLikes("users3.txt");
b5.printPopularPosts(5, "21");
/*Expected output: 
There are fewer than 5 posts for year 21. Top 1 posts for year 21
192 likes: Never a dull moment at CU!
*/

//findLeastActiveUser

//Expected output: "vengefulSauce"
User u = b.findLeastActiveUser();
cout << u.getUsername() << endl;

//Expected output: ""
User u2 = b2.findLeastActiveUser();
cout << u2.getUsername() << endl;

//Expected output: ""
User u3 = b3.findLeastActiveUser();
cout << u3.getUsername() << endl;

//Expected output: "vengefulSauce"
User u4 = b4.findLeastActiveUser();
cout << u4.getUsername() << endl;

//Expected output: "jake"
User u5 = b5.findLeastActiveUser();
cout << u5.getUsername() << endl;


//countUniqueLikes

assert(b2.countUniqueLikes("cuboulderalumni") == -2);//testing for no users or posts stored
assert(b4.countUniqueLikes("cuboulderalumni") == 125);//testing for succesfully counting # of unique likes
assert(b5.countUniqueLikes("cuboulderalumni") == 0);//testing for if no user has liked their posts
assert(b5.countUniqueLikes("jake") == -1);//testing if no user has viewed their posts
}