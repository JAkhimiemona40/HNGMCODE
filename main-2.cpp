/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std; 

bool isHung (int); // prototype
 
int main()
{
    string start = "";
    cout << "Welcome To Hangman!" << endl;
    cout << "Type start to begin." << endl;
    cin >> start;
    
    cout << "RULES OF THE GAME:" << endl;
    cout << "You will be asked a series of multiple choice questions. Every wrong answer given" << endl;
    cout << "will result in the hanging of your character and you lose. In order to win," << endl;
    cout << "You must successfully answer 63% of the questions correctly. Good luck!" << endl;
    
    ofstream writer; 
    writer.open ("infile.txt"); 
    writer << "QUESTION 1: What relational operator means greater than or equal to?" << endl;
    writer << "A Answer: >\nB Answer: >=\nC Answer: =>\nD Answer: <\nCorrect answer: B" << endl;

    writer << "QUESTION 2: What two values does a bool variable allow?" << endl;
    writer << "A Answer: 0 and 1\nB Answer: True or false\nC Answer: Yes and no\nD Answer: 1 and 2\nCorrect answer: B" << endl;

    writer << "QUESTION 3: Which relational expression (where x is 4 and y is 8) is true?" << endl;
    writer << "A Answer: x = y\nB Answer: x > y\nC Answer: x < = y\nD Answer: x >= y\nCorrect answer: C" << endl;

    writer << "QUESTION 4: If we place an if statement within an if statement, we are creating a:" << endl;
    writer << "A Answer: If-Then-Else statement\nB Answer: Multiway branch\nC Answer: If-Then-Else-If statement\nD Answer: Nested control structure\nCorrect answer: D" << endl;

    writer << "QUESTION 5: The && and || operators are:" << endl;
    writer << "Answer A: Binary operators\nAnswer B: Unary operators\nAnswer C: Secondary operators\nAnswer D: Primary operators\nCorrect answer: A" << endl;

    writer << "QUESTION 6: To find out if either the test grade is an A or the quiz grade is an A we would write the expression" << endl;
    writer << "Answer A: testGrade = `A' || quizGrade = `A'\nAnswer B: testGrade = `A' && quizGrade = `A'\nAnswer C: testGrade == `A' && quizGrade == `A'\nAnswer D: testGrade ==`A' || quizGrade == `A'\nCorrect answer: D" << endl;

    writer << "QUESTION 7: Which two pairs of expressions are equivalent?" << endl;
    writer << "A Answer: !(a == b) and a != b\nB Answer: !(a == b) and a =! B\nC Answer: (a == b)! and a != b\nD Answer: (a == b)! and a =! B\nCorrect answer: A" << endl;

    writer << "QUESTION 8: Which operator has the lowest precedence?" << endl;
    writer << "A Answer: &&\nB Answer: ==\nC Answer: ||\nD Answer: =\nCorrect answer: D" << endl;

    writer << "QUESTION 9: An assertion that must be true before a module is executed for the module to execute correctly is a:" << endl;
    writer << "A Answer: Postcondition\nB Answer: Precondition\nC Answer: Priorcondition\nD Answer: Subsequentcondition\nCorrect answer: B" << endl;

    writer << "QUESTION 10: The While statement is different from the If statement because?" << endl;
    writer << "A Answer: It is a looping structure\nB Answer: It is used to repeat a course of action\nC Answer: The statement is either skipped, executed once, or executed over and over\nD Answer: All of the above\nCorrect answer: D" << endl;

    writer << "QUESTION 11: What are the two major types of loops?" << endl;
    writer << "A Answer: Count-controlled loops and event-controlled loops\nB Answer: Sentinel-controlled loops and end-of-file-Controlled loops\nC Answer: Sentinel-controlled loops and flag-controlled loops\nD Answer: Count-controlled loops and flag-controlled loops\nCorrect answer: A" << endl;

    writer << "QUESTION 12: A While statement is a looping construct that allows a program to repeat a statement as long as the value on an expression is?" << endl;
    writer << "A Answer: False\nB Answer: True\nC Answer: Positive\nD Answer: Negative\nCorrect answer: B" << endl;

    writer << "QUESTION 13: What are the phases of loop execution?" << endl;
    writer << "A Answer: Entry, test, exit\nB Answer: Entry, iteration, test\nC Answer: Entry, iteration, test, exit\nD Answer: Entry, entry, iteration, exit\nCorrect answer: C" << endl;

    writer << "QUESTION 14: Event-controlled loops repeat until: " << endl;
    writer << "A Answer: something happens within the loop\nB Answer: the specified number of times is reached\nC Answer: the statement has been executed 25 times\nD Answer: the statement is false\nCorrect answer: A" << endl;

    writer << "QUESTION 15: Event-controlled loops repeat until: " << endl;
    writer << "A Answer: something happens within the loop\nB Answer: the specified number of times is reached\nC Answer: the statement has been executed 25 times\nD Answer: the statement is false\nCorrect answer: B" << endl;

    writer << "QUESTION 16: The condition that causes a loop to be exited is the:" << endl;
    writer << "A Answer: exit the loop condition\nB Answer: termination condition\nC Answer: conclude condition\nD Answer: execution condition\nCorrect answer: B" << endl;

    writer.close();
    
    string question, answer1, answer2, answer3, answer4, correct;
    ifstream reader;
    char user, correct_char;
    bool won;
    int errors = 0;
    
    reader.open("infile.txt");

    while(getline(reader, question) and errors < 7)
    
    {
        
      cout << endl << question << endl;
      // gets the answer choices from the file and displays them
      getline(reader, answer1);
      getline(reader, answer2);
      getline(reader, answer3);
      getline(reader, answer4);
      cout << answer1 << endl << answer2 << endl << answer3 << endl << answer4 << endl;

      getline(reader, correct);
      correct_char = correct.back();

      cout << "What answer do you choose: ";
      cin >> user;
      user = toupper(user); // toupper == converts lowercase to uppercase 


      if (user != correct_char) 
      {
        cout << endl << "\t \t \tINCORRECT ANSWER!" << endl;
        errors++;
        isHung(errors);
      }
      
      else 
      {
        cout << endl << "\t \t \tCORRECT ANSWER!" << endl;
      }
      
      }
    if (errors < 7)
    {
      won = true;
    }
    
    else 
    {
      won = false;
    }

    if (won) 
    {
      cout << "\n\nCONGRATULATIONS YOU WON!!!!!" << endl;
    }
    
    else 
    {
      cout << "\n\nYOU LOST, BETTER LUCK NEXT TIME :[" << endl;
    }
    
    
    
    float grade1;
    
    grade1 = (16 - errors);
    
    cout << grade1 << endl;
    
    float grade2;
    
    grade2 = (grade1 / 16) * 100;
    
    cout << "Your percentage is " << grade2 << endl;
    
}



bool isHung (int num_errors) 
{

  switch(num_errors) // switch statement works like if statement
{
    case 7:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      cout << "\t \t \t" << "\t \t" << "/|\\" << endl;
      cout << "\t \t \t" << "\t \t" << " | " << endl;
      cout << "\t \t \t" << "\t \t" << "/ \\" << endl;
      cout << "\t \t \t" << "YOU ARE HUNG" << endl;
      break;
    case 6:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      cout << "\t \t \t" << "\t \t" << "/|\\" << endl;
      cout << "\t \t \t" << "\t \t" << " | " << endl;
      cout << "\t \t \t" << "\t \t" << "/  " << endl;
      break;
    case 5:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      cout << "\t \t \t" << "\t \t" << "/|\\" << endl;
      cout << "\t \t \t" << "\t \t" << " | " << endl;
      break;
    case 4:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      cout << "\t \t \t" << "\t \t" << "/|\\" << endl;
      break;
    case 3:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      cout << "\t \t \t" << "\t \t" << "/| " << endl;
      break;
    case 2:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      cout << "\t \t \t" << "\t \t" << "/   " << endl;
      break;
    case 1:
      cout << "\t \t \t" << "\t \t" << " O " << endl;
      break;
}

  if (num_errors == 7)
{
    return true;
}

  else
  {
    return false;
  }

}
